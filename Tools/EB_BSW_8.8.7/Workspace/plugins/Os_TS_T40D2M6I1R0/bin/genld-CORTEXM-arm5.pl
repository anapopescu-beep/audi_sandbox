#!/usr/bin/perl -w

BEGIN
{
	my $scriptdir = __FILE__;
	$scriptdir =~ s/[^\\\/]+$//;
	push @INC, $scriptdir;
}

# genld-CORTEXM.pl - generate linker script for CORTEXM architecture
#
# $Id: genld-CORTEXM-arm5.pl 1.1 2023/04/18 07:06:15CEST Dan Dustinta (dan.dustinta) in_work  $
#
# Copyright 1998-2016 Elektrobit Automotive GmbH
#
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.
# #############################################################################

# includes ####################################################################
use GenldCommon;
use GenldArchCORTEXM;
# pre-init ####################################################################
# parse provided arguments, will die if there is an error
push @GenldCommon::usage_fns, \&GenldArchCORTEXM::usage;
my $sysdesc = GenldCommon::parseArgs(\&GenldArchCORTEXM::parseArgs);
my $osecTypes = \%GenldArchCORTEXM::osecTypes;
my $LdBackend = $sysdesc->{'backend'};
my $disableRomInit = $sysdesc->{'-disableRomInit'};

# if starting from RAM, set all generated section to fixed addresses
# (load == execution address)
if(defined $disableRomInit) {
	$osecTypes->{'DATA'}->{'_arm5_attr_fixed'} = 'FIXED';
	$osecTypes->{'DATA_BSS'}->{'_arm5_attr_fixed'} = 'FIXED';
}

$LdBackend->setArchCharacteristics($osecTypes, \%GenldArchCORTEXM::memoryBlocks);
# generate linker script includes
GenldCommon::processIncludes();

# begin #######################################################################
$LdBackend->beginOutputSectionMappings();

# reset vector ################################################################
$LdBackend->beginMemoryBlockMappings('reset');
$LdBackend->printOutputSection("reset", 'RESET',
	undef,
	['.reset']
);
$LdBackend->endMemoryBlockMappings('reset');

# exceptiontable ##############################################################
$LdBackend->beginMemoryBlockMappings('exctable');
$LdBackend->printOutputSection("ExceptionTable", 'RESET',
	undef,
	['ExceptionTable', 'InterruptTable']
);
$LdBackend->endMemoryBlockMappings('exctable');

# ROM section #################################################################
$LdBackend->beginMemoryBlockMappings('rom');
$LdBackend->printSymbolDefinition("__GLBL_ROM_START", '.');

# text
$LdBackend->printOutputSection("text", 'TEXT',
	undef,
	['.os_text','.text','i.*'],
	undef, undef, '__GLBL_TEXT_START','__GLBL_TEXT_END'
);

# rodata
$LdBackend->printOutputSection("rodata", 'RODATA',
	undef,
	['.rodata','.constdata','.const*'],
	undef, undef, '__GLBL_RODATA_START','__GLBL_RODATA_END'
);

$LdBackend->printSymbolDefinition("__GLBL_ROM_END", '(ROM_start_addr + ROM_size)', undef, 'FIXED');
$LdBackend->endMemoryBlockMappings('rom');

# ROM data section ############################################################
$LdBackend->beginMemoryBlockMappings('rom_data');

if(defined $disableRomInit) {
	$LdBackend->printSymbolDefinition("__GLBL_RAM_START", 'RAM_start_addr', undef, 'FIXED');
} else {
	$LdBackend->printSymbolDefinition("__GLBL_RAM_START", 'RAM_start_addr');
}

# combine core specific and general anonymous sections
my @anon_data = ('.data');

for (my $coreid=$sysdesc->{'-numcores'}-1; $coreid>=0; $coreid--) {
	# Private data/bss sections
	my @coreapps = grep { $_->{'-core'} eq $coreid } (@{$sysdesc->{'-app'}});
	foreach my $app (@coreapps) {
		printPrivateObjectRegion($app, $coreid);
	}
	push(@anon_data, ".data.core$coreid");
	push(@anon_data, ".data.shared.core$coreid");

}

# catch all anonymous data section
$LdBackend->printOutputSection("data_DATA", 'DATA',
	undef,
	[ @anon_data ]
);

$LdBackend->endMemoryBlockMappings('rom_data');

# RAM section #################################################################
$LdBackend->beginMemoryBlockMappings("ram");
# combine core specific and general anonymous sections
my @anon_bss = ('.bss');

# the kernel stack is init by the startup code
for (my $coreid=$sysdesc->{'-numcores'}-1; $coreid>=0; $coreid--) {
	foreach my $stack (@{$sysdesc->{'-stack'}}) {
		if($stack->{'name'} eq "os_kernstack$coreid") {
			$LdBackend->printOutputSection($stack->{'name'}, 'STACK',
				undef,
				[ ".bss.core$coreid.$stack->{'name'}" ],
				undef, undef, undef, "$stack->{'name'}_END_STACK",
				undef, $stack->{'-size'}, $stack->{'-size'}
			);
		}
	}

	push(@anon_bss, ".bss.core$coreid");
	push(@anon_bss, ".bss.shared.core$coreid");
}

# Data sections to the core-local memories
# Core 0 catches all core-unspecific data and therefore must be last!
for (my $coreid=$sysdesc->{'-numcores'}-1; $coreid>=0; $coreid--) {
	# Stacks
	# If stacks are defined on the command line, put every
	# stack in a seperate output section. This is e.g. required for
	# several MPUs to get the stack aligned correctly.
	# If there is no stack parameter, put all kernel stacks
	# as well as task stacks in one output region.
	if (defined @{$sysdesc->{'-stack'}}) {
		foreach my $stack (@{$sysdesc->{'-stack'}}) {
			if($stack->{'name'} ne "os_kernstack$coreid") {
				$LdBackend->printOutputSection($stack->{'name'}, 'STACK',
					undef,
					[ ".bss.core$coreid.$stack->{'name'}" ],
					undef, undef, undef, "$stack->{'name'}_END_STACK",
					undef, $stack->{'-size'}, $stack->{'-size'}
				);
			}
		}
	} else {
		$LdBackend->printOutputSection("stacks_core$coreid", 'STACK',
			undef,
			[ ".bss.core$coreid.os_kernstack*" ],
			undef, undef, undef, "KERN_STACK_END_CORE$coreid"
		);
		$LdBackend->printOutputSection("tstacks_core$coreid", 'STACK',
			undef,
			[ ".bss.core$coreid.os_taskstack*" ]
		);
	}
}

# os idle stack
$LdBackend->printOutputSection('os_idlestack', 'STACK',
	undef,
	['.os_idlestack'],
	undef, undef, undef, 'os_idlestack_END_STACK', undef, '256', '256'
);

# catch all anonymous bss section
$LdBackend->printOutputSection("bss_DATA", 'BSS',
	undef,
	[ @anon_bss ]
);

$LdBackend->printSymbolDefinition("__GLBL_RAM_END", '(RAM_start_addr + RAM_size)', undef, 'FIXED');
$LdBackend->endMemoryBlockMappings("ram");

$LdBackend->printSymbolDefinition("__GLBL_IO_START", 'io_addr', 'global');
$LdBackend->printSymbolDefinition("__GLBL_IO_END", '(io_addr + io_size)', 'global');

# end #########################################################################
$LdBackend->endOutputSectionMappings();
GenldCommon::finalize();
exit 0;

# helper functions ############################################################
sub printPrivateObjectRegion
{
	my ($obj, $coreId) = @_;

	my $name    = $obj->{'name'};
	my $objtype = $obj->{'type'};
	my $files   = $obj->{'files'};
	my $size 	= $obj->{'-size'};

	if ( @$files == 0 ) {
		$LdBackend->printComment("$objtype $name --- NO FILES");

		if(defined $disableRomInit) {
			$LdBackend->printSymbolDefinition("data_$name", '.', undef, 'FIXED');
			$LdBackend->printSymbolDefinition("bss_$name", '.', undef, 'FIXED');
		} else {
			$LdBackend->printSymbolDefinition("data_$name", '.');
			$LdBackend->printSymbolDefinition("bss_$name", '.');
		}
	} else {
		$LdBackend->printOutputSection("data_$name", 'DATA',
			$files,
			undef,
			undef, undef, "$name\_START_APP", undef, undef, $size
		);
		$LdBackend->printOutputSection("bss_$name", 'DATA_BSS',
			$files,
			undef,
			undef, undef, undef, "$name\_END_APP", undef, undef, $size
		);
	}

	# recurse to contained objects
	foreach my $containedObjectType (@{$obj->{'contains'}}) {
		foreach my $containedObject (@{$obj->{$containedObjectType}}) {
			printPrivateObjectRegion($containedObject, $coreId);
		}
	}
}

# Editor settings: DO NOT DELETE
# vi:set ts=4:

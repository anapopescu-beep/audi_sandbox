#!/usr/bin/perl -w

BEGIN
{
	my $scriptdir = __FILE__;
	$scriptdir =~ s/[^\\\/]+$//;
	push @INC, $scriptdir;
}

# genld-CORTEXM-armkeil.pl - generate linker script for CORTEXM architecture when using the ARMKEIL linker
#
# $Id: genld-CORTEXM-armkeil.pl 1.1 2023/04/18 07:06:15CEST Dan Dustinta (dan.dustinta) in_work  $
#
# Copyright 1998-2017 Elektrobit Automotive GmbH
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

# set derivate specific configs ###############################################
# default alignment is based on the min page size/memory region of provided MPU
$osecTypes->{'DATA'}->{align} = 256;
$osecTypes->{'BSS'}->{endalign} = 256;
$osecTypes->{'STACK'}->{align} = 256;
$osecTypes->{'STACK'}->{endalign} = 256;
$osecTypes->{'TEXT'}->{align} = 256;
$osecTypes->{'TEXT'}->{endalign} = 256;
$osecTypes->{'RODATA'}->{align} = 256;
$osecTypes->{'RODATA'}->{endalign} = 256;
$osecTypes->{'SYMBOL'}->{align} = 256;

# if starting from RAM, set all generated section to fixed addresses
# (load == execution address)
if(defined $disableRomInit) {
	$osecTypes->{'DATA'}->{'_armkeil_attr_fixed'} = 'FIXED';
	$osecTypes->{'BSS'}->{'_armkeil_attr_fixed'} = 'FIXED';
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

# exception and interrupt table ###############################################
# $LdBackend->printSymbolDefinition("__GLBL_ROM_START", 'rom_sect_addr', undef, 'FIXED');
for (my $coreid=0; $coreid<$sysdesc->{'-numcores'}; $coreid++)
{
	$LdBackend->beginMemoryBlockMappings("exctable_C${coreid}");

	if ( $coreid == 0 )
	{
		$LdBackend->printOutputSection("ExceptionTable_C${coreid}", 'RESET', undef, ["ExceptionTable_C${coreid}","InterruptTable_C${coreid}"],"__GLBL_ROM_START");
	}
	else
	{
		$LdBackend->printOutputSection("ExceptionTable_C${coreid}", 'RESET', undef, ["ExceptionTable_C${coreid}","InterruptTable_C${coreid}"], undef);
	}

	$LdBackend->endMemoryBlockMappings("exctable_C${coreid}");
}

# ROM section #################################################################
$LdBackend->beginMemoryBlockMappings('rom');

# text
my $text_align = $sysdesc->{'-text-region-size'};
$LdBackend->printOutputSection("text", 'TEXT',
	undef,
	['.os_text', '.text', 'i.*', 'x$sdivmod', 'x$udivmod', '.ARM.use_no_argv'],
	undef, undef, '__GLBL_TEXT_START','__GLBL_TEXT_END',
	undef, $text_align, $text_align
);

# rodata
my $rodata_align = $sysdesc->{'-const-region-size'};
$LdBackend->printOutputSection("rodata", 'RODATA',
	undef,
	['.rodata','.constdata','.const*'],
	undef, undef, '__GLBL_RODATA_START','__GLBL_RODATA_END',
	undef, $rodata_align, $rodata_align
);

$LdBackend->printSymbolDefinition("__GLBL_ROM_END", '+0');
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
my @anon_bss = ('.bss');

for (my $coreid=$sysdesc->{'-numcores'}-1; $coreid>=0; $coreid--) {
	# Private data/bss sections
	my @coreapps = grep { $_->{'-core'} eq $coreid } (@{$sysdesc->{'-app'}});
	foreach my $app (@coreapps) {
		printPrivateObjectRegion($app, $coreid);
	}
	push(@anon_data, ".data.core$coreid");
	push(@anon_data, ".data.shared.core$coreid");

	push(@anon_bss, ".bss.core$coreid");
	push(@anon_bss, ".bss.shared.core$coreid");
}

# data section
my $data_align = $sysdesc->{'-data-region-size'};
$LdBackend->printOutputSection("data_DATA", 'DATA',
	undef,
	[ @anon_data ],
	undef, undef, 'data_DATA_START', 'data_DATA_END',
	undef, $data_align, $data_align
);

# catch all anonymous bss section
my $bss_data_align = $sysdesc->{'-data-region-size'};
$LdBackend->printOutputSection("bss_DATA", 'BSS',
	undef,
	[ @anon_bss ],
	undef, undef, 'bss_DATA_START', 'bss_DATA_END',
	undef, $bss_data_align, $bss_data_align
);

# get the max stack size to align the RAM load region to
my $max_stack_size = getMaxStackSize();

# the RAM load region use this as start address
if(defined $disableRomInit) {
	$LdBackend->printSymbolDefinition('ROM_DATA_END', '.', undef, 'FIXED', $max_stack_size);
} else {
	$LdBackend->printSymbolDefinition('ROM_DATA_END', '.', undef, undef, $max_stack_size);
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
	if (defined $sysdesc->{'-stack'} and (ref $sysdesc->{'-stack'} eq 'ARRAY')) {
		foreach my $stack (@{$sysdesc->{'-stack'}}) {
			# align stack startaddress to the size of the stack
			my $stack_align = $stack->{'-size'};
			$LdBackend->printOutputSection($stack->{'name'}, 'STACK',
				undef,
				[ ".bss.core$coreid.$stack->{'name'}" ],
				undef, undef, undef, "$stack->{'name'}_END_STACK",
				undef, $stack_align, $stack_align
			);
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
	['.bss.os_idlestack'],
	undef, undef, undef, 'os_idlestack_END_STACK'
);

$LdBackend->printSymbolDefinition("__GLBL_RAM_END", '+0', undef);

$LdBackend->endMemoryBlockMappings('rom_data');

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
		$LdBackend->printOutputSection("bss_$name", 'BSS',
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

# calculate the max stack size provided
sub getMaxStackSize
{
	my $max_stack_size = 0;
	
	if (defined $sysdesc->{'-stack'} and (ref $sysdesc->{'-stack'} eq 'ARRAY')) {
		foreach my $stack (@{$sysdesc->{'-stack'}}) {
			my $stack_size = $stack->{'-size'};
			if($stack_size > $max_stack_size) {
				$max_stack_size = $stack_size;
			}
		}
	}

	# if empty, use the default alignment of the symbols, actually that should
	# never happen because of the default stacks
	if($max_stack_size == 0) {
		$max_stack_size = $osecTypes->{'SYMBOL'}->{align};
	}

	return $max_stack_size;
}


# Editor settings: DO NOT DELETE
# vi:set ts=4:

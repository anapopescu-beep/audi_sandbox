#!/usr/bin/perl -w

BEGIN
{
	my $scriptdir = __FILE__;
	$scriptdir =~ s/[^\\\/]+$//;
	push @INC, $scriptdir;
}

#
# genld-CORTEXM.pl - generate linker script for CORTEXM architecture
#
# $Id: genld-CORTEXM.pl 1.1 2023/04/18 07:06:15CEST Dan Dustinta (dan.dustinta) in_work  $
#
# (C) Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.
#

use GenldCommon;
use GenldArchCORTEXM;

# parseArgs will die if there is an error
push @GenldCommon::usage_fns, \&GenldArchCORTEXM::usage;
my $sysdesc = GenldCommon::parseArgs(\&GenldArchCORTEXM::parseArgs);
my $LdBackend = $sysdesc->{'backend'};
$LdBackend->setArchCharacteristics(\%GenldArchCORTEXM::osecTypes, \%GenldArchCORTEXM::memoryBlocks);
my $osecTypes = \%GenldArchCORTEXM::osecTypes;

my $segmentText = undef;
my $segmentData = undef;
if (defined($sysdesc->{'-emit-load-segments'}))
{
	$segmentText = ':text';
	$segmentData = ':data';
}

if (defined($sysdesc->{'-mpuMinRegionSize'}))
{
	# set derivate specific configs ###############################################
	# default alignment is based on the min page size/memory region of provided MPU

	my $mpuRegionSize = $sysdesc->{'-mpuMinRegionSize'};
	$osecTypes->{'DATA'}->{align} = $mpuRegionSize;
	$osecTypes->{'BSS'}->{endalign} = $mpuRegionSize;
	$osecTypes->{'STACK'}->{align} = $mpuRegionSize;
	$osecTypes->{'STACK'}->{endalign} = $mpuRegionSize;
	$osecTypes->{'TEXT'}->{align} = $mpuRegionSize;
	$osecTypes->{'TEXT'}->{endalign} = $mpuRegionSize;
	$osecTypes->{'RODATA'}->{align} = $mpuRegionSize;
	$osecTypes->{'RODATA'}->{endalign} = $mpuRegionSize;
	$osecTypes->{'SYMBOL'}->{align} = $mpuRegionSize;
}

# process include files
GenldCommon::processIncludes();

$LdBackend->beginOutputSectionMappings();

#
#	printOutputSection parameters:
#	$osecName		: name
#	$osecType		: type
#	$inFiles		: array of file names
#	$inSections		: array of sections
#	$startSymbol	: symbol name, start of the output section in RAM
#	$endSymbol		: symbol name, end of the output section in RAM
#	$initSymbol		: symbol name, start of initvalues of the output section in ROM
#	$initEndSymbol	: symbol name, end of initvalues of the output section in ROM
#

# Optional reset section
if (defined($sysdesc->{'-emitResetSection'}))
{
	$LdBackend->beginMemoryBlockMappings('reset', $segmentText);
	$LdBackend->printOutputSection('reset', 'RESET', undef, ['.reset']);
	$LdBackend->endMemoryBlockMappings('reset');
}

# Exception and interrupt table
for (my $coreid=0; $coreid<$sysdesc->{'-numcores'}; $coreid++)
{
	$LdBackend->beginMemoryBlockMappings("exctable_C${coreid}", $segmentText);

	$LdBackend->printOutputSectionH({
			'osecName' => "ExceptionTable_C${coreid}",
			'osecType' => 'RESET',
			'inSections' => ["ExceptionTable_C${coreid}","InterruptTable_C${coreid}"],
		});

	$LdBackend->endMemoryBlockMappings("exctable_C${coreid}");
}

# Text and read-only data
$LdBackend->beginMemoryBlockMappings('rom');
$LdBackend->printOutputSectionH({
		'osecName' => 'text',
		'osecType' => 'TEXT',
		'inSections' => ['.os_text', '.text', 'i.*'],
		'startSymbol' => '__GLBL_TEXT_START',
		'endSymbol' => '__GLBL_TEXT_END'
	});
$LdBackend->printOutputSectionH({
		'osecName' => 'rodata',
		'osecType' => 'RODATA',
		'inSections' => ['.rodata', '.constdata', '.const*'],
		'startSymbol' => '__GLBL_RODATA_START',
		'endSymbol' => '__GLBL_RODATA_END'
	});
$LdBackend->endMemoryBlockMappings('rom');

$LdBackend->beginMemoryBlockMappings('ram', $segmentData);

$stackIndex = 0;
# First, collect all the stacks at the beginning of RAM
for (my $coreid=$sysdesc->{'-numcores'}-1; $coreid>=0; $coreid--)
{
	# Stacks
	# If stacks are defined on the command line, put every
	# stack in a seperate output section. This is e.g. required for
	# several MPUs to get the stack aligned correctly.
	# If there is no stack parameter, put all kernel stacks
	# as well as task stacks in one output region.
	if (defined $sysdesc->{'-stack'} and (ref $sysdesc->{'-stack'} eq 'ARRAY'))
	{
		foreach my $stack (@{$sysdesc->{'-stack'}}) {
			my $stackSize = undef;
			$stackSize = $stack->{'-size'} if $stack->{'-size'};

			if (defined ($stackSize))
			{
				$LdBackend->printOutputSectionH({
						'osecName' => "$stack->{name}_C${coreid}",
						'osecType' => 'STACK',
						'inSections' => [ ".bss.core${coreid}.$stack->{'name'}" ],
						'startSymbol' => "__STACK${stackIndex}_START",
						'startAlign' => $stackSize,
						'endAlign' => $stackSize,
					});
				$stackIndex++;
			}
		}
		if ($sysdesc->{'-backend'} eq 'iar') {
			my @stacks=();
			foreach my $stack (@{$sysdesc->{'-stack'}}) {
				push @stacks, $stack->{'name'};
			}
			$LdBackend->placeInOrder("STACKS", \@stacks);
		}
	}
	else
	{
		$LdBackend->printOutputSectionH({
				'osecName' => "stacks_core${coreid}",
				'osecType' => 'STACK',
				'inSections' => [ ".bss.core${coreid}.os_kernstack*" ],
				'startSymbol' => "__STACK${stackIndex}_START",
				'endSymbol' => "KERN_STACK_END_CORE${coreid}",
			});
		$stackIndex++;
		$LdBackend->printOutputSectionH({
				'osecName' => "tstacks_core${coreid}",
				'osecType' => 'STACK',
				'inSections' => [ ".bss.core${coreid}.os_taskstack*" ],
				'startSymbol' => "__STACK${stackIndex}_START",
			});
		$stackIndex++;
	}
}

# Data sections to the core-local memories
# Core 0 catches all core-unspecific data and therefore must be last!
for (my $coreid=$sysdesc->{'-numcores'}-1; $coreid>=0; $coreid--)
{
	# Private data/bss sections
	my @coreapps = grep { $_->{'-core'} eq $coreid } (@{$sysdesc->{'-app'}});
	foreach my $app (@coreapps) {
		printPrivateObjectRegion($app, $coreid);
	}

	# Catch-all for core-specific data
	$LdBackend->printOutputSectionH({
			'osecName' => "data_core${coreid}",
			'osecType' => 'DATA',
			'inSections' => [ ".data_core${coreid}", ".data_shared_core${coreid}" ],
			'startSymbol' => "__STARTDATA_C${coreid}",
			'endSymbol' => "__ENDDATA_C${coreid}",
			'initSymbol' => "__INITDATA_C${coreid}"
		});

	$LdBackend->printOutputSectionH({
			'osecName' => "bss_core${coreid}",
			'osecType' => 'BSS',
			'inSections' => [ ".bss_core${coreid}", ".bss_shared_core${coreid}" ],
			'startSymbol' => "__STARTBSS_C${coreid}",
			'endSymbol' => "__ENDBSS_C${coreid}"
		});

	if ($sysdesc->{'-backend'} eq 'iar') {
		$LdBackend->placeInOrder("c${coreid}_DATABSS", ["data_core${coreid}", "bss_core${coreid}"]);
	}
}

# Catch-all for data/bss not assigned to a specific core
# Assigned to core 0
$LdBackend->printOutputSectionH({
		'osecName' => 'DATA',
		'osecType' => 'DATA',
		'inSections' => ['.data'],
		'startSymbol' => '__STARTDATA',
		'endSymbol' =>  '__ENDDATA',
		'initSymbol' =>  '__INITDATA'
	});

$LdBackend->printOutputSectionH({
		'osecName' => 'BSS',
		'osecType' => 'BSS',
		'inSections' => ['.bss','.bss.*','.os_idlestack','COMMON'],
		'startSymbol' => '__STARTBSS',
		'endSymbol' =>  '__ENDBSS'
	});

if ($sysdesc->{'-backend'} eq 'iar') {
	$LdBackend->placeInOrder('DATABSS', ['DATA', 'BSS']);
}

$LdBackend->endMemoryBlockMappings('ram');

foreach my $mr (sort (keys %{$sysdesc->{'-mr'}}))
{
	$LdBackend->printComment("symbols for user configured memory region $mr");

	my $obj = $sysdesc->{'-mr'}{$mr};
	foreach my $mr_sym (@{$obj}{qw(RSA RLA BSA IDAT)})
	{
		next unless defined $mr_sym;
		my $dest_adr = "OS_DUMMY_ADR";

		if($mr_sym =~ /=/) {
			($mr_sym,$dest_adr) = ($`,$');
		}

		$LdBackend->printSymbolDefinition($mr_sym, $dest_adr);
	}
	GenldCommon::printOut("\n");
}

$LdBackend->endOutputSectionMappings();

GenldCommon::finalize();

exit 0;

sub printPrivateObjectRegion
{
	my ($obj, $coreId) = @_;

	my $name    = $obj->{'name'};
	my $objtype = $obj->{'type'};
	my $files   = $obj->{'files'};
	my $size    = $obj->{'-size'};

	if ( @$files == 0 ) {
		GenldCommon::printOut("/* ${objtype} ${name} --- NO FILES */");

		$LdBackend->printSymbolDefinition("__DATA_${name}", 0);
		$LdBackend->printSymbolDefinition("__DEND_${name}", 0);
		$LdBackend->printSymbolDefinition("__IDAT_${name}", 0);
		$LdBackend->printSymbolDefinition("__IEND_${name}", 0);

	} else {
		my $idat = "__IDAT_${name}";
		my $iend = "__IEND_${name}";
		my $data = "__DATA_${name}";
		my $dend = "__DEND_${name}";
		$LdBackend->printOutputSectionH({
				'osecName' => "data_${name}",
				'osecType' => 'DATA',
				'inFiles' => $files,
				'startSymbol' => $data,
				'initSymbol' => $idat,
				'initEndSymbol' => $iend,
				'startAlign' => $size
			});
		$LdBackend->printOutputSectionH({
				'osecName' => "bss_${name}",
				'osecType' => 'BSS',
				'inFiles' => $files,
				'endSymbol' => $dend,
				'endAlign' => $size
			});
		if ($sysdesc->{'-backend'} eq 'iar') {
			$LdBackend->placeInOrder("${name}_DATABSS", ["data_${name}", "bss_${name}"], $size);
		}
	}

	GenldCommon::printOut("\n");

	# recurse to contained objects
	foreach my $containedObjectType (@{$obj->{'contains'}})
	{
		foreach my $containedObject (@{$obj->{$containedObjectType}})
		{
			printPrivateObjectRegion($containedObject, $coreId);
		}
	}
}

# Editor settings: DO NOT DELETE
# vi:set ts=4:

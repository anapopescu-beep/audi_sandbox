#!/usr/bin/perl -w
#
# genld-CORTEXM-iar.pl - generate linker script for IAR, CORTEXM variant.
#
# $Id: genld-CORTEXM-iar.pl 1.1 2023/04/18 07:06:15CEST Dan Dustinta (dan.dustinta) in_work  $
#
# Usage:
# genld-CORTEXM-iar.pl (outfile) objdir [-app|-task|-isr name objfile [...]] ...
#
# System, application and file names cannot contain spaces.
#
# Copyright Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.

print STDERR "Usage: $0 outfile objdir [app_spec ...]\n"
	and die if (! defined $ARGV[1]);

my $outname = shift;
my $objdir = getDotlessPath(shift);

open(OUTFILE, ">$outname") or die "$0: Unable to open $outname for writing: $!\n";


# Return a path that does not contain "..". Poor man's implementation of
# realpath(3).
sub getDotlessPath
{
	my $pathName = shift;
	# replaces backslashes with slashes.
	$pathName =~ s/\\/\//g;

	my @pathparts = split(/\//, $pathName);
	my $ret = "";
	my $skipNext = 0;

	for my $p (reverse @{pathparts})
	{
		if ($p eq '..')
		{
			$skipNext++;
		}
		else
		{
			if ($skipNext == 0)
			{
				$ret = $p . "/" . $ret;
			}
			else
			{
				$skipNext--;
			}
		}
	}

	return $ret;
}

# Convert a decimal or hexadecimal string to a numeric value.
# Returns the numeric value.
sub HexDecStringToNumber
{
	my $strNumber = shift; # String to convert.
	my $base = 10;
	my $ret = 0;

	# check, if a Hex prefix is present
	if (substr($strNumber, 0, 2) eq "0x")
	{
		$base = 16;
		# cut off '0x'
		$strNumber = substr($strNumber, 2, length($strNumber) - 2);
	}

	# convert to decimal. Note: The shipped perl does not include the POSIX
	# module, so we have to do it by hand.
	for (my $i = 0; $i < length($strNumber); $i++)
	{
		my $digit = ord(substr($strNumber, $i, 1)) - ord('0');
		$ret = $ret * $base;
		$ret += $digit;
	}

	return $ret;
}

# ===========================================================================
# parse command line
# ===========================================================================

my @apps;	# Application/task names.
my @stacks; # Stack sections and MPU sizes

# Get the date
my ($mm, $hh, $DD, $MM, $YY) = (localtime(time))[1,2,3,4,5];
my $gendate = sprintf("%04d-%02d-%02d %02d:%02d", ($YY+1900), ($MM+1), $DD, $hh, $mm);

# 2nd: Parse all the app-specs in the command line.
# ---------------------------------------------------------------------------
my %objdescs =
(
	'app' => "Application",
	'task' => 'Task',
	'isr' => 'ISR',
);

for(my $i=0; $i < @ARGV; $i++)
{
	if ( $ARGV[$i] =~ /^-(app|task|isr)$/ )
	{
		die "Too few parameters" unless $i<($#ARGV + 1);

		# Save the app name in the array.
		unshift @apps,
		{
			'name' => $ARGV[++$i],
			'regionsize' => HexDecStringToNumber($ARGV[++$i]),
			'type' => $objdescs{$1},
			'files' => [ ],
		};
	}
	elsif ( $ARGV[$i] eq '-stack' )
	{
		# -stack STACKSECTION MPUSIZE
		die "Too few parameters!" unless ($i + 1) < $#ARGV;

		# remember section and MPU size.
		push @stacks,
		{
			'section' => $ARGV[++$i],			# Note: Section is without preceding '.'.
			'regionsize' => HexDecStringToNumber($ARGV[++$i]),
		};
	}
	else
	{

		my $file = $ARGV[$i];
		push @{$apps[0]{'files'}}, $file;
	}
}

# restore input order
@apps = reverse @apps;
# sort according to region size to minimize alignment gaps
@apps = sort { $a->{'regionsize'} cmp $b->{'regionsize'} } @apps;
# sort stacks according to region size as well.
@stacks = sort { $a->{'regionsize'} cmp $b->{'regionsize'} } @stacks;

# ===========================================================================
# local functions
# ===========================================================================

# Print symbols for an unused section.
sub RegionUnused
{
	my $name = shift;			# exact name of the section (used in symbols)
	my $comment = shift;	# informative comment about section

	print OUTFILE <<EOF;
/* Section $name is unused: */
/* ${comment} */
define block ${name} with fixed order, alignment = 8
{
	/* empty */
};

define block ${name}_init with fixed order, alignment = 8
{
	/* empty */
};

".${name}": place in RAM { block ${name} };
".${name}_init": place in FLASH { block ${name}_init };

EOF
}

# print to OUTFILE a list of objects with a given prefix.
# The list is comma-separated (all but last element).
sub PrintObjectsList
{
	my $prefix = shift;		# prefix to print
	my $objects = shift;	# list of objects
	my $trailingComma = shift; # print a trailing comma?

	for my $object (@{$objects})
	{
		if (($trailingComma == 0) && ($object eq @{$objects}[-1]))
		{
			print OUTFILE "$prefix $object\n";
		}
		else
		{
			print OUTFILE "$prefix $object,\n";
		}
	}
}


# print one output section representing a memory region
# by a list of objects from which .data and .bss is extracted
#
# A memory region is mapped to two output sections. The first one
# contains the initialized data, the second one the uninitialized
# data.
# The kernel initializes the initialized data from the ROM image
# using from the range __IDAT_<name> to __IEND_<name>. The remainder
# of the region (i.e. __DATA_<name> + (__IEND_<name> - __IDAT_<name>))
# must be the BSS portion and is initialized with zero.
sub RegionByObjects
{
	my $name = shift;			# exact name of section (used in symbols)
	my $comment = shift;		# informative comment about section
	my $objects = shift;		# objects, from which data and bss is extracted
	my $palign = shift;			# align and pad section to palign bytes

	print OUTFILE <<EOF;
/* ${comment} */
define block ${name} with fixed order, alignment = $palign, size = $palign
{
EOF
	PrintObjectsList("\tsection .data object", \@{$objects}, 1);
	PrintObjectsList("\tsection .bss object", \@{$objects}, 0);
	print OUTFILE <<EOF;
};

define block ${name}_init with fixed order, alignment = 8
{
EOF
	PrintObjectsList("\tsection .data_init object", \@{$objects}, 0);
	print OUTFILE <<EOF;
};


do not initialize
{
EOF
	PrintObjectsList("\tsection .bss object", \@{$objects}, 0);
	print OUTFILE <<EOF;
};

initialize manually with packing = none
{
EOF
	PrintObjectsList("\tsection .data object", \@{$objects}, 0);
	print OUTFILE <<EOF;
};

".${name}": place in RAM { block ${name} };
".${name}_init": place in FLASH { block ${name}_init };

EOF
}

# print one output section representing a memory region
# by an input section name. The input section is mapped as a NOLOAD section (like .bss).
sub RegionBySection
{
	my $name = shift;			# exact name of section (used in symbols)
	my $comment = shift;		# informative comment about section
	my $inputSec = shift;		# name of input section
	my $palign = shift;			# align and pad section to palign bytes

	print OUTFILE <<EOF;
/* ${comment} */
define block ${name} with fixed order, alignment = $palign, size = $palign
{
	section $inputSec
};

do not initialize
{
	section $inputSec
};

".${name}": place in RAM { block ${name} };
EOF
}

# generate OS stack sections
sub genStackSections
{
	my $i = 0;

	foreach my $stack (@stacks)
	{
		my $section = '.bss.core0.' . $stack->{'section'};
		my $regionsize = $stack->{'regionsize'};
		my $stackname = "os_stack_$i";

		if ($regionsize != 0)
		{
			RegionBySection($stackname, "Os Stack $i", $section, $regionsize);
		}
		else
		{
			RegionUnused($stackname, "Os Stack $i");
		}
		$i++;
	}
}


# ===========================================================================
# header, static parts (.text and .rodata)
# ===========================================================================
print OUTFILE <<EOF;
/* Linker script for the IAR (CORTEXM).
 *
 * GENERATED FILE: DO NOT EDIT
 * Generated by $0 on $gendate
 *
*/

/* include static board file header */
include "$objdir/../generated/board_memory_defs.ldscript";

/* ExceptionTable and InterruptTable contain entry points, so the linker
 * must not discard them.
*/
keep
{
	section ExceptionTable,
	section InterruptTable
};

/* Symbols for Memory Protection: Global RAM region */
define exported symbol __GLBL_RAM_START = start(RAM);
define exported symbol __GLBL_RAM_END = start(RAM) + size(RAM);

/* Symbols for Memory Protection: Global ROM region */
define exported symbol __GLBL_ROM_START = start(EXCTABLE);
define exported symbol __GLBL_ROM_END = start(FLASH) + size(FLASH);


/* Block definitions ... */
define block .ExceptionTable with fixed order, alignment = 8
{
	section ExceptionTable,
	section InterruptTable
};

define block .text with alignment = 8
{
	section .os_text,
	section .text
};

define block .const with alignment = 8
{
	section .rodata*
};

".ExceptionTable": place in EXCTABLE { block .ExceptionTable };
".text": place in FLASH { block .text };
".const": place in FLASH { block .const };
EOF

# ===========================================================================
# Stacks: BSS sections
# ===========================================================================
genStackSections();

# ===========================================================================
# Tasks / Isrs / Applications: Private data / bss section.
# ===========================================================================

foreach my $app (@apps)
{
	my $appname = $app->{'name'};
	my $objtype = $app->{'type'};
	my $files = $app->{'files'};
	my $regionsize = $app->{'regionsize'};

	# prepend object directory.
#	my @obj_files = map
#	{
#		$_
#	} @$files;

	if (   ($objtype eq $objdescs{"app"})
		|| ($objtype eq $objdescs{"task"})
		|| ($objtype eq $objdescs{"isr"}) )
	{
		if ($regionsize == 0)
		{
			RegionUnused($appname, "$objtype $appname data/bss");
		}
		else
		{
			RegionByObjects($appname,
											"$objtype
											$appname data/bss",
											\@$files,
											$regionsize);
		}
	}
	else
	{
		die("Unknown type $objtype!");
	}
}

# ===========================================================================
# static portions: Symbol definitions, anonymous .data/.bss
# ===========================================================================
print OUTFILE <<EOF;
/* Data initialization.
*/
define block DATA_init with fixed order, alignment = 8
{
	section .data_init,
	section .data.core*.kernelData_init
};

define block DATA with fixed order, alignment = 8
{
	section .data,
	section .data.core*.kernelData,
};

define block BSS with fixed order, alignment = 8
{
	section .bss.core*.os_kernstack,
	section .bss.core*.os_taskstack,
	section .os_idlestack,
	section .os_kernstack_*,
	section .bss,
	section .bss.*
};

initialize manually with packing = none
{
	section .data,
	section .data.core*.kernelData
};

do not initialize
{
	section .bss.core*.os_kernstack,
	section .bss.core*.os_taskstack,
	section .os_idlestack,
	section .os_kernstack_*,
	section .bss,
	section .bss.*
};

"DATA_init": place in FLASH { block DATA_init };
"DATA": place in RAM { block DATA };
"BSS": place in RAM { block BSS };

EOF

# Editor settings: DO NOT DELETE
# vi:set ts=2 sw=2:

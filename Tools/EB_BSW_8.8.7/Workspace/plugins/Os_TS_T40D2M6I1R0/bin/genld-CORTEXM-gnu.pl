#!/usr/bin/perl -w
#
# genld-ARM-gnu.pl - generate linker script for GNU binutils, ARM variant.
#
# $Id: genld-CORTEXM-gnu.pl 1.1 2023/04/18 07:06:15CEST Dan Dustinta (dan.dustinta) in_work  $
#
# Usage:
# genld-CORTEXM-gnu.pl (outfile) objdir [-app|-task|-isr name objfile [...]] ...
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

my $bootsection = "";	# boot section name.
my $bootmemory = "";	# boot memory area
my $bootoffset = 0;		# reset vector offset (optional)

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
	elsif ( $ARGV[$i] eq '-boot' )
	{
		# -boot BOOTSECTION BOOTMEMORY
		die "Too few parameters!" unless ($i + 1) < $#ARGV;

		# remember bootsection and memorytype.
		$bootsection = $ARGV[++$i];			# Note: Section is without preceding '.'.
		$bootmemory = $ARGV[++$i];
		
		if (($i < $#ARGV) && ($ARGV[$i+1] =~ /^\d+$/))
		{
			$bootoffset = $ARGV[++$i];
		}
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
	__DATA_${name} = 0;
	__DEND_${name} = 0;
	__IDAT_${name} = 0;
	__IEND_${name} = 0;
EOF
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
	${name}_data : ALIGN($palign)
	{
		. = ALIGN($palign);
EOF
	for my $object (@{$objects})
	{
		print OUTFILE "\t\t${object}(.data)\n";
	}

	print OUTFILE <<EOF;
	} >RAM AT>FLASH

	${name}_bss (NOLOAD) :
	{
EOF
	for my $object (@{$objects})
	{
		print OUTFILE "\t\t${object}(.bss)\n";
	}

	print OUTFILE <<EOF;
		. = ALIGN($palign);
	} >RAM

	__DATA_${name} = ADDR(${name}_data);
	__DEND_${name} = .;
	__IDAT_${name} = LOADADDR(${name}_data);
	__IEND_${name} = LOADADDR(${name}_data) + SIZEOF(${name}_data);
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
	${name}_noload (NOLOAD) : ALIGN($palign)
	{
		*(${inputSec})
		. = ALIGN($palign);
	} >RAM
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
/* Linker script for the GNU ld (ARM).
 *
 * GENERATED FILE: DO NOT EDIT
 * Generated by $0 on $gendate
 *
*/

/* include static board file header */
INCLUDE "$objdir/../generated/board_memory_defs.ldscript"

/* CORTEXMExceptionTable contains the exception vectors and must not be
 * eliminated, even though it is not referenced anywhere.
 * CORTEXMInterruptTable contains the interrupt vectors. Likewise, it must
 * not get removed.
*/
EXTERN(CORTEXMExceptionTable)
EXTERN(CORTEXMInterruptTable)

SECTIONS
{
EOF

if ($bootsection ne '')
{
print OUTFILE <<EOF;
	$bootsection :
	{
		. = $bootoffset;
		LONG(boardResetStart)
	} >$bootmemory = 0x0000

EOF
}

print OUTFILE <<EOF;
	.ExceptionTable : ALIGN(64)
	{
		*(ExceptionTable)
		*(InterruptTable)
	} >EXCTABLE

	.const : ALIGN(8)
	{
		*(.rodata*)
		. = ALIGN(8);
	} >FLASH

	.text : ALIGN(8)
	{
		*(.os_text*)
		*(.text*)
		. = ALIGN(8);
	} >FLASH

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
	my $files   = $app->{'files'};
	my $regionsize = $app->{'regionsize'};

	# prepend object directory.
	my @obj_files = map
	{
		$objdir . $_
	} @$files;


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
							"$objtype $appname data/bss",
							\@obj_files,
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
	. = ALIGN(8);
	/* Anonymous .data/.bss section */
	OS_ANON_data :
	{
		*(.data.core*.kernelData)
		*(.data)
	} >RAM AT>FLASH

	OS_ANON_bss (NOLOAD) :
	{
		*(.bss)
		*(COMMON)
		/* catch all remaining stacks of trusted tasks/ISRs */
		*(.bss.core*.os_kernstack*)
		*(.bss.core*.os_taskstack*)
		*(.os_idlestack)
		*(.os_kernstack_*)
		*(.bss.*)
		. = ALIGN(8);
	} >RAM

	/* The following symbols are used to initialize anonymous data in the board
	 * files:
	*/
	/* anonymous data section: initialized data VMA start */
	__STARTDATA = ADDR(OS_ANON_data);
	/* anonymous data section: initialized data VMA end */
	__ENDDATA = ADDR(OS_ANON_data) + SIZEOF(OS_ANON_data);

	/* anonymous data section: LMA of initialized data */
	__INITDATA = LOADADDR(OS_ANON_data);

	/* anonymous data section: bss VMA start */
	__STARTBSS = ADDR(OS_ANON_bss);
	/* global data section: bss VMA end */
	__ENDBSS = ADDR(OS_ANON_bss) + SIZEOF(OS_ANON_bss);
EOF
# ===========================================================================
# Footer:
# ===========================================================================

print OUTFILE <<EOF;
}
EOF

# Editor settings: DO NOT DELETE
# vi:set ts=2 sw=2:

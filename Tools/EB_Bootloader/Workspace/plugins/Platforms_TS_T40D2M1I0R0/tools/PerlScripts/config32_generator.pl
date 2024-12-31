use strict;
use warnings;

my $inputpath = $ARGV[0];
if (not defined $inputpath)
{
  die "ERROR: no parameter passed on comandline!\n";
}

if (!(-e $inputpath))
{
  die "ERROR: input path does not exist: \"$inputpath\"\n";
}

$inputpath =~ tr/\\/\//;


my $config_t32 = <<END;
; Environment variables
OS=
ID=T32
TMP=$inputpath/tmp 
SYS=$inputpath 


; USB information 
PBI=
USB
;NODE=C11100151285

; Printer settings 
PRINTER=WINDOWS

;T32 API Access
RCL=NETASSIST
PACKLEN=1024
PORT=20006


; Screen fonts
SCREEN=
MWI

END

print $config_t32;


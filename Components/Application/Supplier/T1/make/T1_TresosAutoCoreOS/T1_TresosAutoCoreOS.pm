######################################################################################
#
#   File:           T1_TresosAutoCoreOS.pm
#
#   Description:    Parse EB tresos AutoCore OS specific OS headers and extract
#                   OS-configuration
#                   Assumes that OS-files are well-formed
#
#   $Author: Dan Dustinta (dan.dustinta) $
#
#   $Revision: 1.4 $
#
#   Copyright:      GLIWA embedded systems GmbH & Co. KG
#                   Weilheim i.OB.
#                   All rights reserved
#
######################################################################################

use 5.006_000;

package T1_TresosAutoCoreOS;
require Exporter;
our @ISA = ('Exporter');
our @EXPORT = qw(OsReadOsConfiguration OsGetValue OsGetSysElementReference OsGetIsrWrapper OsPerformInstrumentation);

use strict;
use warnings;
use File::Spec::Functions 'rel2abs';
use File::Path;
use File::stat;

#----------------------------------------------------------------------------------
my $appendElementType = 'false';
my $mcuCore = '';                   # used MCU [MPC5xxx/V850/TMS570/ARM/TC2xx/TC3xx]
my $osConfigHeader = '';            # name and path of Os_Config.h
my $osUserHeader = '';              # name and path of Os_user.h
my $parseOsStackCfg = 'false';
my @runnableParseModules;           # Optional: modules such RTE.c can be parsed for runnable names. Macros are created accordingly in T1_config.h (or T1_ids.h respectively).
#----------------------------------------------------------------------------------

my $nOfCores = 1;

my %systemElements = qw();
my %osApplications;

my $isrShims = '';

my @includeDirs = ();

my $debug = 0;


my $symbolPrefix;
my @osDefineStacks;
my %traceIds;
my %executionCountersPerTask;
my $maxTaskId = 0;
my $maxIsrId = 0;

#----------------------------------------------------------------------------------
sub OsParseParam($)
{
    my $currentParam = shift;

    if( not $currentParam =~ /^;/ ) # a ';' functions as a comment operator
    {
        my $val = '';
        my $validParamFound = 0;
        my @substr = split /;/, $currentParam;
        $currentParam = $substr[0];
        $currentParam =~ s/\s+$//;
        if( $debug )
        {
            print "$currentParam \n";
        }

           if( ($val) = $currentParam =~ /-osUserHeader=(.*)/ )              { $osUserHeader      = rel2abs( $val ); $validParamFound = 1; }
        elsif( ($val) = $currentParam =~ /-osConfigHeader=(.*)/ )            { $osConfigHeader    = rel2abs( $val ); $validParamFound = 1; }
        elsif( ($val) = $currentParam =~ /-mcuCore=(.*)/ )                   { $mcuCore           = $val;            $validParamFound = 1; }
        elsif( ($val) = $currentParam =~ /-parseOsStackCfg=(true|false)/ )   { $parseOsStackCfg   = $val;            $validParamFound = 1; }
        elsif( ($val) = $currentParam =~ /-appendElementType=(true|false)/ ) { $appendElementType = $val;            $validParamFound = 1; }
        elsif( ($val) = $currentParam =~ /-runnableParseModule=(.*)/ )       { push @runnableParseModules, rel2abs( $val ); $validParamFound = 1; }

        if( ( not $validParamFound ) and ( $currentParam =~ /\s*-.*/ ) )
        {
            die "error: invalid parameter $currentParam found in command line";
        }
    }
}

######################################################################################
# Parse command line
######################################################################################
sub OsReadOsConfiguration($$@)
{
    ( my $invocationFile, $symbolPrefix, my @incDirs ) = @_;

    @includeDirs = @incDirs;

    if ($invocationFile)
    {
        open my $fh, '<', $invocationFile or die qq(Error: could not locate invocation file "${invocationFile}.");

        while( my $currentLine = <$fh> )
        {
            &OsParseParam( $currentLine );
        }

        close $fh;
    }

    my $osName = "Tresos";

    #----------------------------------------------------------------------------------
    # Determine the task names, interrupt names and IDs
    #----------------------------------------------------------------------------------
    open my $fh, '<', $osUserHeader or die qq(Error: Could not open file "${osUserHeader}");
    while( my $currentLine = <$fh> )
    {
        if( $currentLine =~ /#\s*define\s+(\w+)\s+(\d+)/ )
        {
            # Potentially found trace ID, store these in a hash for latter assignment
            $traceIds{$1} = int $2;
        }
    }
    close $fh;

    open $fh, '<', $osConfigHeader or die qq(Error: Could not open file "${osConfigHeader}");
    while( my $currentLine = <$fh> )
    {
        if( $currentLine =~ /#\s*define\s+(\w+)\s+(\d+)/ )
        {
            # Potentially found trace ID, store these in a hash for latter assignment
            $traceIds{$1} = int $2;
        }
    }
    close $fh;

    my $currentOsApplicationRef;
    my $currentSystemElementRef;
    my $currentTaskOsStackRef;
    my $currentStackOsStartSymbolRef;
    my $currentStackOffset;
    my $currentStackSize;

    my @osDefineStackFirstPass;

    open $fh, '<', $osConfigHeader or die qq(Error: Could not open file "${osConfigHeader}");
    while( my $currentLine = <$fh> )
    {
        if( $currentLine =~ /OS_APPCONFIG_INIT\s*\(\s*\/\*\s*(\w+)/ )
        {
            $osApplications{$1} = {
                Name => $1,
                Core => undef,
            };

            $currentOsApplicationRef = $osApplications{$1};
            undef $currentSystemElementRef;
        }
        elsif( $currentLine =~ /OS_TASKCONFIG_INIT\s*\(\s*\/\*\s*(\w+)/ )
        {
            # Found new task
            $systemElements{'Task'}{$1} = {
                Name            => $1,
                SymbolName      => undef,
                Comment         => '',
                Offset          => 0,
                ID              => exists $traceIds{$1} ? int $traceIds{$1} : undef,
                Period          => 0,
                Core            => 'all',
                Type            => 'Task',
                Priority        => undef,
                OsStackRef      => undef,
                MaxActivations  => undef,
                FunctionalGroup => undef, # Used to save name of OS application
            };

            $currentSystemElementRef = $systemElements{'Task'}{$1};
            undef $currentOsApplicationRef;
        }
        elsif( $currentLine =~ /OS_ISRCONFIG_INIT\s*\(\s*\/\*\s*(\w+)/ )
        {
            # Found ISR

            $systemElements{'Interrupt'}{$1} = {
                Name            => $1,
                SymbolName      => undef,
                Comment         => '',
                Offset          => 0,
                ID              => exists $traceIds{$1} ? int $traceIds{$1} : undef,
                Period          => 0,
                Core            => undef, # for multi-core only initial value
                Type            => 'Interrupt',
                Category        => undef,
                Priority        => undef,
                FunctionalGroup => undef, # Used to save name of OS application
            };

            $currentSystemElementRef = $systemElements{'Interrupt'}{$1};
            undef $currentOsApplicationRef;
        }
        elsif( $currentLine =~ /#\s*define/)
        {
            undef $currentOsApplicationRef;
            undef $currentSystemElementRef;
        }
        elsif( defined $currentSystemElementRef or defined $currentOsApplicationRef )
        {
            my $key;
            my $value;
            if( $currentLine =~ /^\s*([\S]+)\s*\/\*\s*([\S\s]+?)\s*\*\// ) # Value / Key (e.g. v6.0)
            {
                $key = $2;
                $value = $1;
            }
            elsif( $currentLine =~ /^\s*\/\*\s*([\S\s]+?)\s*\*\/\s*(\S+)/ ) # Key / Value (e.g. v6.1)
            {
                $key = $1;
                $value = $2;
            }
            else
            {
                # No key value pair found continue with next line
                next;
            }

            # Strip leading ampersand
            # Stip tailing u and comma
            ($value) = $value =~ /^&?(\S+?)[uU]?,?$/;

            if( defined $currentSystemElementRef )
            {
                if( $key =~ /Flags/ )
                {
                    if( $value =~ /OS_ISRF_CAT2|OS_ISRF_CATK/ )
                    {
                        # CAT 2 or Kernel ISR
                        $currentSystemElementRef->{Category} = 2;
                    }
                    elsif( $value =~ /OS_ISRF_CAT1/ )
                    {
                        $currentSystemElementRef->{Category} = 1;
                    }

                    if( 'true' eq $appendElementType and  $value =~ /OS_ISRF_(\w+)/ )
                    {
                        $currentSystemElementRef->{Comment} .= $1;
                    }
                    elsif( 'true' eq $appendElementType and $value =~ /OS_TF_EXTENDED/ )
                    {
                        $currentSystemElementRef->{Comment} .= 'ECC';
                    }
                }
                elsif( $key =~ /(?:ISR|Run|Queuing) priority/ )
                {
                    my $level = int $value;

                    if( 'Interrupt' eq $currentSystemElementRef->{Type} )
                    {
                        if( ( $mcuCore eq 'V850' ) or ( $mcuCore eq 'TMS570' ) or ( $mcuCore eq 'ARM' ) )
                        {
                            $level = 1000 - $level; # priorities for ISRs are inverted
                        }
                        else
                        {
                            $level += 1000;   # Ensure all ISRs have higher priority than all tasks
                        }
                    }

                    $currentSystemElementRef->{Priority} = $level;
                }
                elsif( $key =~ /Task entry/ )
                {
                    $currentSystemElementRef->{SymbolName} = $symbolPrefix . $value;
                }
                elsif( $key =~ /Interrupt entry/ )
                {
                    $currentSystemElementRef->{SymbolName} = $symbolPrefix . $value;
                }
                elsif( $key =~ /Max. activations/ )
                {
                    $currentSystemElementRef->{MaxActivations} = int $value + 1;
                }
                elsif( $key =~ /Application/ )
                {
                    my ($osApplication) = $value =~ /\[(\w+)\]/;
                    $currentSystemElementRef->{FunctionalGroup} = $osApplication;
                }
                elsif( $parseOsStackCfg )
                {
                    if( 'Task' eq $currentSystemElementRef->{Type} )
                    {
                        if( $key =~ /\&(\w+)\[(\d+)\],\s*\/\* Stack base \*\// )
                        {
                            $currentTaskOsStackRef = 'OsStack_' . $currentSystemElementRef->{Name};
                            $currentSystemElementRef->{OsStackRef} = $currentTaskOsStackRef;
                            $currentStackOsStartSymbolRef = $1;
                            $currentStackOffset = $2;
                            # print "Stack base $1 and offset $2 on $currentTask found\n" if $debug;
                        }
                        elsif( $key =~ /(\d+)U,\s*\/\* Stack size \*\// )
                        {
                            $currentStackSize = $1;

                            push @osDefineStackFirstPass, {
                                Name           => $currentTaskOsStackRef,
                                StartSymbolRef => $currentStackOsStartSymbolRef,
                                Offset         => $currentStackOffset,
                                Size           => $currentStackSize,
                                Core           => \$currentSystemElementRef->{Core},
                            };
                        }
                    }
                }
            }
            elsif( defined $currentOsApplicationRef  )
            {
                if( $key =~ /CPU core/ )
                {
                    my $core = int $value;
                    $currentOsApplicationRef->{Core} = $core;

                    $nOfCores = $core + 1 if $core + 1 > $nOfCores;
                }
            }
        }
    }
    close $fh;

    # Assign trace ids, first tasks then interrupts
    foreach my $systemElement ( values %{$systemElements{'Task'}}, values %{$systemElements{'Interrupt'}} )
    {
        if( defined $systemElement->{FunctionalGroup} )
        {
            my $osApplication = $systemElement->{FunctionalGroup};
            if( defined $osApplications{$osApplication}->{Core} )
            {
                $systemElement->{Core} = int $osApplications{$osApplication}->{Core};
            }
        }

        if( 'Task' eq $systemElement->{Type} )
        {
            $maxTaskId = $systemElement->{ID} if $systemElement->{ID} > $maxTaskId;
        }
        elsif( 'Interrupt' eq $systemElement->{Type} )
        {
            # Adjust ISR ID's
            $systemElement->{ID} += 1 + $maxTaskId;
            $maxIsrId = $systemElement->{ID} if $systemElement->{ID} > $maxIsrId;
        }
    }

    # OS stacks second pass
    foreach my $osStack ( @osDefineStackFirstPass )
    {
        my $core = ${$osStack->{Core}};
        delete $osStack->{Core};

        if( $core eq 'all' )
        {
            foreach my $coreId ( 0..($nOfCores-1) )
            {
                push @{$osDefineStacks[$coreId]}, $osStack;
            }
        }
        elsif( $nOfCores <= $core )
        {
            die "error: coreId $core must be smaller than the maximum coreId $nOfCores found in \$osConfigHeader";
        }
        else
        {
            push @{$osDefineStacks[$core]}, $osStack;
        }
    }

    foreach my $runnableParseModule ( @runnableParseModules )
    {
        if( -e $runnableParseModule )
        {
            my $currentTask;
            my $isTask = 0;
            my @symbolsPerTask;
            my $currentTaskRef;
            my $foundVfbEEStartMacro;
            my $searchForExecutionCounterVar;
            my $currentExecutionCounterSymbolGroupRef;
            my $currentExecutionCounterSymbolGroupEach1Ref;

            open my $RUN_MOD_FILE, '<', $runnableParseModule or die qq(Error: Unable to read "${runnableParseModule}"\n);

            while( my $currentLine = <$RUN_MOD_FILE> )
            {
                if( $currentLine =~ /^TASK\(\s*(\w+)\s*\)/ )
                {
                    $isTask = 1;
                    $currentTask = $1;
                    print qq(Debug: Found task "${currentTask}"\n) if $debug;
                    $currentTaskRef = $systemElements{'Task'}{$currentTask};

                    unless( defined $currentTaskRef )
                    {
                        warn qq(Warning: Found TASK(${currentTask}) in "${currentTask}" which has not been found while reading the OS configuration!\n);
                        $isTask = 0;
                        undef $currentTask;
                    }

                    undef @symbolsPerTask; # Clear on new task definition
                    undef $searchForExecutionCounterVar;
                    undef $currentExecutionCounterSymbolGroupEach1Ref;

                    if( exists $executionCountersPerTask{$currentTask} )
                    {
                        $searchForExecutionCounterVar = $executionCountersPerTask{$currentTask}{varName};

                        my @array_ref = ();
                        $currentExecutionCounterSymbolGroupEach1Ref = \@array_ref;
                    }
                }
                elsif( $isTask )
                {
                    # Extract Executable Entities (RunnableEntity or BswSchedulableEntity)
                    # Executable Entities are identified by either of the following two conditions
                    # 1. Comment "RunnableEntity"
                    # 2. The VFB Tracing Hooks for Runnable Entity and BSW Schedulable Entities Trace Events

                    if( $currentLine =~ /\/\*\s+RunnableEntity\s+(\w+)\s+\*\// )
                    {
                        undef $foundVfbEEStartMacro;

                        my $runnableName = $1;

                        print qq(Debug: Found Runnable "${runnableName}" in task "${currentTask}"\n) if $debug;

                        if( not grep { /^$symbolPrefix$runnableName$/ } @symbolsPerTask )
                        {
                            push @symbolsPerTask, $symbolPrefix.$runnableName;

                            if( defined $currentExecutionCounterSymbolGroupRef )
                            {
                                push @$currentExecutionCounterSymbolGroupRef, $symbolPrefix.$runnableName;
                            }
                            elsif( defined $currentExecutionCounterSymbolGroupEach1Ref )
                            {
                                push @$currentExecutionCounterSymbolGroupEach1Ref, $symbolPrefix.$runnableName;
                            }
                        }

                        # Only push to task if task exists and if the Runnable is not already present
                        if( $currentTaskRef and not grep { /^$runnableName$/ } @{$currentTaskRef->{'Runnables'}} )
                        {
                            # Create Runnable SystemElement under Task SystemElement
                            push @{$currentTaskRef->{'Runnables'}}, $runnableName;
                        }
                    }
                    elsif( ( $currentLine =~ /(Rte_(\w*)Runnable_\w+_Start)/ ) or ( $currentLine =~ /(SchM_(\w*)Schedulable_\w+_Start)/ ) ) # Use two RegEx's to ensure that signatures match
                    {
                        my $startMacro = $1;
                        my $client = $2; # Trace Client Name, currently unused but might become handy in the future

                        $foundVfbEEStartMacro = 1;
                    }
                    elsif( $foundVfbEEStartMacro )
                    {
                        chomp $currentLine;
                        $currentLine =~ s/\s+//s; # Remove whitespace, including end-of-line

                        if( $currentLine =~ /^.*?(\w+)\s*\(.*?\).*$/ )
                        {
                            my $runnableName = $1;

                            print qq(Debug: Found Runnable "${runnableName}" in task "${currentTask}"\n) if $debug;

                            if( not grep { /^$symbolPrefix$runnableName$/ } @symbolsPerTask )
                            {
                                push @symbolsPerTask, $symbolPrefix.$runnableName;

                                if( defined $currentExecutionCounterSymbolGroupRef )
                                {
                                    push @$currentExecutionCounterSymbolGroupRef, $symbolPrefix.$runnableName;
                                }
                                elsif( defined $currentExecutionCounterSymbolGroupEach1Ref )
                                {
                                    push @$currentExecutionCounterSymbolGroupEach1Ref, $symbolPrefix.$runnableName;
                                }
                            }

                            # Only push to task if task exists and if the Runnable is not already present
                            if( $currentTaskRef and not grep { /^$runnableName$/ } @{$currentTaskRef->{'Runnables'}} )
                            {
                                # Create Runnable SystemElement under Task SystemElement
                                push @{$currentTaskRef->{'Runnables'}}, $runnableName;
                            }
                        }

                        undef $foundVfbEEStartMacro;
                    }
                    elsif( $currentLine =~ /^\}/ )
                    {
                        if( 0 < scalar @symbolsPerTask )
                        {
                            my @array_ref = @symbolsPerTask;
                            $systemElements{'SymbolGroup'}{$currentTask . '_All_Runnables'} = {
                                'Name'               => $currentTask . '_All_Runnables',
                                'IsCode'             => 'true',
                                'MeasureDuration'    => 1000,
                                'FocusIntervalCount' => 16777216,
                                'Core'               => $systemElements{'Task'}{$currentTask}{'Core'},
                                'SymbolGroupElemRef' => \@array_ref
                            };
                        }


                        if( defined $currentExecutionCounterSymbolGroupEach1Ref and 0 < scalar @$currentExecutionCounterSymbolGroupEach1Ref )
                        {
                            $systemElements{'SymbolGroup'}{$currentTask . '_Each_1_Runnables'} = {
                                'Name'               => $currentTask . '_Each_1_Runnables',
                                'IsCode'             => 'true',
                                'MeasureDuration'    => 1000,
                                'FocusIntervalCount' => 16777216,
                                'Core'               => $systemElements{'Task'}{$currentTask}{'Core'},
                                'SymbolGroupElemRef' => $currentExecutionCounterSymbolGroupEach1Ref
                            };
                        }

                        undef $isTask;
                        undef $currentTaskRef;
                        undef $currentExecutionCounterSymbolGroupRef;
                    }
                    elsif( defined $searchForExecutionCounterVar )
                    {
                        if( $currentLine =~ /if\s*\(.*${searchForExecutionCounterVar}(?:\s*%\s*(\d+)[uU]?\s*\))?\s*==\s*(\d+)[uU]?/ )
                        {
                            my $modulo = defined $1 ? int $1 : 'undef';
                            my $offset = int $2;

                            my @array_ref = ();
                            $systemElements{'SymbolGroup'}{$currentTask . "_Each_${modulo}_Offset_${offset}"} = {
                                'Name'               => $currentTask . "_Each_${modulo}_Offset_${offset}_Runnables",
                                'IsCode'             => 'true',
                                'MeasureDuration'    => 1000,
                                'FocusIntervalCount' => 16777216,
                                'Core'               => $systemElements{'Task'}{$currentTask}{'Core'},
                                'SymbolGroupElemRef' => \@array_ref
                            };

                            $currentExecutionCounterSymbolGroupRef = \@array_ref;
                        }
                        elsif( $currentLine =~ /\(\s*\(\s*${searchForExecutionCounterVar}\s*\+\s*\d+[uU]?\s*\)\s*%\s*(\d+)[uU]?\s*\)\s*;/ )
                        {
                            my $modulo = int $1;

                            # Adjust "undef" in entries to "$modulo"
                            foreach my $key ( grep { /${currentTask}_Each_undef_/ } keys %{$systemElements{'SymbolGroup'}} )
                            {
                                $systemElements{'SymbolGroup'}{$key}{Name} =~ s/_Each_undef_/_Each_${modulo}_/;
                            }
                        }
                        elsif( $currentLine =~ /^\s+\}/ )
                        {
                            undef $currentExecutionCounterSymbolGroupRef;
                        }
                    }
                }
                elsif( $currentLine =~ /^STATIC\s+VAR\s*\((\w+).+\)\s*(Rte_ExecutionCounter_(\w+)).+$/ )
                {
                    my $type = $1;
                    my $varName = $2;
                    my $taskName = $3;

                    my %typeToMaxVal = (
                        uint8 => 255,
                        uint16 => 65535,
                        uint32 => 4294967295
                    );

                    my $maxVal = int $typeToMaxVal{$type};

                    print qq(Debug: Found var "${varName}" max value is "${maxVal}"\n) if $debug;

                    $executionCountersPerTask{$taskName} = {
                        varName => $varName,
                        maxVal => $maxVal
                    };
                }
            }

            close $RUN_MOD_FILE;
        }
        else
        {
            warn qq(Warning: Runnable parse module "$runnableParseModule" not found\n);
        }
    }

    my ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst) = localtime time;
    my $dateAndTime = sprintf "%02d.%02d.%04d at %02d:%02d:%02d", $mday, $mon + 1, $year + 1900, $hour, $min, $sec;

    $systemElements{'OS'}{'Info'} = {   'GenDate'        => $dateAndTime,
                                        'GenSource'      => 'Os_user.h and Os_config.h',
                                        'NofCores'       => $nOfCores,
                                        'CpuFreq'        => 0,
                                        'defineStackRef' => \@osDefineStacks, };

    return;
}

sub OsGetValue($$$)
{
    my $ref = shift;
    my $key = shift;
    my $name = shift;
    return $ref->{$key}{$name} if exists $ref->{$key}{$name};

    return 0;
}

sub OsGetSysElementReference($)
{
    my $name = shift;
    return $systemElements{$name} if exists $systemElements{$name};

    return 0;
}

sub OsGetIsrWrapper()
{
    return $isrShims;
}

sub OsPerformInstrumentation()
{

}

1;

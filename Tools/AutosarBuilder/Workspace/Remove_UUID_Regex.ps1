$scriptPath = split-path -parent $MyInvocation.MyCommand.Definition
$source = Join-Path $scriptPath "\..\..\..\Architectures\Application\Description\ECUextract.arxml"
$dest = Join-Path $scriptPath "\..\..\..\Architectures\Application\Description\ECUextract.arxml"
(get-content $source) | %{$_ -replace ' UUID=.*','>'} | set-content $dest
@rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem r
@rem
@rem File:          T1_projGen.bat
@rem
@rem Description:   Batch file to run T1_projGen.pl
@rem
@rem $Author: Razvan Badiu (razvan.badiu) $
@rem
@rem $Revision: 1.2 $
@rem
@rem Copyright:     GLIWA embedded systems GmbH & Co. KG
@rem                Weilheim i.OB.
@rem                All rights reserved
@rem
@rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem rem r

@echo off
pushd %~dp0..

.\T1_Perl\T1_projGen.exe -UserCfg=T1_UserCfg.inv -Cfg=T1_Cfg_CAN_FD.inv -OsPm=T1_TresosAutoCoreOS.pm -OsCfg=T1_OsCfg.inv
rem -I tells Perl where to look for modules
REM perl -I T1_TresosAutoCoreOS -I T1_Perl T1_Perl\T1_projGen.pl -UserCfg=T1_UserCfg.inv -Cfg=T1_Cfg_CAN_FD.inv -OsPm=T1_TresosAutoCoreOS.pm -OsCfg=T1_OsCfg.inv
popd
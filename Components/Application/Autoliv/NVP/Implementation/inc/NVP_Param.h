/*************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

DUPLICATION or DISCLOSURE PROHIBITED without prior written consent

**************************************************************************

This file defines the information (interfaces, definitions and data) provided
by the component NVP_Param, part of the package <Package name>.
These are globally visible.  
This file is intended to be included in a package header file; 
all components should include the package header file instead of this file.

Current revision: $Revision: 1.1.3.3 $
Checked in:       $Date: 2022/11/25 08:59:32CET $

*************************************************************************/

/* [COVERS: DSG_NVP_00010] */

#ifdef NVP_PARAM_H
#else
#define NVP_PARAM_H 1

#include "Std_Types.h"

#include "Nvp_Generated_NvmDefault.h"

/*************************************************************************
Declaration of constants
*************************************************************************/

/*************************************************************************
Declaration of types
*************************************************************************/

typedef uint8 u8NVPIntegrityStatusType; /* Integrity status of Non Volatile Parameters */

/*************************************************************************
Declaration of macros
*************************************************************************/

/*************************************************************************
Declaration of constant data
*************************************************************************/

/*************************************************************************
Declaration of functions
*************************************************************************/

#endif   /* NVP_PARAM_H */


/*************************************************************************
Evolution of the component

Created by :

$Log: NVP_Param.h  $
Revision 1.1.3.3 2022/11/25 08:59:32CET David Puscasu (david.puscasu) 
Update NVP generated files
Revision 1.1 2021/08/26 09:16:59EEST Pierre-Olivier Pilot (pierre-olivier.pilot) 
Initial revision
Member added to project e:/MKSProjects/SBE/Innovation/ECS/Phase_01/Components/Application/Autoliv/NVP/Implementation/inc/project.pj
Revision 1.1 2020/12/08 13:59:57CET Gaetan Lievre (gaetan.lievre) 
Initial revision
Member added to project e:/MKSProjects/AEM/Frame_Platforms/S32K144/Phase_01/View_Development/Components/Application/Autoliv/NVP/Implementation/inc/project.pj
Revision 1.2 2019/10/09 16:15:12CEST Gaetan Lievre (gaetan.lievre) 
Update for Nvm
Revision 1.1 2019/06/25 16:17:58CEST Nicolas Bianchi (nicolas.bianchi) 
Initial revision
Member added to project e:/MKSProjects/DEV_KIT/S32K/Phase_01/Components/Application/NVP/Implementation/inc/project.pj
Revision 1.1.1.3 2017/03/27 15:22:38CEST Charlene Dibourg (charlene.dibourg) 
Remove NVP functions
Revision 1.1.1.2 2017/02/24 09:50:08CET Michael Pastor (michael.pastor) 
MAJ PP4G R3.1E from Explo since 15/02/2017
Revision 1.1.1.1 2017/02/15 17:19:54CET Michael Pastor (michael.pastor) 
Check In modified already present files
Revision 1.1 2016/10/05 18:27:15CEST Maxime Bourdon (maxime.bourdon) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/Extended/PP4G_R31E/Components/Application/NVP/Implementation/inc/project.pj
Revision 1.1 2016/10/05 18:27:15CEST Maxime Bourdon (maxime.bourdon) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/PP4G_Extended/Components/Application/NVP/Implementation/inc/project.pj
Revision 1.1 2016/10/05 10:13:15CEST Michael Pastor (michael.pastor) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_02/Core/Components/Application/NVP/Implementation/inc/project.pj
Revision 1.1 2016/09/20 09:48:08CEST Michael Pastor (michael.pastor) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/Automation/PropagationProject_R3.0M/PP4G/Platform_Mainstream_Phase_01/Core/Components/Application/NVP/Implementation/inc/inc.pj
Revision 1.6 2016/09/05 10:38:47CEST Sabine Flechelle (sabine.flechelle) 
PP4G R3.0M 444498 - Remove P R Q A
Revision 1.5 2016/09/05 10:27:45CEST Sabine Flechelle (sabine.flechelle) 
PP4G R3.0M 444498 - Remove P R Q A
Replace by P R Q A in comments
Revision 1.4 2016/09/05 10:02:15CEST Sabine Flechelle (sabine.flechelle) 
PP4G R3.0M 444498 - Remove all P R Q As
P R Q A is replaced by QAC_WARNING
Revision 1.3 2016/06/07 12:52:39CEST Audrey Vache (avache) 
Memory mapping implementation
Revision 1.2 2015/11/03 10:22:03CET Maxime Bourdon (mbourdon) 
RTE files inclusion clean up
Revision 1.1 2015/10/13 15:52:58CEST Cedric Sauvage (csauvage) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/AUTOSAR/RTE_Benchmark/ETAS/Development_View/Source/Application/_NVP/inc/project.pj
Revision 1.7 2014/05/05 16:36:18CEST Cedric Sauvage (csauvage) 
Integration of E2P stack
Revision 1.6 2014/04/24 18:18:07CEST Francois.Gilbert (fgilbert) 
CIL update parameters
Revision 1.5 2014/04/24 11:24:20CEST Francois.Gilbert (fgilbert) 
New parameter of CIL : Precision for VDA conversion
QAC_WARNING deviations coding
Revision 1.4 2014/04/23 13:41:21CEST Francois.Gilbert (fgilbert) 
VDA parameters
CIL CAN gains and offset
Revision 1.3 2014/04/23 11:34:01CEST Francois.Gilbert (fgilbert) 
New EOL parameters : Array that says if functions are managed by EOL
Revision 1.2 2014/04/14 16:57:04CEST Sabine Flechelle (sflechelle) 
Issue_143106 - EOL and BFD needs
- transit from 17 to 21 cycles
- add EOL nvp needs
Revision 1.1 2014/04/10 19:38:13CEST Herve Egnifi (hegnifi) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_01/Development_View/Source/Application/_NVP/inc/project.pj

*************************************************************************/

/* end of file */

/*===============================================================================*/
/*                                                                               */
/*                               BOOT Layers                                     */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/*                               PROG_VAG layer                                  */
/*                                                                               */
/*===============================================================================*/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file PROG_VAG_Cbk.c                  */
/*%%  |                             |  %%  \brief PROG layer source plugin file  */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 0.13.0 BL3 */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&    &&&&&             |  %%                                        */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
/*%%  |_____________________________|  %%                                        */
/*%%                                   %%                                        */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*===============================================================================*/
/* Copyright 2021 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*===============================================================================*/

/*=============================== FILE INCLUSION ================================*/
/*                                                                               */
#include "EB_Prj.h"
#include "PROG_Hsm.h"
#include "PROG_HsmPROG.h"
#include "PROG_VAG_Cbk.h"

[!AUTOSPACING!]
/*=============================== IMPLEMENTATION ================================*/
/*                                                                               */

[!IF "(as:modconf('Prog')/VAG/Downgrade_Protection = 'true')"!]
/** \brief Get minimum RFS version stored in secured area (RfsVMinimum)
 **
 ** Callback is called: 1. during the check memory of the pseudo flash driver while the verification
 **                        of the validation criteria is processing
 **                     2. during the execution of the check programming dependencies request
 **
 ** \param[in]  ubLogicalBlock index of the logical block in Prog plugin configuration
 ** \param[out] pubRfsVMinimum pointer to the RFS version minimum (ASCII value range[0x30..0x39])
 **
 ** Callback shall implement: Retrieve the minimum RFS version of the logical block
 **
 ** \return eProgStatus : Status of retrieving the value
 ** \return PROG_E_OK        - The get has been successfully performed
 ** \return PROG_E_NOT_OK    - The get has failed (for any kind of error)
 **
 **/
tProgStatus PROG_CustomGetRfsVMinimum(u8 ubLogicalBlock, u8* pubRfsVMinimum)
{
    OSC_PARAM_UNUSED(ubLogicalBlock);
    OSC_PARAM_UNUSED(pubRfsVMinimum);

    return PROG_E_OK;
}

/** \brief Get current RFS version stored in secured area (RfsVCurrent)
 **
 ** Callback is called: 1. during the erase memory of a logical block
 **                     2. during the execution of the check programming dependencies request
 **
 ** \param[in]  ubLogicalBlock index of the logical block in Prog plugin configuration
 ** \param[out] pubRfsVCurrent pointer to the RFS version current (ASCII value range[0x30..0x39])
 **
 ** Callback shall implement: Retrieve the current RFS version of the logical block
 **
 ** \return eProgStatus : Status of retrieving the value
 ** \return PROG_E_OK                 - The get has been successfully performed
 ** \return PROG_E_RFS_DRIVER_FAIL    - The get has failed (for any kind of error)
 **
 **/
tProgStatus PROG_CustomGetRfsVCurrent(u8 ubLogicalBlock, u8* pubRfsVCurrent)
{
    OSC_PARAM_UNUSED(ubLogicalBlock);
    OSC_PARAM_UNUSED(pubRfsVCurrent);

    return PROG_E_OK;
}

/** \brief Get new RFS version from the logical block (contained in admin-table )
 **
 ** Callback is called: 1. during the check memory of a logical block
 **                     2. during the execution of the check programming dependencies request
 **
 ** \param[in]  ubLogicalBlock index of the logical block in Prog plugin configuration
 ** \param[out] pubRfsVLB pointer to the new RFS version of the logical block (admin-table value) (ASCII value range[0x30..0x39])
 **
 ** Callback shall implement: Retrieve the downloded RfsV of the logical block from admin-table
 **
 ** \return eProgStatus : Status of retrieving the value
 ** \return PROG_E_OK                 - The get has been successfully performed
 ** \return PROG_E_RFS_DRIVER_FAIL    - The get has failed (for any kind of error)
 **
 **/
tProgStatus PROG_CustomGetRfsVLB(u8 ubLogicalBlock, u8* pubRfsVLB)
{
    OSC_PARAM_UNUSED(ubLogicalBlock);
    OSC_PARAM_UNUSED(pubRfsVLB);

    return PROG_E_OK;
}

/** \brief Update the current RFS version associated to a logical block in Nvm with the new value from admin table after a successful
 **        download of the logical block (RfsVCurrent = RfsvLB)
 **        This function can also be called for the implementation of the routine control with RI:0x065E
 **
 ** Callback is called: during the check memory of the logical block precisely after a successful verification of both the signature
 **                     and the comparison of RfsV numbers
 **
 ** \param[in] ubLogicalBlock index of the logical block in Prog plugin configuration
 ** \param[in] pubRfsVCurrent pointer to the new current RfsV (ASCII value range[0x30..0x39])
 **
 ** Callback shall implement: Stores the new current RfsV value into a Non-voltile memory
 **
 ** \return eProgStatus : Status of the update
 ** \return PROG_E_OK                 - Update has been successfully performed
 ** \return PROG_E_RFS_DRIVER_FAIL    - Update failed (for any kind of error)
 **
 **/
tProgStatus PROG_CustomStoreRfsVCurrent(u8 ubLogicalBlock, const u8* pubRfsVCurrent)
{
    OSC_PARAM_UNUSED(ubLogicalBlock);
    OSC_PARAM_UNUSED(pubRfsVCurrent);

    return PROG_E_OK;
}
[!ENDIF!]

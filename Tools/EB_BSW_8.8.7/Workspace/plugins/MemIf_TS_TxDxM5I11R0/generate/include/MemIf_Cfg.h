/**
 * \file
 *
 * \brief AUTOSAR MemIf
 *
 * This file contains the implementation of the AUTOSAR
 * module MemIf.
 *
 * \version 5.11.15
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef MEMIF_CFG_H
#define MEMIF_CFG_H

[!VAR "NumDevices"="num:i(MemIfGeneral/MemIfNumberOfDevices)"!][!//
#if (defined MEMIF_MEMACC_USAGE)
#error MEMIF_MEMACC_USAGE is already defined
#endif
/** \brief Macro switch for MemAcc usage */
#define MEMIF_MEMACC_USAGE                [!//
[!IF "MemIfGeneral/MemIfMemAccUsage = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!//
[!/*
 Check if the Ea and Fee is able to allow multiple instanciations
 if there are multiple configurations for these modules.
*/!][!//
[!MACRO "HEADER_NAME", "ModName" = "'Ea'"!][!/*
  */!][!VAR "Infix"!][!/*
    */!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!/*
      */!][!"CommonPublishedInformation/VendorApiInfix"!][!/*
    */!][!ENDIF!][!/*
  */!][!ENDVAR!][!/*
  */!][!"$ModName"!][!/*
    */!][!IF "$Infix != '' "!][!/*
      */!]_[!"CommonPublishedInformation/VendorId"!]_[!"$Infix"!][!/*
    */!][!ENDIF!][!/*
  */!].h[!//
[!ENDMACRO!][!//
[!//
[!//
[!//
[!MACRO "EXTEND_NAME", "ModName" = "'Ea'"!][!/*
  */!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!/*
    */!][!VAR "Name" = "concat($ModName,'_',CommonPublishedInformation/VendorId,'_',CommonPublishedInformation/VendorApiInfix)"!][!/*
  */!][!ELSE!][!/*
    */!][!VAR "Name" = "$ModName"!][!/*
  */!][!ENDIF!][!//
[!ENDMACRO!][!//
[!//
[!//
[!//
[!/* *** first build prefix-list *** */!][!//
[!//
[!VAR "Prefixes"="''"!][!//
[!IF "MemIfGeneral/MemIfMemAccUsage = 'false'"!][!/*
  */!][!VAR "OldDeviceIndex" ="-1"!][!/*
  */!][!VAR "NumberOfDevices"="0"!][!/*
  */!][!VAR "DEVICE_IDs" = "''"!][!/*
  */!][!LOOP "as:modconf('Eep')"!][!/*
    */!][!VAR "NumberOfDevices"="$NumberOfDevices+1"!][!/*
    */!][!IF "contains($DEVICE_IDs, concat(EepGeneral/EepDriverIndex,'_') )"!][!/*
      */!][!ERROR "There may not be two Eep memory drivers with the same device ID. Please check EepGeneral/EepDriverIndex"!][!/*
      */!][!BREAK!][!/*
    */!][!ENDIF!][!/*
    */!][!VAR "DEVICE_IDs" = "concat($DEVICE_IDs,EepGeneral/EepDriverIndex,'_')"!][!/*
  */!][!ENDLOOP!][!//
[!//
[!/*
  */!][!LOOP "as:modconf('Fls')"!][!/*
    */!][!VAR "NumberOfDevices"="$NumberOfDevices + 1"!][!/*
    */!][!IF "contains($DEVICE_IDs, concat(FlsGeneral/FlsDriverIndex,'_') )"!][!/*
      */!][!ERROR "There may not be two Fls memory drivers with the same device ID. Please check FlsGeneral/FlsDriverIndex"!][!/*
      */!][!BREAK!][!/*
    */!][!ENDIF!][!/*
    */!][!VAR "DEVICE_IDs" = "concat($DEVICE_IDs,FlsGeneral/FlsDriverIndex,'_')"!][!/*
  */!][!ENDLOOP!][!//
[!ELSE!][!/* MemAcc used
  */!][!VAR "OldMemAccAddressAreaId" ="-1"!][!/*
  */!][!VAR "NumberOfAreas"="0"!][!/*
  */!][!VAR "AREA_IDs" = "''"!][!/*
  */!][!LOOP "as:modconf('MemAcc')/MemAccAddressAreaConfiguration/*"!][!/*
    */!][!VAR "NumberOfAreas"="$NumberOfAreas + 1"!][!/*
    */!][!IF "contains($AREA_IDs, concat(MemAccAddressAreaId,'_') )"!][!/*
      */!][!ERROR "There may not be two memory areas with the same area ID. Please check MemAcc/MemAccAddressAreaConfiguration"!][!/*
      */!][!BREAK!][!/*
    */!][!ENDIF!][!/*
    */!][!VAR "AREA_IDs" = "concat($AREA_IDs,MemAccAddressAreaId,'_')"!][!/*
  */!][!ENDLOOP!][!//
[!ENDIF!]
[!//
[!//
[!/*
 The relation
 MemIfGeneral/MemIfNumberOfDevices = count(as:modconf('Ea')) + count(as:modconf('Fee'))
 is also enforced by the xdm file.
*/!][!//
[!//
[!/*
*/!][!IF "num:i($NumDevices) != (count(as:modconf('Ea')) + count(as:modconf('Fee')))"!][!/*
  */!][!ERROR "Number of devices must match the configured Ea and Fee devices"!][!/*
*/!][!ENDIF!][!//
[!//
[!//
[!IF "MemIfGeneral/MemIfMemAccUsage = 'false'"!][!/*
  */!][!IF "$NumberOfDevices > 1"!][!/*
    */!][!VAR "Driver"="''"!][!/*
    */!][!VAR "ListDrivers"="''"!][!//
[!/* *** If more than 1 device is present perform validity checks *** */!][!//
    /* !LINKSTO EB_MEMIF_018_3,2  */
    /* !LINKSTO EB_MEMIF_018_4,2  */[!/*
    */!][!LOOP "as:modconf('Ea')"!][!/*
      */!][!VAR "Driver" = "EaBlockConfiguration/*[1]/EaDeviceIndex"!][!/*
[!/* *** All the blocks of Ea must link the same driver *** */!][!/*
      */!][!LOOP "EaBlockConfiguration/*"!][!/*
        */!][!IF "node:refvalid( ./EaDeviceIndex )"!][!/*
          */!][!IF "$Driver != ./EaDeviceIndex "!][!/*
            */!][!ERROR!][!/*
              */!]A hardware abstraction module may not have blocks in two EEP driver modules. References unequal [!"$Driver"!] != [!"(./EaDeviceIndex)"!][!/*
            */!][!ENDERROR!][!/*
            */!][!BREAK!][!/*
          */!][!ENDIF!][!/*
        */!][!ELSE!][!/*
            */!][!ERROR!][!/*
              */!]Field EaDeviceIndex must hold reference to the device this block is stored in.[!/*
            */!][!ENDERROR!][!/*
        */!][!ENDIF!][!/*
      */!][!ENDLOOP!][!/*
      */!][!IF "contains($ListDrivers,$Driver)"!][!/*
        */!][!ERROR!][!/*
          */!]MEMIF cannot map two hardware abstraction modules to the same driver! [!"$Driver"!] referenced more than once![!/*
        */!][!ENDERROR!][!/*
       */!][!BREAK!][!/*
      */!][!ENDIF!][!/*
      */!][!VAR "ListDrivers" = "concat($ListDrivers,'_',$Driver)"!][!/*
    */!][!ENDLOOP!][!/*

    */!][!LOOP "as:modconf('Fee')"!][!/*
[!/* *** All the blocks of Fee must link the same driver *** */!][!/*
      */!][!VAR "Driver" = "FeeBlockConfiguration/*[1]/FeeDeviceIndex"!][!/*
      */!][!LOOP "FeeBlockConfiguration/*"!][!/*
        */!][!IF "node:refvalid( ./FeeDeviceIndex )"!][!/*
          */!][!IF "$Driver != ./FeeDeviceIndex "!][!/*
            */!][!ERROR!][!/*
              */!]A hardware abstraction module may not have blocks in two FLS driver modules. References unequal [!"$Driver"!] != [!"(./FeeDeviceIndex)"!][!/*
            */!][!ENDERROR!][!/*
            */!][!BREAK!][!/*
          */!][!ENDIF!][!/*
        */!][!ELSE!][!/*
          */!][!ERROR!][!/*
            */!]Field FeeDeviceIndex must hold reference to the device this block is stored in.[!/*
          */!][!ENDERROR!][!/*
        */!][!ENDIF!][!/*
      */!][!ENDLOOP!][!/*
      */!][!IF "contains($ListDrivers,$Driver)"!][!/*
        */!][!ERROR!][!/*
          */!]MEMIF cannot map two hardware abstraction modules to the same driver! [!"$Driver"!] referenced more than once![!/*
        */!][!ENDERROR!][!/*
        */!][!BREAK!][!/*
      */!][!ENDIF!][!/*
      */!][!VAR "ListDrivers" = "concat($ListDrivers,'_',$Driver)"!][!/*
    */!][!ENDLOOP!][!/*
  */!][!ENDIF!][!/*
*/!][!ELSE!][!/*
  */!][!IF "$NumberOfAreas > 1"!][!/*
    */!][!VAR "MemoryArea"="''"!][!/*
    */!][!VAR "ListAreas"="''"!][!//
[!/* *** If more than 1 area is present perform validity checks *** */!][!//
    /* !LINKSTO EB_MEMIF_018_3_MemAcc,1  */
    /* !LINKSTO EB_MEMIF_018_4_MemAcc,1  */[!/*
      */!][!LOOP "as:modconf('Ea')"!][!/*
        */!][!VAR "MemoryArea" = "EaBlockConfiguration/*[1]/EaMemAccAddressArea"!][!//
[!/* *** All the blocks of Ea must link the same memory area *** */!][!/*
        */!][!LOOP "EaBlockConfiguration/*"!][!/*
          */!][!IF "node:refvalid( ./EaMemAccAddressArea )"!][!/*
            */!][!IF "$MemoryArea != ./EaMemAccAddressArea "!][!/*
              */!][!ERROR!][!/*
                */!]A hardware abstraction module may not have blocks in two memory areas. References unequal [!"$MemoryArea"!] != [!"(./EaMemAccAddressArea)"!][!/*
              */!][!ENDERROR!][!/*
              */!][!BREAK!][!/*
            */!][!ENDIF!][!/*
          */!][!ELSE!][!/*
              */!][!ERROR!][!/*
                */!]Field EaMemAccAddressArea must hold reference to the memory area this block is stored in.[!/*
              */!][!ENDERROR!][!/*
          */!][!ENDIF!][!/*
        */!][!ENDLOOP!][!/*
        */!][!IF "contains($ListAreas,$MemoryArea)"!][!/*
          */!][!ERROR!][!/*
            */!]MEMIF cannot map two hardware abstraction modules to the same memory area! [!"$MemoryArea"!] referenced more than once![!/*
          */!][!ENDERROR!][!/*
         */!][!BREAK!][!/*
        */!][!ENDIF!][!/*
        */!][!VAR "ListAreas" = "concat($ListAreas,'_',$MemoryArea)"!][!/*
      */!][!ENDLOOP!][!/*

      */!][!LOOP "as:modconf('Fee')"!][!/*
        */!][!VAR "MemoryArea" = "FeeBlockConfiguration/*[1]/FeeMemAccAddressArea"!][!//
[!/* *** All the blocks of Fee must link the same memory area *** */!][!/*
        */!][!LOOP "FeeBlockConfiguration/*"!][!/*
          */!][!IF "node:refvalid( ./FeeMemAccAddressArea )"!][!/*
            */!][!IF "$MemoryArea != ./FeeMemAccAddressArea "!][!/*
              */!][!ERROR!][!/*
                */!]A hardware abstraction module may not have blocks in two memory areas. References unequal [!"$MemoryArea"!] != [!"(./FeeMemAccAddressArea)"!][!/*
              */!][!ENDERROR!][!/*
              */!][!BREAK!][!/*
            */!][!ENDIF!][!/*
          */!][!ELSE!][!/*
              */!][!ERROR!][!/*
                */!]Field FeeMemAccAddressArea must hold reference to the memory area this block is stored in.[!/*
              */!][!ENDERROR!][!/*
          */!][!ENDIF!][!/*
        */!][!ENDLOOP!][!/*
        */!][!IF "contains($ListAreas,$MemoryArea)"!][!/*
          */!][!ERROR!][!/*
            */!]MEMIF cannot map two hardware abstraction modules to the same memory area! [!"$MemoryArea"!] referenced more than once![!/*
          */!][!ENDERROR!][!/*
         */!][!BREAK!][!/*
        */!][!ENDIF!][!/*
        */!][!VAR "ListAreas" = "concat($ListAreas,'_',$MemoryArea)"!][!/*
      */!][!ENDLOOP!][!/*
  */!][!ENDIF!][!//
[!ENDIF!][!//
[!//
[!IF "MemIfGeneral/MemIfMemAccUsage = 'false'"!]
[!//
[!//
[!//
[!/* Sort extended names ( abstraction name + vendor API infix) according to the ID of referenced memory area */!][!//
[!//
[!//
[!/* Search sequentially in the Eep and then in Fls for the lowest index
  "Name" variable is overwritten in the loop if a new smaller Id is found */!][!//
[!//
[!/* Gaps for missing indexes is filled with "_" marker */!][!//
[!VAR "Name"="''"!][!//
[!//
[!//
[!FOR "k" = "1" TO "$NumberOfDevices"!][!/*
  */!][!VAR "NewDeviceIndex" = "65536"!][!/*
  */!][!VAR "Infix"= "''"!][!/*
  */!][!LOOP "as:modconf('Eep')"!][!/*
    */!][!IF "($NewDeviceIndex > EepGeneral/EepDriverIndex) and ( $OldDeviceIndex < EepGeneral/EepDriverIndex )"!][!/*
      */!][!VAR "NewDeviceIndex" = "EepGeneral/EepDriverIndex"!][!/*
      */!][!VAR "Name"="''"!][!/*
      */!][!LOOP "as:modconf('Ea')"!][!/*
        */!][!IF "$NewDeviceIndex = node:value(node:ref((.)/EaBlockConfiguration/*/EaDeviceIndex)/EepDriverIndex)"!][!/*
          */!][!CALL "EXTEND_NAME", "ModName" = "'Ea'"!][!/*
          */!][!BREAK!][!/*
        */!][!ENDIF!][!/*
      */!][!ENDLOOP!][!/*
    */!][!ENDIF!][!/*
  */!][!ENDLOOP!][!/*
  */!][!LOOP "as:modconf('Fls')"!][!/*
    */!][!IF "($NewDeviceIndex > FlsGeneral/FlsDriverIndex) and ( $OldDeviceIndex < FlsGeneral/FlsDriverIndex )"!][!/*
      */!][!VAR "NewDeviceIndex" = "FlsGeneral/FlsDriverIndex"!][!/*
      */!][!VAR "Name"="''"!][!/*
      */!][!LOOP "as:modconf('Fee')"!][!/*
        */!][!IF "$NewDeviceIndex = node:value(node:ref((.)/FeeBlockConfiguration/*/FeeDeviceIndex)/FlsDriverIndex)"!][!/*
          */!][!CALL "EXTEND_NAME", "ModName" = "'Fee'"!][!/*
          */!][!BREAK!][!/*
        */!][!ENDIF!][!/*
      */!][!ENDLOOP!][!/*
    */!][!ENDIF!][!/*
  */!][!ENDLOOP!][!//
[!/* *** Fill missing indexes with null pointer so NVM and driver indexes match *** */!][!/*
  */!][!FOR "z" = "$OldDeviceIndex + 2" TO "$NewDeviceIndex"!][!/*
    */!][!VAR "Prefixes" = "concat($Prefixes,';&',"",'_')"!][!/*
  */!][!ENDFOR!][!/*
  */!][!VAR "Prefixes" = "concat($Prefixes,';&',$Name,'_')"!][!/*
  */!][!VAR "OldDeviceIndex" = "$NewDeviceIndex"!][!/*
*/!][!ENDFOR!][!//
[!VAR "Prefixes" = "substring-after($Prefixes, ';')"!][!//
[!ELSE!][!//
[!//
[!//
[!//
[!/* Sort extended names ( abstraction name + vendor API infix) according to the ID of referenced memory area */!][!//
[!//
[!//
[!/* Search sequentially in the MemAcc for the lowest index
   "Name" variable is overwritten in the loop if a new smaller Id is found */!][!//
[!//
[!/* Gaps for missing indexes is filled with "_" marker */!][!//
[!VAR "Name"="''"!][!//
[!//
[!//
[!FOR "k" = "1" TO "$NumberOfAreas"!][!/*
  */!][!VAR "NewMemAccAddressAreaId" = "65536"!][!/*
  */!][!VAR "Infix"= "''"!][!/*
  */!][!LOOP "as:modconf('MemAcc')/MemAccAddressAreaConfiguration/*"!][!/*
    */!][!IF "($NewMemAccAddressAreaId > MemAccAddressAreaId) and ($OldMemAccAddressAreaId < MemAccAddressAreaId )"!][!/*
      */!][!VAR "NewMemAccAddressAreaId" = "MemAccAddressAreaId"!][!/*
      */!][!VAR "Name"="''"!][!/*
      */!][!LOOP "as:modconf('Ea')"!][!/*
        */!][!IF "$NewMemAccAddressAreaId = node:value(node:ref((.)/EaBlockConfiguration/*/EaMemAccAddressArea)/MemAccAddressAreaId)"!][!/*
          */!][!CALL "EXTEND_NAME", "ModName" = "'Ea'"!][!/*
          */!][!BREAK!][!/*
        */!][!ENDIF!][!/*
      */!][!ENDLOOP!][!/*
      */!][!LOOP "as:modconf('Fee')"!][!/*
        */!][!IF "$NewMemAccAddressAreaId = node:value(node:ref((.)/FeeBlockConfiguration/*/FeeMemAccAddressArea)/MemAccAddressAreaId)"!][!/*
          */!][!CALL "EXTEND_NAME", "ModName" = "'Fee'"!][!/*
          */!][!BREAK!][!/*
        */!][!ENDIF!][!/*
      */!][!ENDLOOP!][!/*
    */!][!ENDIF!][!/*
  */!][!ENDLOOP!][!//
[!/* *** Fill missing indexes with null pointer so NVM and driver indexes match *** */!][!/*
  */!][!FOR "z" = "$OldMemAccAddressAreaId + 2" TO "$NewMemAccAddressAreaId"!][!/*
    */!][!VAR "Prefixes" = "concat($Prefixes,';&',"",'_')"!][!/*
  */!][!ENDFOR!][!/*
  */!][!VAR "Prefixes" = "concat($Prefixes,';&',$Name,'_')"!][!/*
  */!][!VAR "OldMemAccAddressAreaId" = "$NewMemAccAddressAreaId"!][!/*
*/!][!ENDFOR!][!//
[!VAR "Prefixes" = "substring-after($Prefixes, ';')"!][!//
[!ENDIF!][!//
/*==================[includes]==============================================*/

[!//
/* !LINKSTO MemIf037,1 */
#include <Std_Types.h>                            /* AUTOSAR standard types     */
#include <TSAutosar.h>                            /* EB specific standard types */

/* include lower layer headers */
[!LOOP "as:modconf('Ea')"!][!//
#include <[!CALL "HEADER_NAME", "ModName" = "'Ea'"!]>
[!ENDLOOP!][!//
[!//
[!LOOP "as:modconf('Fee')"!][!//
#include <[!CALL "HEADER_NAME", "ModName" = "'Fee'"!]>
[!ENDLOOP!][!//

/*==================[macros]================================================*/
#if (defined MEMIF_DEV_ERROR_DETECT)
#error MEMIF_DEV_ERROR_DETECT is already defined
#endif /* if (defined MEMIF_DEV_ERROR_DETECT) */
/** \brief En-/disable development error tracer checks */
#define MEMIF_DEV_ERROR_DETECT   [!//
[!IF "MemIfGeneral/MemIfDevErrorDetect = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]


#if (defined MEMIF_MAXIMUM_NUMBER_OF_DEVICES)
#error MEMIF_MAXIMUM_NUMBER_OF_DEVICES is already defined
#endif /* if (defined MEMIF_MAXIMUM_NUMBER_OF_DEVICES) */
/** \brief Maximum number of the underlying memory abstraction modules
 **
 ** Largest Driver Index or 1 if only one abstraction module is present */
[!IF "$NumDevices > 1"!][!//
[!IF "MemIfGeneral/MemIfMemAccUsage = 'false'"!]
#define MEMIF_MAXIMUM_NUMBER_OF_DEVICES  [!"num:i($OldDeviceIndex+1)"!]U
[!ELSE!]
#define MEMIF_MAXIMUM_NUMBER_OF_DEVICES  [!"num:i($OldMemAccAddressAreaId+1)"!]U
[!ENDIF!]
[!ELSE!][!//
#define MEMIF_MAXIMUM_NUMBER_OF_DEVICES 1U
[!ENDIF!][!//
#if (defined MEMIF_VERSION_INFO_API)
#error MEMIF_VERSION_INFO_API is already defined
#endif /* if (defined MEMIF_VERSION_INFO_API) */
/** \brief En-/disable API version information */
#define MEMIF_VERSION_INFO_API   [!//
[!IF "MemIfGeneral/MemIfVersionInfoApi = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

/* !LINKSTO MemIf019,1 */
[!IF "$NumDevices = 1"!][!/*
[!/* *** determine device prefix *** */!][!/*
  */!][!IF "count(as:modconf('Ea')) = 1"!][!/*
    */!][!VAR "Prefix"!]Ea_[!ENDVAR!][!/*
  */!][!ELSE!][!/*
    */!][!VAR "Prefix"!]Fee_[!ENDVAR!][!/*
  */!][!ENDIF!][!//
[!//

/*
 * Since only one underlying device is configured, the parameter DeviceIndex is not used therefore
 * it is cast to void.
 * Direct cast to void is done in MemIf to avoid compilation errors in case of static code checking
 * enabled (EB_STATIC_CHECK is defined).
 */

/* Macro mappings of driver API calls */

#if (defined MemIf_Read)
#error MemIf_Read is already defined
#endif /* if (defined MemIf_Read) */
#define MemIf_Read(DeviceIndex, BlockNumber, BlockOffset, DataBufferPtr, Length) \
  (((void) (DeviceIndex)),[!"$Prefix"!]Read(BlockNumber, BlockOffset, DataBufferPtr, Length))

#if (defined MemIf_Write)
#error MemIf_Write is already defined
#endif /* if (defined MemIf_Write) */
#define MemIf_Write(DeviceIndex,  BlockNumber, DataBufferPtr) \
  (((void) (DeviceIndex)),[!"$Prefix"!]Write(BlockNumber, DataBufferPtr))

#if (defined MemIf_Cancel)
#error MemIf_Cancel is already defined
#endif /* if (defined MemIf_Cancel) */
#define MemIf_Cancel(DeviceIndex) \
  (((void) (DeviceIndex)),[!"$Prefix"!]Cancel())

#if (defined MemIf_GetStatus)
#error MemIf_GetStatus is already defined
#endif /* if (defined MemIf_GetStatus) */
#define MemIf_GetStatus(DeviceIndex) \
  (((void) (DeviceIndex)),[!"$Prefix"!]GetStatus())

#if (defined MemIf_GetJobResult)
#error MemIf_GetJobResult is already defined
#endif /* if (defined MemIf_GetJobResult) */
#define MemIf_GetJobResult(DeviceIndex) \
  (((void) (DeviceIndex)),[!"$Prefix"!]GetJobResult())

#if (defined MemIf_InvalidateBlock)
#error MemIf_InvalidateBlock is already defined
#endif /* if (defined MemIf_InvalidateBlock) */
#define MemIf_InvalidateBlock(DeviceIndex, BlockNumber) \
  (((void) (DeviceIndex)),[!"$Prefix"!]InvalidateBlock(BlockNumber))

#if (defined MemIf_EraseImmediateBlock)
#error MemIf_EraseImmediateBlock is already defined
#endif /* if (defined MemIf_EraseImmediateBlock) */
#define MemIf_EraseImmediateBlock(DeviceIndex, BlockNumber) \
  (((void) (DeviceIndex)),[!"$Prefix"!]EraseImmediateBlock(BlockNumber))

[!IF "MemIfGeneral/MemIfMemAccUsage = 'false'"!]
#if (defined MemIf_SetMode)
#error MemIf_SetMode is already defined
#endif /* if (defined MemIf_SetMode) */
#define MemIf_SetMode(Mode) \
  [!"$Prefix"!]SetMode(Mode)
[!ENDIF!]
[!//
[!ENDIF!][!/* NumDevices */!][!//
[!//
[!//
/* !LINKSTO MemIf020,1 */
[!IF "$NumDevices > 1"!][!//
[!IF "MemIfGeneral/MemIfMemAccUsage = 'false'"!]
#if (defined MEMIF_SETMODE_FCTPTR)
#error MEMIF_SETMODE_FCTPTR is already defined
#endif /* if (defined MEMIF_SETMODE_FCTPTR) */
/* function pointers for the function pointer arrays */
#define MEMIF_SETMODE_FCTPTR \
{\
[!LOOP "text:split($Prefixes, ';')"!][!//
[!IF "(.) != '&_'"!][!//
  [!"."!]SetMode,\
[!ELSE!][!//
  NULL_PTR,\
[!ENDIF!][!//
[!ENDLOOP!][!//
}
[!ENDIF!][!//

#if (defined MEMIF_READ_FCTPTR)
#error MEMIF_READ_FCTPTR is already defined
#endif /* if (defined MEMIF_READ_FCTPTR) */
#define MEMIF_READ_FCTPTR \
{\
[!LOOP "text:split($Prefixes, ';')"!][!//
[!IF "(.) != '&_'"!][!//
  [!"."!]Read,\
[!ELSE!][!//
  NULL_PTR,\
[!ENDIF!][!//
[!ENDLOOP!][!//
}

#if (defined MEMIF_WRITE_FCTPTR)
#error MEMIF_WRITE_FCTPTR is already defined
#endif /* if (defined MEMIF_WRITE_FCTPTR) */
#define MEMIF_WRITE_FCTPTR \
{\
[!LOOP "text:split($Prefixes, ';')"!][!//
[!IF "(.) != '&_'"!][!//
  [!"."!]Write,\
[!ELSE!][!//
  NULL_PTR,\
[!ENDIF!][!//
[!ENDLOOP!][!//
}

#if (defined MEMIF_CANCEL_FCTPTR)
#error MEMIF_CANCEL_FCTPTR is already defined
#endif /* if (defined MEMIF_CANCEL_FCTPTR) */
#define MEMIF_CANCEL_FCTPTR \
{\
[!LOOP "text:split($Prefixes, ';')"!][!//
[!IF "(.) != '&_'"!][!//
  [!"."!]Cancel,\
[!ELSE!][!//
  NULL_PTR,\
[!ENDIF!][!//
[!ENDLOOP!][!//
}

#if (defined MEMIF_GETSTATUS_FCTPTR)
#error MEMIF_GETSTATUS_FCTPTR is already defined
#endif /* if (defined MEMIF_GETSTATUS_FCTPTR) */
#define MEMIF_GETSTATUS_FCTPTR \
{\
[!LOOP "text:split($Prefixes, ';')"!][!//
[!IF "(.) != '&_'"!][!//
  [!"."!]GetStatus,\
[!ELSE!][!//
  NULL_PTR,\
[!ENDIF!][!//
[!ENDLOOP!][!//
}

#if (defined MEMIF_GETJOBRESULT_FCTPTR)
#error MEMIF_GETJOBRESULT_FCTPTR is already defined
#endif /* if (defined MEMIF_GETJOBRESULT_FCTPTR) */
#define MEMIF_GETJOBRESULT_FCTPTR \
{\
[!LOOP "text:split($Prefixes, ';')"!][!//
[!IF "(.) != '&_'"!][!//
  [!"."!]GetJobResult,\
[!ELSE!][!//
  NULL_PTR,\
[!ENDIF!][!//
[!ENDLOOP!][!//
}

#if (defined MEMIF_INVALIDATEBLOCK_FCTPTR)
#error MEMIF_INVALIDATEBLOCK_FCTPTR is already defined
#endif /* if (defined MEMIF_INVALIDATEBLOCK_FCTPTR) */
#define MEMIF_INVALIDATEBLOCK_FCTPTR \
{\
[!LOOP "text:split($Prefixes, ';')"!][!//
[!IF "(.) != '&_'"!][!//
  [!"."!]InvalidateBlock,\
[!ELSE!][!//
  NULL_PTR,\
[!ENDIF!][!//
[!ENDLOOP!][!//
}

#if (defined MEMIF_ERASEIMMEDIATEBLOCK_FCTPTR)
#error MEMIF_ERASEIMMEDIATEBLOCK_FCTPTR is already defined
#endif /* if (defined MEMIF_ERASEIMMEDIATEBLOCK_FCTPTR) */
#define MEMIF_ERASEIMMEDIATEBLOCK_FCTPTR \
{\
[!LOOP "text:split($Prefixes, ';')"!][!//
[!IF "(.) != '&_'"!][!//
  [!"."!]EraseImmediateBlock,\
[!ELSE!][!//
  NULL_PTR,\
[!ENDIF!][!//
[!ENDLOOP!][!//
}

[!ENDIF!][!//
/*==================[type definitions]======================================*/

/*==================[external data]=========================================*/

#endif /* ifndef MEMIF_CFG_H */
/*==================[end of file]===========================================*/

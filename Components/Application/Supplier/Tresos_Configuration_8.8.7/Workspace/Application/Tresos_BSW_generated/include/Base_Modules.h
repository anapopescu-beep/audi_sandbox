/**
 * \file
 *
 * \brief AUTOSAR Base
 *
 * This file contains the implementation of the AUTOSAR
 * module Base.
 *
 * \version 5.2.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* !LINKSTO Base.ModuleInfo.HeaderFile,1 */
#ifndef BASE_MODULES_H
#define BASE_MODULES_H

/*==================[macros]=================================================*/

#ifndef BASE_ADC_ENABLED
/** \brief Enable status of the module Adc (/Adc/Adc) (VariantPreCompile) */
#define BASE_ADC_ENABLED STD_ON
#endif

#ifndef BASE_ADC_HEADER
/** \brief Name of the Adc (/Adc/Adc) module's main header file */
#define BASE_ADC_HEADER <Adc.h>
#endif

#ifndef BASE_BASE_ENABLED
/** \brief Enable status of the module Base (/Base/Base) (VariantPreCompile) */
#define BASE_BASE_ENABLED STD_ON
#endif

#ifndef BASE_BASE_HEADER
/** \brief Name of the Base (/Base/Base) module's main header file */
#define BASE_BASE_HEADER <Base.h>
#endif

#ifndef BASE_BASENXP_ENABLED
/** \brief Enable status of the module BaseNXP (/BaseNXP/BaseNXP) (VariantPreCompile) */
#define BASE_BASENXP_ENABLED STD_ON
#endif

#ifndef BASE_BASENXP_HEADER
/** \brief Name of the BaseNXP (/BaseNXP/BaseNXP) module's main header file */
#define BASE_BASENXP_HEADER <BaseNXP.h>
#endif

#ifndef BASE_BSWM_ENABLED
/** \brief Enable status of the module BswM (/BswM/BswM) (VariantPreCompile) */
#define BASE_BSWM_ENABLED STD_ON
#endif

#ifndef BASE_BSWM_HEADER
/** \brief Name of the BswM (/BswM/BswM) module's main header file */
#define BASE_BSWM_HEADER <BswM.h>
#endif

#ifndef BASE_CAN_ENABLED
/** \brief Enable status of the module Can (/Can/Can) (VariantPreCompile) */
#define BASE_CAN_ENABLED STD_ON
#endif

#ifndef BASE_CAN_HEADER
/** \brief Name of the Can (/Can/Can) module's main header file */
#define BASE_CAN_HEADER <Can.h>
#endif

#ifndef BASE_CANIF_ENABLED
/** \brief Enable status of the module CanIf (/CanIf/CanIf) (VariantPostBuild) */
#define BASE_CANIF_ENABLED STD_ON
#endif


#ifndef BASE_CANIF_CONFIG_PTR
/** \brief Address of the first multiple configuration container for CanIf (/CanIf/CanIf) */
#define BASE_CANIF_CONFIG_PTR (&CanIfInitCfg)
#endif

#ifndef BASE_CANIF_HEADER
/** \brief Name of the CanIf (/CanIf/CanIf) module's main header file */
#define BASE_CANIF_HEADER <CanIf.h>
#endif

#ifndef BASE_CANSM_ENABLED
/** \brief Enable status of the module CanSM (/CanSM/CanSM) (VariantPostBuild) */
#define BASE_CANSM_ENABLED STD_ON
#endif


#ifndef BASE_CANSM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for CanSM (/CanSM/CanSM) */
#define BASE_CANSM_CONFIG_PTR (&CanSMConfiguration)
#endif

#ifndef BASE_CANSM_HEADER
/** \brief Name of the CanSM (/CanSM/CanSM) module's main header file */
#define BASE_CANSM_HEADER <CanSM.h>
#endif

#ifndef BASE_CANTP_ENABLED
/** \brief Enable status of the module CanTp (/CanTp/CanTp) (VariantPostBuild) */
#define BASE_CANTP_ENABLED STD_ON
#endif


#ifndef BASE_CANTP_CONFIG_PTR
/** \brief Address of the first multiple configuration container for CanTp (/CanTp/CanTp) */
#define BASE_CANTP_CONFIG_PTR (&CanTpConfig)
#endif

#ifndef BASE_CANTP_HEADER
/** \brief Name of the CanTp (/CanTp/CanTp) module's main header file */
#define BASE_CANTP_HEADER <CanTp.h>
#endif

#ifndef BASE_COM_ENABLED
/** \brief Enable status of the module Com (/Com/Com) (VariantPostBuild) */
#define BASE_COM_ENABLED STD_ON
#endif


#ifndef BASE_COM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for Com (/Com/Com) */
#define BASE_COM_CONFIG_PTR (&ComConfig)
#endif

#ifndef BASE_COM_HEADER
/** \brief Name of the Com (/Com/Com) module's main header file */
#define BASE_COM_HEADER <Com.h>
#endif

#ifndef BASE_COMM_ENABLED
/** \brief Enable status of the module ComM (/ComM/ComM) (VariantPostBuild) */
#define BASE_COMM_ENABLED STD_ON
#endif


#ifndef BASE_COMM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for ComM (/ComM/ComM) */
#define BASE_COMM_CONFIG_PTR (&ComMConfigSet_0)
#endif

#ifndef BASE_COMM_HEADER
/** \brief Name of the ComM (/ComM/ComM) module's main header file */
#define BASE_COMM_HEADER <ComM.h>
#endif

#ifndef BASE_COMPILER_ENABLED
/** \brief Enable status of the module Compiler (/Compiler/Compiler) (VariantPreCompile) */
#define BASE_COMPILER_ENABLED STD_ON
#endif

#ifndef BASE_COMPILER_HEADER
/** \brief Name of the Compiler (/Compiler/Compiler) module's main header file */
#define BASE_COMPILER_HEADER <Compiler.h>
#endif

#ifndef BASE_CRC_ENABLED
/** \brief Enable status of the module Crc (/Crc/Crc) (VariantPreCompile) */
#define BASE_CRC_ENABLED STD_ON
#endif

#ifndef BASE_CRC_HEADER
/** \brief Name of the Crc (/Crc/Crc) module's main header file */
#define BASE_CRC_HEADER <Crc.h>
#endif

#ifndef BASE_DCM_ENABLED
/** \brief Enable status of the module Dcm (/Dcm/Dcm) (VariantPreCompile) */
#define BASE_DCM_ENABLED STD_ON
#endif


#ifndef BASE_DCM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for Dcm (/Dcm/Dcm) */
#define BASE_DCM_CONFIG_PTR (&DcmConfigSet)
#endif

#ifndef BASE_DCM_HEADER
/** \brief Name of the Dcm (/Dcm/Dcm) module's main header file */
#define BASE_DCM_HEADER <Dcm.h>
#endif

#ifndef BASE_DEM_ENABLED
/** \brief Enable status of the module Dem (/Dem/Dem) (VariantPreCompile) */
#define BASE_DEM_ENABLED STD_ON
#endif


#ifndef BASE_DEM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for Dem (/Dem/Dem) */
#define BASE_DEM_CONFIG_PTR (&Dem_Config_0)
#endif

#ifndef BASE_DEM_HEADER
/** \brief Name of the Dem (/Dem/Dem) module's main header file */
#define BASE_DEM_HEADER <Dem.h>
#endif

#ifndef BASE_DET_ENABLED
/** \brief Enable status of the module Det (/Det/Det) (VariantPreCompile) */
#define BASE_DET_ENABLED STD_ON
#endif

#ifndef BASE_DET_HEADER
/** \brief Name of the Det (/Det/Det) module's main header file */
#define BASE_DET_HEADER <Det.h>
#endif

#ifndef BASE_DIO_ENABLED
/** \brief Enable status of the module Dio (/Dio/Dio) (VariantPreCompile) */
#define BASE_DIO_ENABLED STD_ON
#endif

#ifndef BASE_DIO_HEADER
/** \brief Name of the Dio (/Dio/Dio) module's main header file */
#define BASE_DIO_HEADER <Dio.h>
#endif

#ifndef BASE_ECUC_ENABLED
/** \brief Enable status of the module EcuC (/EcuC/EcuC) (VariantPostBuild) */
#define BASE_ECUC_ENABLED STD_ON
#endif

#ifndef BASE_ECUC_HEADER
/** \brief Name of the EcuC (/EcuC/EcuC) module's main header file */
#define BASE_ECUC_HEADER <EcuC.h>
#endif

#ifndef BASE_ECUM_ENABLED
/** \brief Enable status of the module EcuM (/EcuM/EcuM) (VariantPostBuild) */
#define BASE_ECUM_ENABLED STD_ON
#endif


#ifndef BASE_ECUM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for EcuM (/EcuM/EcuM) */
#define BASE_ECUM_CONFIG_PTR (&EcuM_Config_0)
#endif

#ifndef BASE_ECUM_HEADER
/** \brief Name of the EcuM (/EcuM/EcuM) module's main header file */
#define BASE_ECUM_HEADER <EcuM.h>
#endif

#ifndef BASE_FEE_ENABLED
/** \brief Enable status of the module Fee (/Fee/Fee) (VariantPreCompile) */
#define BASE_FEE_ENABLED STD_ON
#endif

#ifndef BASE_FEE_HEADER
/** \brief Name of the Fee (/Fee/Fee) module's main header file */
#define BASE_FEE_HEADER <Fee.h>
#endif

#ifndef BASE_FLS_ENABLED
/** \brief Enable status of the module Fls (/Fls/Fls) (VariantPostBuild) */
#define BASE_FLS_ENABLED STD_ON
#endif

#ifndef BASE_FLS_HEADER
/** \brief Name of the Fls (/Fls/Fls) module's main header file */
#define BASE_FLS_HEADER <Fls.h>
#endif

#ifndef BASE_GPT_ENABLED
/** \brief Enable status of the module Gpt (/Gpt/Gpt) (VariantPostBuild) */
#define BASE_GPT_ENABLED STD_ON
#endif


#ifndef BASE_GPT_CONFIG_PTR
/** \brief Address of the first multiple configuration container for Gpt (/Gpt/Gpt) */
#define BASE_GPT_CONFIG_PTR (&GptChannelConfigSet)
#endif

#ifndef BASE_GPT_HEADER
/** \brief Name of the Gpt (/Gpt/Gpt) module's main header file */
#define BASE_GPT_HEADER <Gpt.h>
#endif

#ifndef BASE_MCALEXT_ENABLED
/** \brief Enable status of the module McalExt (/McalExt/McalExt) (VariantPreCompile) */
#define BASE_MCALEXT_ENABLED STD_ON
#endif

#ifndef BASE_MCALEXT_HEADER
/** \brief Name of the McalExt (/McalExt/McalExt) module's main header file */
#define BASE_MCALEXT_HEADER <McalExt.h>
#endif

#ifndef BASE_MCL_ENABLED
/** \brief Enable status of the module Mcl (/Mcl/Mcl) (VariantPostBuild) */
#define BASE_MCL_ENABLED STD_ON
#endif

#ifndef BASE_MCL_HEADER
/** \brief Name of the Mcl (/Mcl/Mcl) module's main header file */
#define BASE_MCL_HEADER <Mcl.h>
#endif

#ifndef BASE_MCU_ENABLED
/** \brief Enable status of the module Mcu (/Mcu/Mcu) (VariantPreCompile) */
#define BASE_MCU_ENABLED STD_ON
#endif

#ifndef BASE_MCU_HEADER
/** \brief Name of the Mcu (/Mcu/Mcu) module's main header file */
#define BASE_MCU_HEADER <Mcu.h>
#endif

#ifndef BASE_MEMIF_ENABLED
/** \brief Enable status of the module MemIf (/MemIf/MemIf) (VariantPreCompile) */
#define BASE_MEMIF_ENABLED STD_ON
#endif

#ifndef BASE_MEMIF_HEADER
/** \brief Name of the MemIf (/MemIf/MemIf) module's main header file */
#define BASE_MEMIF_HEADER <MemIf.h>
#endif

#ifndef BASE_MEMMAP_ENABLED
/** \brief Enable status of the module MemMap (/MemMap/MemMap) (VariantPreCompile) */
#define BASE_MEMMAP_ENABLED STD_ON
#endif

#ifndef BASE_MEMMAP_HEADER
/** \brief Name of the MemMap (/MemMap/MemMap) module's main header file */
#define BASE_MEMMAP_HEADER <MemMap.h>
#endif

#ifndef BASE_NVM_ENABLED
/** \brief Enable status of the module NvM (/NvM/NvM) (VariantPreCompile) */
#define BASE_NVM_ENABLED STD_ON
#endif

#ifndef BASE_NVM_HEADER
/** \brief Name of the NvM (/NvM/NvM) module's main header file */
#define BASE_NVM_HEADER <NvM.h>
#endif

#ifndef BASE_OS_ENABLED
/** \brief Enable status of the module Os (/Os/Os) (VariantPreCompile) */
#define BASE_OS_ENABLED STD_ON
#endif

#ifndef BASE_OS_HEADER
/** \brief Name of the Os (/Os/Os) module's main header file */
#define BASE_OS_HEADER <Os.h>
#endif

#ifndef BASE_PDUR_ENABLED
/** \brief Enable status of the module PduR (/PduR/PduR) (VariantPostBuild) */
#define BASE_PDUR_ENABLED STD_ON
#endif


#ifndef BASE_PDUR_CONFIG_PTR
/** \brief Address of the first multiple configuration container for PduR (/PduR/PduR) */
#define BASE_PDUR_CONFIG_PTR (&PduRRoutingTables)
#endif

#ifndef BASE_PDUR_HEADER
/** \brief Name of the PduR (/PduR/PduR) module's main header file */
#define BASE_PDUR_HEADER <PduR.h>
#endif

#ifndef BASE_PORT_ENABLED
/** \brief Enable status of the module Port (/Port/Port) (VariantPreCompile) */
#define BASE_PORT_ENABLED STD_ON
#endif

#ifndef BASE_PORT_HEADER
/** \brief Name of the Port (/Port/Port) module's main header file */
#define BASE_PORT_HEADER <Port.h>
#endif

#ifndef BASE_PWM_ENABLED
/** \brief Enable status of the module Pwm (/Pwm/Pwm) (VariantPreCompile) */
#define BASE_PWM_ENABLED STD_ON
#endif

#ifndef BASE_PWM_HEADER
/** \brief Name of the Pwm (/Pwm/Pwm) module's main header file */
#define BASE_PWM_HEADER <Pwm.h>
#endif

#ifndef BASE_RESOURCE_ENABLED
/** \brief Enable status of the module Resource (/Resource/Resource) (VariantPreCompile) */
#define BASE_RESOURCE_ENABLED STD_ON
#endif

#ifndef BASE_RESOURCE_HEADER
/** \brief Name of the Resource (/Resource/Resource) module's main header file */
#define BASE_RESOURCE_HEADER <Resource.h>
#endif

#ifndef BASE_RTE_ENABLED
/** \brief Enable status of the module Rte (/Rte/Rte) (VariantPreCompile) */
#define BASE_RTE_ENABLED STD_ON
#endif

#ifndef BASE_RTE_HEADER
/** \brief Name of the Rte (/Rte/Rte) module's main header file */
#define BASE_RTE_HEADER <Rte.h>
#endif

#ifndef BASE_SPI_ENABLED
/** \brief Enable status of the module Spi (/Spi/Spi) (VariantPostBuild) */
#define BASE_SPI_ENABLED STD_ON
#endif

#ifndef BASE_SPI_HEADER
/** \brief Name of the Spi (/Spi/Spi) module's main header file */
#define BASE_SPI_HEADER <Spi.h>
#endif

#endif /* ifndef BASE_MODULES_H */
/*==================[end of file]============================================*/

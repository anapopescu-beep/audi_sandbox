/**
* @file    Port_Cfg.c
*
* @version 1.0.2
* @brief   AUTOSAR Port - PORT driver configuration.
* @details This file contains the PORT driver precompile configuration.
*
* @addtogroup  Port
* @{
*/
/*=================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : PORT_CI
*   Dependencies         : none
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 1.0.2
*   Build Version        : S32K14xS32K14X_MCAL_1_0_2_RTM_ASR_REL_4_2_REV_0002_20190426
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2019 NXP
*   All Rights Reserved.
=================================================================================================*/
/*=================================================================================================
=================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section PORT_CFG_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* MemMap.h is included after each section define in order to set the current memory section as defined by AUTOSAR.
*
* @section PORT_CFG_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section PORT_CFG_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character signifiance and case sensitivity are supported for external identifiers.
* The used compilers/linkers allow more than 31 characters significance for external identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/
#include "Port.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/**
* @brief        Parameters that shall be published within the Port driver header file and also in the
*               module's description file
* @details      The integration of incompatible files shall be avoided.
*
*/
#define PORT_VENDOR_ID_CFG_C                       43
/** @violates @ref PORT_CFG_REF_3 The used compilers use more than 31 chars for identifiers. */
#define PORT_AR_RELEASE_MAJOR_VERSION_CFG_C        4
/** @violates @ref PORT_CFG_REF_3 The used compilers use more than 31 chars for identifiers. */
#define PORT_AR_RELEASE_MINOR_VERSION_CFG_C        2
/** @violates @ref PORT_CFG_REF_3 The used compilers use more than 31 chars for identifiers. */
#define PORT_AR_RELEASE_REVISION_VERSION_CFG_C     2
#define PORT_SW_MAJOR_VERSION_CFG_C                1
#define PORT_SW_MINOR_VERSION_CFG_C                0
#define PORT_SW_PATCH_VERSION_CFG_C                2

/*=================================================================================================
                                      FILE VERSION CHECKS
=================================================================================================*/
/* Check if Port_Cfg.c and Port.h are of the same vendor */
#if (PORT_VENDOR_ID_CFG_C != PORT_VENDOR_ID)
    #error "Port_Cfg.c and Port.h have different vendor ids"
#endif

/* Check if Port_Cfg.c and Port.h file are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_CFG_C != PORT_AR_RELEASE_MAJOR_VERSION)     || \
     (PORT_AR_RELEASE_MINOR_VERSION_CFG_C != PORT_AR_RELEASE_MINOR_VERSION)     || \
     (PORT_AR_RELEASE_REVISION_VERSION_CFG_C != PORT_AR_RELEASE_REVISION_VERSION)  \
    )
   #error "AutoSar Version Numbers of Port_Cfg.c and Port.h are different"
#endif

/* Check if Port_Cfg.c and Port.h are of the same software version */
#if ((PORT_SW_MAJOR_VERSION_CFG_C != PORT_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_CFG_C != PORT_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_CFG_C != PORT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Port_Cfg.c and Port.h are different"
#endif

/*=================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/


/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/

#define PORT_START_SEC_CONST_16
/** @violates @ref PORT_CFG_REF_1 only preprocessor statements and comments before "#include". */
/** @violates @ref PORT_CFG_REF_2 Precautions to prevent the contents of a header file being included twice. */
#include "Port_MemMap.h"

#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief Port Pin description data
*/
CONST (uint16, PORT_CONST) Port_au16PinDescription[8][9] =
{

            

/*  Mode PORT_ALT0_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT0_ADC0_SE0_CMP0_IN0 |
PORT1_ADC0_SE1_CMP0_IN1 |
PORT2_ADC1_SE0 |
PORT3_ADC1_SE1 |
PORT6_ADC0_SE2 |
PORT7_ADC0_SE3 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7)
          ),
/* Pads 16 ... 31 */
  (uint16)0x0000,
/* Pads  32 ...  47 : PORT32_ADC0_SE4_ADC1_SE14 |
PORT33_ADC0_SE5_ADC1_SE15 |
PORT34_ADC0_SE6 |
PORT35_ADC0_SE7 |
PORT38_XTAL |
PORT39_EXTAL |
PORT44_ADC1_SE7 |
PORT45_ADC1_SE8_ADC0_SE8 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(12) |
            SHL_PAD_U16(13)
          ),
/* Pads 48 ... 63 */
  (uint16)0x0000,
/* Pads  64 ...  79 : PORT64_ADC0_SE8 |
PORT65_ADC0_SE9 |
PORT66_ADC0_SE10_CMP0_IN5 |
PORT67_ADC0_SE11_CMP0_IN4 |
PORT68_CMP0_IN2 |
PORT70_ADC1_SE4 |
PORT71_ADC1_SE5 |
PORT78_ADC0_SE12 |
PORT79_ADC0_SE13 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(14) |
            SHL_PAD_U16(15)
          ),
/* Pads  80 ...  95 : PORT80_ADC0_SE14 |
PORT81_ADC0_SE15 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1)
          ),
/* Pads  96 ... 111 : PORT98_ADC1_SE2 |
PORT99_ADC1_SE3 |
PORT100_ADC1_SE6 |
PORT102_CMP0_IN7 |
PORT103_CMP0_IN6 */
  (uint16)( SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7)
          ),
/* Pads 112 ... 127 */
  (uint16)0x0000,
/* Pads 128 ... 143 : PORT130_ADC1_SE10 |
PORT134_ADC1_SE11 |
PORT136_CMP0_IN3 */
  (uint16)( SHL_PAD_U16(2) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(8)
          )
}
,
/*  Mode PORT_GPIO_MODE: */
{
/* Pads   0 ...  15 : PORT0_GPIO |
PORT1_GPIO |
PORT2_GPIO |
PORT3_GPIO |
PORT4_GPIO |
PORT5_GPIO |
PORT6_GPIO |
PORT7_GPIO |
PORT10_GPIO |
PORT11_GPIO |
PORT12_GPIO |
PORT13_GPIO */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(10) |
            SHL_PAD_U16(11) |
            SHL_PAD_U16(12) |
            SHL_PAD_U16(13)
          ),
/* Pads 16 ... 31 */
  (uint16)0x0000,
/* Pads  32 ...  47 : PORT32_GPIO |
PORT33_GPIO |
PORT34_GPIO |
PORT35_GPIO |
PORT36_GPIO |
PORT37_GPIO |
PORT38_GPIO |
PORT39_GPIO |
PORT44_GPIO |
PORT45_GPIO */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(12) |
            SHL_PAD_U16(13)
          ),
/* Pads 48 ... 63 */
  (uint16)0x0000,
/* Pads  64 ...  79 : PORT64_GPIO |
PORT65_GPIO |
PORT66_GPIO |
PORT67_GPIO |
PORT68_GPIO |
PORT69_GPIO |
PORT70_GPIO |
PORT71_GPIO |
PORT72_GPIO |
PORT73_GPIO |
PORT78_GPIO |
PORT79_GPIO */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(8) |
            SHL_PAD_U16(9) |
            SHL_PAD_U16(14) |
            SHL_PAD_U16(15)
          ),
/* Pads  80 ...  95 : PORT80_GPIO |
PORT81_GPIO */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1)
          ),
/* Pads  96 ... 111 : PORT96_GPIO |
PORT97_GPIO |
PORT98_GPIO |
PORT99_GPIO |
PORT100_GPIO |
PORT101_GPIO |
PORT102_GPIO |
PORT103_GPIO |
PORT111_GPIO */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(15)
          ),
/* Pads 112 ... 127 : PORT112_GPIO */
  (uint16)( SHL_PAD_U16(0)
          ),
/* Pads 128 ... 143 : PORT128_GPIO |
PORT129_GPIO |
PORT130_GPIO |
PORT131_GPIO |
PORT132_GPIO |
PORT133_GPIO |
PORT134_GPIO |
PORT135_GPIO |
PORT136_GPIO |
PORT137_GPIO |
PORT138_GPIO |
PORT139_GPIO */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(8) |
            SHL_PAD_U16(9) |
            SHL_PAD_U16(10) |
            SHL_PAD_U16(11)
          )
}
,
/*  Mode PORT_ALT2_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT0_FTM2_CH1 |
PORT1_FTM1_CH1 |
PORT2_FTM3_CH0 |
PORT3_FTM3_CH1 |
PORT6_FTM0_FLT1 |
PORT7_FTM0_FLT2 |
PORT10_FTM1_CH4 |
PORT11_FTM1_CH5 |
PORT12_FTM1_CH6 |
PORT13_FTM1_CH7 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(10) |
            SHL_PAD_U16(11) |
            SHL_PAD_U16(12) |
            SHL_PAD_U16(13)
          ),
/* Pads 16 ... 31 */
  (uint16)0x0000,
/* Pads  32 ...  47 : PORT32_LPUART0_RX |
PORT33_LPUART0_TX |
PORT34_FTM1_CH0 |
PORT35_FTM1_CH1 |
PORT36_FTM0_CH4 |
PORT37_FTM0_CH5 |
PORT38_LPI2C0_SDA |
PORT39_LPI2C0_SCL |
PORT44_FTM0_CH0 |
PORT45_FTM0_CH1 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(12) |
            SHL_PAD_U16(13)
          ),
/* Pads 48 ... 63 */
  (uint16)0x0000,
/* Pads  64 ...  79 : PORT64_FTM0_CH0 |
PORT65_FTM0_CH1 |
PORT66_FTM0_CH2 |
PORT67_FTM0_CH3 |
PORT68_FTM1_CH0 |
PORT69_FTM2_CH0 |
PORT70_LPUART1_RX |
PORT71_LPUART1_TX |
PORT72_LPUART1_RX |
PORT73_LPUART1_TX |
PORT78_FTM1_CH2 |
PORT79_FTM1_CH3 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(8) |
            SHL_PAD_U16(9) |
            SHL_PAD_U16(14) |
            SHL_PAD_U16(15)
          ),
/* Pads  80 ...  95 : PORT80_FTM1_FLT2 |
PORT81_FTM1_FLT3 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1)
          ),
/* Pads  96 ... 111 : PORT96_FTM0_CH2 |
PORT97_FTM0_CH3 |
PORT98_FTM3_CH4 |
PORT99_FTM3_CH5 |
PORT100_FTM0_FLT3 |
PORT101_FTM2_CH3 |
PORT102_LPUART2_RX |
PORT103_LPUART2_TX |
PORT111_FTM0_CH0 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(15)
          ),
/* Pads 112 ... 127 : PORT112_FTM0_CH1 */
  (uint16)( SHL_PAD_U16(0)
          ),
/* Pads 128 ... 143 : PORT128_LPSPI0_SCK |
PORT129_LPSPI0_SIN |
PORT130_LPSPI0_SOUT |
PORT131_FTM0_FLT0 |
PORT133_TCLK2 |
PORT134_LPSPI0_PCS2 |
PORT135_FTM0_CH7 |
PORT136_FTM0_CH6 |
PORT137_FTM0_CH7 |
PORT138_CLKOUT |
PORT139_LPSPI2_PCS0 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(8) |
            SHL_PAD_U16(9) |
            SHL_PAD_U16(10) |
            SHL_PAD_U16(11)
          )
}
,
/*  Mode PORT_ALT3_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT0_LPI2C0_SCLS |
PORT1_LPI2C0_SDAS |
PORT2_LPI2C0_SDA |
PORT3_LPI2C0_SCL |
PORT5_TCLK1 |
PORT6_LPSPI1_PCS1 |
PORT12_CAN1_RX |
PORT13_CAN1_TX */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(12) |
            SHL_PAD_U16(13)
          ),
/* Pads 16 ... 31 */
  (uint16)0x0000,
/* Pads  32 ...  47 : PORT32_LPSPI0_PCS0 |
PORT33_LPSPI0_SOUT |
PORT34_LPSPI0_SCK |
PORT35_LPSPI0_SIN |
PORT36_LPSPI0_SOUT |
PORT37_LPSPI0_PCS1 |
PORT44_FTM3_FLT2 |
PORT45_FTM3_FLT1 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(12) |
            SHL_PAD_U16(13)
          ),
/* Pads 48 ... 63 */
  (uint16)0x0000,
/* Pads  64 ...  79 : PORT64_LPSPI2_SIN |
PORT65_LPSPI2_SOUT |
PORT66_CAN0_RX |
PORT67_CAN0_TX |
PORT68_RTC_CLKOUT |
PORT69_RTC_CLKOUT |
PORT70_CAN1_RX |
PORT71_CAN1_TX |
PORT72_FTM1_FLT0 |
PORT73_FTM1_FLT1 |
PORT78_LPSPI2_PCS0 |
PORT79_LPSPI2_SCK */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(8) |
            SHL_PAD_U16(9) |
            SHL_PAD_U16(14) |
            SHL_PAD_U16(15)
          ),
/* Pads  80 ...  95 : PORT80_CAN2_RX |
PORT81_CAN2_TX */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1)
          ),
/* Pads  96 ... 111 : PORT96_LPSPI1_SCK |
PORT97_LPSPI1_SIN |
PORT98_LPSPI1_SOUT |
PORT99_LPSPI1_PCS0 |
PORT100_FTM3_FLT3 |
PORT101_LPTMR0_ALT2 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5)
          ),
/* Pads 112 ... 127 */
  (uint16)0x0000,
/* Pads 128 ... 143 : PORT128_TCLK1 |
PORT129_LPI2C0_HREQ |
PORT130_LPTMR0_ALT3 |
PORT131_LPUART2_RTS |
PORT132_FTM2_QD_PHB |
PORT133_FTM2_QD_PHA |
PORT135_FTM3_FLT0 |
PORT137_LPUART2_CTS |
PORT138_LPSPI2_PCS1 |
PORT139_LPTMR0_ALT1 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(9) |
            SHL_PAD_U16(10) |
            SHL_PAD_U16(11)
          )
}
,
/*  Mode PORT_ALT4_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT0_FXIO_D2 |
PORT1_FXIO_D3 |
PORT2_EWM_OUT_b |
PORT3_EWM_IN |
PORT4_CMP0_OUT |
PORT7_RTC_CLKIN |
PORT10_FXIO_D0 |
PORT11_FXIO_D1 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(10) |
            SHL_PAD_U16(11)
          ),
/* Pads 16 ... 31 */
  (uint16)0x0000,
/* Pads  32 ...  47 : PORT32_LPTMR0_ALT3 |
PORT33_TCLK0 |
PORT34_FTM1_QD_PHB |
PORT35_FTM1_QD_PHA |
PORT37_LPSPI0_PCS0 |
PORT44_CAN2_RX |
PORT45_CAN2_TX */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(12) |
            SHL_PAD_U16(13)
          ),
/* Pads 48 ... 63 */
  (uint16)0x0000,
/* Pads  64 ...  79 : PORT66_LPUART0_RX |
PORT67_LPUART0_TX |
PORT70_FTM3_CH2 |
PORT71_FTM3_CH3 */
  (uint16)( SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7)
          ),
/* Pads 80 ... 95 */
  (uint16)0x0000,
/* Pads  96 ... 111 : PORT96_FTM2_CH0 |
PORT97_FTM2_CH1 |
PORT98_FXIO_D4 |
PORT99_FXIO_D5 |
PORT101_FTM2_FLT1 |
PORT102_FTM2_FLT2 |
PORT103_FTM2_FLT3 |
PORT111_LPSPI0_SCK */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(15)
          ),
/* Pads 112 ... 127 : PORT112_LPSPI0_SIN */
  (uint16)( SHL_PAD_U16(0)
          ),
/* Pads 128 ... 143 : PORT130_FTM3_CH6 |
PORT131_FTM2_FLT0 |
PORT132_FTM2_CH2 |
PORT133_FTM2_CH3 |
PORT134_FTM3_CH7 |
PORT138_FTM2_CH4 |
PORT139_FTM2_CH5 */
  (uint16)( SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(10) |
            SHL_PAD_U16(11)
          )
}
,
/*  Mode PORT_ALT5_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT0_FTM2_QD_PHA |
PORT1_FTM1_QD_PHA |
PORT2_FXIO_D4 |
PORT3_FXIO_D5 |
PORT4_EWM_OUT_b |
PORT11_CMP0_RRT */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(11)
          ),
/* Pads 16 ... 31 */
  (uint16)0x0000,
/* Pads  32 ...  47 : PORT32_CAN0_RX |
PORT33_CAN0_TX |
PORT37_CLKOUT */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(5)
          ),
/* Pads 48 ... 63 */
  (uint16)0x0000,
/* Pads  64 ...  79 : PORT68_EWM_IN */
  (uint16)( SHL_PAD_U16(4)
          ),
/* Pads 80 ... 95 */
  (uint16)0x0000,
/* Pads  96 ... 111 : PORT98_FXIO_D6 |
PORT99_FXIO_D7 */
  (uint16)( SHL_PAD_U16(2) |
            SHL_PAD_U16(3)
          ),
/* Pads 112 ... 127 : PORT112_CMP0_RRT */
  (uint16)( SHL_PAD_U16(0)
          ),
/* Pads 128 ... 143 : PORT128_LPSPI1_SOUT |
PORT129_LPSPI1_PCS0 |
PORT132_CAN0_RX |
PORT133_CAN0_TX */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5)
          )
}
,
/*  Mode PORT_ALT6_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT0_LPUART0_CTS |
PORT1_LPUART0_RTS |
PORT2_LPUART0_RX |
PORT3_LPUART0_TX |
PORT6_LPUART1_CTS |
PORT7_LPUART1_RTS |
PORT12_FTM2_QD_PHB |
PORT13_FTM2_QD_PHA */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(12) |
            SHL_PAD_U16(13)
          ),
/* Pads 16 ... 31 */
  (uint16)0x0000,
/* Pads  32 ...  47 : PORT34_TRGMUX_IN3 |
PORT35_TRGMUX_IN2 |
PORT36_TRGMUX_IN1 |
PORT37_TRGMUX_IN0 */
  (uint16)( SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5)
          ),
/* Pads 48 ... 63 */
  (uint16)0x0000,
/* Pads  64 ...  79 : PORT64_FTM1_CH6 |
PORT65_FTM1_CH7 |
PORT68_FTM1_QD_PHB |
PORT69_FTM2_QD_PHB |
PORT70_FTM1_QD_PHB |
PORT71_FTM1_QD_PHA |
PORT72_LPUART0_CTS |
PORT73_LPUART0_RTS |
PORT78_TRGMUX_IN9 |
PORT79_TRGMUX_IN8 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(8) |
            SHL_PAD_U16(9) |
            SHL_PAD_U16(14) |
            SHL_PAD_U16(15)
          ),
/* Pads 80 ... 95 */
  (uint16)0x0000,
/* Pads  96 ... 111 : PORT96_FXIO_D0 |
PORT97_FXIO_D1 |
PORT98_TRGMUX_IN5 |
PORT99_TRGMUX_IN4 |
PORT101_TRGMUX_IN7 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(5)
          ),
/* Pads 112 ... 127 */
  (uint16)0x0000,
/* Pads 128 ... 143 : PORT128_FTM1_FLT2 |
PORT129_FTM1_FLT1 |
PORT130_LPUART1_CTS |
PORT131_TRGMUX_IN6 |
PORT132_FXIO_D6 |
PORT133_FXIO_D7 |
PORT134_LPUART1_RTS |
PORT138_FXIO_D4 |
PORT139_FXIO_D5 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(10) |
            SHL_PAD_U16(11)
          )
}
,
/*  Mode PORT_ALT7_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT0_TRGMUX_OUT3 |
PORT1_TRGMUX_OUT0 |
PORT4_JTAG_TMS_SWD_DIO |
PORT5_RESET_b |
PORT10_JTAG_TDO */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(10)
          ),
/* Pads 16 ... 31 */
  (uint16)0x0000,
/* Pads 32 ... 47 */
  (uint16)0x0000,
/* Pads 48 ... 63 */
  (uint16)0x0000,
/* Pads  64 ...  79 : PORT68_JTAG_TCLK_SWD_CLK |
PORT69_JTAG_TDI */
  (uint16)( SHL_PAD_U16(4) |
            SHL_PAD_U16(5)
          ),
/* Pads 80 ... 95 */
  (uint16)0x0000,
/* Pads  96 ... 111 : PORT96_TRGMUX_OUT1 |
PORT97_TRGMUX_OUT2 |
PORT99_NMI_b */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(3)
          ),
/* Pads 112 ... 127 */
  (uint16)0x0000,
/* Pads 128 ... 143 : PORT131_CMP0_OUT |
PORT132_EWM_OUT_b |
PORT133_EWM_IN |
PORT138_TRGMUX_OUT4 |
PORT139_TRGMUX_OUT5 */
  (uint16)( SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(10) |
            SHL_PAD_U16(11)
          )
}


    };
#endif

#define PORT_STOP_SEC_CONST_16
/** @violates @ref PORT_CFG_REF_1 only preprocessor statements and comments before "#include". */
/** @violates @ref PORT_CFG_REF_2 Precautions to prevent the contents of a header file being included twice. */
#include "Port_MemMap.h"
/*=================================================================================================
*                                      GLOBAL VARIABLES
=================================================================================================*/

/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/

/*=================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/

/*=================================================================================================
*                                       GLOBAL FUNCTIONS
=================================================================================================*/

#ifdef __cplusplus
}
#endif
/** @} */

/* End of File */

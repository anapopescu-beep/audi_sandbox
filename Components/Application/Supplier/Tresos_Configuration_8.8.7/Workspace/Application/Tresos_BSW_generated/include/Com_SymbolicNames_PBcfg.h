#ifndef COM_SYMBOLIC_NAMES_PB_CFG_H
#define COM_SYMBOLIC_NAMES_PB_CFG_H

/**
 * \file
 *
 * \brief AUTOSAR Com
 *
 * This file contains the implementation of the AUTOSAR
 * module Com.
 *
 * \version 6.3.54
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[includes]==============================================*/
#include <Com_SymbolicNames_TDK_4G_PBcfg.h>

/*==================[macros]================================================*/

/* IPDU group ID defines */
#if (defined ComConf_ComIPduGroup_IPDUGroupIN_eCS) /* To prevent double declaration */
#error ComConf_ComIPduGroup_IPDUGroupIN_eCS already defined
#endif /* #if (defined ComConf_ComIPduGroup_IPDUGroupIN_eCS) */

#define ComConf_ComIPduGroup_IPDUGroupIN_eCS 0U


#if (defined ComConf_ComIPduGroup_IPDUGroupOUT_eCS) /* To prevent double declaration */
#error ComConf_ComIPduGroup_IPDUGroupOUT_eCS already defined
#endif /* #if (defined ComConf_ComIPduGroup_IPDUGroupOUT_eCS) */

#define ComConf_ComIPduGroup_IPDUGroupOUT_eCS 30U


#if (defined ComConf_ComIPduGroup_IPDUGroupOUT_eCS_Comm) /* To prevent double declaration */
#error ComConf_ComIPduGroup_IPDUGroupOUT_eCS_Comm already defined
#endif /* #if (defined ComConf_ComIPduGroup_IPDUGroupOUT_eCS_Comm) */

#define ComConf_ComIPduGroup_IPDUGroupOUT_eCS_Comm 31U


/* External Rx IPdus defines */
#if (defined ComConf_ComIPdu_PDipdu_Airbag_01_64R) /* To prevent double declaration */
#error ComConf_ComIPdu_PDipdu_Airbag_01_64R already defined
#endif /* #if (defined ComConf_ComIPdu_PDipdu_Airbag_01_64R) */

#define ComConf_ComIPdu_PDipdu_Airbag_01_64R 0U


#if (defined ComConf_ComIPdu_PDipdu_Airbag_02_1312R) /* To prevent double declaration */
#error ComConf_ComIPdu_PDipdu_Airbag_02_1312R already defined
#endif /* #if (defined ComConf_ComIPdu_PDipdu_Airbag_02_1312R) */

#define ComConf_ComIPdu_PDipdu_Airbag_02_1312R 1U


#if (defined ComConf_ComIPdu_PDipdu_Airbag_eCS_01_184112401R) /* To prevent double declaration */
#error ComConf_ComIPdu_PDipdu_Airbag_eCS_01_184112401R already defined
#endif /* #if (defined ComConf_ComIPdu_PDipdu_Airbag_eCS_01_184112401R) */

#define ComConf_ComIPdu_PDipdu_Airbag_eCS_01_184112401R 2U


#if (defined ComConf_ComIPdu_PDIPdu_Gliwa_In_300R) /* To prevent double declaration */
#error ComConf_ComIPdu_PDIPdu_Gliwa_In_300R already defined
#endif /* #if (defined ComConf_ComIPdu_PDIPdu_Gliwa_In_300R) */

#define ComConf_ComIPdu_PDIPdu_Gliwa_In_300R 3U


/* External Tx IPdu defines */
#if (defined ComConf_ComIPdu_PDIPdu_Gliwa_Out_200T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDIPdu_Gliwa_Out_200T already defined
#endif /* #if (defined ComConf_ComIPdu_PDIPdu_Gliwa_Out_200T) */

#define ComConf_ComIPdu_PDIPdu_Gliwa_Out_200T 0U


#if (defined ComConf_ComIPdu_PDIPdu_Dev_Out_0_256T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDIPdu_Dev_Out_0_256T already defined
#endif /* #if (defined ComConf_ComIPdu_PDIPdu_Dev_Out_0_256T) */

#define ComConf_ComIPdu_PDIPdu_Dev_Out_0_256T 1U


#if (defined ComConf_ComIPdu_PDIPdu_MFData_1988T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDIPdu_MFData_1988T already defined
#endif /* #if (defined ComConf_ComIPdu_PDIPdu_MFData_1988T) */

#define ComConf_ComIPdu_PDIPdu_MFData_1988T 2U


#if (defined ComConf_ComIPdu_PDIPdu_MFData_Logger_1989T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDIPdu_MFData_Logger_1989T already defined
#endif /* #if (defined ComConf_ComIPdu_PDIPdu_MFData_Logger_1989T) */

#define ComConf_ComIPdu_PDIPdu_MFData_Logger_1989T 3U


#if (defined ComConf_ComIPdu_PDipdu_eCS_01_184112400T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDipdu_eCS_01_184112400T already defined
#endif /* #if (defined ComConf_ComIPdu_PDipdu_eCS_01_184112400T) */

#define ComConf_ComIPdu_PDipdu_eCS_01_184112400T 4U


/* External Rx Signal IDs (no group signals) defines */
#if (defined ComConf_ComSignal_SGis_AB_Anzeige_Fussg1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_Anzeige_Fussg1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_Anzeige_Fussg1_64R) */

#define ComConf_ComSignal_SGis_AB_Anzeige_Fussg1_64R 0U


#if (defined ComConf_ComSignal_SGis_AB_Belegung_VF1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_Belegung_VF1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_Belegung_VF1_64R) */

#define ComConf_ComSignal_SGis_AB_Belegung_VF1_64R 1U


#if (defined ComConf_ComSignal_SGis_AB_Crash_Int1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_Crash_Int1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_Crash_Int1_64R) */

#define ComConf_ComSignal_SGis_AB_Crash_Int1_64R 2U


#if (defined ComConf_ComSignal_SGis_AB_Deaktiviert1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_Deaktiviert1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_Deaktiviert1_64R) */

#define ComConf_ComSignal_SGis_AB_Deaktiviert1_64R 3U


#if (defined ComConf_ComSignal_SGis_AB_Deaktivierung_HV1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_Deaktivierung_HV1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_Deaktivierung_HV1_64R) */

#define ComConf_ComSignal_SGis_AB_Deaktivierung_HV1_64R 4U


#if (defined ComConf_ComSignal_SGis_AB_Diagnose1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_Diagnose1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_Diagnose1_64R) */

#define ComConf_ComSignal_SGis_AB_Diagnose1_64R 5U


#if (defined ComConf_ComSignal_SGis_AB_EDR_Trigger1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_EDR_Trigger1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_EDR_Trigger1_64R) */

#define ComConf_ComSignal_SGis_AB_EDR_Trigger1_64R 6U


#if (defined ComConf_ComSignal_SGis_AB_Erh_Auf_VB1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_Erh_Auf_VB1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_Erh_Auf_VB1_64R) */

#define ComConf_ComSignal_SGis_AB_Erh_Auf_VB1_64R 7U


#if (defined ComConf_ComSignal_SGis_AB_Front_Crash1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_Front_Crash1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_Front_Crash1_64R) */

#define ComConf_ComSignal_SGis_AB_Front_Crash1_64R 8U


#if (defined ComConf_ComSignal_SGis_AB_Gurtschloss_FA_ext1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_Gurtschloss_FA_ext1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_Gurtschloss_FA_ext1_64R) */

#define ComConf_ComSignal_SGis_AB_Gurtschloss_FA_ext1_64R 9U


#if (defined ComConf_ComSignal_SGis_AB_Gurtschloss_FA_ext_aktiv1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_Gurtschloss_FA_ext_aktiv1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_Gurtschloss_FA_ext_aktiv1_64R) */

#define ComConf_ComSignal_SGis_AB_Gurtschloss_FA_ext_aktiv1_64R 10U


#if (defined ComConf_ComSignal_SGis_AB_Gurtwarn_VB1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_Gurtwarn_VB1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_Gurtwarn_VB1_64R) */

#define ComConf_ComSignal_SGis_AB_Gurtwarn_VB1_64R 11U


#if (defined ComConf_ComSignal_SGis_AB_Gurtwarn_VF1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_Gurtwarn_VF1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_Gurtwarn_VF1_64R) */

#define ComConf_ComSignal_SGis_AB_Gurtwarn_VF1_64R 12U


#if (defined ComConf_ComSignal_SGis_AB_Heck_Crash1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_Heck_Crash1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_Heck_Crash1_64R) */

#define ComConf_ComSignal_SGis_AB_Heck_Crash1_64R 13U


#if (defined ComConf_ComSignal_SGis_AB_Lampe1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_Lampe1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_Lampe1_64R) */

#define ComConf_ComSignal_SGis_AB_Lampe1_64R 14U


#if (defined ComConf_ComSignal_SGis_AB_MKB_Anforderung1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_MKB_Anforderung1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_MKB_Anforderung1_64R) */

#define ComConf_ComSignal_SGis_AB_MKB_Anforderung1_64R 15U


#if (defined ComConf_ComSignal_SGis_AB_MKB_gueltig1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_MKB_gueltig1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_MKB_gueltig1_64R) */

#define ComConf_ComSignal_SGis_AB_MKB_gueltig1_64R 16U


#if (defined ComConf_ComSignal_SGis_AB_PAO_Leuchte_Anf1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_PAO_Leuchte_Anf1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_PAO_Leuchte_Anf1_64R) */

#define ComConf_ComSignal_SGis_AB_PAO_Leuchte_Anf1_64R 17U


#if (defined ComConf_ComSignal_SGis_AB_RGS_Anst1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_RGS_Anst1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_RGS_Anst1_64R) */

#define ComConf_ComSignal_SGis_AB_RGS_Anst1_64R 18U


#if (defined ComConf_ComSignal_SGis_AB_Rollover_Crash1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_Rollover_Crash1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_Rollover_Crash1_64R) */

#define ComConf_ComSignal_SGis_AB_Rollover_Crash1_64R 19U


#if (defined ComConf_ComSignal_SGis_AB_SB_Crash1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_SB_Crash1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_SB_Crash1_64R) */

#define ComConf_ComSignal_SGis_AB_SB_Crash1_64R 20U


#if (defined ComConf_ComSignal_SGis_AB_SF_Crash1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_SF_Crash1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_SF_Crash1_64R) */

#define ComConf_ComSignal_SGis_AB_SF_Crash1_64R 21U


#if (defined ComConf_ComSignal_SGis_AB_Stellgliedtest1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_Stellgliedtest1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_Stellgliedtest1_64R) */

#define ComConf_ComSignal_SGis_AB_Stellgliedtest1_64R 22U


#if (defined ComConf_ComSignal_SGis_AB_Systemfehler1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_Systemfehler1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_Systemfehler1_64R) */

#define ComConf_ComSignal_SGis_AB_Systemfehler1_64R 23U


#if (defined ComConf_ComSignal_SGis_AB_Texte_AKS1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_Texte_AKS1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_Texte_AKS1_64R) */

#define ComConf_ComSignal_SGis_AB_Texte_AKS1_64R 24U


#if (defined ComConf_ComSignal_SGis_AB_VB_deaktiviert1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_VB_deaktiviert1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_VB_deaktiviert1_64R) */

#define ComConf_ComSignal_SGis_AB_VB_deaktiviert1_64R 25U


#if (defined ComConf_ComSignal_SGis_AB_Versorgungsspannung1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_Versorgungsspannung1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_Versorgungsspannung1_64R) */

#define ComConf_ComSignal_SGis_AB_Versorgungsspannung1_64R 26U


#if (defined ComConf_ComSignal_SGis_AB_eCS_Error1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_eCS_Error1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_eCS_Error1_64R) */

#define ComConf_ComSignal_SGis_AB_eCS_Error1_64R 27U


#if (defined ComConf_ComSignal_SGis_ASM_Masterzeit_021_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_ASM_Masterzeit_021_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_ASM_Masterzeit_021_64R) */

#define ComConf_ComSignal_SGis_ASM_Masterzeit_021_64R 28U


#if (defined ComConf_ComSignal_SGis_Airbag_01_BZ1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_Airbag_01_BZ1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_Airbag_01_BZ1_64R) */

#define ComConf_ComSignal_SGis_Airbag_01_BZ1_64R 29U


#if (defined ComConf_ComSignal_SGis_Airbag_01_CRC1_64R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_Airbag_01_CRC1_64R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_Airbag_01_CRC1_64R) */

#define ComConf_ComSignal_SGis_Airbag_01_CRC1_64R 30U


#if (defined ComConf_ComSignal_SGis_AB_Gurtschloss_BF1_1312R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_Gurtschloss_BF1_1312R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_Gurtschloss_BF1_1312R) */

#define ComConf_ComSignal_SGis_AB_Gurtschloss_BF1_1312R 31U


#if (defined ComConf_ComSignal_SGis_AB_Gurtschloss_FA1_1312R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_Gurtschloss_FA1_1312R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_Gurtschloss_FA1_1312R) */

#define ComConf_ComSignal_SGis_AB_Gurtschloss_FA1_1312R 32U


#if (defined ComConf_ComSignal_SGis_AB_Gurtschloss_Reihe2_BF1_1312R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_Gurtschloss_Reihe2_BF1_1312R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_Gurtschloss_Reihe2_BF1_1312R) */

#define ComConf_ComSignal_SGis_AB_Gurtschloss_Reihe2_BF1_1312R 33U


#if (defined ComConf_ComSignal_SGis_AB_Gurtschloss_Reihe2_FA1_1312R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_Gurtschloss_Reihe2_FA1_1312R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_Gurtschloss_Reihe2_FA1_1312R) */

#define ComConf_ComSignal_SGis_AB_Gurtschloss_Reihe2_FA1_1312R 34U


#if (defined ComConf_ComSignal_SGis_AB_Gurtschloss_Reihe3_BF1_1312R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_Gurtschloss_Reihe3_BF1_1312R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_Gurtschloss_Reihe3_BF1_1312R) */

#define ComConf_ComSignal_SGis_AB_Gurtschloss_Reihe3_BF1_1312R 35U


#if (defined ComConf_ComSignal_SGis_AB_Gurtschloss_Reihe3_FA1_1312R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_Gurtschloss_Reihe3_FA1_1312R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_Gurtschloss_Reihe3_FA1_1312R) */

#define ComConf_ComSignal_SGis_AB_Gurtschloss_Reihe3_FA1_1312R 36U


#if (defined ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_BF1_184112401R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_BF1_184112401R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_BF1_184112401R) */

#define ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_BF1_184112401R 37U


#if (defined ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_FA1_184112401R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_FA1_184112401R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_FA1_184112401R) */

#define ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_FA1_184112401R 38U


#if (defined ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_Reihe2_BF1_184112401R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_Reihe2_BF1_184112401R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_Reihe2_BF1_184112401R) */

#define ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_Reihe2_BF1_184112401R 39U


#if (defined ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_Reihe2_FA1_184112401R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_Reihe2_FA1_184112401R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_Reihe2_FA1_184112401R) */

#define ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_Reihe2_FA1_184112401R 40U


#if (defined ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_Reihe3_BF1_184112401R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_Reihe3_BF1_184112401R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_Reihe3_BF1_184112401R) */

#define ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_Reihe3_BF1_184112401R 41U


#if (defined ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_Reihe3_FA1_184112401R) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_Reihe3_FA1_184112401R already defined
#endif /* #if (defined ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_Reihe3_FA1_184112401R) */

#define ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_Reihe3_FA1_184112401R 42U


/* External Tx Signal IDs (no group signals) defines */
#if (defined ComConf_ComSignal_SGMF_Logger_Byte_0_1989T) /* To prevent double declaration */
#error ComConf_ComSignal_SGMF_Logger_Byte_0_1989T already defined
#endif /* #if (defined ComConf_ComSignal_SGMF_Logger_Byte_0_1989T) */

#define ComConf_ComSignal_SGMF_Logger_Byte_0_1989T 0U


#if (defined ComConf_ComSignal_SGis_eCS_Error_Reihe1_BFS_1_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Error_Reihe1_BFS_1_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Error_Reihe1_BFS_1_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Error_Reihe1_BFS_1_184112400T 1U


#if (defined ComConf_ComSignal_SGis_eCS_Error_Reihe1_BFS_2_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Error_Reihe1_BFS_2_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Error_Reihe1_BFS_2_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Error_Reihe1_BFS_2_184112400T 2U


#if (defined ComConf_ComSignal_SGis_eCS_Error_Reihe1_FS_1_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Error_Reihe1_FS_1_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Error_Reihe1_FS_1_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Error_Reihe1_FS_1_184112400T 3U


#if (defined ComConf_ComSignal_SGis_eCS_Error_Reihe1_FS_2_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Error_Reihe1_FS_2_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Error_Reihe1_FS_2_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Error_Reihe1_FS_2_184112400T 4U


#if (defined ComConf_ComSignal_SGis_eCS_Error_Reihe2_BFS_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Error_Reihe2_BFS_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Error_Reihe2_BFS_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Error_Reihe2_BFS_184112400T 5U


#if (defined ComConf_ComSignal_SGis_eCS_Error_Reihe2_FS_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Error_Reihe2_FS_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Error_Reihe2_FS_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Error_Reihe2_FS_184112400T 6U


#if (defined ComConf_ComSignal_SGis_eCS_SBS_LastState_Reihe2_BFS_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_SBS_LastState_Reihe2_BFS_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_SBS_LastState_Reihe2_BFS_184112400T) */

#define ComConf_ComSignal_SGis_eCS_SBS_LastState_Reihe2_BFS_184112400T 7U


#if (defined ComConf_ComSignal_SGis_eCS_SBS_LastState_Reihe2_FS_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_SBS_LastState_Reihe2_FS_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_SBS_LastState_Reihe2_FS_184112400T) */

#define ComConf_ComSignal_SGis_eCS_SBS_LastState_Reihe2_FS_184112400T 8U


#if (defined ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_BFS_1_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_BFS_1_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_BFS_1_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_BFS_1_184112400T 9U


#if (defined ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_BFS_2_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_BFS_2_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_BFS_2_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_BFS_2_184112400T 10U


#if (defined ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_FS_1_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_FS_1_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_FS_1_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_FS_1_184112400T 11U


#if (defined ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_FS_2_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_FS_2_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_FS_2_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_FS_2_184112400T 12U


#if (defined ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe2_BFS_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe2_BFS_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe2_BFS_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe2_BFS_184112400T 13U


#if (defined ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe2_FS_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe2_FS_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe2_FS_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe2_FS_184112400T 14U


#if (defined ComConf_ComSignal_SGis_eCS_Gurtschloss_Status_Reihe2_BF1_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Gurtschloss_Status_Reihe2_BF1_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Gurtschloss_Status_Reihe2_BF1_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Gurtschloss_Status_Reihe2_BF1_184112400T 15U


#if (defined ComConf_ComSignal_SGis_eCS_Gurtschloss_Status_Reihe2_FA1_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Gurtschloss_Status_Reihe2_FA1_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Gurtschloss_Status_Reihe2_FA1_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Gurtschloss_Status_Reihe2_FA1_184112400T 16U


#if (defined ComConf_ComSignal_SGis_eCS_HW_defekt1_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_HW_defekt1_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_HW_defekt1_184112400T) */

#define ComConf_ComSignal_SGis_eCS_HW_defekt1_184112400T 17U


#if (defined ComConf_ComSignal_SGis_eCS_SBS_Belegung_Reihe2_BF1_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_SBS_Belegung_Reihe2_BF1_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_SBS_Belegung_Reihe2_BF1_184112400T) */

#define ComConf_ComSignal_SGis_eCS_SBS_Belegung_Reihe2_BF1_184112400T 18U


#if (defined ComConf_ComSignal_SGis_eCS_SBS_Belegung_Reihe2_FA1_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_SBS_Belegung_Reihe2_FA1_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_SBS_Belegung_Reihe2_FA1_184112400T) */

#define ComConf_ComSignal_SGis_eCS_SBS_Belegung_Reihe2_FA1_184112400T 19U


#if (defined ComConf_ComSignal_SGis_eCS_Status1_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Status1_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Status1_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Status1_184112400T 20U


#if (defined ComConf_ComSignal_SGis_eCS_Stoerung1_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Stoerung1_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Stoerung1_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Stoerung1_184112400T 21U


/* External Rx Group Signal IDs defines */
#if (defined ComConf_ComGroupSignal_GliwaIn_Byte_0_300R) /* To prevent double declaration */
#error ComConf_ComGroupSignal_GliwaIn_Byte_0_300R already defined
#endif /* #if (defined ComConf_ComGroupSignal_GliwaIn_Byte_0_300R) */

#define ComConf_ComGroupSignal_GliwaIn_Byte_0_300R 43U


#if (defined ComConf_ComGroupSignal_GliwaIn_Byte_1_300R) /* To prevent double declaration */
#error ComConf_ComGroupSignal_GliwaIn_Byte_1_300R already defined
#endif /* #if (defined ComConf_ComGroupSignal_GliwaIn_Byte_1_300R) */

#define ComConf_ComGroupSignal_GliwaIn_Byte_1_300R 44U


#if (defined ComConf_ComGroupSignal_GliwaIn_Byte_2_300R) /* To prevent double declaration */
#error ComConf_ComGroupSignal_GliwaIn_Byte_2_300R already defined
#endif /* #if (defined ComConf_ComGroupSignal_GliwaIn_Byte_2_300R) */

#define ComConf_ComGroupSignal_GliwaIn_Byte_2_300R 45U


#if (defined ComConf_ComGroupSignal_GliwaIn_Byte_3_300R) /* To prevent double declaration */
#error ComConf_ComGroupSignal_GliwaIn_Byte_3_300R already defined
#endif /* #if (defined ComConf_ComGroupSignal_GliwaIn_Byte_3_300R) */

#define ComConf_ComGroupSignal_GliwaIn_Byte_3_300R 46U


#if (defined ComConf_ComGroupSignal_GliwaIn_Byte_4_300R) /* To prevent double declaration */
#error ComConf_ComGroupSignal_GliwaIn_Byte_4_300R already defined
#endif /* #if (defined ComConf_ComGroupSignal_GliwaIn_Byte_4_300R) */

#define ComConf_ComGroupSignal_GliwaIn_Byte_4_300R 47U


#if (defined ComConf_ComGroupSignal_GliwaIn_Byte_5_300R) /* To prevent double declaration */
#error ComConf_ComGroupSignal_GliwaIn_Byte_5_300R already defined
#endif /* #if (defined ComConf_ComGroupSignal_GliwaIn_Byte_5_300R) */

#define ComConf_ComGroupSignal_GliwaIn_Byte_5_300R 48U


#if (defined ComConf_ComGroupSignal_GliwaIn_Byte_6_300R) /* To prevent double declaration */
#error ComConf_ComGroupSignal_GliwaIn_Byte_6_300R already defined
#endif /* #if (defined ComConf_ComGroupSignal_GliwaIn_Byte_6_300R) */

#define ComConf_ComGroupSignal_GliwaIn_Byte_6_300R 49U


#if (defined ComConf_ComGroupSignal_GliwaIn_Byte_7_300R) /* To prevent double declaration */
#error ComConf_ComGroupSignal_GliwaIn_Byte_7_300R already defined
#endif /* #if (defined ComConf_ComGroupSignal_GliwaIn_Byte_7_300R) */

#define ComConf_ComGroupSignal_GliwaIn_Byte_7_300R 50U


/* External Tx Group Signal IDs defines */
#if (defined ComConf_ComGroupSignal_DataOut_Byte_0_7_256T) /* To prevent double declaration */
#error ComConf_ComGroupSignal_DataOut_Byte_0_7_256T already defined
#endif /* #if (defined ComConf_ComGroupSignal_DataOut_Byte_0_7_256T) */

#define ComConf_ComGroupSignal_DataOut_Byte_0_7_256T 22U


#if (defined ComConf_ComGroupSignal_DataOut_Byte_16_23_256T) /* To prevent double declaration */
#error ComConf_ComGroupSignal_DataOut_Byte_16_23_256T already defined
#endif /* #if (defined ComConf_ComGroupSignal_DataOut_Byte_16_23_256T) */

#define ComConf_ComGroupSignal_DataOut_Byte_16_23_256T 23U


#if (defined ComConf_ComGroupSignal_DataOut_Byte_24_31_256T) /* To prevent double declaration */
#error ComConf_ComGroupSignal_DataOut_Byte_24_31_256T already defined
#endif /* #if (defined ComConf_ComGroupSignal_DataOut_Byte_24_31_256T) */

#define ComConf_ComGroupSignal_DataOut_Byte_24_31_256T 24U


#if (defined ComConf_ComGroupSignal_DataOut_Byte_32_39_256T) /* To prevent double declaration */
#error ComConf_ComGroupSignal_DataOut_Byte_32_39_256T already defined
#endif /* #if (defined ComConf_ComGroupSignal_DataOut_Byte_32_39_256T) */

#define ComConf_ComGroupSignal_DataOut_Byte_32_39_256T 25U


#if (defined ComConf_ComGroupSignal_DataOut_Byte_40_47_256T) /* To prevent double declaration */
#error ComConf_ComGroupSignal_DataOut_Byte_40_47_256T already defined
#endif /* #if (defined ComConf_ComGroupSignal_DataOut_Byte_40_47_256T) */

#define ComConf_ComGroupSignal_DataOut_Byte_40_47_256T 26U


#if (defined ComConf_ComGroupSignal_DataOut_Byte_48_55_256T) /* To prevent double declaration */
#error ComConf_ComGroupSignal_DataOut_Byte_48_55_256T already defined
#endif /* #if (defined ComConf_ComGroupSignal_DataOut_Byte_48_55_256T) */

#define ComConf_ComGroupSignal_DataOut_Byte_48_55_256T 27U


#if (defined ComConf_ComGroupSignal_DataOut_Byte_56_63_256T) /* To prevent double declaration */
#error ComConf_ComGroupSignal_DataOut_Byte_56_63_256T already defined
#endif /* #if (defined ComConf_ComGroupSignal_DataOut_Byte_56_63_256T) */

#define ComConf_ComGroupSignal_DataOut_Byte_56_63_256T 28U


#if (defined ComConf_ComGroupSignal_DataOut_Byte_8_15_256T) /* To prevent double declaration */
#error ComConf_ComGroupSignal_DataOut_Byte_8_15_256T already defined
#endif /* #if (defined ComConf_ComGroupSignal_DataOut_Byte_8_15_256T) */

#define ComConf_ComGroupSignal_DataOut_Byte_8_15_256T 29U


#if (defined ComConf_ComGroupSignal_MF_Byte_0_7_1988T) /* To prevent double declaration */
#error ComConf_ComGroupSignal_MF_Byte_0_7_1988T already defined
#endif /* #if (defined ComConf_ComGroupSignal_MF_Byte_0_7_1988T) */

#define ComConf_ComGroupSignal_MF_Byte_0_7_1988T 30U


#if (defined ComConf_ComGroupSignal_MF_Byte_16_23_1988T) /* To prevent double declaration */
#error ComConf_ComGroupSignal_MF_Byte_16_23_1988T already defined
#endif /* #if (defined ComConf_ComGroupSignal_MF_Byte_16_23_1988T) */

#define ComConf_ComGroupSignal_MF_Byte_16_23_1988T 31U


#if (defined ComConf_ComGroupSignal_MF_Byte_24_31_1988T) /* To prevent double declaration */
#error ComConf_ComGroupSignal_MF_Byte_24_31_1988T already defined
#endif /* #if (defined ComConf_ComGroupSignal_MF_Byte_24_31_1988T) */

#define ComConf_ComGroupSignal_MF_Byte_24_31_1988T 32U


#if (defined ComConf_ComGroupSignal_MF_Byte_32_39_1988T) /* To prevent double declaration */
#error ComConf_ComGroupSignal_MF_Byte_32_39_1988T already defined
#endif /* #if (defined ComConf_ComGroupSignal_MF_Byte_32_39_1988T) */

#define ComConf_ComGroupSignal_MF_Byte_32_39_1988T 33U


#if (defined ComConf_ComGroupSignal_MF_Byte_40_47_1988T) /* To prevent double declaration */
#error ComConf_ComGroupSignal_MF_Byte_40_47_1988T already defined
#endif /* #if (defined ComConf_ComGroupSignal_MF_Byte_40_47_1988T) */

#define ComConf_ComGroupSignal_MF_Byte_40_47_1988T 34U


#if (defined ComConf_ComGroupSignal_MF_Byte_48_55_1988T) /* To prevent double declaration */
#error ComConf_ComGroupSignal_MF_Byte_48_55_1988T already defined
#endif /* #if (defined ComConf_ComGroupSignal_MF_Byte_48_55_1988T) */

#define ComConf_ComGroupSignal_MF_Byte_48_55_1988T 35U


#if (defined ComConf_ComGroupSignal_MF_Byte_56_63_1988T) /* To prevent double declaration */
#error ComConf_ComGroupSignal_MF_Byte_56_63_1988T already defined
#endif /* #if (defined ComConf_ComGroupSignal_MF_Byte_56_63_1988T) */

#define ComConf_ComGroupSignal_MF_Byte_56_63_1988T 36U


#if (defined ComConf_ComGroupSignal_MF_Byte_8_15_1988T) /* To prevent double declaration */
#error ComConf_ComGroupSignal_MF_Byte_8_15_1988T already defined
#endif /* #if (defined ComConf_ComGroupSignal_MF_Byte_8_15_1988T) */

#define ComConf_ComGroupSignal_MF_Byte_8_15_1988T 37U


#if (defined ComConf_ComGroupSignal_GliwaOut_Byte_0_7_200T) /* To prevent double declaration */
#error ComConf_ComGroupSignal_GliwaOut_Byte_0_7_200T already defined
#endif /* #if (defined ComConf_ComGroupSignal_GliwaOut_Byte_0_7_200T) */

#define ComConf_ComGroupSignal_GliwaOut_Byte_0_7_200T 38U


#if (defined ComConf_ComGroupSignal_GliwaOut_Byte_16_23_200T) /* To prevent double declaration */
#error ComConf_ComGroupSignal_GliwaOut_Byte_16_23_200T already defined
#endif /* #if (defined ComConf_ComGroupSignal_GliwaOut_Byte_16_23_200T) */

#define ComConf_ComGroupSignal_GliwaOut_Byte_16_23_200T 39U


#if (defined ComConf_ComGroupSignal_GliwaOut_Byte_24_31_200T) /* To prevent double declaration */
#error ComConf_ComGroupSignal_GliwaOut_Byte_24_31_200T already defined
#endif /* #if (defined ComConf_ComGroupSignal_GliwaOut_Byte_24_31_200T) */

#define ComConf_ComGroupSignal_GliwaOut_Byte_24_31_200T 40U


#if (defined ComConf_ComGroupSignal_GliwaOut_Byte_32_39_200T) /* To prevent double declaration */
#error ComConf_ComGroupSignal_GliwaOut_Byte_32_39_200T already defined
#endif /* #if (defined ComConf_ComGroupSignal_GliwaOut_Byte_32_39_200T) */

#define ComConf_ComGroupSignal_GliwaOut_Byte_32_39_200T 41U


#if (defined ComConf_ComGroupSignal_GliwaOut_Byte_40_47_200T) /* To prevent double declaration */
#error ComConf_ComGroupSignal_GliwaOut_Byte_40_47_200T already defined
#endif /* #if (defined ComConf_ComGroupSignal_GliwaOut_Byte_40_47_200T) */

#define ComConf_ComGroupSignal_GliwaOut_Byte_40_47_200T 42U


#if (defined ComConf_ComGroupSignal_GliwaOut_Byte_48_55_200T) /* To prevent double declaration */
#error ComConf_ComGroupSignal_GliwaOut_Byte_48_55_200T already defined
#endif /* #if (defined ComConf_ComGroupSignal_GliwaOut_Byte_48_55_200T) */

#define ComConf_ComGroupSignal_GliwaOut_Byte_48_55_200T 43U


#if (defined ComConf_ComGroupSignal_GliwaOut_Byte_56_63_200T) /* To prevent double declaration */
#error ComConf_ComGroupSignal_GliwaOut_Byte_56_63_200T already defined
#endif /* #if (defined ComConf_ComGroupSignal_GliwaOut_Byte_56_63_200T) */

#define ComConf_ComGroupSignal_GliwaOut_Byte_56_63_200T 44U


#if (defined ComConf_ComGroupSignal_GliwaOut_Byte_8_15_200T) /* To prevent double declaration */
#error ComConf_ComGroupSignal_GliwaOut_Byte_8_15_200T already defined
#endif /* #if (defined ComConf_ComGroupSignal_GliwaOut_Byte_8_15_200T) */

#define ComConf_ComGroupSignal_GliwaOut_Byte_8_15_200T 45U


/* External Rx Signal Group IDs defines */
#if (defined ComConf_ComSignalGroup_GRGliwaInGroup_300R) /* To prevent double declaration */
#error ComConf_ComSignalGroup_GRGliwaInGroup_300R already defined
#endif /* #if (defined ComConf_ComSignalGroup_GRGliwaInGroup_300R) */

#define ComConf_ComSignalGroup_GRGliwaInGroup_300R 0U


/* External Tx Signal Group IDs defines */
#if (defined ComConf_ComSignalGroup_GRDataOutSignalGroup_0_256T) /* To prevent double declaration */
#error ComConf_ComSignalGroup_GRDataOutSignalGroup_0_256T already defined
#endif /* #if (defined ComConf_ComSignalGroup_GRDataOutSignalGroup_0_256T) */

#define ComConf_ComSignalGroup_GRDataOutSignalGroup_0_256T 0U


#if (defined ComConf_ComSignalGroup_GRMeasurementFrameGroup_1988T) /* To prevent double declaration */
#error ComConf_ComSignalGroup_GRMeasurementFrameGroup_1988T already defined
#endif /* #if (defined ComConf_ComSignalGroup_GRMeasurementFrameGroup_1988T) */

#define ComConf_ComSignalGroup_GRMeasurementFrameGroup_1988T 1U


#if (defined ComConf_ComSignalGroup_GRGliwaOutGroup_200T) /* To prevent double declaration */
#error ComConf_ComSignalGroup_GRGliwaOutGroup_200T already defined
#endif /* #if (defined ComConf_ComSignalGroup_GRGliwaOutGroup_200T) */

#define ComConf_ComSignalGroup_GRGliwaOutGroup_200T 2U



/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
#endif /* ifndef COM_SYMBOLIC_NAMES_PB_CFG_H  */
/*==================[end of file]===========================================*/

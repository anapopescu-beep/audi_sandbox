#if (!defined COM_SYMBOLIC_NAMES_PB_CFG_H)
#define COM_SYMBOLIC_NAMES_PB_CFG_H

/**
 * \file
 *
 * \brief AUTOSAR Com
 *
 * This file contains the implementation of the AUTOSAR
 * module Com.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
/*==================[includes]==============================================*/

/*==================[macros]================================================*/

/* IPDU group ID defines */
#if (defined ComConf_ComIPduGroup_IPDUGroupIN_eCS) /* To prevent double declaration */
#error ComConf_ComIPduGroup_IPDUGroupIN_eCS already defined
#endif /* #if (defined ComConf_ComIPduGroup_IPDUGroupIN_eCS) */

#define ComConf_ComIPduGroup_IPDUGroupIN_eCS 0U


#if (defined ComConf_ComIPduGroup_IPDUGroupOUT_eCS) /* To prevent double declaration */
#error ComConf_ComIPduGroup_IPDUGroupOUT_eCS already defined
#endif /* #if (defined ComConf_ComIPduGroup_IPDUGroupOUT_eCS) */

#define ComConf_ComIPduGroup_IPDUGroupOUT_eCS 1U


#if (defined ComConf_ComIPduGroup_IPDUGroupOUT_eCS_Comm) /* To prevent double declaration */
#error ComConf_ComIPduGroup_IPDUGroupOUT_eCS_Comm already defined
#endif /* #if (defined ComConf_ComIPduGroup_IPDUGroupOUT_eCS_Comm) */

#define ComConf_ComIPduGroup_IPDUGroupOUT_eCS_Comm 2U


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
#if (defined ComConf_ComSignal_SGis_eCS_Gurtschloss_Status_Reihe2_BF1_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Gurtschloss_Status_Reihe2_BF1_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Gurtschloss_Status_Reihe2_BF1_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Gurtschloss_Status_Reihe2_BF1_184112400T 0U


#if (defined ComConf_ComSignal_SGis_eCS_Gurtschloss_Status_Reihe2_FA1_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Gurtschloss_Status_Reihe2_FA1_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Gurtschloss_Status_Reihe2_FA1_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Gurtschloss_Status_Reihe2_FA1_184112400T 1U


#if (defined ComConf_ComSignal_SGis_eCS_HW_defekt1_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_HW_defekt1_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_HW_defekt1_184112400T) */

#define ComConf_ComSignal_SGis_eCS_HW_defekt1_184112400T 2U


#if (defined ComConf_ComSignal_SGis_eCS_SBS_Belegung_Reihe2_BF1_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_SBS_Belegung_Reihe2_BF1_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_SBS_Belegung_Reihe2_BF1_184112400T) */

#define ComConf_ComSignal_SGis_eCS_SBS_Belegung_Reihe2_BF1_184112400T 3U


#if (defined ComConf_ComSignal_SGis_eCS_SBS_Belegung_Reihe2_FA1_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_SBS_Belegung_Reihe2_FA1_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_SBS_Belegung_Reihe2_FA1_184112400T) */

#define ComConf_ComSignal_SGis_eCS_SBS_Belegung_Reihe2_FA1_184112400T 4U


#if (defined ComConf_ComSignal_SGis_eCS_Status1_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Status1_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Status1_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Status1_184112400T 5U


#if (defined ComConf_ComSignal_SGis_eCS_Stoerung1_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Stoerung1_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Stoerung1_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Stoerung1_184112400T 6U


#if (defined ComConf_ComSignal_SGis_eCS_MF_Logger_Byte_1989T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_MF_Logger_Byte_1989T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_MF_Logger_Byte_1989T) */

#define ComConf_ComSignal_SGis_eCS_MF_Logger_Byte_1989T 7U


#if (defined ComConf_ComSignal_SGis_eCS_Error_Reihe1_BFS_1_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Error_Reihe1_BFS_1_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Error_Reihe1_BFS_1_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Error_Reihe1_BFS_1_184112400T 8U


#if (defined ComConf_ComSignal_SGis_eCS_Error_Reihe1_BFS_2_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Error_Reihe1_BFS_2_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Error_Reihe1_BFS_2_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Error_Reihe1_BFS_2_184112400T 9U


#if (defined ComConf_ComSignal_SGis_eCS_Error_Reihe1_FS_1_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Error_Reihe1_FS_1_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Error_Reihe1_FS_1_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Error_Reihe1_FS_1_184112400T 10U


#if (defined ComConf_ComSignal_SGis_eCS_Error_Reihe1_FS_2_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Error_Reihe1_FS_2_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Error_Reihe1_FS_2_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Error_Reihe1_FS_2_184112400T 11U


#if (defined ComConf_ComSignal_SGis_eCS_Error_Reihe2_BFS_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Error_Reihe2_BFS_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Error_Reihe2_BFS_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Error_Reihe2_BFS_184112400T 12U


#if (defined ComConf_ComSignal_SGis_eCS_Error_Reihe2_FS_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Error_Reihe2_FS_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Error_Reihe2_FS_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Error_Reihe2_FS_184112400T 13U


#if (defined ComConf_ComSignal_SGis_eCS_SBS_LastState_Reihe2_BFS_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_SBS_LastState_Reihe2_BFS_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_SBS_LastState_Reihe2_BFS_184112400T) */

#define ComConf_ComSignal_SGis_eCS_SBS_LastState_Reihe2_BFS_184112400T 14U


#if (defined ComConf_ComSignal_SGis_eCS_SBS_LastState_Reihe2_FS_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_SBS_LastState_Reihe2_FS_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_SBS_LastState_Reihe2_FS_184112400T) */

#define ComConf_ComSignal_SGis_eCS_SBS_LastState_Reihe2_FS_184112400T 15U


#if (defined ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_BFS_1_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_BFS_1_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_BFS_1_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_BFS_1_184112400T 16U


#if (defined ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_BFS_2_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_BFS_2_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_BFS_2_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_BFS_2_184112400T 17U


#if (defined ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_FS_1_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_FS_1_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_FS_1_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_FS_1_184112400T 18U


#if (defined ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_FS_2_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_FS_2_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_FS_2_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_FS_2_184112400T 19U


#if (defined ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe2_BFS_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe2_BFS_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe2_BFS_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe2_BFS_184112400T 20U


#if (defined ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe2_FS_184112400T) /* To prevent double declaration */
#error ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe2_FS_184112400T already defined
#endif /* #if (defined ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe2_FS_184112400T) */

#define ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe2_FS_184112400T 21U


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



/*------------------[symbols without prefix for backward compatibility]-----*/
#if (defined COM_PROVIDE_LEGACY_SYMBOLIC_NAMES)

/* IPDU group ID defines */

#if (defined Com_IPDUGroupIN_eCS) /* To prevent double declaration */
#error Com_IPDUGroupIN_eCS already defined
#endif /* #if (defined Com_IPDUGroupIN_eCS) */

#define Com_IPDUGroupIN_eCS ComConf_ComIPduGroup_IPDUGroupIN_eCS



#if (defined Com_IPDUGroupOUT_eCS) /* To prevent double declaration */
#error Com_IPDUGroupOUT_eCS already defined
#endif /* #if (defined Com_IPDUGroupOUT_eCS) */

#define Com_IPDUGroupOUT_eCS ComConf_ComIPduGroup_IPDUGroupOUT_eCS



#if (defined Com_IPDUGroupOUT_eCS_Comm) /* To prevent double declaration */
#error Com_IPDUGroupOUT_eCS_Comm already defined
#endif /* #if (defined Com_IPDUGroupOUT_eCS_Comm) */

#define Com_IPDUGroupOUT_eCS_Comm ComConf_ComIPduGroup_IPDUGroupOUT_eCS_Comm


/* External Rx IPdus defines */
#if (defined Com_PDipdu_Airbag_01_64R) /* To prevent double declaration */
#error Com_PDipdu_Airbag_01_64R already defined
#endif /* #if (defined Com_PDipdu_Airbag_01_64R) */

#define Com_PDipdu_Airbag_01_64R ComConf_ComIPdu_PDipdu_Airbag_01_64R


#if (defined Com_PDipdu_Airbag_02_1312R) /* To prevent double declaration */
#error Com_PDipdu_Airbag_02_1312R already defined
#endif /* #if (defined Com_PDipdu_Airbag_02_1312R) */

#define Com_PDipdu_Airbag_02_1312R ComConf_ComIPdu_PDipdu_Airbag_02_1312R


#if (defined Com_PDipdu_Airbag_eCS_01_184112401R) /* To prevent double declaration */
#error Com_PDipdu_Airbag_eCS_01_184112401R already defined
#endif /* #if (defined Com_PDipdu_Airbag_eCS_01_184112401R) */

#define Com_PDipdu_Airbag_eCS_01_184112401R ComConf_ComIPdu_PDipdu_Airbag_eCS_01_184112401R


#if (defined Com_PDIPdu_Gliwa_In_300R) /* To prevent double declaration */
#error Com_PDIPdu_Gliwa_In_300R already defined
#endif /* #if (defined Com_PDIPdu_Gliwa_In_300R) */

#define Com_PDIPdu_Gliwa_In_300R ComConf_ComIPdu_PDIPdu_Gliwa_In_300R


/* External Tx IPdu defines */
#if (defined Com_PDIPdu_Gliwa_Out_200T) /* To prevent double declaration */
#error Com_PDIPdu_Gliwa_Out_200T already defined
#endif /* #if (defined Com_PDIPdu_Gliwa_Out_200T) */

#define Com_PDIPdu_Gliwa_Out_200T ComConf_ComIPdu_PDIPdu_Gliwa_Out_200T


#if (defined Com_PDIPdu_Dev_Out_0_256T) /* To prevent double declaration */
#error Com_PDIPdu_Dev_Out_0_256T already defined
#endif /* #if (defined Com_PDIPdu_Dev_Out_0_256T) */

#define Com_PDIPdu_Dev_Out_0_256T ComConf_ComIPdu_PDIPdu_Dev_Out_0_256T


#if (defined Com_PDIPdu_MFData_1988T) /* To prevent double declaration */
#error Com_PDIPdu_MFData_1988T already defined
#endif /* #if (defined Com_PDIPdu_MFData_1988T) */

#define Com_PDIPdu_MFData_1988T ComConf_ComIPdu_PDIPdu_MFData_1988T


#if (defined Com_PDIPdu_MFData_Logger_1989T) /* To prevent double declaration */
#error Com_PDIPdu_MFData_Logger_1989T already defined
#endif /* #if (defined Com_PDIPdu_MFData_Logger_1989T) */

#define Com_PDIPdu_MFData_Logger_1989T ComConf_ComIPdu_PDIPdu_MFData_Logger_1989T


#if (defined Com_PDipdu_eCS_01_184112400T) /* To prevent double declaration */
#error Com_PDipdu_eCS_01_184112400T already defined
#endif /* #if (defined Com_PDipdu_eCS_01_184112400T) */

#define Com_PDipdu_eCS_01_184112400T ComConf_ComIPdu_PDipdu_eCS_01_184112400T


/* External Rx Signal IDs (no group signals) defines */
#if (defined Com_SGis_AB_Anzeige_Fussg1_64R) /* To prevent double declaration */
#error Com_SGis_AB_Anzeige_Fussg1_64R already defined
#endif /* #if (defined Com_SGis_AB_Anzeige_Fussg1_64R) */

#define Com_SGis_AB_Anzeige_Fussg1_64R ComConf_ComSignal_SGis_AB_Anzeige_Fussg1_64R


#if (defined Com_SGis_AB_Belegung_VF1_64R) /* To prevent double declaration */
#error Com_SGis_AB_Belegung_VF1_64R already defined
#endif /* #if (defined Com_SGis_AB_Belegung_VF1_64R) */

#define Com_SGis_AB_Belegung_VF1_64R ComConf_ComSignal_SGis_AB_Belegung_VF1_64R


#if (defined Com_SGis_AB_Crash_Int1_64R) /* To prevent double declaration */
#error Com_SGis_AB_Crash_Int1_64R already defined
#endif /* #if (defined Com_SGis_AB_Crash_Int1_64R) */

#define Com_SGis_AB_Crash_Int1_64R ComConf_ComSignal_SGis_AB_Crash_Int1_64R


#if (defined Com_SGis_AB_Deaktiviert1_64R) /* To prevent double declaration */
#error Com_SGis_AB_Deaktiviert1_64R already defined
#endif /* #if (defined Com_SGis_AB_Deaktiviert1_64R) */

#define Com_SGis_AB_Deaktiviert1_64R ComConf_ComSignal_SGis_AB_Deaktiviert1_64R


#if (defined Com_SGis_AB_Deaktivierung_HV1_64R) /* To prevent double declaration */
#error Com_SGis_AB_Deaktivierung_HV1_64R already defined
#endif /* #if (defined Com_SGis_AB_Deaktivierung_HV1_64R) */

#define Com_SGis_AB_Deaktivierung_HV1_64R ComConf_ComSignal_SGis_AB_Deaktivierung_HV1_64R


#if (defined Com_SGis_AB_Diagnose1_64R) /* To prevent double declaration */
#error Com_SGis_AB_Diagnose1_64R already defined
#endif /* #if (defined Com_SGis_AB_Diagnose1_64R) */

#define Com_SGis_AB_Diagnose1_64R ComConf_ComSignal_SGis_AB_Diagnose1_64R


#if (defined Com_SGis_AB_EDR_Trigger1_64R) /* To prevent double declaration */
#error Com_SGis_AB_EDR_Trigger1_64R already defined
#endif /* #if (defined Com_SGis_AB_EDR_Trigger1_64R) */

#define Com_SGis_AB_EDR_Trigger1_64R ComConf_ComSignal_SGis_AB_EDR_Trigger1_64R


#if (defined Com_SGis_AB_Erh_Auf_VB1_64R) /* To prevent double declaration */
#error Com_SGis_AB_Erh_Auf_VB1_64R already defined
#endif /* #if (defined Com_SGis_AB_Erh_Auf_VB1_64R) */

#define Com_SGis_AB_Erh_Auf_VB1_64R ComConf_ComSignal_SGis_AB_Erh_Auf_VB1_64R


#if (defined Com_SGis_AB_Front_Crash1_64R) /* To prevent double declaration */
#error Com_SGis_AB_Front_Crash1_64R already defined
#endif /* #if (defined Com_SGis_AB_Front_Crash1_64R) */

#define Com_SGis_AB_Front_Crash1_64R ComConf_ComSignal_SGis_AB_Front_Crash1_64R


#if (defined Com_SGis_AB_Gurtschloss_FA_ext1_64R) /* To prevent double declaration */
#error Com_SGis_AB_Gurtschloss_FA_ext1_64R already defined
#endif /* #if (defined Com_SGis_AB_Gurtschloss_FA_ext1_64R) */

#define Com_SGis_AB_Gurtschloss_FA_ext1_64R ComConf_ComSignal_SGis_AB_Gurtschloss_FA_ext1_64R


#if (defined Com_SGis_AB_Gurtschloss_FA_ext_aktiv1_64R) /* To prevent double declaration */
#error Com_SGis_AB_Gurtschloss_FA_ext_aktiv1_64R already defined
#endif /* #if (defined Com_SGis_AB_Gurtschloss_FA_ext_aktiv1_64R) */

#define Com_SGis_AB_Gurtschloss_FA_ext_aktiv1_64R ComConf_ComSignal_SGis_AB_Gurtschloss_FA_ext_aktiv1_64R


#if (defined Com_SGis_AB_Gurtwarn_VB1_64R) /* To prevent double declaration */
#error Com_SGis_AB_Gurtwarn_VB1_64R already defined
#endif /* #if (defined Com_SGis_AB_Gurtwarn_VB1_64R) */

#define Com_SGis_AB_Gurtwarn_VB1_64R ComConf_ComSignal_SGis_AB_Gurtwarn_VB1_64R


#if (defined Com_SGis_AB_Gurtwarn_VF1_64R) /* To prevent double declaration */
#error Com_SGis_AB_Gurtwarn_VF1_64R already defined
#endif /* #if (defined Com_SGis_AB_Gurtwarn_VF1_64R) */

#define Com_SGis_AB_Gurtwarn_VF1_64R ComConf_ComSignal_SGis_AB_Gurtwarn_VF1_64R


#if (defined Com_SGis_AB_Heck_Crash1_64R) /* To prevent double declaration */
#error Com_SGis_AB_Heck_Crash1_64R already defined
#endif /* #if (defined Com_SGis_AB_Heck_Crash1_64R) */

#define Com_SGis_AB_Heck_Crash1_64R ComConf_ComSignal_SGis_AB_Heck_Crash1_64R


#if (defined Com_SGis_AB_Lampe1_64R) /* To prevent double declaration */
#error Com_SGis_AB_Lampe1_64R already defined
#endif /* #if (defined Com_SGis_AB_Lampe1_64R) */

#define Com_SGis_AB_Lampe1_64R ComConf_ComSignal_SGis_AB_Lampe1_64R


#if (defined Com_SGis_AB_MKB_Anforderung1_64R) /* To prevent double declaration */
#error Com_SGis_AB_MKB_Anforderung1_64R already defined
#endif /* #if (defined Com_SGis_AB_MKB_Anforderung1_64R) */

#define Com_SGis_AB_MKB_Anforderung1_64R ComConf_ComSignal_SGis_AB_MKB_Anforderung1_64R


#if (defined Com_SGis_AB_MKB_gueltig1_64R) /* To prevent double declaration */
#error Com_SGis_AB_MKB_gueltig1_64R already defined
#endif /* #if (defined Com_SGis_AB_MKB_gueltig1_64R) */

#define Com_SGis_AB_MKB_gueltig1_64R ComConf_ComSignal_SGis_AB_MKB_gueltig1_64R


#if (defined Com_SGis_AB_PAO_Leuchte_Anf1_64R) /* To prevent double declaration */
#error Com_SGis_AB_PAO_Leuchte_Anf1_64R already defined
#endif /* #if (defined Com_SGis_AB_PAO_Leuchte_Anf1_64R) */

#define Com_SGis_AB_PAO_Leuchte_Anf1_64R ComConf_ComSignal_SGis_AB_PAO_Leuchte_Anf1_64R


#if (defined Com_SGis_AB_RGS_Anst1_64R) /* To prevent double declaration */
#error Com_SGis_AB_RGS_Anst1_64R already defined
#endif /* #if (defined Com_SGis_AB_RGS_Anst1_64R) */

#define Com_SGis_AB_RGS_Anst1_64R ComConf_ComSignal_SGis_AB_RGS_Anst1_64R


#if (defined Com_SGis_AB_Rollover_Crash1_64R) /* To prevent double declaration */
#error Com_SGis_AB_Rollover_Crash1_64R already defined
#endif /* #if (defined Com_SGis_AB_Rollover_Crash1_64R) */

#define Com_SGis_AB_Rollover_Crash1_64R ComConf_ComSignal_SGis_AB_Rollover_Crash1_64R


#if (defined Com_SGis_AB_SB_Crash1_64R) /* To prevent double declaration */
#error Com_SGis_AB_SB_Crash1_64R already defined
#endif /* #if (defined Com_SGis_AB_SB_Crash1_64R) */

#define Com_SGis_AB_SB_Crash1_64R ComConf_ComSignal_SGis_AB_SB_Crash1_64R


#if (defined Com_SGis_AB_SF_Crash1_64R) /* To prevent double declaration */
#error Com_SGis_AB_SF_Crash1_64R already defined
#endif /* #if (defined Com_SGis_AB_SF_Crash1_64R) */

#define Com_SGis_AB_SF_Crash1_64R ComConf_ComSignal_SGis_AB_SF_Crash1_64R


#if (defined Com_SGis_AB_Stellgliedtest1_64R) /* To prevent double declaration */
#error Com_SGis_AB_Stellgliedtest1_64R already defined
#endif /* #if (defined Com_SGis_AB_Stellgliedtest1_64R) */

#define Com_SGis_AB_Stellgliedtest1_64R ComConf_ComSignal_SGis_AB_Stellgliedtest1_64R


#if (defined Com_SGis_AB_Systemfehler1_64R) /* To prevent double declaration */
#error Com_SGis_AB_Systemfehler1_64R already defined
#endif /* #if (defined Com_SGis_AB_Systemfehler1_64R) */

#define Com_SGis_AB_Systemfehler1_64R ComConf_ComSignal_SGis_AB_Systemfehler1_64R


#if (defined Com_SGis_AB_Texte_AKS1_64R) /* To prevent double declaration */
#error Com_SGis_AB_Texte_AKS1_64R already defined
#endif /* #if (defined Com_SGis_AB_Texte_AKS1_64R) */

#define Com_SGis_AB_Texte_AKS1_64R ComConf_ComSignal_SGis_AB_Texte_AKS1_64R


#if (defined Com_SGis_AB_VB_deaktiviert1_64R) /* To prevent double declaration */
#error Com_SGis_AB_VB_deaktiviert1_64R already defined
#endif /* #if (defined Com_SGis_AB_VB_deaktiviert1_64R) */

#define Com_SGis_AB_VB_deaktiviert1_64R ComConf_ComSignal_SGis_AB_VB_deaktiviert1_64R


#if (defined Com_SGis_AB_Versorgungsspannung1_64R) /* To prevent double declaration */
#error Com_SGis_AB_Versorgungsspannung1_64R already defined
#endif /* #if (defined Com_SGis_AB_Versorgungsspannung1_64R) */

#define Com_SGis_AB_Versorgungsspannung1_64R ComConf_ComSignal_SGis_AB_Versorgungsspannung1_64R


#if (defined Com_SGis_AB_eCS_Error1_64R) /* To prevent double declaration */
#error Com_SGis_AB_eCS_Error1_64R already defined
#endif /* #if (defined Com_SGis_AB_eCS_Error1_64R) */

#define Com_SGis_AB_eCS_Error1_64R ComConf_ComSignal_SGis_AB_eCS_Error1_64R


#if (defined Com_SGis_ASM_Masterzeit_021_64R) /* To prevent double declaration */
#error Com_SGis_ASM_Masterzeit_021_64R already defined
#endif /* #if (defined Com_SGis_ASM_Masterzeit_021_64R) */

#define Com_SGis_ASM_Masterzeit_021_64R ComConf_ComSignal_SGis_ASM_Masterzeit_021_64R


#if (defined Com_SGis_Airbag_01_BZ1_64R) /* To prevent double declaration */
#error Com_SGis_Airbag_01_BZ1_64R already defined
#endif /* #if (defined Com_SGis_Airbag_01_BZ1_64R) */

#define Com_SGis_Airbag_01_BZ1_64R ComConf_ComSignal_SGis_Airbag_01_BZ1_64R


#if (defined Com_SGis_Airbag_01_CRC1_64R) /* To prevent double declaration */
#error Com_SGis_Airbag_01_CRC1_64R already defined
#endif /* #if (defined Com_SGis_Airbag_01_CRC1_64R) */

#define Com_SGis_Airbag_01_CRC1_64R ComConf_ComSignal_SGis_Airbag_01_CRC1_64R


#if (defined Com_SGis_AB_Gurtschloss_BF1_1312R) /* To prevent double declaration */
#error Com_SGis_AB_Gurtschloss_BF1_1312R already defined
#endif /* #if (defined Com_SGis_AB_Gurtschloss_BF1_1312R) */

#define Com_SGis_AB_Gurtschloss_BF1_1312R ComConf_ComSignal_SGis_AB_Gurtschloss_BF1_1312R


#if (defined Com_SGis_AB_Gurtschloss_FA1_1312R) /* To prevent double declaration */
#error Com_SGis_AB_Gurtschloss_FA1_1312R already defined
#endif /* #if (defined Com_SGis_AB_Gurtschloss_FA1_1312R) */

#define Com_SGis_AB_Gurtschloss_FA1_1312R ComConf_ComSignal_SGis_AB_Gurtschloss_FA1_1312R


#if (defined Com_SGis_AB_Gurtschloss_Reihe2_BF1_1312R) /* To prevent double declaration */
#error Com_SGis_AB_Gurtschloss_Reihe2_BF1_1312R already defined
#endif /* #if (defined Com_SGis_AB_Gurtschloss_Reihe2_BF1_1312R) */

#define Com_SGis_AB_Gurtschloss_Reihe2_BF1_1312R ComConf_ComSignal_SGis_AB_Gurtschloss_Reihe2_BF1_1312R


#if (defined Com_SGis_AB_Gurtschloss_Reihe2_FA1_1312R) /* To prevent double declaration */
#error Com_SGis_AB_Gurtschloss_Reihe2_FA1_1312R already defined
#endif /* #if (defined Com_SGis_AB_Gurtschloss_Reihe2_FA1_1312R) */

#define Com_SGis_AB_Gurtschloss_Reihe2_FA1_1312R ComConf_ComSignal_SGis_AB_Gurtschloss_Reihe2_FA1_1312R


#if (defined Com_SGis_AB_Gurtschloss_Reihe3_BF1_1312R) /* To prevent double declaration */
#error Com_SGis_AB_Gurtschloss_Reihe3_BF1_1312R already defined
#endif /* #if (defined Com_SGis_AB_Gurtschloss_Reihe3_BF1_1312R) */

#define Com_SGis_AB_Gurtschloss_Reihe3_BF1_1312R ComConf_ComSignal_SGis_AB_Gurtschloss_Reihe3_BF1_1312R


#if (defined Com_SGis_AB_Gurtschloss_Reihe3_FA1_1312R) /* To prevent double declaration */
#error Com_SGis_AB_Gurtschloss_Reihe3_FA1_1312R already defined
#endif /* #if (defined Com_SGis_AB_Gurtschloss_Reihe3_FA1_1312R) */

#define Com_SGis_AB_Gurtschloss_Reihe3_FA1_1312R ComConf_ComSignal_SGis_AB_Gurtschloss_Reihe3_FA1_1312R


#if (defined Com_SGis_AB_eCS_Aktuatortest_BF1_184112401R) /* To prevent double declaration */
#error Com_SGis_AB_eCS_Aktuatortest_BF1_184112401R already defined
#endif /* #if (defined Com_SGis_AB_eCS_Aktuatortest_BF1_184112401R) */

#define Com_SGis_AB_eCS_Aktuatortest_BF1_184112401R ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_BF1_184112401R


#if (defined Com_SGis_AB_eCS_Aktuatortest_FA1_184112401R) /* To prevent double declaration */
#error Com_SGis_AB_eCS_Aktuatortest_FA1_184112401R already defined
#endif /* #if (defined Com_SGis_AB_eCS_Aktuatortest_FA1_184112401R) */

#define Com_SGis_AB_eCS_Aktuatortest_FA1_184112401R ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_FA1_184112401R


#if (defined Com_SGis_AB_eCS_Aktuatortest_Reihe2_BF1_184112401R) /* To prevent double declaration */
#error Com_SGis_AB_eCS_Aktuatortest_Reihe2_BF1_184112401R already defined
#endif /* #if (defined Com_SGis_AB_eCS_Aktuatortest_Reihe2_BF1_184112401R) */

#define Com_SGis_AB_eCS_Aktuatortest_Reihe2_BF1_184112401R ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_Reihe2_BF1_184112401R


#if (defined Com_SGis_AB_eCS_Aktuatortest_Reihe2_FA1_184112401R) /* To prevent double declaration */
#error Com_SGis_AB_eCS_Aktuatortest_Reihe2_FA1_184112401R already defined
#endif /* #if (defined Com_SGis_AB_eCS_Aktuatortest_Reihe2_FA1_184112401R) */

#define Com_SGis_AB_eCS_Aktuatortest_Reihe2_FA1_184112401R ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_Reihe2_FA1_184112401R


#if (defined Com_SGis_AB_eCS_Aktuatortest_Reihe3_BF1_184112401R) /* To prevent double declaration */
#error Com_SGis_AB_eCS_Aktuatortest_Reihe3_BF1_184112401R already defined
#endif /* #if (defined Com_SGis_AB_eCS_Aktuatortest_Reihe3_BF1_184112401R) */

#define Com_SGis_AB_eCS_Aktuatortest_Reihe3_BF1_184112401R ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_Reihe3_BF1_184112401R


#if (defined Com_SGis_AB_eCS_Aktuatortest_Reihe3_FA1_184112401R) /* To prevent double declaration */
#error Com_SGis_AB_eCS_Aktuatortest_Reihe3_FA1_184112401R already defined
#endif /* #if (defined Com_SGis_AB_eCS_Aktuatortest_Reihe3_FA1_184112401R) */

#define Com_SGis_AB_eCS_Aktuatortest_Reihe3_FA1_184112401R ComConf_ComSignal_SGis_AB_eCS_Aktuatortest_Reihe3_FA1_184112401R


/* External Tx Signal IDs (no group signals) defines */
#if (defined Com_SGis_eCS_Gurtschloss_Status_Reihe2_BF1_184112400T) /* To prevent double declaration */
#error Com_SGis_eCS_Gurtschloss_Status_Reihe2_BF1_184112400T already defined
#endif /* #if (defined Com_SGis_eCS_Gurtschloss_Status_Reihe2_BF1_184112400T) */

#define Com_SGis_eCS_Gurtschloss_Status_Reihe2_BF1_184112400T ComConf_ComSignal_SGis_eCS_Gurtschloss_Status_Reihe2_BF1_184112400T


#if (defined Com_SGis_eCS_Gurtschloss_Status_Reihe2_FA1_184112400T) /* To prevent double declaration */
#error Com_SGis_eCS_Gurtschloss_Status_Reihe2_FA1_184112400T already defined
#endif /* #if (defined Com_SGis_eCS_Gurtschloss_Status_Reihe2_FA1_184112400T) */

#define Com_SGis_eCS_Gurtschloss_Status_Reihe2_FA1_184112400T ComConf_ComSignal_SGis_eCS_Gurtschloss_Status_Reihe2_FA1_184112400T


#if (defined Com_SGis_eCS_HW_defekt1_184112400T) /* To prevent double declaration */
#error Com_SGis_eCS_HW_defekt1_184112400T already defined
#endif /* #if (defined Com_SGis_eCS_HW_defekt1_184112400T) */

#define Com_SGis_eCS_HW_defekt1_184112400T ComConf_ComSignal_SGis_eCS_HW_defekt1_184112400T


#if (defined Com_SGis_eCS_SBS_Belegung_Reihe2_BF1_184112400T) /* To prevent double declaration */
#error Com_SGis_eCS_SBS_Belegung_Reihe2_BF1_184112400T already defined
#endif /* #if (defined Com_SGis_eCS_SBS_Belegung_Reihe2_BF1_184112400T) */

#define Com_SGis_eCS_SBS_Belegung_Reihe2_BF1_184112400T ComConf_ComSignal_SGis_eCS_SBS_Belegung_Reihe2_BF1_184112400T


#if (defined Com_SGis_eCS_SBS_Belegung_Reihe2_FA1_184112400T) /* To prevent double declaration */
#error Com_SGis_eCS_SBS_Belegung_Reihe2_FA1_184112400T already defined
#endif /* #if (defined Com_SGis_eCS_SBS_Belegung_Reihe2_FA1_184112400T) */

#define Com_SGis_eCS_SBS_Belegung_Reihe2_FA1_184112400T ComConf_ComSignal_SGis_eCS_SBS_Belegung_Reihe2_FA1_184112400T


#if (defined Com_SGis_eCS_Status1_184112400T) /* To prevent double declaration */
#error Com_SGis_eCS_Status1_184112400T already defined
#endif /* #if (defined Com_SGis_eCS_Status1_184112400T) */

#define Com_SGis_eCS_Status1_184112400T ComConf_ComSignal_SGis_eCS_Status1_184112400T


#if (defined Com_SGis_eCS_Stoerung1_184112400T) /* To prevent double declaration */
#error Com_SGis_eCS_Stoerung1_184112400T already defined
#endif /* #if (defined Com_SGis_eCS_Stoerung1_184112400T) */

#define Com_SGis_eCS_Stoerung1_184112400T ComConf_ComSignal_SGis_eCS_Stoerung1_184112400T


#if (defined Com_SGis_eCS_MF_Logger_Byte_1989T) /* To prevent double declaration */
#error Com_SGis_eCS_MF_Logger_Byte_1989T already defined
#endif /* #if (defined Com_SGis_eCS_MF_Logger_Byte_1989T) */

#define Com_SGis_eCS_MF_Logger_Byte_1989T ComConf_ComSignal_SGis_eCS_MF_Logger_Byte_1989T


#if (defined Com_SGis_eCS_Error_Reihe1_BFS_1_184112400T) /* To prevent double declaration */
#error Com_SGis_eCS_Error_Reihe1_BFS_1_184112400T already defined
#endif /* #if (defined Com_SGis_eCS_Error_Reihe1_BFS_1_184112400T) */

#define Com_SGis_eCS_Error_Reihe1_BFS_1_184112400T ComConf_ComSignal_SGis_eCS_Error_Reihe1_BFS_1_184112400T


#if (defined Com_SGis_eCS_Error_Reihe1_BFS_2_184112400T) /* To prevent double declaration */
#error Com_SGis_eCS_Error_Reihe1_BFS_2_184112400T already defined
#endif /* #if (defined Com_SGis_eCS_Error_Reihe1_BFS_2_184112400T) */

#define Com_SGis_eCS_Error_Reihe1_BFS_2_184112400T ComConf_ComSignal_SGis_eCS_Error_Reihe1_BFS_2_184112400T


#if (defined Com_SGis_eCS_Error_Reihe1_FS_1_184112400T) /* To prevent double declaration */
#error Com_SGis_eCS_Error_Reihe1_FS_1_184112400T already defined
#endif /* #if (defined Com_SGis_eCS_Error_Reihe1_FS_1_184112400T) */

#define Com_SGis_eCS_Error_Reihe1_FS_1_184112400T ComConf_ComSignal_SGis_eCS_Error_Reihe1_FS_1_184112400T


#if (defined Com_SGis_eCS_Error_Reihe1_FS_2_184112400T) /* To prevent double declaration */
#error Com_SGis_eCS_Error_Reihe1_FS_2_184112400T already defined
#endif /* #if (defined Com_SGis_eCS_Error_Reihe1_FS_2_184112400T) */

#define Com_SGis_eCS_Error_Reihe1_FS_2_184112400T ComConf_ComSignal_SGis_eCS_Error_Reihe1_FS_2_184112400T


#if (defined Com_SGis_eCS_Error_Reihe2_BFS_184112400T) /* To prevent double declaration */
#error Com_SGis_eCS_Error_Reihe2_BFS_184112400T already defined
#endif /* #if (defined Com_SGis_eCS_Error_Reihe2_BFS_184112400T) */

#define Com_SGis_eCS_Error_Reihe2_BFS_184112400T ComConf_ComSignal_SGis_eCS_Error_Reihe2_BFS_184112400T


#if (defined Com_SGis_eCS_Error_Reihe2_FS_184112400T) /* To prevent double declaration */
#error Com_SGis_eCS_Error_Reihe2_FS_184112400T already defined
#endif /* #if (defined Com_SGis_eCS_Error_Reihe2_FS_184112400T) */

#define Com_SGis_eCS_Error_Reihe2_FS_184112400T ComConf_ComSignal_SGis_eCS_Error_Reihe2_FS_184112400T


#if (defined Com_SGis_eCS_SBS_LastState_Reihe2_BFS_184112400T) /* To prevent double declaration */
#error Com_SGis_eCS_SBS_LastState_Reihe2_BFS_184112400T already defined
#endif /* #if (defined Com_SGis_eCS_SBS_LastState_Reihe2_BFS_184112400T) */

#define Com_SGis_eCS_SBS_LastState_Reihe2_BFS_184112400T ComConf_ComSignal_SGis_eCS_SBS_LastState_Reihe2_BFS_184112400T


#if (defined Com_SGis_eCS_SBS_LastState_Reihe2_FS_184112400T) /* To prevent double declaration */
#error Com_SGis_eCS_SBS_LastState_Reihe2_FS_184112400T already defined
#endif /* #if (defined Com_SGis_eCS_SBS_LastState_Reihe2_FS_184112400T) */

#define Com_SGis_eCS_SBS_LastState_Reihe2_FS_184112400T ComConf_ComSignal_SGis_eCS_SBS_LastState_Reihe2_FS_184112400T


#if (defined Com_SGis_eCS_Status_Verr_Reihe1_BFS_1_184112400T) /* To prevent double declaration */
#error Com_SGis_eCS_Status_Verr_Reihe1_BFS_1_184112400T already defined
#endif /* #if (defined Com_SGis_eCS_Status_Verr_Reihe1_BFS_1_184112400T) */

#define Com_SGis_eCS_Status_Verr_Reihe1_BFS_1_184112400T ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_BFS_1_184112400T


#if (defined Com_SGis_eCS_Status_Verr_Reihe1_BFS_2_184112400T) /* To prevent double declaration */
#error Com_SGis_eCS_Status_Verr_Reihe1_BFS_2_184112400T already defined
#endif /* #if (defined Com_SGis_eCS_Status_Verr_Reihe1_BFS_2_184112400T) */

#define Com_SGis_eCS_Status_Verr_Reihe1_BFS_2_184112400T ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_BFS_2_184112400T


#if (defined Com_SGis_eCS_Status_Verr_Reihe1_FS_1_184112400T) /* To prevent double declaration */
#error Com_SGis_eCS_Status_Verr_Reihe1_FS_1_184112400T already defined
#endif /* #if (defined Com_SGis_eCS_Status_Verr_Reihe1_FS_1_184112400T) */

#define Com_SGis_eCS_Status_Verr_Reihe1_FS_1_184112400T ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_FS_1_184112400T


#if (defined Com_SGis_eCS_Status_Verr_Reihe1_FS_2_184112400T) /* To prevent double declaration */
#error Com_SGis_eCS_Status_Verr_Reihe1_FS_2_184112400T already defined
#endif /* #if (defined Com_SGis_eCS_Status_Verr_Reihe1_FS_2_184112400T) */

#define Com_SGis_eCS_Status_Verr_Reihe1_FS_2_184112400T ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe1_FS_2_184112400T


#if (defined Com_SGis_eCS_Status_Verr_Reihe2_BFS_184112400T) /* To prevent double declaration */
#error Com_SGis_eCS_Status_Verr_Reihe2_BFS_184112400T already defined
#endif /* #if (defined Com_SGis_eCS_Status_Verr_Reihe2_BFS_184112400T) */

#define Com_SGis_eCS_Status_Verr_Reihe2_BFS_184112400T ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe2_BFS_184112400T


#if (defined Com_SGis_eCS_Status_Verr_Reihe2_FS_184112400T) /* To prevent double declaration */
#error Com_SGis_eCS_Status_Verr_Reihe2_FS_184112400T already defined
#endif /* #if (defined Com_SGis_eCS_Status_Verr_Reihe2_FS_184112400T) */

#define Com_SGis_eCS_Status_Verr_Reihe2_FS_184112400T ComConf_ComSignal_SGis_eCS_Status_Verr_Reihe2_FS_184112400T


/* External Rx Group Signal IDs defines */
#if (defined Com_GliwaIn_Byte_0_300R) /* To prevent double declaration */
#error Com_GliwaIn_Byte_0_300R already defined
#endif /* #if (defined Com_GliwaIn_Byte_0_300R) */

#define Com_GliwaIn_Byte_0_300R ComConf_ComGroupSignal_GliwaIn_Byte_0_300R


#if (defined Com_GliwaIn_Byte_1_300R) /* To prevent double declaration */
#error Com_GliwaIn_Byte_1_300R already defined
#endif /* #if (defined Com_GliwaIn_Byte_1_300R) */

#define Com_GliwaIn_Byte_1_300R ComConf_ComGroupSignal_GliwaIn_Byte_1_300R


#if (defined Com_GliwaIn_Byte_2_300R) /* To prevent double declaration */
#error Com_GliwaIn_Byte_2_300R already defined
#endif /* #if (defined Com_GliwaIn_Byte_2_300R) */

#define Com_GliwaIn_Byte_2_300R ComConf_ComGroupSignal_GliwaIn_Byte_2_300R


#if (defined Com_GliwaIn_Byte_3_300R) /* To prevent double declaration */
#error Com_GliwaIn_Byte_3_300R already defined
#endif /* #if (defined Com_GliwaIn_Byte_3_300R) */

#define Com_GliwaIn_Byte_3_300R ComConf_ComGroupSignal_GliwaIn_Byte_3_300R


#if (defined Com_GliwaIn_Byte_4_300R) /* To prevent double declaration */
#error Com_GliwaIn_Byte_4_300R already defined
#endif /* #if (defined Com_GliwaIn_Byte_4_300R) */

#define Com_GliwaIn_Byte_4_300R ComConf_ComGroupSignal_GliwaIn_Byte_4_300R


#if (defined Com_GliwaIn_Byte_5_300R) /* To prevent double declaration */
#error Com_GliwaIn_Byte_5_300R already defined
#endif /* #if (defined Com_GliwaIn_Byte_5_300R) */

#define Com_GliwaIn_Byte_5_300R ComConf_ComGroupSignal_GliwaIn_Byte_5_300R


#if (defined Com_GliwaIn_Byte_6_300R) /* To prevent double declaration */
#error Com_GliwaIn_Byte_6_300R already defined
#endif /* #if (defined Com_GliwaIn_Byte_6_300R) */

#define Com_GliwaIn_Byte_6_300R ComConf_ComGroupSignal_GliwaIn_Byte_6_300R


#if (defined Com_GliwaIn_Byte_7_300R) /* To prevent double declaration */
#error Com_GliwaIn_Byte_7_300R already defined
#endif /* #if (defined Com_GliwaIn_Byte_7_300R) */

#define Com_GliwaIn_Byte_7_300R ComConf_ComGroupSignal_GliwaIn_Byte_7_300R


/* External Tx Group Signal IDs defines */
#if (defined Com_DataOut_Byte_0_7_256T) /* To prevent double declaration */
#error Com_DataOut_Byte_0_7_256T already defined
#endif /* #if (defined Com_DataOut_Byte_0_7_256T) */

#define Com_DataOut_Byte_0_7_256T ComConf_ComGroupSignal_DataOut_Byte_0_7_256T


#if (defined Com_DataOut_Byte_16_23_256T) /* To prevent double declaration */
#error Com_DataOut_Byte_16_23_256T already defined
#endif /* #if (defined Com_DataOut_Byte_16_23_256T) */

#define Com_DataOut_Byte_16_23_256T ComConf_ComGroupSignal_DataOut_Byte_16_23_256T


#if (defined Com_DataOut_Byte_24_31_256T) /* To prevent double declaration */
#error Com_DataOut_Byte_24_31_256T already defined
#endif /* #if (defined Com_DataOut_Byte_24_31_256T) */

#define Com_DataOut_Byte_24_31_256T ComConf_ComGroupSignal_DataOut_Byte_24_31_256T


#if (defined Com_DataOut_Byte_32_39_256T) /* To prevent double declaration */
#error Com_DataOut_Byte_32_39_256T already defined
#endif /* #if (defined Com_DataOut_Byte_32_39_256T) */

#define Com_DataOut_Byte_32_39_256T ComConf_ComGroupSignal_DataOut_Byte_32_39_256T


#if (defined Com_DataOut_Byte_40_47_256T) /* To prevent double declaration */
#error Com_DataOut_Byte_40_47_256T already defined
#endif /* #if (defined Com_DataOut_Byte_40_47_256T) */

#define Com_DataOut_Byte_40_47_256T ComConf_ComGroupSignal_DataOut_Byte_40_47_256T


#if (defined Com_DataOut_Byte_48_55_256T) /* To prevent double declaration */
#error Com_DataOut_Byte_48_55_256T already defined
#endif /* #if (defined Com_DataOut_Byte_48_55_256T) */

#define Com_DataOut_Byte_48_55_256T ComConf_ComGroupSignal_DataOut_Byte_48_55_256T


#if (defined Com_DataOut_Byte_56_63_256T) /* To prevent double declaration */
#error Com_DataOut_Byte_56_63_256T already defined
#endif /* #if (defined Com_DataOut_Byte_56_63_256T) */

#define Com_DataOut_Byte_56_63_256T ComConf_ComGroupSignal_DataOut_Byte_56_63_256T


#if (defined Com_DataOut_Byte_8_15_256T) /* To prevent double declaration */
#error Com_DataOut_Byte_8_15_256T already defined
#endif /* #if (defined Com_DataOut_Byte_8_15_256T) */

#define Com_DataOut_Byte_8_15_256T ComConf_ComGroupSignal_DataOut_Byte_8_15_256T


#if (defined Com_MF_Byte_0_7_1988T) /* To prevent double declaration */
#error Com_MF_Byte_0_7_1988T already defined
#endif /* #if (defined Com_MF_Byte_0_7_1988T) */

#define Com_MF_Byte_0_7_1988T ComConf_ComGroupSignal_MF_Byte_0_7_1988T


#if (defined Com_MF_Byte_16_23_1988T) /* To prevent double declaration */
#error Com_MF_Byte_16_23_1988T already defined
#endif /* #if (defined Com_MF_Byte_16_23_1988T) */

#define Com_MF_Byte_16_23_1988T ComConf_ComGroupSignal_MF_Byte_16_23_1988T


#if (defined Com_MF_Byte_24_31_1988T) /* To prevent double declaration */
#error Com_MF_Byte_24_31_1988T already defined
#endif /* #if (defined Com_MF_Byte_24_31_1988T) */

#define Com_MF_Byte_24_31_1988T ComConf_ComGroupSignal_MF_Byte_24_31_1988T


#if (defined Com_MF_Byte_32_39_1988T) /* To prevent double declaration */
#error Com_MF_Byte_32_39_1988T already defined
#endif /* #if (defined Com_MF_Byte_32_39_1988T) */

#define Com_MF_Byte_32_39_1988T ComConf_ComGroupSignal_MF_Byte_32_39_1988T


#if (defined Com_MF_Byte_40_47_1988T) /* To prevent double declaration */
#error Com_MF_Byte_40_47_1988T already defined
#endif /* #if (defined Com_MF_Byte_40_47_1988T) */

#define Com_MF_Byte_40_47_1988T ComConf_ComGroupSignal_MF_Byte_40_47_1988T


#if (defined Com_MF_Byte_48_55_1988T) /* To prevent double declaration */
#error Com_MF_Byte_48_55_1988T already defined
#endif /* #if (defined Com_MF_Byte_48_55_1988T) */

#define Com_MF_Byte_48_55_1988T ComConf_ComGroupSignal_MF_Byte_48_55_1988T


#if (defined Com_MF_Byte_56_63_1988T) /* To prevent double declaration */
#error Com_MF_Byte_56_63_1988T already defined
#endif /* #if (defined Com_MF_Byte_56_63_1988T) */

#define Com_MF_Byte_56_63_1988T ComConf_ComGroupSignal_MF_Byte_56_63_1988T


#if (defined Com_MF_Byte_8_15_1988T) /* To prevent double declaration */
#error Com_MF_Byte_8_15_1988T already defined
#endif /* #if (defined Com_MF_Byte_8_15_1988T) */

#define Com_MF_Byte_8_15_1988T ComConf_ComGroupSignal_MF_Byte_8_15_1988T


#if (defined Com_GliwaOut_Byte_0_7_200T) /* To prevent double declaration */
#error Com_GliwaOut_Byte_0_7_200T already defined
#endif /* #if (defined Com_GliwaOut_Byte_0_7_200T) */

#define Com_GliwaOut_Byte_0_7_200T ComConf_ComGroupSignal_GliwaOut_Byte_0_7_200T


#if (defined Com_GliwaOut_Byte_16_23_200T) /* To prevent double declaration */
#error Com_GliwaOut_Byte_16_23_200T already defined
#endif /* #if (defined Com_GliwaOut_Byte_16_23_200T) */

#define Com_GliwaOut_Byte_16_23_200T ComConf_ComGroupSignal_GliwaOut_Byte_16_23_200T


#if (defined Com_GliwaOut_Byte_24_31_200T) /* To prevent double declaration */
#error Com_GliwaOut_Byte_24_31_200T already defined
#endif /* #if (defined Com_GliwaOut_Byte_24_31_200T) */

#define Com_GliwaOut_Byte_24_31_200T ComConf_ComGroupSignal_GliwaOut_Byte_24_31_200T


#if (defined Com_GliwaOut_Byte_32_39_200T) /* To prevent double declaration */
#error Com_GliwaOut_Byte_32_39_200T already defined
#endif /* #if (defined Com_GliwaOut_Byte_32_39_200T) */

#define Com_GliwaOut_Byte_32_39_200T ComConf_ComGroupSignal_GliwaOut_Byte_32_39_200T


#if (defined Com_GliwaOut_Byte_40_47_200T) /* To prevent double declaration */
#error Com_GliwaOut_Byte_40_47_200T already defined
#endif /* #if (defined Com_GliwaOut_Byte_40_47_200T) */

#define Com_GliwaOut_Byte_40_47_200T ComConf_ComGroupSignal_GliwaOut_Byte_40_47_200T


#if (defined Com_GliwaOut_Byte_48_55_200T) /* To prevent double declaration */
#error Com_GliwaOut_Byte_48_55_200T already defined
#endif /* #if (defined Com_GliwaOut_Byte_48_55_200T) */

#define Com_GliwaOut_Byte_48_55_200T ComConf_ComGroupSignal_GliwaOut_Byte_48_55_200T


#if (defined Com_GliwaOut_Byte_56_63_200T) /* To prevent double declaration */
#error Com_GliwaOut_Byte_56_63_200T already defined
#endif /* #if (defined Com_GliwaOut_Byte_56_63_200T) */

#define Com_GliwaOut_Byte_56_63_200T ComConf_ComGroupSignal_GliwaOut_Byte_56_63_200T


#if (defined Com_GliwaOut_Byte_8_15_200T) /* To prevent double declaration */
#error Com_GliwaOut_Byte_8_15_200T already defined
#endif /* #if (defined Com_GliwaOut_Byte_8_15_200T) */

#define Com_GliwaOut_Byte_8_15_200T ComConf_ComGroupSignal_GliwaOut_Byte_8_15_200T


/* External Rx Signal Group IDs defines */
#if (defined Com_GRGliwaInGroup_300R) /* To prevent double declaration */
#error Com_GRGliwaInGroup_300R %> already defined
#endif /* #if (defined Com_GRGliwaInGroup_300R) */

#define Com_GRGliwaInGroup_300R ComConf_ComSignalGroup_GRGliwaInGroup_300R


/* External Tx Signal Group IDs defines */
#if (defined Com_GRDataOutSignalGroup_0_256T) /* To prevent double declaration */
#error Com_GRDataOutSignalGroup_0_256T %> already defined
#endif /* #if (defined Com_GRDataOutSignalGroup_0_256T) */

#define Com_GRDataOutSignalGroup_0_256T ComConf_ComSignalGroup_GRDataOutSignalGroup_0_256T


#if (defined Com_GRMeasurementFrameGroup_1988T) /* To prevent double declaration */
#error Com_GRMeasurementFrameGroup_1988T %> already defined
#endif /* #if (defined Com_GRMeasurementFrameGroup_1988T) */

#define Com_GRMeasurementFrameGroup_1988T ComConf_ComSignalGroup_GRMeasurementFrameGroup_1988T


#if (defined Com_GRGliwaOutGroup_200T) /* To prevent double declaration */
#error Com_GRGliwaOutGroup_200T %> already defined
#endif /* #if (defined Com_GRGliwaOutGroup_200T) */

#define Com_GRGliwaOutGroup_200T ComConf_ComSignalGroup_GRGliwaOutGroup_200T


#endif /* (defined COM_PROVIDE_LEGACY_SYMBOLIC_NAMES) */

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
#endif /* if !defined( COM_SYMBOLIC_NAMES_PB_CFG_H ) */
/*==================[end of file]===========================================*/

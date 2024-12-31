/*********************************************************************************/
/*                                                                               */
/*                                BOOT Layers                                    */
/*                                                                               */
/* ------------------------------------------------------------------------------*/
/*                                                                               */
/*                                 PROG_VAG configuration                        */
/*                                                                               */
/*********************************************************************************/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file PROG_VAG_Types.h                */
/*%%  |                             |  %%  \brief PROG layer include plugin file */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 0.13.0 BL3              */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&    &&&&&             |  %%                                        */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
/*%%  |_____________________________|  %%                                        */
/*%%                                   %%                                        */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*********************************************************************************/
/* Copyright 2021 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*********************************************************************************/

[!AUTOSPACING!]

[!IF "(as:modconf('Prog')/VAG/Downgrade_Protection = 'true')"!]
[!IF "as:modconf('Prog')/General/PreliminaryErasing = 'true'"!]
/* Number of block in the server for downgrade protection */
#define PROG_DGP_BVT_NUMBER_OF_BLOCKS               [!WS "15"!](PROG_BLOCK_NB - 2U)
[!ELSE!]
/* Number of block in the server for downgrade protection */
#define PROG_DGP_BVT_NUMBER_OF_BLOCKS               [!WS "15"!](PROG_BLOCK_NB - 1U)
[!ENDIF!]
#define PROG_DGP_BID_LENGTH_1_BYTE                  [!WS "18"!]0x01U
#define PROG_DGP_BID_LENGTH_2_BYTE                  [!WS "18"!]0x02U

[!IF "(as:modconf('Prog')/VAG/BID_Length = '1')"!]
/* Downgrade Protection types definition */
#define PROG_DGP_BID_LENGTH                          PROG_DGP_BID_LENGTH_1_BYTE
[!ELSE!]
/* Downgrade Protection types definition */
#define PROG_DGP_BID_LENGTH                          PROG_DGP_BID_LENGTH_2_BYTE
[!ENDIF!]
#define PROG_DGP_RFS_VERSION_SIZE                   [!WS "20"!]0x04U
#define PROG_DGP_PTI_LENGTH                         [!WS "26"!]0x07U
#define PROG_DGP_TOTAL_PFT_LENGTH                   [!WS "20"!](4 + PROG_DGP_PTI_LENGTH + PROG_DGP_BVT_NUMBER_OF_BLOCKS*(PROG_DGP_BID_LENGTH + PROG_DGP_RFS_VERSION_SIZE))

typedef struct
{
    u16 uwBID;                                     [!WS "40"!]/* Logical block identifier */
    u8 aubRfsVersionPFT[PROG_DGP_RFS_VERSION_SIZE];[!WS "3"!]/* Downgrade protection version number of logical block "RfsV" */
}tProgRfsVersion;

typedef struct
{
    u16 uwPTILength;                                                   /* Length of the pseudo flash driver identification in bytes */
    u8  ubPTIDContent[PROG_DGP_PTI_LENGTH];                            /* Contents of the pseudo flash driver identification        */
    u16 uwBVTA;                                                        /* Number of logical blocks in the flash container           */
    tProgRfsVersion stRfsVersionNumber[PROG_DGP_BVT_NUMBER_OF_BLOCKS]; /* Block version table                                       */
}tProgDowngradeProtectionTable;

/* Fonction pointer for validation criteria API */
typedef tProgBoolean (*ptValidRfsDriver)(const tProgDowngradeProtectionTable* pstDowngradeProtectTable);

[!ENDIF!]

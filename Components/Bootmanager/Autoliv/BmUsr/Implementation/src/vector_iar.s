/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
C-File Template Version: 
******************************************************************************/
/* PRQA S 0288 ++ */
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.1 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Bootmanager/Autoliv/BmUsr/Implementation/src/project.pj $
*/
/* PRQA S 0288 -- */
/*!****************************************************************************

@details
   <Describes details of this module 'Template.c' file within overall
    context of component implementation>

******************************************************************************/
    MODULE vector_iar.s

    ; Forward declaration of sections.
    SECTION CSTACK:DATA:NOROOT(3)

    ;SECTION  .vector: DATA (2)
    SECTION  .vector: CODE

    EXPORT VTABLE
    
    EXTERN Reset_Handler
    
   
    
    DATA

VTABLE

    DCD sfe(CSTACK)              /* Top of Stack for Initial Stack Pointer */
    DCD Reset_Handler            /* Reset Handler */
    


    END

/******************************************************************************
End Of File
*****************************************************************************/

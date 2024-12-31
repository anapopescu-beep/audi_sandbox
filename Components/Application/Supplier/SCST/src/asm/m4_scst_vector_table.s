/******************************************************************************
*
* Copyright 2015-2016 Freescale
* Copyright 2019-2020 NXP
*
* NXP Confidential. This software is owned or controlled by NXP and may only 
* be used strictly in accordance with the applicable license terms. 
* By expressly accepting such terms or by downloading, installing, activating
* and/or otherwise using the software, you are agreeing that you have read, 
* and that you agree to comply with and are bound by, such license terms. 
* If you do not agree to be bound by the applicable license terms, 
* then you may not retain, install, activate or otherwise use the software.
*
******************************************************************************/
#include "m4_scst_configuration.h"
#include "m4_scst_compiler.h"

    /* Symbols defined in the current module but to be visible to outside */
    SCST_EXPORT m4_scst_VTABLE
   
    /* Symbols defined outside but used within current module */
    SCST_EXTERN m4_scst_ISR_dispatcher
    
    SCST_SECTION_CONST_ALIGN(m4_scst_vector_table,SCST_BYTES_128)
    SCST_ALIGN_BYTES_128

m4_scst_VTABLE:

    SCST_WORD m4_scst_ISR_dispatcher        /* Top of Stack for Initial Stack Pointer: Here should be same value as in user vector table */
    SCST_WORD m4_scst_ISR_dispatcher        /* Reset Handler */
    SCST_WORD m4_scst_ISR_dispatcher        /* NMI Handler */
    SCST_WORD m4_scst_ISR_dispatcher        /* Hard Fault Handler */
    SCST_WORD m4_scst_ISR_dispatcher        /* Reserved */
    SCST_WORD m4_scst_ISR_dispatcher        /* Bus Fault Handler */
    SCST_WORD m4_scst_ISR_dispatcher        /* Usage Fault Handler */
    SCST_WORD m4_scst_ISR_dispatcher        /* Reserved */
    SCST_WORD m4_scst_ISR_dispatcher        /* Reserved */
    SCST_WORD m4_scst_ISR_dispatcher        /* Reserved */
    SCST_WORD m4_scst_ISR_dispatcher        /* Reserved */
    SCST_WORD m4_scst_ISR_dispatcher        /* SVCall Handler */
    SCST_WORD m4_scst_ISR_dispatcher        /* Debug Monitor Handler */
    SCST_WORD m4_scst_ISR_dispatcher        /* Reserved */
    SCST_WORD m4_scst_ISR_dispatcher        /* PendSV Handler */
    SCST_WORD m4_scst_ISR_dispatcher        /* SysTick Handler */ /* 15*/

    /* External interrupts 0-15 */
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
                                     
    /* External interrupts 16-31 */  
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
                                     
    /* External interrupts 32-47 */  
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
                                     
    /* External interrupts 48-63 */  
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
                                     
    /* External interrupts 64-79 */  
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
                                     
    /* External interrupts 80-95 */  
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
                                     
    /* External interrupts 96-111 */ 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
                                     
    /* External interrupts 112-127 */
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
                                     
    /* External interrupts 128-143 */
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
                                     
    /* External interrupts 144-159 */
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
                                     
    /* External interrupts 160-175 */
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 
    SCST_WORD m4_scst_ISR_dispatcher 

    SCST_FILE_END

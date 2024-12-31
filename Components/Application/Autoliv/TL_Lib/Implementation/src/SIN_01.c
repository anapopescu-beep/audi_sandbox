/**
 * @file       $RCSfile: SIN_01.c $
 * @brief      This file contains function F__I16SINI16 for calculation of trigonometric functions.
 * @author     Klaus Goebel, Dagmar Andoleit
 * @copyright  (c) 2016, dSPACE GmbH, Paderborn, Germany
 * @version    $Revision: 1.1 $ $Date: 2022/11/11 13:24:54CET $
 */
 
#include "dsfxp.h"

/******************************************************************************
*
* FUNCTION:
*   F__I16SINI16(v)
*
* DESCRIPTION:
*   Calculates sine as series approach.
*   Scaling is less than Int16, 2^-14
*
* PARAMETERS:
*   Int16   v      input value: -pi .. pi
*
* RETURNS:
*   Int16   fcn    return value
*
******************************************************************************/
Int16 F__I16SINI16(Int16 x)
{
    Int16 i;
    Int16 n;
    Int16 z1;

    n = x;
    x &= 0x7FFF;
    x -= 0x4000;

    if (x == -16384)
    {
        z1 = 0;
    }
    else
    {
        if ( x < 0 )
        {
            x = (Int16)-x;
        }

        i = (Int16)(x >> 7U);
        z1  = (Int16)cosLUT[i];
        z1 -= (Int16)((UInt32)((UInt16)(z1 - cosLUT[i+1]) * (UInt16)(x & 0x007F)) >> 7U);

        if (n < 0)
        {
            z1 = (Int16)-z1;
        }
    }
    return z1;
}
/* END F__I16SINI16() */

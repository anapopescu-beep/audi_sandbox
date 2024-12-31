/******************************************************************************
*
* FILE:
*   hyp.h         
*
* RELATED FILES:
*   math.h
*
* DESCRIPTION:
*   Definines prototype of hypot function.
*
*   Calculates the hypotenuse.
*   C__HYPOT(x, y);

*
*  AUTHOR(S):
*    S. Hillebrand
*
*  Copyright (c) 2003 dSPACE GmbH, GERMANY
*
*  $Workfile: tl_math.h $ $Revision: 1.1.3.2 $ $Date: 2022/11/11 13:24:53CET $ $Author: Andrei Anca (andrei.anca) $
******************************************************************************/

#ifndef __tl_math_h__
#define __tl_math_h__

#include <math.h>

/* hypot */
#define C__HYPOT(x, y)\
    sqrt((x)*(x) + (y)*(y))

#endif /* #ifndef __tl_math_h__ */

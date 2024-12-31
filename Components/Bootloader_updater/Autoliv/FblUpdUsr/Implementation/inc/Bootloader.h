/****************************************************************
*
*  Filename:      ../../../../../Release/CanFlash/Bootloader.h
*  Project:       Exported definition of C-Array Flash-Driver
*  File created:  Wed Aug 30 13:57:42 2023

*
****************************************************************/

#ifndef ____
#define ____

#define _NUMBLOCKS 1

#define _DECRYPTVALUE	0x0
#define _DECRYPTDATA(a)   (vuint8)((vuint8)(a) ^ (vuint8)_DECRYPTVALUE)
#define _BLOCK0_ADDRESS	0x1000
#define _BLOCK0_LENGTH	0x1F000
#define _BLOCK0_CHECKSUM	0x31E1u

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 Blk0[_BLOCK0_LENGTH];


#endif    /* #ifdef ____ */


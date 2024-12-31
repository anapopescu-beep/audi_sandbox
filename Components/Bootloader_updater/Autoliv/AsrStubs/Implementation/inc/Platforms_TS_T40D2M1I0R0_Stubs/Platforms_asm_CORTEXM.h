/* Platforms_asm_PA.h
 *
 * This file includes the appropriate Platforms_asm_PA_xxx.h include file * depending on the chosen toolchain.
 *
 * Macros are defined that permit the same source files to be processed by the assemblers of
 * all toolchains. This is done by including the appropriate toolchain file.
 * The assembler memory-map file is also included if appropriate.
 *
 *
 * $Id: Platforms_asm_CORTEXM.h 1.1 2023/02/08 14:30:48CET Catalin Ghibirsina (catalin.ghibirsina) in_work  $
*/
#ifndef __PLATFORMS_ASM_CORTEXM_H
#define __PLATFORMS_ASM_CORTEXM_H

#include "Platforms_defs.h"

/* Include the appropriate abstraction file for the toolchain
*/
#if (PLATFORMS_TOOLCHAIN==PLATFORMS_gnu)
#include <Platforms_asm_CORTEXM_gnu.h>
#elif (PLATFORMS_TOOLCHAIN==PLATFORMS_multi)
#include <Platforms_asm_CORTEXM_multi.h>
#elif (PLATFORMS_TOOLCHAIN==PLATFORMS_iar)
#include "Platforms_asm_CORTEXM_iar.h"
#else
#error "Unknown or unsupported toolchain. Check your Makefiles!"
#endif




/*
 * PLATFORMS_ASM_SRC_END
 *
 * This macro marks the end of an assembly source file.
 * Note:  This is the default implementation, it may be changed in the toolchain header!
 *        The default implementation is empty, because only a few assemblers need it.
*/
#ifndef PLATFORMS_ASM_SRC_END
#define PLATFORMS_ASM_SRC_END
#endif

/* Text section alignment
 *
 * This could be already defined by the user's memmap, so we only define it if it isn't already defined.
*/
#ifndef PLATFORMS_ASM_ALIGN_TEXT
#define PLATFORMS_ASM_ALIGN_TEXT Platforms_align(16,4)
#endif

/* intctab section alignment
 *
 * This could be already defined by the user's memmap, so we only define it if it isn't already defined.
*/
#ifndef PLATFORMS_ASM_ALIGN_INTCTAB
#define PLATFORMS_ASM_ALIGN_INTCTAB  Platforms_align(4,2)
#endif
#ifndef PLATFORMS_ASM_ALIGN_INTCVEC
#define PLATFORMS_ASM_ALIGN_INTCVEC  Platforms_align(PLATFORMS_INTC_VECSIZE, PLATFORMS_INTC_VECSIZE_POW2)
#endif

/* exctab section alignment
 *
 * These could be already defined by the user's memmap, so we only define them if they aren't already defined.
*/
#ifndef PLATFORMS_ASM_ALIGN_EXCTAB
#define PLATFORMS_ASM_ALIGN_EXCTAB   Platforms_align(256,8)
#endif
#ifndef PLATFORMS_ASM_ALIGN_EXCTAB10
#define PLATFORMS_ASM_ALIGN_EXCTAB10 Platforms_align(16,4)
#endif
#ifndef PLATFORMS_ASM_ALIGN_EXCTAB20
#define PLATFORMS_ASM_ALIGN_EXCTAB20 Platforms_align(32,5)
#endif
#ifndef PLATFORMS_ASM_ALIGN_EXCVEC
#define PLATFORMS_ASM_ALIGN_EXCVEC   Platforms_align(16,4)
#endif

/*
 * Abstraction to the the type and size associated with symbols in
 * some object file formats (most notably ELF).
 *
 * These are optional, so if a toolchain does not support this feature
 * the macros can be defined empty for that toolchain.
 *
 * The following default implementation works for most toolchains.
 */
/* Marks fsymbol as a function */
#ifndef PLATFORMS_ASM_FUNCTION
#define PLATFORMS_ASM_FUNCTION(fsymbol)  .type   fsymbol, @function
#endif

/* Marks fsymbol as an object */
#ifndef PLATFORMS_ASM_OBJECT
#define PLATFORMS_ASM_OBJECT(fsymbol)    .type   fsymbol, @object
#endif

/* Sets the size of the function/object at fsymbol;
 * To be used immediately after the definition of the object, size is computed
 * as the offset of the symbol definition to the current location.
 */
#ifndef PLATFORMS_ASM_SIZE
#define PLATFORMS_ASM_SIZE(fsymbol)      .size   fsymbol, . - fsymbol
#endif

/* CHECK: PARSE */
#endif
/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/

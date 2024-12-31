#if !defined(OS_H)
#define OS_H

#include "board.h"

#define SuspendAllInterrupts BoardDisableInterrupts
#define ResumeAllInterrupts BoardEnableInterrupts
#define EnableAllInterrupts BoardEnableInterrupts
#define DisableAllInterrupts BoardDisableInterrupts

#endif /* OS_H */


    PUBLIC CORTEXMExceptionTable
    EXTERN boardResetStart
    EXTERN BoardStack
    EXTERN boardInvalidException
    SECTION .ExceptionTable :CODE
   
    DATA
CORTEXMExceptionTable
    DC32 (BoardStack + 0x200U)
    DC32 boardResetStart
    DC32 boardInvalidException
    DC32 boardInvalidException
    DC32 boardInvalidException
    DC32 boardInvalidException
    DC32 boardInvalidException
    DC32 boardInvalidException
    DC32 boardInvalidException
    DC32 boardInvalidException
    DC32 boardInvalidException
    DC32 boardInvalidException
    DC32 boardInvalidException
    DC32 boardInvalidException
    DC32 boardInvalidException
    DC32 boardInvalidException
    END

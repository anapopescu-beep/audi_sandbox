#ifndef OS_STUBS_H_
#define OS_STUBS_H_

typedef unsigned char      os_uint8_t;

typedef os_uint8_t os_taskid_t;

struct os_task_s
{
   os_taskid_t taskId;
};

typedef struct os_task_s os_task_t;

struct os_kerneldata_s
{
   const os_task_t * taskCurrent;      /* currently running task on this core */
};

typedef struct os_kerneldata_s os_kerneldata_t;

extern os_kerneldata_t kstkernel_data_stub;

#define OS_GetKernelData() (&kstkernel_data_stub)

typedef os_uint8_t os_erroraction_t;

typedef os_erroraction_t        ProtectionReturnType;


#endif

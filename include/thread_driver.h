#ifndef _SCE_THREAD_DRIVER_H
#define _SCE_THREAD_DRIVER_H

#include <kerneltypes_driver.h>

typedef struct SceKernelMutexOptParam SceKernelMutexOptParam, *PSceKernelMutexOptParam;

struct SceKernelMutexOptParam {
    SceSize size;
    int ceilingPriority;
};

#endif /* _SCE_THREAD_DRIVER_H */

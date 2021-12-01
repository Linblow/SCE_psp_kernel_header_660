#ifndef _SCE_HEAPLIB_DRIVER_H
#define _SCE_HEAPLIB_DRIVER_H

#include <kerneltypes_driver.h>

typedef struct _AllocHeapOptParam _AllocHeapOptParam, *P_AllocHeapOptParam;
typedef struct _AllocHeapOptParam AllocHeapOptParam;

struct _AllocHeapOptParam {
    SceSize size;
    SceSize alignment;
};

#endif /* _SCE_HEAPLIB_DRIVER_H */

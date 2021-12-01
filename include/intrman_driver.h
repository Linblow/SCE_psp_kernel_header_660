#ifndef _SCE_INTRMAN_DRIVER_H
#define _SCE_INTRMAN_DRIVER_H

#include <kerneltypes_driver.h>

typedef u_int32_t SceCpuClockCounter;
typedef u_int64_t SceCpuClockCounterWide;

typedef struct _IntrHandlerOptionParam _IntrHandlerOptionParam, *P_IntrHandlerOptionParam;
typedef struct _IntrHandlerOptionParam IntrHandlerOptionParam;

typedef struct _IntrSubHandlerFunctionTable _IntrSubHandlerFunctionTable, *P_IntrSubHandlerFunctionTable;
typedef struct _IntrSubHandlerFunctionTable IntrSubHandlerFunctionTable;

struct _IntrHandlerOptionParam {
    SceSize size;
    int numsubintr;
    IntrSubHandlerFunctionTable * subfunctable;
};

struct _IntrSubHandlerFunctionTable {
    int size;
    void * gp_reg;
    int (* preRegisterHandler)(int, int, int (* )(int, void *, u_int32_t), void *);
    int (* postRegisterHandler)(int, int, int (* )(int, void *, u_int32_t), void *);
    int (* preReleaseHandler)(int, int);
    int (* postReleaseHandler)(int, int);
    int (* enable)(int, int);
    int (* disable)(int, int);
    int (* suspend)(int, int, int *);
    int (* resume)(int, int, int);
    int (* occurred)(int, int);
};

#endif /* _SCE_INTRMAN_DRIVER_H */

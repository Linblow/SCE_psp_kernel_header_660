#ifndef _SCE_SUSPEND_DRIVER_H
#define _SCE_SUSPEND_DRIVER_H

#include <kerneltypes_driver.h>

typedef struct SceKernelPowerHandlers       SceKernelPowerHandlers,       *PSceKernelPowerHandlers;
typedef struct SceKernelSysEventHandler     SceKernelSysEventHandler,     *PSceKernelSysEventHandler;
typedef struct SceKernelSysEventPllChgInfo  SceKernelSysEventPllChgInfo,  *PSceKernelSysEventPllChgInfo;
typedef struct SceKernelSysEventResumeInfo  SceKernelSysEventResumeInfo,  *PSceKernelSysEventResumeInfo;
typedef struct SceKernelSysEventSuspendInfo SceKernelSysEventSuspendInfo, *PSceKernelSysEventSuspendInfo;

struct SceKernelPowerHandlers {
    int    size;
    int (* pTick)(int);
    int (* pLockForKernel)(int);
    int (* pUnlockForKernel)(int);
    int (* pLockForUser)(int);
    int (* pUnlockForUser)(int);
    int (* pRebootStart)(int);
    int (* pVmemLock)(int, void * *, u_int32_t *);
    int (* pVmemTryLock)(int, void * *, u_int32_t *);
    int (* pVmemUnlock)(int);
};

struct SceKernelSysEventHandler {
    u_int32_t   size;
    char      * name;
    u_int32_t   mask;
    int      (* handler)(int, char *, void *, void * *);
    void      * gp;
    int         lock;
    struct SceKernelSysEventHandler * next;
    u_int32_t   reserved[9];
};

struct SceKernelSysEventPllChgInfo {
    u_int32_t   size;
    int         pllclock;
};

struct SceKernelSysEventResumeInfo {
    u_int32_t   size;
    void      * pIplInfo;
    u_int64_t   ullSleepStart;
    u_int64_t   ullSleeping;
    u_int32_t   reserved[8];
};

struct SceKernelSysEventSuspendInfo {
    u_int32_t   size;
    u_int32_t   poweroffmode;
    u_int64_t   ullCurrent;
    u_int32_t * puiWakeupReqMask;
    void      * pSuspendInfo;
    u_int32_t   reserved[10];
};

#endif /* _SCE_SUSPEND_DRIVER_H */

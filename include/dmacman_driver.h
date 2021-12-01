#ifndef _SCE_DMACMAN_DRIVER_H
#define _SCE_DMACMAN_DRIVER_H

#include <kerneltypes_driver.h>
#include <pl080.h>

typedef struct sceKernelDmaOperation sceKernelDmaOperation, *PsceKernelDmaOperation;

struct sceKernelDmaOperation {
    struct sceKernelDmaOperation * pNext;
    struct sceKernelDmaOperation * pPrev;
    struct sceKernelDmaOperation * pParent;
    struct sceKernelDmaOperation * pChild;
    int    (* cbfunc)(struct sceKernelDmaOperation *, int, int, void *);
    void    * pCookie;
    u_int32_t evpat;
    SceUShort uiFlag;
    short     dmaCh;
    SceUInt   uiSrcAddr;
    SceUInt   uiDestAddr;
    SceUInt   uiLLI;
    SceUInt   uiControl;
    SceUInt   uiConfiguration;
    SceUShort uiChMask[2];
    struct PL080_LLI * HeadLLI;
    struct PL080_LLI * EndLLI;
};

#endif /* _SCE_DMACMAN_DRIVER_H */

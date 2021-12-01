#ifndef _SCE_MODULEMGR_DRIVER_H
#define _SCE_MODULEMGR_DRIVER_H

#include <kerneltypes_driver.h>

typedef struct _ldfilefunc _ldfilefunc, *P_ldfilefunc;
typedef struct _ldfilefunc LDfilefunc;

typedef struct SceModuleStatus SceModuleStatus, *PSceModuleStatus;

struct _ldfilefunc {
    int (* beforeOpen)(void *, char *, int);
    int (* afterOpen)(void *, int);
    int (* close)(void *, int);
    int (* setBufSize)(void *, int, SceSize);
    int (* beforeRead)(void *, int, SceSize);
    int (* read)(void *, int, void *, SceSize);
    int (* lseek)(void *, int, long, int);
    int (* getfsize)(void *, int);
};

struct SceModuleStatus {
    char      name[56];
    SceUShort version;
    SceUShort flags;
    int       id;
    SceULong  entry_addr;
    SceULong  gp_value;
    SceULong  text_addr;
    SceULong  text_size;
    SceULong  data_size;
    SceULong  bss_size;
    SceULong  lreserve[2];
};

int SceKernelNpDrmGetModuleKeyFunction(SceUID , char * , SceOff * );

#endif /* _SCE_MODULEMGR_DRIVER_H */

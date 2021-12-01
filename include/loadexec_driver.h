#ifndef _SCE_LOADEXEC_DRIVER_H
#define _SCE_LOADEXEC_DRIVER_H

#include <kerneltypes_driver.h>

typedef struct SceKernelLoadExecHbImage     SceKernelLoadExecHbImage,     *PSceKernelLoadExecHbImage;
typedef struct SceKernelLoadExecParamVSHv0  SceKernelLoadExecParamVSHv0,  *PSceKernelLoadExecParamVSHv0;
typedef struct SceKernelSafetyCheckUserWork SceKernelSafetyCheckUserWork, *PSceKernelSafetyCheckUserWork;
typedef struct SceKernelVSHParam            SceKernelVSHParam,            *PSceKernelVSHParam;

struct SceKernelLoadExecHbImage {
    u_int32_t size;
    void * pHbImgHeader;
    struct {
        void * start;
        SceSize size;
    } fragments[16];
};

struct SceKernelLoadExecParamVSHv0 {
    SceSize   size;
    SceSize   args;
    void    * argp;
    char    * key;
    SceSize   vsh_args;
    void    * vsh_argp;
    char    * config;
    char    * config_user;
    u_int32_t flags;
};

struct SceKernelSafetyCheckUserWork {
    SceSize   size;
    u_int32_t must_be_zero;
    u_int32_t must_be_notzero;
};

struct SceKernelVSHParam {
    u_int32_t totalsize;
    u_int32_t headsize;
    int       exit_status;
    int       prev_status;
    int       shutdown_status;
    int       reboot_status;
    int       exec_status;
    int       reserved1;
};

#endif /* _SCE_LOADEXEC_DRIVER_H */

#ifndef _SCE_SYSMEM_DRIVER_H
#define _SCE_SYSMEM_DRIVER_H

#include <kerneltypes_driver.h>

typedef struct PartitionInfo              PartitionInfo,              *PPartitionInfo;
typedef struct SceKernelBlockInfo         SceKernelBlockInfo,         *PSceKernelBlockInfo;
typedef struct SceKernelHeapInfo          SceKernelHeapInfo,          *PSceKernelHeapInfo;
typedef struct SceKernelLoadExecParamVSH  SceKernelLoadExecParamVSH,  *PSceKernelLoadExecParamVSH;
typedef struct SceKernelLowheapInfo       SceKernelLowheapInfo,       *PSceKernelLowheapInfo;
typedef struct SceKernelUsersystemLibWork SceKernelUsersystemLibWork, *PSceKernelUsersystemLibWork;

struct PartitionInfo {
    SceSize   info_size;
    SceVAddr  part_base;
    SceSize   part_size;
    int       part_mode;
};

struct SceKernelBlockInfo {
    SceSize   size;
    char      name[32];
    SceUInt   attr;
    SceVAddr  headaddr;
    SceSize   blocksize;
    int       sizelockflag;
    int       useflag;
};

struct SceKernelHeapInfo {
    SceSize   size;
    char      name[32];
    SceUInt   attr;
    SceUInt   flag;
    SceSize   heapblocksize;
    SceSize   totalsize;
    SceSize   totalfreesize;
    SceSize   maxfreesize;
    SceSize   lowheapcount;
    SceVAddr  lowheapadrs[0];
};

struct SceKernelLoadExecParamVSH {
    SceSize   size;
    SceSize   args;
    void    * argp;
    char    * key;
    SceSize   vsh_args;
    void    * vsh_argp;
    char    * config;
    char    * config_user;
    u_int32_t flags;
    SceSize   paramsfo_args;
    void    * paramsfo_argp;
    void    * hbwakeupinfo;
};

struct SceKernelLowheapInfo {
    SceSize   size;
    SceSize   heapsize;
    SceSize   usesize;
    SceSize   freesize;
    SceSize   maxfreesize;
    SceSize   unitcount;
    /* not 100% sure, but must be checked by RE */
    struct {
        SceVAddr addr;
        SceSize  size;
    } *units;
};

struct SceKernelUsersystemLibWork {
    SceSize   size;
    void    * geliststop;
    int    (* psceGeListUpdateStallAddr)(int, void *);
    int     * piLazyListId;
};

#endif /* _SCE_SYSMEM_DRIVER_H */

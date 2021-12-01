#ifndef _SCE_IOFILEMGR_DRIVER_H
#define _SCE_IOFILEMGR_DRIVER_H

#include <kerneltypes_driver.h>

typedef struct SceIoCwd            SceIoCwd,            *PSceIoCwd;
typedef struct SceIoDeviceEntry    SceIoDeviceEntry,    *PSceIoDeviceEntry;
typedef struct SceIoDeviceFunction SceIoDeviceFunction, *PSceIoDeviceFunction;
typedef struct SceIoDeviceTable    SceIoDeviceTable,    *PSceIoDeviceTable;
typedef struct SceIoIob            SceIoIob,            *PSceIoIob;
typedef struct SceIoThreadCwd      SceIoThreadCwd,      *PSceIoThreadCwd;

typedef int (* df_init_t)(struct SceIoDeviceEntry *);
typedef int (* df_exit_t)(struct SceIoDeviceEntry *);
typedef int (* df_close_t)(struct SceIoIob *);
typedef int (* df_remove_t)(struct SceIoIob *, char *);
typedef int (* df_rmdir_t)(struct SceIoIob *, char *);
typedef int (* df_dopen_t)(struct SceIoIob *, char *);
typedef int (* df_dclose_t)(struct SceIoIob *);
typedef int (* df_chdir_t)(struct SceIoIob *, char *);
typedef int (* df_umount_t)(struct SceIoIob *, char *);
typedef int (* df_cancel_t)(struct SceIoIob *);

struct SceIoCwd {
    struct SceIoCwd * next;
    char * pathname;
    struct SceIoDeviceEntry * entry;
    void * cwd_private;
    int    refcount;
};

struct SceIoDeviceEntry {
    struct SceIoDeviceTable * d_dp;
    void * d_private;
    int    d_userfd_count;
};

struct SceIoDeviceFunction {
    df_init_t   df_init;
    df_exit_t   df_exit;
    int      (* df_open)(struct SceIoIob *, char *, int, SceMode);
    df_close_t  df_close;
    SceSSize (* df_read)(struct SceIoIob *, void *, SceSize);
    SceSSize (* df_write)(struct SceIoIob *, void *, SceSize);
    SceOff   (* df_lseek)(struct SceIoIob *, SceOff, int);
    int      (* df_ioctl)(struct SceIoIob *, int, void *, SceSize, void *, SceSize);
    df_remove_t df_remove;
    int      (* df_mkdir)(struct SceIoIob *, char *, SceMode);
    df_rmdir_t  df_rmdir;
    df_dopen_t  df_dopen;
    df_dclose_t df_dclose;
    int      (* df_dread)(struct SceIoIob *, struct SceIoDirent *);
    int      (* df_getstat)(struct SceIoIob *, char *, struct SceIoStat *);
    int      (* df_chstat)(struct SceIoIob *, char *, struct SceIoStat *, u_int32_t);
    int      (* df_rename)(struct SceIoIob *, char *, char *);
    df_chdir_t  df_chdir;
    int      (* df_mount)(struct SceIoIob *, char *, char *, int, void *, int);
    df_umount_t df_umount;
    int      (* df_devctl)(struct SceIoIob *, char *, int, void *, SceSize, void *, SceSize);
    df_cancel_t df_cancel;
};

struct SceIoDeviceTable {
    char * dt_string;
    int    dt_type;
    int    dt_size;
    char * dt_desc;
    struct SceIoDeviceFunction * dt_func;
};

struct SceIoIob {
    int                       i_flgs;
    int                       i_unit;
    struct SceIoDeviceEntry * i_de;
    int                       d_type;
    void                    * i_private;
    struct SceIoCwd         * i_cwd;
    SceOff                    i_fpos;
    SceUID                    i_thread;
    int                       dummy;
};

struct SceIoThreadCwd {
    struct SceIoThreadCwd * next;
    void * tls;
    struct SceIoCwd * cwd;
};

#endif /* _SCE_IOFILEMGR_DRIVER_H */

#ifndef _SCE_SYSTIMER_DRIVER_H
#define _SCE_SYSTIMER_DRIVER_H

#include <kerneltypes_driver.h>

typedef struct system_timer_cb       system_timer_cb,       *Psystem_timer_cb;
typedef struct system_timer_info     system_timer_info,     *Psystem_timer_info;
typedef struct system_timer_register system_timer_register, *Psystem_timer_register;

typedef struct system_timer_cb       SceSTimerCB;
typedef struct system_timer_info     SceSTimerInfo;
typedef struct system_timer_register SceSTimerReg;

struct system_timer_cb {
    SceSTimerInfo SYSTMR[4];
    u_int32_t nextid;
};

struct system_timer_info {
    void    * regadr;
    int       intrcode;
    int       timid;
    SceUInt32 prev_tmcy;
    SceUInt32 prev_icnt;
    int    (* timeuphandler)(int, SceUInt32, void *, SceUInt);
    SceUInt32 totalcount;
    void    * common;
};

struct system_timer_register {
    SceUInt32 Control;
    SceUInt32 N;
    SceUInt32 M;
};

#endif /* _SCE_SYSTIMER_DRIVER_H */

#ifndef _SCE_UID_DRIVER_H
#define _SCE_UID_DRIVER_H

#include <kerneltypes_driver.h>
#include <queue_driver.h>

#include <stdarg.h>

typedef struct _UID_BASIC           _UID_BASIC,         *P_UID_BASIC;
typedef struct _UID_FUNCS           _UID_FUNCS,         *P_UID_FUNCS;
typedef struct _UID_HOLD_HEAD       _UID_HOLD_HEAD,     *P_UID_HOLD_HEAD;
typedef struct _UID_HOLD_Element    _UID_HOLD_Element,  *P_UID_HOLD_Element;
typedef struct _UID_OBJECT          _UID_OBJECT,        *P_UID_OBJECT;
typedef struct _UID_TYPE            _UID_TYPE,          *P_UID_TYPE;

typedef struct _UID_BASIC           SceUIDbasicCB;
typedef struct _UID_FUNCS           SceUIDfuncs;
typedef struct _UID_HOLD_Element    SceUIDholdElement;
typedef struct _UID_HOLD_HEAD       SceUIDholdHead;
typedef struct _UID_OBJECT          SceUIDobjectCB;
typedef struct _UID_TYPE            SceUIDtypeCB;

struct _UID_OBJECT {
    Dlink                family_link;
    struct _UID_TYPE   * isa;
    SceUID               uid;
    char               * name;
    u_int8_t             total_words;
    u_int8_t             instans_woff;
    u_int16_t            attribute;
};

struct _UID_TYPE {
    struct _UID_OBJECT o;
    union {
        struct _UID_TYPE * type_list;
        int                inherit_count;
    } t;
    struct _UID_TYPE  * super;
    struct _UID_FUNCS * funcsp;
};

struct _UID_FUNCS {
    u_int32_t sha1key;
    SceUID (* funcp)(SceUIDobjectCB *, SceUIDtypeCB *, u_int32_t, va_list);
};

struct _UID_HOLD_HEAD {
    Dlink                hold_list;
    Dlink                holder_list;
    int                  hold_count;
    int                  holder_count;
};

struct _UID_BASIC {
    SceUIDholdHead     * hold;
};

struct _UID_HOLD_Element {
    Dlink                hold_list;
    Dlink                holder_list;
    struct _UID_OBJECT * holdid;
    struct _UID_OBJECT * holderid;
};

#endif /* _SCE_UID_DRIVER_H */

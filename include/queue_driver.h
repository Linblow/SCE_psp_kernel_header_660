#ifndef _SCE_QUEUE_DRIVER_H
#define _SCE_QUEUE_DRIVER_H

typedef struct _Dlink _Dlink, *P_Dlink;
typedef struct _Dlink Dlink;

struct _Dlink {
    struct _Dlink * next;
    struct _Dlink * prev;
};

#endif /* _SCE_QUEUE_DRIVER_H */

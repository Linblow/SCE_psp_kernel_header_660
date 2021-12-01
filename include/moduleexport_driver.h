#ifndef _SCE_MODULEEXPORT_DRIVER_H
#define _SCE_MODULEEXPORT_DRIVER_H

#include <kerneltypes_driver.h>

typedef struct _scelibent   _scelibent,     *P_scelibent;
typedef struct _scelibent2  _scelibent2,    *P_scelibent2;
typedef struct _scelibstub  _scelibstub,    *P_scelibstub;
typedef struct _scelibstub2 _scelibstub2,   *P_scelibstub2;

typedef struct _scelibent   SceKernelLibraryEntryTable;
typedef struct _scelibent2  SceKernelLibraryEntryTable2;
typedef struct _scelibstub  SceKernelLibraryStubTable;
typedef struct _scelibstub2 SceKernelLibraryStubTable2;

struct _scelibent {
    char      * libname;
    u_int16_t   version;
    u_int16_t   attribute;
    u_int8_t    structsize;
    u_int8_t    nvar;
    u_int16_t   nfunc;
    void      * entrytable;
};

struct _scelibent2 {
    char      * libname;
    u_int16_t   version;
    u_int16_t   attribute;
    u_int8_t    structsize;
    u_int8_t    nvar;
    u_int16_t   nfunc;
    void      * entrytable;
    u_int16_t   nvar2;
    u_int8_t    hashinfo;
    u_int8_t    nidaltsets;
};

struct _scelibstub {
    char      * libname;
    u_int16_t   version;
    u_int16_t   attribute;
    u_int8_t    structsize;
    u_int8_t    nvar;
    u_int16_t   nfunc;
    u_int32_t * nidtable;
    void      * stubtable;
    void      * vstubtable;
};

struct _scelibstub2 {
    char      * libname;
    u_int16_t   version;
    u_int16_t   attribute;
    u_int8_t    structsize;
    u_int8_t    nvar;
    u_int16_t   nfunc;
    u_int32_t * nidtable;
    void      * stubtable;
    void      * vstubtable;
    u_int16_t   nvar2;
    u_int8_t    reserve1;
    u_int8_t    reserve2;
};

#endif /* _SCE_MODULEEXPORT_DRIVER_H */

#ifndef _SCE_KERNELTYPES_H
#define _SCE_KERNELTYPES_H

#ifndef _SCEUID
#define _SCEUID
typedef int                 SceUID;
#define SceUID_NAME_MAX     31
#endif

typedef unsigned char       SceUChar;
typedef unsigned int        SceUInt;
typedef unsigned int        SceSize;
typedef int                 SceSSize;
typedef int                 SceMode;
typedef long long           SceOff;
typedef long long           SceIores;

#endif	/* _SCE_KERNELTYPES_H */

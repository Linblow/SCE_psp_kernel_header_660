#ifndef _SCE_PL080_H
#define _SCE_PL080_H

#include <kerneltypes_driver.h>

typedef struct PL080_CHREGS PL080_CHREGS, *PPL080_CHREGS;
typedef struct PL080_LLI    PL080_LLI,    *PPL080_LLI;
typedef struct PL080_REGS   PL080_REGS,   *PPL080_REGS;

struct PL080_CHREGS {
    u_int32_t SrcAddr;
    u_int32_t DestAddr;
    u_int32_t LLI;
    u_int32_t Control;
    u_int32_t Configuration;
    u_int32_t _14_1C[3];
};

struct PL080_LLI {
    u_int32_t SrcAddr;
    u_int32_t DestAddr;
    u_int32_t LLI;
    u_int32_t Control;
};

struct PL080_REGS {
    u_int32_t IntStatus;
    u_int32_t IntTCStatus;
    u_int32_t IntTCClear;
    u_int32_t IntErrorStatus;
    u_int32_t IntErrClr;
    u_int32_t RawIntTCStatus;
    u_int32_t RawIntErrorStatus;
    u_int32_t EnbldChns;
    u_int32_t SoftBReq;
    u_int32_t SoftSReq;
    u_int32_t SoftLBReq;
    u_int32_t SoftLSReq;
    u_int32_t Configuration;
    u_int32_t Sync;
    u_int32_t SReqMask;
    u_int32_t _03C_0FC[49];
    struct PL080_CHREGS Ch[8];
    u_int32_t _200_FDC[888];
    u_int32_t PeriphID0;
    u_int32_t PeriphID1;
    u_int32_t PeriphID2;
    u_int32_t PeriphID3;
    u_int32_t CellID0;
    u_int32_t CellID1;
    u_int32_t CellID2;
    u_int32_t CellID3;
};

#endif /* _SCE_PL080_H */

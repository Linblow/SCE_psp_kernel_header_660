#ifndef _SCE_GAMEINFO_DRIVER_H
#define _SCE_GAMEINFO_DRIVER_H

#include <kerneltypes_driver.h>

typedef struct SceGameInfo SceGameInfo, *PSceGameInfo;

struct SceGameInfo {
    u_int32_t size;
    u_int32_t flags;
    u_int8_t  umd_data_string[16];
    u_int8_t  expect_umd_data[16];
    char      QTGP2[8];
    char      QTGP3[16];
    u_int32_t allow_replace_umd;
    u_int8_t  param_product_string[16];
    u_int32_t param_parental;
    char      vsh_version[8];
    u_int32_t umd_cache_on;
    u_int32_t compiled_sdk_version;
    u_int32_t compiler_version;
    u_int32_t DNAS;
    u_int32_t utility_location;
    char      vsh_bootfilename[64];
    u_int8_t  param_gamedata_id[16];
    char      param_app_ver[8];
    u_int8_t  subscription_validity[8];
    u_int32_t param_bootable;
    u_int32_t param_opnssmp_ver;
};

#endif /* _SCE_GAMEINFO_DRIVER_H */

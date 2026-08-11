#ifndef __SYSTEM_H
#define __SYSTEM_H

#include "include/mcemu.h"

#define SYS_LOAD_MC_MODULES   0x01
#define SYS_LOAD_USB_MODULES  0x02
#define SYS_LOAD_ISOFS_MODULE 0x04

unsigned int USBA_crc32(const char *string);
int sysGetDiscID(char *discID);
void sysInitDev9(void);
void sysShutdownDev9(void);
void sysReset(int modload_mask);
void sysExecExit(void);
void sysPowerOff(void);
#ifdef __DECI2_DEBUG
int sysInitDECI2(void);
#endif

void sysLaunchLoaderElf(const char *filename, const char *mode_str, int size_cdvdman_irx, void **cdvdman_irx, int size_mcemu_irx, void **mcemu_irx, int EnablePS2Logo, unsigned int compatflags);

int sysExecElf(const char *path);
int sysLoadModuleBuffer(void *buffer, int size, int argc, char *argv);

// Module load results surfaced by sysReset/bdmLoadModules so failures are
// visible on-screen instead of being silently dropped.
extern int g_sysUsbdLoad;
extern int g_sysUsbmassLoad;
extern int g_sysSmsutilsLoad;
extern int g_lastModuleId;
extern int g_lastModuleRet;
#ifdef PADEMU
extern int g_sysPademuLoad;
extern int g_sysXbox360Load;
extern int g_sysXboxoneLoad;
extern int g_sysPademuId;
extern int g_sysPademuRet;
extern int g_sysXbox360Id;
extern int g_sysXbox360Ret;
extern int g_sysXboxoneId;
extern int g_sysXboxoneRet;
#endif
int sysCheckMC(void);
int sysCheckVMC(const char *prefix, const char *sep, char *name, int createSize, vmc_superblock_t *vmc_superblock);

#endif

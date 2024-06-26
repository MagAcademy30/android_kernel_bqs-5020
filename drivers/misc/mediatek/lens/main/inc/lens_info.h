/*
 * Copyright (C) 2015 MediaTek Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef _MAIN_LENS_H

#define _MAIN_LENS_H

#include <linux/ioctl.h>
#include "lens_list.h"

#define MAX_NUM_OF_LENS 32

#define AF_MAGIC 'A'

/* AFDRV_XXXX be the same as AF_DRVNAME in (*af).c */
#define AFDRV_BU6424AF "BU6424AF"
#define AFDRV_DW9714AF "DW9714AF"
#define AFDRV_FM50AF   "FM50AF"

/* Structures */
struct stAF_MotorInfo {
/* current position */
	u32 u4CurrentPosition;
/* macro position */
	u32 u4MacroPosition;
/* Infinity position */
	u32 u4InfPosition;
/* Motor Status */
	bool bIsMotorMoving;
/* Motor Open? */
	bool bIsMotorOpen;
/* Support SR? */
	bool bIsSupportSR;
};

/* Structures */
struct stAF_MotorCalPos {
/* macro position */
	u32 u4MacroPos;
/* Infinity position */
	u32 u4InfPos;
};

/* Structures */
struct stAF_MotorName {
	u8 uMotorName[32];
};

/* Structures */
struct stAF_MotorCmd {
	u32 u4CmdID;
	u32 u4Param;
};

/* Structures */
struct stAF_MotorOisInfo {
	int i4OISHallPosXum;
	int i4OISHallPosYum;
	int i4OISHallFactorX;
	int i4OISHallFactorY;
};

/* Structures */
struct stAF_DrvList {
	u8 uEnable;
	u8 uDrvName[32];
	int (*pAF_SetI2Cclient)(struct i2c_client *pstAF_I2Cclient, spinlock_t *pAF_SpinLock, int *pAF_Opened);
	long (*pAF_Ioctl)(struct file *a_pstFile, unsigned int a_u4Command, unsigned long a_u4Param);
	int (*pAF_Release)(struct inode *a_pstInode, struct file *a_pstFile);
};

#define I2CBUF_MAXSIZE 10

struct stAF_CCUI2CFormat {
	u8 I2CBuf[I2CBUF_MAXSIZE];
	u8 BufSize;
};

#define I2CDATA_MAXSIZE 4
/* Structures */
struct stAF_DrvI2CFormat {
	/* Addr Format */
	u8 Addr[I2CDATA_MAXSIZE];
	u8 AddrNum;
	/* Data Format : CtrlBits | ( ( Data >> BitRR ) & Mask1 ) << BitRL ) & Mask2 */
	u8 CtrlData[I2CDATA_MAXSIZE]; /* Control Data */
	u8 BitRR[I2CDATA_MAXSIZE];
	u8 Mask1[I2CDATA_MAXSIZE];
	u8 BitRL[I2CDATA_MAXSIZE];
	u8 Mask2[I2CDATA_MAXSIZE];
	u8 DataNum;
};

#define I2CSEND_MAXSIZE 4
/* Structures */
struct stAF_MotorI2CSendCmd {
	u8 Resolution;
	u8 SlaveAddr;
	/* I2C Send */
	struct stAF_DrvI2CFormat I2CFmt[I2CSEND_MAXSIZE];
	u8 I2CSendNum;
};

/* Control commnad */
/* S means "set through a ptr" */
/* T means "tell by a arg value" */
/* G means "get by a ptr" */
/* Q means "get by return a value" */
/* X means "switch G and S atomically" */
/* H means "switch T and Q atomically" */
#define AFIOC_G_MOTORINFO _IOR(AF_MAGIC, 0, struct stAF_MotorInfo)

#define AFIOC_T_MOVETO _IOW(AF_MAGIC, 1, u32)

#define AFIOC_T_SETINFPOS _IOW(AF_MAGIC, 2, u32)

#define AFIOC_T_SETMACROPOS _IOW(AF_MAGIC, 3, u32)

#define AFIOC_G_MOTORCALPOS _IOR(AF_MAGIC, 4, struct stAF_MotorCalPos)

#define AFIOC_S_SETPARA _IOW(AF_MAGIC, 5, struct stAF_MotorCmd)

#define AFIOC_G_MOTORI2CSENDCMD _IOR(AF_MAGIC, 6, struct stAF_MotorI2CSendCmd)

#define AFIOC_S_SETDRVNAME _IOW(AF_MAGIC, 10, struct stAF_MotorName)

#define AFIOC_S_SETPOWERDOWN _IOW(AF_MAGIC, 11, u32)

#define AFIOC_G_MOTOROISINFO _IOR(AF_MAGIC, 12, struct stAF_MotorOisInfo)

#define AFIOC_S_SETPOWERCTRL _IOW(AF_MAGIC, 13, u32)

#define AFIOC_S_SETLENSTEST  _IOW(AF_MAGIC, 14, u32)

#endif

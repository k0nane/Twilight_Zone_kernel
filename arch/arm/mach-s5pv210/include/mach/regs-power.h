/* arch/arm/plat-s5pc11x/include/plat/regs-power.h
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * S5PC11X power control register definitions
*/

#ifndef __ASM_ARM_REGS_PWR
#define __ASM_ARM_REGS_PWR __FILE__


//#ifdef CONFIG_PM_PWR_GATING

/* defintion to support clock & power gating */
#define DOMAIN_ACTIVE_MODE 1
#define DOMAIN_LP_MODE     2

// Power Domain of S5PC110
//#define S5PC110_POWER_DOMAIN_TOP	(0x1 << 0)	//TOP block
#define S5PC110_POWER_DOMAIN_MFC	(0x1 << 1)	//MFC, F block
#define S5PC110_POWER_DOMAIN_G3D	(0x1 << 2)	//G3D block
#define S5PC110_POWER_DOMAIN_LCD	(0x1 << 3)	//LCD, L block
#define S5PC110_POWER_DOMAIN_TV		(0x1 << 4)	//TV, T block
#define S5PC110_POWER_DOMAIN_CAM	(0x1 << 5)	//CAM, X block
#define S5PC110_POWER_DOMAIN_AUDIO	(0x1 << 7)	//AUDIO block

#define S5PC110_POWER_DOMAIN_UNCANGIBLE_MASK 0x01000000
#define S5PC110_POWER_DOMAIN_CPU	(S5PC110_POWER_DOMAIN_UNCANGIBLE_MASK | (0x10))
#define S5PC110_POWER_DOMAIN_SYSTIMER	(S5PC110_POWER_DOMAIN_UNCANGIBLE_MASK | (0x08))
#define S5PC110_POWER_DOMAIN_TOP	(S5PC110_POWER_DOMAIN_UNCANGIBLE_MASK | (0x09))
#define S5PC110_POWER_DOMAIN_ALIVE	(S5PC110_POWER_DOMAIN_UNCANGIBLE_MASK | (0x0A))
#define S5PC110_POWER_DOMAIN_RTC	(S5PC110_POWER_DOMAIN_UNCANGIBLE_MASK | (0x0B))

// NORMAL_CFG definition
#define MFC_ACTIVE_MODE		0x02
#define G3D_ACTIVE_MODE		0x04
#define LCD_ACTIVE_MODE		0x08
#define TV_ACTIVE_MODE		0x10
#define CAM_ACTIVE_MODE		0x20
#define AUDIO_ACTIVE_MODE	0x80

// BLK_PWR_STAT definition
#define BLK_PWR_TOP_READY	0x01
#define BLK_PWR_MFC_READY	0x02
#define BLK_PWR_G3D_READY	0x04
#define BLK_PWR_LCD_READY	0x08
#define BLK_PWR_TV_READY	0x10
#define BLK_PWR_CAM_READY	0x20
#define BLK_PWR_AUDIO_READY	0x80

/*MFC domain locks*/
#define MFC_DOMAIN_LOCK_TOKEN		0x01 << 0
#define MFC_DOMAIN_LOCK_TOKEN_SET	(MFC_DOMAIN_LOCK_TOKEN)

/*G3D domain locks*/
#define G3D_DOMAIN_LOCK_TOKEN		0x01 << 1
#define G3D_DOMAIN_LOCK_TOKEN_SET	(G3D_DOMAIN_LOCK_TOKEN)

/*LCD domain locks*/
#define FIMD_DOMAIN_LOCK_TOKEN		0x01 << 2
#define MIE_DOMAIN_LOCK_TOKEN		0x01 << 3
#define DSIM_DOMAIN_LOCK_TOKEN		0x01 << 4
#define LCD_DOMAIN_LOCK_TOKEN_SET	(FIMD_DOMAIN_LOCK_TOKEN \
|MIE_DOMAIN_LOCK_TOKEN|DSIM_DOMAIN_LOCK_TOKEN)

/*TV domain locks*/
#define VP_DOMAIN_LOCK_TOKEN		0x01 << 5
#define MIXER_DOMAIN_LOCK_TOKEN		0x01 << 6
#define TVENC_DOMAIN_LOCK_TOKEN		0x01 << 7
#define HDMI_DOMAIN_LOCK_TOKEN		0x01 << 8
#define TV_DOMAIN_LOCK_TOKEN_SET	(VP_DOMAIN_LOCK_TOKEN \
|MIXER_DOMAIN_LOCK_TOKEN|TVENC_DOMAIN_LOCK_TOKEN|HDMI_DOMAIN_LOCK_TOKEN)

/*Camera domain locks*/
#define FIMC0_DOMAIN_LOCK_TOKEN		0x01 << 9
#define FIMC1_DOMAIN_LOCK_TOKEN		0x01 << 10
#define FIMC2_DOMAIN_LOCK_TOKEN		0x01 << 11
#define JPEG_DOMAIN_LOCK_TOKEN		0x01 << 12
#define ROTATOR_DOMAIN_LOCK_TOKEN	0x01 << 13
#define IPC_DOMAIN_LOCK_TOKEN		0x01 << 14
#define CSIS_DOMAIN_LOCK_TOKEN		0x01 << 15
#define CAMERA_DOMAIN_LOCK_TOKEN_SET	(FIMC0_DOMAIN_LOCK_TOKEN \
|FIMC1_DOMAIN_LOCK_TOKEN|FIMC2_DOMAIN_LOCK_TOKEN|JPEG_DOMAIN_LOCK_TOKEN \
|ROTATOR_DOMAIN_LOCK_TOKEN|IPC_DOMAIN_LOCK_TOKEN|CSIS_DOMAIN_LOCK_TOKEN)

/*audio domain lock*/
#define I2S0_DOMAIN_LOCK_TOKEN		0x01 << 16

/*Power domain sets*/

/*MFC domain clock set*/
#define POWER_DOMAIN_MFC_CLOCK_SET	(S5P_CLKGATE_IP0_MFC)

/*G3D domain clock set*/
#define POWER_DOMAIN_G3D_CLOCK_SET	(S5P_CLKGATE_IP0_G3D)

/*LCD domain clock set*/
#define POWER_DOMAIN_LCD_CLOCK_SET	(S5P_CLKGATE_IP1_FIMD \
|S5P_CLKGATE_IP1_MIE|S5P_CLKGATE_IP1_DSIM)

/*TV domain lock set*/
#define POWER_DOMAIN_TV_CLOCK_SET	(S5P_CLKGATE_IP1_VP \
|S5P_CLKGATE_IP1_MIXER|S5P_CLKGATE_IP1_TVENC|S5P_CLKGATE_IP1_HDMI)

/*Camera domain lock set*/
#define POWER_DOMAIN_CAMERA_CLOCK_SET	(S5P_CLKGATE_IP0_FIMC0 \
|S5P_CLKGATE_IP0_FIMC1|S5P_CLKGATE_IP0_FIMC2|S5P_CLKGATE_IP0_JPEG \
|S5P_CLKGATE_IP0_ROTATOR|S5P_CLKGATE_IP0_IPC|S5P_CLKGATE_IP0_CSIS)


//api
extern void s5pc110_lock_power_domain(unsigned int nToken);
extern void s5pc110_unlock_power_domain(unsigned int nToken);
extern int s5p_power_gating(unsigned int power_domain, unsigned int on_off);

//#endif //CONFIG_PM_PWR_GATING


#endif /* __ASM_ARM_REGS_PWR */

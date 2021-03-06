/*
 * Copyright (c) 2013-2014, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __REGULATOR_CPR_REGULATOR_H__
#define __REGULATOR_CPR_REGULATOR_H__

#include <linux/regulator/machine.h>

#define CPR_REGULATOR_DRIVER_NAME	"qcom,cpr-regulator"

/**
 * enum cpr_fuse_corner_enum - CPR fuse corner enum values
 * %CPR_FUSE_CORNER_SVS:		Lowest voltage for APC
 * %CPR_FUSE_CORNER_NORMAL:		Normal mode voltage
 * %CPR_FUSE_CORNER_TURBO:		Turbo mode voltage
 * %CPR_FUSE_CORNER_SUPER_TURBO:	Super Turbo mode voltage
 *
 * These should be used in regulator_set_voltage() for CPR
 * regulator as if they had units of uV.
 */
enum cpr_fuse_corner_enum {
	CPR_FUSE_CORNER_SVS = 1,
	CPR_FUSE_CORNER_NORMAL,
	CPR_FUSE_CORNER_TURBO,
	CPR_FUSE_CORNER_MAX,
};

/**
 * enum vdd_mx_vmin_method - Method to determine vmin for vdd-mx
 * %VDD_MX_VMIN_APC:			Equal to APC voltage
 * %VDD_MX_VMIN_APC_CORNER_CEILING:	Equal to PVS corner ceiling voltage
 * %VDD_MX_VMIN_APC_SLOW_CORNER_CEILING:
 *					Equal to slow speed corner ceiling
 * %VDD_MX_VMIN_MX_VMAX:		Equal to specified vdd-mx-vmax voltage
 * %VDD_MX_VMIN_APC_CORNER_MAP:		Equal to the APC corner mapped MX
 *					voltage
 */
enum vdd_mx_vmin_method {
	VDD_MX_VMIN_APC,
	VDD_MX_VMIN_APC_CORNER_CEILING,
	VDD_MX_VMIN_APC_SLOW_CORNER_CEILING,
	VDD_MX_VMIN_MX_VMAX,
	VDD_MX_VMIN_APC_CORNER_MAP,
};

#ifdef CONFIG_MSM_CPR_REGULATOR

int __init cpr_regulator_init(void);

#else

static inline int __init cpr_regulator_init(void)
{
	return -ENODEV;
}

#endif /* CONFIG_MSM_CPR_REGULATOR */

#endif /* __REGULATOR_CPR_REGULATOR_H__ */

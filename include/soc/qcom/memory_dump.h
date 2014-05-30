/* Copyright (c) 2012, 2014, The Linux Foundation. All rights reserved.
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

#ifndef __MSM_MEMORY_DUMP_H
#define __MSM_MEMORY_DUMP_H

#include <linux/types.h>

enum dump_client_type {
	MSM_CPU_CTXT = 0,
	MSM_L1_CACHE,
	MSM_L2_CACHE,
	MSM_OCMEM,
	MSM_TMC_ETFETB,
	MSM_ETM0_REG,
	MSM_ETM1_REG,
	MSM_ETM2_REG,
	MSM_ETM3_REG,
	MSM_TMC0_REG, /* TMC_ETR */
	MSM_TMC1_REG, /* TMC_ETF */
	MSM_LOG_BUF,
	MSM_LOG_BUF_FIRST_IDX,
	MAX_NUM_CLIENTS,
};

struct msm_client_dump {
	enum dump_client_type id;
	unsigned long start_addr;
	unsigned long end_addr;
};

struct msm_dump_table {
	u32 version;
	u32 num_entries;
	struct msm_client_dump client_entries[MAX_NUM_CLIENTS];
};

#ifdef CONFIG_MSM_MEMORY_DUMP
extern int msm_dump_tbl_register(struct msm_client_dump *client_entry);
#else
static inline int msm_dump_tbl_register(struct msm_client_dump *entry)
{
	return -EIO;
}
#endif


#if defined(CONFIG_MSM_MEMORY_DUMP) || defined(CONFIG_MSM_MEMORY_DUMP_V2)
extern uint32_t msm_dump_table_version(void);
#else
static inline uint32_t msm_dump_table_version(void)
{
	return 0;
}
#endif

#define MSM_DUMP_MAKE_VERSION(ma, mi)	((ma << 20) | mi)
#define MSM_DUMP_MAJOR(val)		(val >> 20)
#define MSM_DUMP_MINOR(val)		(val & 0xFFFFF)


#define MAX_NUM_ENTRIES		0x120

enum msm_dump_data_ids {
	MSM_DUMP_DATA_CPU_CTX = 0x00,
	MSM_DUMP_DATA_L1_INST_CACHE = 0x60,
	MSM_DUMP_DATA_L1_DATA_CACHE = 0x80,
	MSM_DUMP_DATA_ETM_REG = 0xA0,
	MSM_DUMP_DATA_L2_CACHE = 0xC0,
	MSM_DUMP_DATA_L3_CACHE = 0xD0,
	MSM_DUMP_DATA_OCMEM = 0xE0,
	MSM_DUMP_DATA_MISC = 0xE8,
	MSM_DUMP_DATA_TMC_ETF = 0xF0,
	MSM_DUMP_DATA_TMC_REG = 0x100,
	MSM_DUMP_DATA_LOG_BUF = 0x110,
	MSM_DUMP_DATA_LOG_BUF_FIRST_IDX = 0x111,
	MSM_DUMP_DATA_MAX = MAX_NUM_ENTRIES,
};

struct msm_memory_dump {
	unsigned long dump_table_phys;
	struct msm_dump_table *dump_table_ptr;
};

#define TABLE_MAJOR(val)	(val >> 20)
#define TABLE_MINOR(val)	(val & 0xFFFFF)
#define MK_TABLE(ma, mi)	((ma << 20) | mi)

#ifndef CONFIG_MSM_MEMORY_DUMP
static inline int msm_dump_table_register(struct msm_client_dump *entry)
{
	return -EIO;
}
#else
int msm_dump_table_register(struct msm_client_dump *client_entry);
#endif
#endif

/*
 *  arch/arm/mach-mxs/include/mach/uncompress.h
 *
 *  Copyright (C) 1999 ARM Limited
 *  Copyright (C) Shane Nay (shane@minirl.com)
 *  Copyright 2010 Freescale Semiconductor, Inc. All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
#ifndef __MACH_MXS_UNCOMPRESS_H__
#define __MACH_MXS_UNCOMPRESS_H__

#include <asm/mach-types.h>

#define MX23_DUART_BASE_ADDR	0x80070000
#define MX28_DUART_BASE_ADDR	0x80074000

static inline void arch_decomp_setup(void)
{
	switch (arch_id) {
	case MACH_TYPE_MX23EVK:
		ucuart_init_amba01x(MX23_DUART_BASE_ADDR);
		break;
	case MACH_TYPE_MX28EVK:
	case MACH_TYPE_TX28:
		ucuart_init_amba01x(MX28_DUART_BASE_ADDR);
		break;
	default:
		break;
	}
}

#endif /* __MACH_MXS_UNCOMPRESS_H__ */

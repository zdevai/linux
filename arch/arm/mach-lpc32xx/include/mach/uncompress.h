/*
 * arch/arm/mach-lpc32xx/include/mach/uncompress.h
 *
 * Author: Kevin Wells <kevin.wells@nxp.com>
 *
 * Copyright (C) 2010 NXP Semiconductors
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

#ifndef __ASM_ARM_ARCH_UNCOMPRESS_H
#define __ASM_ARM_ARCH_UNCOMPRESS_H

#include <mach/platform.h>

static inline void arch_decomp_setup(void)
{
	ucuart_init_8250(LPC32XX_UART5_BASE, 2, UCUART_IO_MEM32);
}

#endif

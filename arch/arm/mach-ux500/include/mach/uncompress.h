/*
 *  Copyright (C) 2009 ST-Ericsson
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
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef __ASM_ARCH_UNCOMPRESS_H
#define __ASM_ARCH_UNCOMPRESS_H

#include <asm/mach-types.h>
#include <mach/hardware.h>

static inline void arch_decomp_setup(void)
{
	/* Check in run time if we run on an U8500 or U5500 */
	if (machine_is_u5500())
		ucuart_init_amba01x(U5500_UART0_BASE);
	else
		ucuart_init_amba01x(U8500_UART2_BASE);
}

#endif /* __ASM_ARCH_UNCOMPRESS_H */

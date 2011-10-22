/*
 *  arch/arm/mach-realview/include/mach/uncompress.h
 *
 *  Copyright (C) 2003 ARM Limited
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
#include <asm/mach-types.h>

#include <mach/board-eb.h>
#include <mach/board-pb11mp.h>
#include <mach/board-pb1176.h>
#include <mach/board-pba8.h>
#include <mach/board-pbx.h>

static inline void arch_decomp_setup(void)
{
	int uart_base;

	if (machine_is_realview_eb())
		uart_base = REALVIEW_EB_UART0_BASE;
	else if (machine_is_realview_pb11mp())
		uart_base = REALVIEW_PB11MP_UART0_BASE;
	else if (machine_is_realview_pb1176())
		uart_base = REALVIEW_PB1176_UART0_BASE;
	else if (machine_is_realview_pba8())
		uart_base = REALVIEW_PBA8_UART0_BASE;
	else if (machine_is_realview_pbx())
		uart_base = REALVIEW_PBX_UART0_BASE;
	else
		return;

	ucuart_init_amba01x(uart_base);
}

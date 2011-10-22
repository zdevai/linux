/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
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

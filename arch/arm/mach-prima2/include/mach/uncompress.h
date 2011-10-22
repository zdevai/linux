/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <mach/uart.h>

static inline void arch_decomp_setup(void)
{
	ucuart_init(SIRFSOC_UART1_PA_BASE, 0, UCUART_IO_MEM32,
			SIRFSOC_UART_TXFIFO_DATA, SIRFSOC_UART_TXFIFO_STATUS,
			SIRFSOC_UART1_TXFIFO_FULL, 0, 0, 0, 0);
}

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <mach/zynq_soc.h>
#include <mach/uart.h>

static inline void arch_decomp_setup(void)
{
	ucuart_init(LL_UART_PADDR, 0, UCUART_IO_MEM32, UART_FIFO_OFFSET,
			UART_SR_OFFSET, UART_SR_TXFULL, 0,
			UART_SR_OFFSET, UART_SR_TXEMPTY, UART_SR_TXEMPTY);
}

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <mach/tcc8k-regs.h>

static inline void arch_decomp_setup(void)
{
	ucuart_init_8250(UART_BASE_PHYS, 2, UCUART_IO_MEM32);
}

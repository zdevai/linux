/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <mach/orion5x.h>

static inline void arch_decomp_setup(void)
{
	ucuart_init_8250(UART0_PHYS_BASE, 2, UCUART_IO_MEM8);
}

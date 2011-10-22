/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <mach/hardware.h>

static inline void arch_decomp_setup(void)
{
	ucuart_init_8250(IOP13XX_UART1_PHYS, 2, UCUART_IO_MEM32);
}

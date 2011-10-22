/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <mach/hardware.h>

/* debug-macro.S treats this port as an AMBA01x, but according to the
 * datasheet, this should be a 8250
 */
static inline void arch_decomp_setup(void)
{
	ucuart_init_8250(SERIAL0_BASE, 2, UCUART_IO_MEM8);
}

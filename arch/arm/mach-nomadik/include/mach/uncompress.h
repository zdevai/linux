/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <mach/hardware.h>

static inline void arch_decomp_setup(void)
{
	ucuart_init_amba01x(NOMADIK_UART1_BASE);
}

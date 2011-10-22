/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
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

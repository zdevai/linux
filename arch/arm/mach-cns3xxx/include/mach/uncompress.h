/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <asm/mach-types.h>
#include <mach/cns3xxx.h>

static inline void arch_decomp_setup(void)
{
	if (machine_is_cns3420vb())
		ucuart_init_amba01x(CNS3XXX_UART0_BASE);
}

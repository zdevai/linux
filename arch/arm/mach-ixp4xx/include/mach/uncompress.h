/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include "ixp4xx-regs.h"
#include <asm/mach-types.h>

static inline void arch_decomp_setup(void)
{
	/*
	 * Some boards are using UART2 as console
	 */
	if (machine_is_adi_coyote() || machine_is_gtwx5715() ||
	    machine_is_gateway7001() || machine_is_wg302v2() ||
	    machine_is_devixp() || machine_is_miccpt() || machine_is_mic256())
		ucuart_init_8250(IXP4XX_UART2_BASE_PHYS, 2, UCUART_IO_MEM32);
	else
		ucuart_init_8250(IXP4XX_UART1_BASE_PHYS, 2, UCUART_IO_MEM32);
}

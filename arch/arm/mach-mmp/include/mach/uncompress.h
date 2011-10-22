/*
 * arch/arm/mach-mmp/include/mach/uncompress.h
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <mach/addr-map.h>
#include <asm/mach-types.h>

#define UART1_BASE	(APB_PHYS_BASE + 0x36000)
#define UART2_BASE	(APB_PHYS_BASE + 0x17000)
#define UART3_BASE	(APB_PHYS_BASE + 0x18000)

static inline void arch_decomp_setup(void)
{
	if (machine_is_avengers_lite())
		ucuart_init_8250(UART3_BASE, 2, UCUART_IO_MEM32);
	else
		ucuart_init_8250(UART2_BASE, 2, UCUART_IO_MEM32);
}

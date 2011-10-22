/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <asm/mach-types.h>

/*
 * Note! This could cause problems on the NetWinder
 */
#define DC21285_BASE	0x42000160
#define SER0_BASE	0x7c0003f8

static inline void arch_decomp_setup(void)
{
	if (machine_is_netwinder())
		ucuart_init_8250(SER0_BASE, 0, UCUART_IO_MEM8);
	else
		ucuart_init(DC21285_BASE, 2, UCUART_IO_MEM32, 0,
				6, 8, 0,
				0, 0, 0);
}

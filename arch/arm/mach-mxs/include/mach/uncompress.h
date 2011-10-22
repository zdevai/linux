/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <asm/mach-types.h>

#define MX23_DUART_BASE_ADDR	0x80070000
#define MX28_DUART_BASE_ADDR	0x80074000

static inline void arch_decomp_setup(void)
{
	switch (arch_id) {
	case MACH_TYPE_MX23EVK:
		ucuart_init_amba01x(MX23_DUART_BASE_ADDR);
		break;
	case MACH_TYPE_MX28EVK:
	case MACH_TYPE_TX28:
		ucuart_init_amba01x(MX28_DUART_BASE_ADDR);
		break;
	default:
		break;
	}
}

/*
 * arch/arm/mach-shark/include/mach/uncompress.h
 * by Alexander Schulz
 *
 * derived from:
 * arch/arm/mach-footbridge/include/mach/uncompress.h
 * Copyright (C) 1996,1997,1998 Russell King
 */

#define ARCH_HAVE_UCUART_GENERIC

static inline void arch_decomp_setup(void)
{
	ucuart_init_8250(0x400003f8, 0, UCUART_IO_MEM8);
}

/*
 * Copyright (C) 2009 Hans J. Koch <hjk@linutronix.de>
 *
 * This file is licensed under the terms of the GPL version 2.
 */
#include <mach/tcc8k-regs.h>

#define ARCH_HAVE_UCUART_GENERIC

static inline void arch_decomp_setup(void)
{
	ucuart_init_8250(UART_BASE_PHYS, 2, UCUART_IO_MEM32);
}

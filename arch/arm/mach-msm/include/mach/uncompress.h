/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include "hardware.h"
#include "mach/msm_iomap.h"

#ifndef MSM_DEBUG_UART_PHYS
#define MSM_DEBUG_UART_PHYS 0
#endif /* MSM_DEBUG_UART_PHYS */

static inline void arch_decomp_setup(void)
{
	ucuart_init(MSM_DEBUG_UART_PHYS, 2, UCUART_IO_MEM32, 0x0c,
			0x08, 0x04, 0x04,
			0, 0, 0);
}

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <mach/hardware.h>
#include <asm/hardware/clps7111.h>

#ifdef CONFIG_DEBUG_CLPS711X_UART2
#define SYSFLGx	SYSFLG2
#define UARTDRx	UARTDR2
#else
#define SYSFLGx	SYSFLG1
#define UARTDRx	UARTDR1
#endif

static inline void arch_decomp_setup(void)
{
	ucuart_init(CLPS7111_PHYS_BASE, 0, UCUART_IO_MEM32, UARTDRx,
			SYSFLGx, SYSFLG_UTXOFF, 0,
			SYSFLGx, SYSFLG_UBUSY, 0);
}

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <linux/types.h>
#include <linux/serial_reg.h>

#include <mach/iomap.h>

static inline void arch_decomp_setup(void)
{
	void __iomem *uart_base = (void*)TEGRA_DEBUG_UART_BASE;

	__raw_writel(__raw_readl(uart_base + UART_LCR << 2) | UART_LCR_DLAB,
			uart_base + UART_LCR << 2);
	__raw_writel(0x75, uart_base + UART_DLL << 2);
	__raw_writel(0, uart_base + UART_DLM << 2);
	__raw_writel(3, uart_base + UART_LCR << 2);

	ucuart_init_8250(TEGRA_DEBUG_UART_BASE, 2, UCUART_IO_MEM8);
}

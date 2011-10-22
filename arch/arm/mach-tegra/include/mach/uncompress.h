/*
 * arch/arm/mach-tegra/include/mach/uncompress.h
 *
 * Copyright (C) 2010 Google, Inc.
 *
 * Author:
 *	Colin Cross <ccross@google.com>
 *	Erik Gilling <konkers@google.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __MACH_TEGRA_UNCOMPRESS_H
#define __MACH_TEGRA_UNCOMPRESS_H

#include <linux/types.h>
#include <linux/serial_reg.h>

#include <mach/iomap.h>

#define ARCH_HAVE_UCUART_GENERIC

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

#endif

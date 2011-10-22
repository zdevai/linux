/*
 * arch/arm/plat-spear/include/plat/uncompress.h
 *
 * Serial port stubs for kernel decompress status messages
 *
 * Copyright (C) 2009 ST Microelectronics
 * Viresh Kumar<viresh.kumar@st.com>
 *
 * This file is licensed under the terms of the GNU General Public
 * License version 2. This program is licensed "as is" without any
 * warranty of any kind, whether express or implied.
 */
#include <mach/hardware.h>

#ifndef __PLAT_UNCOMPRESS_H
#define __PLAT_UNCOMPRESS_H

static inline void arch_decomp_setup(void)
{
	ucuart_init_amba01x(SPEAR_DBG_UART_BASE);
}
#endif /* __PLAT_UNCOMPRESS_H */

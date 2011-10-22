/* arch/arm/mach-msm/include/mach/uncompress.h
 *
 * Copyright (C) 2007 Google, Inc.
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

#ifndef __ASM_ARCH_MSM_UNCOMPRESS_H

#include "hardware.h"
#include "linux/io.h"
#include "mach/msm_iomap.h"

static inline void arch_decomp_setup(void)
{
#if defined(MSM_DEBUG_UART_PHYS)
	ucuart_init(MSM_DEBUG_UART_PHYS, 2, UCUART_IO_MEM32, 0x0c,
			0x08, 0x04, 0x04,
			0, 0, 0);
#endif /* MSM_DEBUG_UART_PHYS */
}
#endif

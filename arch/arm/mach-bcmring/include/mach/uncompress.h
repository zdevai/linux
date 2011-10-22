/*****************************************************************************
* Copyright 2005 - 2008 Broadcom Corporation.  All rights reserved.
*
* Unless you and Broadcom execute a separate written software license
* agreement governing use of this software, this software is licensed to you
* under the terms of the GNU General Public License version 2, available at
* http://www.broadcom.com/licenses/GPLv2.php (the "GPL").
*
* Notwithstanding the above, under no circumstances may you combine this
* software in any way with any other Broadcom software provided under a
* license other than the GPL, without Broadcom's express prior written
* consent.
*****************************************************************************/
#include <mach/csp/mm_addr.h>

#define BCMRING_UART_0_DR	MM_ADDR_IO_UARTA
#define BCMRING_UART_0_FR	0x18

#define ARCH_HAVE_UCUART_GENERIC
static inline void arch_decomp_setup(void)
{
	ucuart_init(MM_ADDR_IO_UARTA, 0, UCUART_IO_MEM32, BCMRING_UART_0_DR,
			BCMRING_UART_0_FR, (1 << 5), 0,
			BCMRING_UART_0_FR, (1 << 7) | (1 << 3), (1 << 7));
}

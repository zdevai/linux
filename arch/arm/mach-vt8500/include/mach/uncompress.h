/* arch/arm/mach-vt8500/include/mach/uncompress.h
 *
 * Copyright (C) 2010 Alexey Charkov <alchark@gmail.com>
 *
 * Based on arch/arm/mach-dove/include/mach/uncompress.h
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
#define ARCH_HAVE_UCUART_GENERIC

static inline void arch_decomp_setup(void)
{
	ucuart_init(0xd8200000, 0, UCUART_IO_MEM8, 0, 0x1C, 0x2, 0, 0, 0, 0);
}

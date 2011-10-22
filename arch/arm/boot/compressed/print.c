/*
 * misc.c
 * 
 * This is a collection of several routines from gzip-1.0.3 
 * adapted for Linux.
 *
 * malloc by Hannu Savolainen 1993 and Matthias Urlichs 1994
 *
 * Modified for ARM Linux by Russell King
 *
 * Nicolas Pitre <nico@visuaide.com>  1999/04/14 :
 *  For this code to run directly from Flash, all constant variables must
 *  be marked with 'const' and all other variables initialized at run-time 
 *  only.  This way all non constant variables will end up in the bss segment,
 *  which should point to addresses in RAM and cleared to 0 on start.
 *  This allows for a much quicker boot time.
 */

#include <linux/compiler.h>	/* for inline */
#include <linux/types.h>
#include <linux/linkage.h>

void putstr(const char *ptr);
void error(char *x);
extern unsigned int __machine_arch_type;
#define arch_id __machine_arch_type

enum ucuart_iotypes {
	UCUART_IO_MEM32 = 0,
	UCUART_IO_MEM8,
};

struct uncompress_uart {
	void __iomem		*base;
	int			reg_shift;
	enum ucuart_iotypes	iotype;
	int			tx_regoff;
	int			txfree_regoff;
	int			txfree_mask;
	int			txfree_val;
	int			flush_regoff;
	int			flush_mask;
	int			flush_val;
};

void ucuart_init(int base, int regshift, enum ucuart_iotypes iotype,
		 int tx_regoff, int txfree_regoff, int txfree_mask,
		 int txfree_val, int flush_regoff, int flush_mask,
		 int flush_val);

void ucuart_init_8250(int base, int regshift, enum ucuart_iotypes iotype);
void ucuart_init_amba01x(int base);

struct uncompress_uart ucuart;

#ifdef CONFIG_UCUART_DT
#include <libfdt.h>

/* Just a concept sketch... */
void ucuart_init_dt(void *fdt)
{
	int ret, offset;
	const void *prop;
	const int *uart_base, *uart_regshift;
	enum ucuart_iotypes iotype = UCUART_IO_MEM8;

	ret = fdt_check_header(fdt);
	if (ret < 0)
		return;

	offset = fdt_path_offset(fdt, "/chosen");
	if (offset == -FDT_ERR_NOTFOUND)
		return;

	prop = fdt_getprop(fdt, offset, "linux,ucuart-8250", NULL);
	if (!prop) {
		putstr("non-8250 uart\n");
		return;
	}

	prop = fdt_getprop(fdt, offset, "linux,ucuart-io-32", NULL);
	if (prop)
		iotype = UCUART_IO_MEM32;

	uart_base = fdt_getprop(fdt, offset, "linux,ucuart-base", NULL);
	uart_regshift = fdt_getprop(fdt, offset, "linux,ucuart-regshift", NULL);

	prop = fdt_getprop(fdt, offset, "linux,ucuart-8250", NULL);
	if (prop)
		ucuart_init_8250(*uart_base, *uart_regshift, iotype);

	prop = fdt_getprop(fdt, offset, "linux,ucuart-amba01x", NULL);
	if (prop)
		ucuart_init_amba01x(*uart_base);

	fdt_pack(fdt);
}
#endif

#include <mach/uncompress.h>

#ifndef ARCH_UCUART_NONGENERIC

#include <linux/io.h>
#include <linux/serial_reg.h>
#include <linux/amba/serial.h>

void ucuart_init(int base, int regshift, enum ucuart_iotypes iotype,
		 int tx_regoff, int txfree_regoff, int txfree_mask,
		 int txfree_val, int flush_regoff, int flush_mask,
		 int flush_val)
{
	ucuart.base = (void __iomem *)base;
	ucuart.reg_shift = regshift;
	ucuart.iotype = iotype;

	ucuart.tx_regoff = tx_regoff;
	ucuart.txfree_regoff = txfree_regoff;
	ucuart.txfree_mask = txfree_mask;
	ucuart.txfree_val = txfree_val;
	ucuart.flush_regoff = flush_regoff;
	ucuart.flush_mask = flush_mask;
	ucuart.flush_val = flush_val;
}

void inline ucuart_init_8250(int base, int regshift, enum ucuart_iotypes iotype)
{
	ucuart_init(base, regshift, iotype, UART_TX,
			UART_LSR, UART_LSR_THRE, UART_LSR_THRE,
			UART_LSR, (UART_LSR_TEMT | UART_LSR_THRE),
			(UART_LSR_TEMT | UART_LSR_THRE));
}

void ucuart_init_amba01x(int base)
{
	/* Do nothing if the UART is not enabled. */
	if (!(__raw_readl(base + UART011_CR) & UART01x_CR_UARTEN))
		return;

	ucuart_init(base, 0, UCUART_IO_MEM32, UART01x_DR,
			UART01x_FR, UART01x_FR_TXFF, 0,
			UART01x_FR, UART01x_FR_BUSY, 0);
}

static inline int uart_read(int regoff)
{
	if (ucuart.iotype == UCUART_IO_MEM32)
		return __raw_readl(ucuart.base + (regoff << ucuart.reg_shift));
	else
		return __raw_readb(ucuart.base + (regoff << ucuart.reg_shift));
}

static inline void uart_write(int regoff, int value)
{
	if (ucuart.iotype == UCUART_IO_MEM32)
		__raw_writel(value, ucuart.base + (regoff << ucuart.reg_shift));
	else
		__raw_writeb(value, ucuart.base + (regoff << ucuart.reg_shift));
}

static inline void putc(int ch)
{
	if (!ucuart.base)
		return;

	if (ucuart.txfree_regoff) {
		while ((uart_read(ucuart.txfree_regoff) & ucuart.txfree_mask)
				!= ucuart.txfree_val)
			barrier();
	}

	uart_write(ucuart.tx_regoff, ch);
}

static inline void flush(void)
{
	if (ucuart.flush_regoff) {
		while ((uart_read(ucuart.flush_regoff) & ucuart.flush_mask) !=
				ucuart.flush_val)
			barrier();
	}
}
#endif /* ARCH_HAVE_UCUART_GENERIC */


#ifdef CONFIG_DEBUG_ICEDCC

#if defined(CONFIG_CPU_V6) || defined(CONFIG_CPU_V6K) || defined(CONFIG_CPU_V7)

static void icedcc_putc(int ch)
{
	int status, i = 0x4000000;

	do {
		if (--i < 0)
			return;

		asm volatile ("mrc p14, 0, %0, c0, c1, 0" : "=r" (status));
	} while (status & (1 << 29));

	asm("mcr p14, 0, %0, c0, c5, 0" : : "r" (ch));
}

#elif defined(CONFIG_CPU_XSCALE)

static void icedcc_putc(int ch)
{
	int status, i = 0x4000000;

	do {
		if (--i < 0)
			return;

		asm volatile ("mrc p14, 0, %0, c14, c0, 0" : "=r" (status));
	} while (status & (1 << 28));

	asm("mcr p14, 0, %0, c8, c0, 0" : : "r" (ch));
}

#else

static void icedcc_putc(int ch)
{
	int status, i = 0x4000000;

	do {
		if (--i < 0)
			return;

		asm volatile ("mrc p14, 0, %0, c0, c0, 0" : "=r" (status));
	} while (status & 2);

	asm("mcr p14, 0, %0, c1, c0, 0" : : "r" (ch));
}

#endif

#define putc(ch)	icedcc_putc(ch)
#define flush()
#endif /* CONFIG_DEBUG_ICEDCC */

void putstr(const char *ptr)
{
	char c;

	while ((c = *ptr++) != '\0') {
		if (c == '\n')
			putc('\r');
		putc(c);
	}

	flush();
}

#ifndef arch_error
#define arch_error(x)
#endif

void error(char *x)
{
	arch_error(x);

	putstr("\n\n");
	putstr(x);
	putstr("\n\n -- System halted");

	while(1);	/* Halt */
}

void inline decomp_setup(void)
{
	arch_decomp_setup();
}

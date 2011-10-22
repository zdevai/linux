/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <linux/atmel_serial.h>

#if defined(CONFIG_AT91_EARLY_DBGU)
#define UART_OFFSET (AT91_DBGU + AT91_BASE_SYS)
#elif defined(CONFIG_AT91_EARLY_USART0)
#define UART_OFFSET AT91_USART0
#elif defined(CONFIG_AT91_EARLY_USART1)
#define UART_OFFSET AT91_USART1
#elif defined(CONFIG_AT91_EARLY_USART2)
#define UART_OFFSET AT91_USART2
#elif defined(CONFIG_AT91_EARLY_USART3)
#define UART_OFFSET AT91_USART3
#elif defined(CONFIG_AT91_EARLY_USART4)
#define UART_OFFSET AT91_USART4
#elif defined(CONFIG_AT91_EARLY_USART5)
#define UART_OFFSET AT91_USART5
#elif
#define UART_OFFSET 0

static inline void arch_decomp_setup(void)
{
	ucuart_init(UART_OFFSET, 0, UCUART_IO_MEM32, ATMEL_US_THR,
			ATMEL_US_CSR, ATMEL_US_TXRDY, ATMEL_US_TXRDY,
			ATMEL_US_CSR, ATMEL_US_TXEMPTY, ATMEL_US_TXEMPTY);
}

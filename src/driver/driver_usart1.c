#include "driver_usart1.h"


static void driver_usart1_clock_setup();

static void driver_usart1_clock_setup(){
    rcc_periph_clock_enable(RCC_GPIOA);
    rcc_periph_clock_enable(RCC_AFIO);
    rcc_periph_clock_enable(RCC_USART1);
}

void driver_usart1_setup(){
    driver_usart1_clock_setup();

    /* Setup GPIO pin GPIO_USART1_RE_TX on GPIO port B for transmit. */
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO_USART1_TX);

	/* Setup UART parameters. */
	usart_set_baudrate(USART1, 115200);
	usart_set_databits(USART1, 8);
	usart_set_stopbits(USART1, USART_STOPBITS_1);
	usart_set_parity(USART1, USART_PARITY_NONE);
	usart_set_flow_control(USART1, USART_FLOWCONTROL_NONE);
	usart_set_mode(USART1, USART_MODE_TX);

	/* Finally enable the USART. */
	usart_enable(USART1);
}

void driver_usart1_puts(char *s){
	while(*s){
		usart_send_blocking(USART1, *s);
		s++;
	}
	return;
}

void usart1_printf(char *fmt, ...){
	char buffer[CMD_BUFFER_LEN + 1];
	va_list arg_ptr;
	va_start(arg_ptr, fmt); 
	vsnprintf(buffer, CMD_BUFFER_LEN+1, fmt, arg_ptr);
	driver_usart1_puts(buffer);
	va_end(arg_ptr);	
}
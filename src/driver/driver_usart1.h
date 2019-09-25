#ifndef DRIVER_USART1_H
#define DRIVER_USART1_H

#include <stdint.h>
#include <stdio.h>
#include <errno.h>
#include <stdarg.h>
#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/usart.h>

#define CMD_BUFFER_LEN  64

void driver_usart1_setup();
void driver_usart1_puts(char *s);
void usart1_printf(char *fmt, ...);

#endif
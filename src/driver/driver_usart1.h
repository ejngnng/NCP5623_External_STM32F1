#ifndef DRIVER_USART1_H
#define DRIVER_USART1_H

#include <stdint.h>
#include <stdio.h>
#include <errno.h>
#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/usart.h>



void driver_usart1_setup();
int _write(int file, char *ptr, int len);

#endif
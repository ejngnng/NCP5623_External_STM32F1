#ifndef DRIVER_TICK_H
#define DRIVER_TICK_H

#include <stdint.h>
#include <libopencm3/cm3/common.h>

void driver_tick_setup();
uint32_t millis();
void delay_ms(uint32_t ms);

void sys_tick_handler();

#endif
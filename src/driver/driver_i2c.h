#ifndef DRIVER_I2C_H
#define DRIVER_I2C_H

#include <stdint.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/i2c.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/cm3/nvic.h>

typedef struct _rgb_t{
    uint8_t r;
    uint8_t g;
    uint8_t b;
}rgb_t;

void driver_i2c1_setup();

void i2c1_ev_isr();

#endif

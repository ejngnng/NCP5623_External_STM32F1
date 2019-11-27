#ifndef DRIVER_I2C_H
#define DRIVER_I2C_H

#include <stdint.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/i2c.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/cm3/nvic.h>
#include "color/color.h"

#ifdef LED_NCP5623
#define LED_I2C_ADDR   0x38
#else
#define LED_I2C_ADDR    0x90
#endif

void driver_i2c1_setup(uint8_t addr);

void i2c1_ev_isr();

#endif

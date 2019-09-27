#ifndef DRIVER_TIM2_H
#define DRIVER_TIM2_H

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/timer.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/cm3/nvic.h>

void driver_timer2_setup();

void driver_timer2_channel_setup(enum tim_oc_id channel);

void tim2_isr();

#endif
#ifndef DRIVER_WS2812_H
#define DRIVER_WS2812_H

#include <stdint.h>
#include <string.h>
#include "color/color.h"

/* 
 *
 * | TIMx | CH1 | CH2 | CH3 | CH4 |
 * | TIM1 | PA8 | PA9 | PA10| PA11|
 * | TIM2 | PA0 | PA1 | PA2 | PA3 |
 * | TIM3 | PA6 | PA7 | PB0 | PB1 |
 * | TIM4 | PB6 | PB7 | PB8 | PB9 |
 *  
 */

/*
* WS2812 data frame 24bit
* G7~G0 R7~-R0 B7~B0
*/

#define WS2812_BIT1    19       // duty cycle 67%
#define WS2812_BIT0    9        // duty cycle 33%


void driver_ws2812_setup(uint8_t nums);
void driver_ws2812_set_rgb(rgb_t rgb, uint8_t *buffer);

void driver_ws2812_set_pixel_rgb(rgb_t rgb, uint8_t nums);

void driver_ws2812_show();

#endif
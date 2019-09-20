#ifndef DRIVER_DMA1_H
#define DRIVER_DMA1_H

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/dma.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/timer.h>

/**
 * STM32F103xx DMA1 Channel Map
 * 
 * |Peripherals| CH1       | CH2        | CH3       | CH4       | CH5         | CH6         | CH7         |
 * |ADC1       | ADC1      |            |           |           |             |             |             |
 * |SPI/I2S    |           |SPI1_RX     |SPI1_TX    |SPI2/I2S_RX|SPI2/I2S_TX  |             |             |
 * |USART      |           |USART3_TX   |USART3_RX  |USART1_TX  |USART1_RX    |USART2_RX    |USART2_TX    |
 * |I2C        |           |            |           |I2C2_TX    |I2C2_RX      |I2C1_TX      |I2C1_RX      |  
 * |TIM1       |           |TIM1_CH1    |TIM1_CH2   |TIM1_CH4   |TIM1_UP      |TIM1_CH3     |             |
 * |TIM2       |TIM2_CH3   |TIM2_UP     |           |           |TIM2_CH1     |             |TIM2_CH2_CH3 |
 * |TIM3       |           |TIM3_CH3    |TIM3_CH4_UP|           |             |TIM3_CH1_TRIG|             |
 * |TIM4       |TIM4_CH1   |            |           |TIM4_CH2   |TIM4_CH3     |             |TIM4_UP      |
 * 
 */

/**
 * STM32F103xx DMA2 Channel Map
 * 
 * |Peripherals | CH1           | CH2             | CH3           | CH4           | CH5         |
 * |ADC3        |               |                 |               |               |ADC3         |
 * |SPI/I2S3    |SPI/I2S2_RX    |SPI/I2S3_TX      |               |               |             |
 * |USART4      |               |                 |USART4_RX      |               |USART4_TX    |
 * |SDIO        |               |                 |               |SDIO           |             |  
 * |TIM5        |TIM5_CH4_TRIG  |TIM5_CH3_UP      |               |TIM5_CH2       |TIM5_CH1     |             
 * |TIM6/DAC_CH1|               |                 |TIM6_UP/DAC_CH1|               |             |
 * |TIM7        |               |                 |               |TIM7_UP/DAC_CH2|             |
 * |TIM8        |TIM8_CH3_UP    |TIM8_CH4_TRIG_COM|TIM8_CH1       |               |TIM8_CH2     |
 * 
 */

void driver_dma1_clock_setup();

// TIM4_CH1 or TIM2_CH3
void driver_dma1_ch1_setup();

// TIM3_CH3 or TIM1 CH1
void driver_dma1_ch2_setup();

// TIM3_CH4 or TIM1_CH2
void driver_dma1_ch3_setup();

// TIM4_CH2 or TIM1_CH4
void driver_dma1_ch4_setup();

// TIM4_CH3 or TIM2_CH1
void driver_dma1_ch5_setup();

// TIM3_CH1 or TIM1_CH3
void driver_dma1_ch6_setup();

// TIM2_CH2 or TIM2_CH3
void driver_dma1_ch7_setup();

void driver_dma1_setup(uint8_t channel);

void driver_tim2ch1_dma1ch5_transmit(uint8_t *tx_buf, int tx_len);

void driver_dma_start();

void driver_dma_stop();

void driver_dma_transmit(uint8_t channel, uint8_t *tx_buf, uint8_t tx_len);

void dma1_channel1_isr();
void dma1_channel2_isr();
void dma1_channel3_isr();
void dma1_channel4_isr();
void dma1_channel5_isr();
void dma1_channel6_isr();
void dma1_channel7_isr();

#endif
#include "vTask_Tail.h"

#if (DEBUG==1)
#include "driver/driver_usart1.h"
#endif

#define TAIL_LED_NUMS   3

static uint8_t *tail_buffer = NULL;

static void vTask_Tail_Setup(){
    tail_buffer = (uint8_t *)malloc(sizeof(uint8_t) * (TAIL_LED_NUMS*24 + 2));
    memset(tail_buffer, 0, sizeof(uint8_t) * (TAIL_LED_NUMS*24 + 2));
    driver_timer2_setup();
    driver_dma1_setup(DMA_CHANNEL1);
}

void vTask_Tail(void *args){
    vTask_Tail_Setup();
    while(1){
        #if (DEBUG==1)
        usart1_printf("5. Tail...\n");
        #endif
        driver_ws2812_set_rgb(color_to_rgb(RGB_Blue), &tail_buffer[1+0*24]);
        driver_ws2812_set_rgb(color_to_rgb(RGB_Black),&tail_buffer[1+1*24]);
        driver_ws2812_set_rgb(color_to_rgb(RGB_Black),&tail_buffer[1+2*24]);
        driver_dma_transmit(DMA_CHANNEL1, tail_buffer, (TAIL_LED_NUMS*24 + 2));
        vTaskDelay(200);

        driver_ws2812_set_rgb(color_to_rgb(RGB_Blue), &tail_buffer[1+0*24]);
        driver_ws2812_set_rgb(color_to_rgb(RGB_Blue),&tail_buffer[1+1*24]);
        driver_ws2812_set_rgb(color_to_rgb(RGB_Black),&tail_buffer[1+2*24]);
        driver_dma_transmit(DMA_CHANNEL1, tail_buffer, (TAIL_LED_NUMS*24 + 2));
        vTaskDelay(200);

        driver_ws2812_set_rgb(color_to_rgb(RGB_Blue), &tail_buffer[1+0*24]);
        driver_ws2812_set_rgb(color_to_rgb(RGB_Blue),&tail_buffer[1+1*24]);
        driver_ws2812_set_rgb(color_to_rgb(RGB_Blue),&tail_buffer[1+2*24]);
        driver_dma_transmit(DMA_CHANNEL1, tail_buffer, (TAIL_LED_NUMS*24 + 2));
        vTaskDelay(200);

        driver_ws2812_set_rgb(color_to_rgb(RGB_Black), &tail_buffer[1+0*24]);
        driver_ws2812_set_rgb(color_to_rgb(RGB_Black),&tail_buffer[1+1*24]);
        driver_ws2812_set_rgb(color_to_rgb(RGB_Black),&tail_buffer[1+2*24]);
        driver_dma_transmit(DMA_CHANNEL1, tail_buffer, (TAIL_LED_NUMS*24 + 2));
        vTaskDelay(200);
    }
}
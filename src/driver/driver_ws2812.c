#include "driver_ws2812.h"
#include "driver_usart1.h"
#include "driver_dma1.h"
#include "driver_tim2.h"

static uint8_t *frame_buffer = NULL;
static uint8_t led_nums = 0;



void driver_ws2812_setup(uint8_t nums){
    led_nums = nums;
    frame_buffer = (uint8_t *)malloc(sizeof(uint8_t) * (nums * 24 + 2));
    memset(frame_buffer, 0, sizeof(uint8_t) * (nums * 24 + 2));
}


void driver_ws2812_set_rgb(rgb_t rgb, uint8_t *buffer){
    for(uint8_t i=0; i<8; i++){
        if(rgb.green >> i & 1){
            *(buffer + i) = WS2812_BIT1;
        }else{
            *(buffer + i) = WS2812_BIT0; 
        }

        if(rgb.red >> i & 1){
            *(buffer + 8 + i) = WS2812_BIT1;
        }else{
            *(buffer + 8 + i) = WS2812_BIT0;
        }

        if(rgb.blue >> i & 1){
            *(buffer + 16 + i) = WS2812_BIT1;
        }else{
            *(buffer + 16 + i) = WS2812_BIT0;
        }
    }
}

void driver_ws2812_set_pixel_rgb(rgb_t rgb, uint8_t nums){
    driver_ws2812_set_rgb(rgb, &frame_buffer[1 + nums * 24]);
}

void driver_ws2812_show(){
    // driver_tim2ch1_dma1ch5_transmit(frame_buffer, (led_nums*24+2));
    // driver_dma_transmit(DMA_CHANNEL1, frame_buffer, (led_nums*24+2));
    driver_dma_transmit(DMA_CHANNEL5, frame_buffer, (led_nums*24+2));
    // driver_dma_transmit(DMA_CHANNEL6, frame_buffer, (led_nums*24+2));
}

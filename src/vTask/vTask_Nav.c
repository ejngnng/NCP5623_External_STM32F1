#include "vTask_Nav.h"

#if(DEBUG==1)
#include "driver/driver_usart1.h"
#endif

#define NAV_LED_NUMS    3


static uint8_t *nav_buffer = NULL;

static void vTask_nav_setup(){
    nav_buffer = (uint8_t *)malloc(sizeof(uint8_t) * (NAV_LED_NUMS*24 + 2));
    memset(nav_buffer, 0, sizeof(uint8_t) * (NAV_LED_NUMS*24 + 2));
    driver_timer2_setup();
    driver_dma1_setup(DMA_CHANNEL5);
}


void vTask_Nav(void *args){
    vTask_nav_setup();
    while(1){
        #if (DEBUG==1)
        usart1_printf("vTask Nav...\n");
        #endif
        for(uint8_t i=0; i<NAV_LED_NUMS; i++){
            driver_ws2812_set_rgb(color_to_rgb(RGB_Red), &nav_buffer[1+i*24]);
        }
        driver_dma_transmit(DMA_CHANNEL5, nav_buffer, (NAV_LED_NUMS*24 + 2));
        vTaskDelay(500);
        for(uint8_t i=0; i<NAV_LED_NUMS; i++){
            driver_ws2812_set_rgb(color_to_rgb(RGB_Black), &nav_buffer[1+i*24]);
        }
        driver_dma_transmit(DMA_CHANNEL5, nav_buffer, (NAV_LED_NUMS*24 +2));
        vTaskDelay(500);
    }
}
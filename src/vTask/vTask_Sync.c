#include "vTask_Sync.h"

#if (DEBUG==1)
#include "driver/driver_usart1.h"
#endif

#define SYNC_LED_NUMS   3

extern rgb_t Colors;
extern bool update;

uint32_t last_update;
bool sync_timeout;  // true: i2c timeout,  false: i2c ok 

static void vTask_Sync_Setup(){
    last_update = 0;
    sync_timeout = true;
    memset(&Colors, 0, sizeof(rgb_t));
    driver_ws2812_setup(SYNC_LED_NUMS);
    driver_i2c1_setup(LED_I2C_ADDR);
    driver_timer2_setup();
    driver_dma1_setup(DMA_CHANNEL7);
}

void vTask_Sync(void *args){
    vTask_Sync_Setup();
    while(1){
        #if (DEBUG==1)
        usart1_printf("2. Sync...\n");
        #endif
        if(update){
            update = false;
            sync_timeout = false;
            last_update = xTaskGetTickCount();
            for(uint8_t i=0; i<SYNC_LED_NUMS; i++){
                driver_ws2812_set_pixel_rgb(Colors, i);
            }
            driver_ws2812_show();
        }else{
            if(xTaskGetTickCount() - last_update >  300){
                sync_timeout = true;
            }
        } 
        vTaskDelay(100);
    }
}
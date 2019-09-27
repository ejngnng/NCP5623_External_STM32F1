#include "main.h"

extern rgb_t Colors;
extern bool update;

#define LED_NUMS    3

void vTask_Setup();
static void vTask_Blink(void *args);
static void vTask_Sync(void *args);
static void vTask_Nav(void *args);
static void VTask_Test(void *args);

int main(){
    rcc_clock_setup_in_hse_8mhz_out_72mhz();
    driver_usart1_setup();
    driver_i2c1_setup();
    driver_tick_setup();
    // driver_timer2_channel_setup(TIM_OC2);
    // driver_timer2_channel_setup(TIM_OC3);
    // driver_dma1_setup(DMA_CHANNEL7);
    // driver_dma1_setup(DMA_CHANNEL1);
    // // driver_timer2_setup();
    // // driver_dma1_setup(DMA_CHANNEL5);
    // driver_ws2812_setup(LED_NUMS);
    // driver_ws2812_set_pixel_rgb(color_to_rgb(RGB_Red), 0);
    // driver_ws2812_set_pixel_rgb(color_to_rgb(RGB_Blue), 1);
    // driver_ws2812_set_pixel_rgb(color_to_rgb(RGB_Blue), 2);
    // driver_ws2812_show();

    memset(&Colors, 0, sizeof(rgb_t));
    update = false;
    // usart1_printf("setup done!!!\n");
    vTask_Setup();
    while(1){

    }
    return 0;
}

void vTask_Setup(){
    xTaskCreate(vTask_Blink, "Blink", 50, NULL, 1, NULL);
    xTaskCreate(vTask_Sync, "Sync", 500, NULL, 3, NULL);
    xTaskCreate(vTask_Nav, "Nav", 500, NULL, 2, NULL);
    xTaskCreate(VTask_Test, "Test", 300, NULL, 4, NULL);
    vTaskStartScheduler();
}

static void vTask_Blink(void *args){

    rcc_periph_clock_enable(RCC_GPIOC);
    gpio_set_mode(
        GPIOC,
        GPIO_MODE_OUTPUT_50_MHZ,
        GPIO_CNF_OUTPUT_PUSHPULL,
        GPIO13
    );
    while(1){
        usart1_printf("1. Blink...\n");
        gpio_toggle(GPIOC, GPIO13);
        vTaskDelay(500);
    }
}

static void vTask_Sync(void *args){
    uint32_t last_update = 0;
    driver_timer2_channel_setup(TIM_OC2);
    driver_timer2_channel_setup(TIM_OC3);
    driver_dma1_setup(DMA_CHANNEL7);
    driver_dma1_setup(DMA_CHANNEL1);
    // driver_timer2_setup();
    // driver_dma1_setup(DMA_CHANNEL5);
    driver_ws2812_setup(LED_NUMS);
    driver_ws2812_set_pixel_rgb(color_to_rgb(RGB_Red), 0);
    driver_ws2812_set_pixel_rgb(color_to_rgb(RGB_Blue), 1);
    driver_ws2812_set_pixel_rgb(color_to_rgb(RGB_Blue), 2);
    driver_ws2812_show();
    while(1){
        usart1_printf("2. Sync...\n");
        if(update){
            update = false;
            last_update = xTaskGetTickCount();
            for(uint8_t i=0; i<LED_NUMS; i++){
                driver_ws2812_set_pixel_rgb(Colors, i);
            }
            driver_ws2812_show();
        }else{
            if(xTaskGetTickCount() - last_update >  300){
                for(uint8_t i=0; i<LED_NUMS; i++){
                    driver_ws2812_set_pixel_rgb(color_to_rgb(RGB_Black), i);
                }
                driver_ws2812_show();
            }
        }

        vTaskDelay(100);
    }
}

static void vTask_Nav(void *args){
    driver_timer2_channel_setup(TIM_OC1);
    driver_dma1_setup(DMA_CHANNEL5);
    uint8_t *nav_buffer = NULL;
    nav_buffer = (uint8_t *)malloc(sizeof(uint8_t) * (LED_NUMS*24 + 2));
    memset(nav_buffer, 0, sizeof(uint8_t) * (LED_NUMS*24 + 2));
    for(uint8_t i=0; i<LED_NUMS; i++){
        driver_ws2812_set_rgb(color_to_rgb(RGB_Red), &nav_buffer[1+i*24]);
    }
    driver_dma_transmit(DMA_CHANNEL5, nav_buffer, (LED_NUMS*24 + 2));
    while(1){
        usart1_printf("3. Nav...\n");
        for(uint8_t i=0; i<LED_NUMS; i++){
            driver_ws2812_set_rgb(color_to_rgb(RGB_Red), &nav_buffer[1+i*24]);
        }
        driver_dma_transmit(DMA_CHANNEL5, nav_buffer, (LED_NUMS*24 + 2));
        vTaskDelay(200);
        for(uint8_t i=0; i<LED_NUMS; i++){
            driver_ws2812_set_rgb(color_to_rgb(RGB_Black), &nav_buffer[1+i*24]);
        }
        driver_dma_transmit(DMA_CHANNEL5, nav_buffer, (LED_NUMS*24 +2));
        vTaskDelay(200);
    }
}

static void VTask_Test(void *args){
    while(1){
        usart1_printf("4. Test...\n");
        vTaskDelay(200);
    }
}
#include "main.h"

extern rgb_t Colors;
extern bool update;

#define LED_NUMS    3

int main(){
    rcc_clock_setup_in_hse_8mhz_out_72mhz();
    driver_usart1_setup();
    driver_i2c1_setup();
    driver_tick_setup();
    driver_timer2_setup();
    driver_dma1_setup(DMA_CHANNEL5);
    driver_dma1_setup(DMA_CHANNEL1);
    driver_dma1_setup(DMA_CHANNEL7);
    driver_ws2812_setup(LED_NUMS);
    driver_ws2812_set_pixel_rgb(color_to_rgb(RGB_Red), 0);
    driver_ws2812_set_pixel_rgb(color_to_rgb(RGB_Blue), 1);
    driver_ws2812_set_pixel_rgb(color_to_rgb(RGB_Blue), 2);
    driver_ws2812_show();
    rcc_periph_clock_enable(RCC_GPIOC);
    gpio_set_mode(
        GPIOC,
        GPIO_MODE_OUTPUT_50_MHZ,
        GPIO_CNF_OUTPUT_PUSHPULL,
        GPIO13
    );
    memset(&Colors, 0, sizeof(rgb_t));
    update = false;
    printf("setup done!!!\n");
    while(1){
        if(update){
            update = false;
            #if (DEBUG==1)
            printf("red: %02X, green: %02X, blue: %02X\n", Colors.r, Colors.g, Colors.b);
            #endif
            for(uint8_t i=0; i<LED_NUMS; i++){
                driver_ws2812_set_pixel_rgb(Colors, i);
            }
            driver_ws2812_show();
        }else{
            gpio_toggle(GPIOC, GPIO13);
            driver_ws2812_show();
            delay_ms(100);
        }
    }
    return 0;
}

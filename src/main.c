#include "main.h"

extern rgb_t Colors;
extern bool update;

int main(){
    rcc_clock_setup_in_hse_8mhz_out_72mhz();
    driver_usart1_setup();
    driver_i2c1_setup();
    driver_slave_init();
    driver_tick_setup();
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
            printf("red: %02X, green: %02X, blue: %02X\n", Colors.r, Colors.g, Colors.b);
        }else{
            gpio_toggle(GPIOC, GPIO13);
        }
    }
    return 0;
}

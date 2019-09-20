#include "main.h"

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
    printf("setup done!!!\n");
    while(1){
        // delay_ms(500);
        // gpio_toggle(GPIOC, GPIO13);
    }
    return 0;
}

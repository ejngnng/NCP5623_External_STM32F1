#include "main.h"

void vTask_Setup();
static void vTask_Blink(void *args);


#if (DEBUG_TASK==1)
static void VTask_Test(void *args);
#endif

int main(){
    rcc_clock_setup_in_hse_8mhz_out_72mhz();
    driver_usart1_setup();
    vTask_Setup();
    while(1){

    }
    return 0;
}

void vTask_Setup(){
    xTaskCreate(vTask_Blink, "Blink", 50, NULL, 1, NULL);
    xTaskCreate(vTask_Sync, "Sync", 500, NULL, 5, NULL);
    xTaskCreate(vTask_Nav, "Nav", 500, NULL, 2, NULL);
    xTaskCreate(vTask_Tail, "Tail", 500, NULL, 3, NULL);
    #if (DEBUG_TASK==1)
    xTaskCreate(VTask_Test, "Test", 500, NULL, 4, NULL);
    #endif
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
        #if (DEBUG==1)
        usart1_printf("1. Blink...\n");
        #endif
        gpio_toggle(GPIOC, GPIO13);
        vTaskDelay(500);
    }
}

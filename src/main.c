#include "main.h"

extern bool sync_timeout;

void vTask_Setup();
static void led_mode_double_flash();
static void led_mode_slow_flash();
static void vTask_Blink(void *args);


#if (DEBUG_TASK==1)
static void VTask_Test(void *args);
#endif

int main(){
    rcc_clock_setup_in_hse_8mhz_out_72mhz();
    driver_usart1_setup();
    usart1_printf("*****************************************\n");
    usart1_printf("Name: %s_%s\n", THISFIRMWARE, THISVERSION);
    usart1_printf("Description: External LED for ArduPilot\n");
    usart1_printf("Author: ninja\n");
    usart1_printf("Date: 2019-09-28\n");
    usart1_printf("*****************************************\n");
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
        if(sync_timeout){
            led_mode_double_flash();
        }else{
            led_mode_slow_flash();
        }

    }
}


static void led_mode_double_flash(){
    gpio_clear(GPIOC, GPIO13);
    vTaskDelay(100);
    gpio_set(GPIOC, GPIO13);
    vTaskDelay(100);
    gpio_clear(GPIOC, GPIO13);
    vTaskDelay(100);
    gpio_set(GPIOC, GPIO13);
    vTaskDelay(500);
}

static void led_mode_slow_flash(){
    gpio_toggle(GPIOC, GPIO13);
    vTaskDelay(500);
}
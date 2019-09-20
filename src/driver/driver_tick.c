#include "driver_tick.h"
#include <libopencm3/cm3/systick.h>
#include <libopencm3/cm3/nvic.h>

volatile uint32_t systick_millis;

void driver_tick_setup(){
    systick_set_clocksource(STK_CSR_CLKSOURCE_AHB_DIV8);    /* SysTick at 72Mhz/8 */
    systick_set_reload(8999);                               /* SysTick Reload for 1ms tick ( 72M/8/1000 =9000 ) */
    systick_interrupt_enable();
    systick_counter_enable();
}

uint32_t millis(){
    return systick_millis;
}

void delay_ms(uint32_t ms){
    uint32_t start = millis();
    uint32_t stop = start + ms;
    while(start < stop){
        start = millis();
    }
}

void sys_tick_handler(){
    systick_millis ++;
}
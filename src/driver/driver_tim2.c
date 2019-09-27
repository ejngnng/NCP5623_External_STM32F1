#include "driver_tim2.h"
#include "driver_usart1.h"

/* 
 *
 * | TIMx | CH1 | CH2 | CH3 | CH4 |
 * | TIM1 | PA8 | PA9 | PA10| PA11|
 * | TIM2 | PA0 | PA1 | PA2 | PA3 |
 * | TIM3 | PA6 | PA7 | PB0 | PB1 |
 * | TIM4 | PB6 | PB7 | PB8 | PB9 |
 *  
 */

// TIM2 CH1 PA0 drive WS2812
void driver_timer2_setup(){
    rcc_periph_clock_enable(RCC_GPIOA);
    rcc_periph_clock_enable(RCC_TIM2);
    rcc_periph_clock_enable(RCC_AFIO);

    gpio_set_mode(
        GPIOA,
        GPIO_MODE_OUTPUT_50_MHZ,
        GPIO_CNF_OUTPUT_ALTFN_PUSHPULL,
        GPIO0 // TIM2--CH1
    );

    gpio_set_mode(
        GPIOA,
        GPIO_MODE_OUTPUT_50_MHZ,
        GPIO_CNF_OUTPUT_ALTFN_PUSHPULL,
        GPIO1 // TIM2--CH2
    );

    gpio_set_mode(
        GPIOA,
        GPIO_MODE_OUTPUT_50_MHZ,
        GPIO_CNF_OUTPUT_ALTFN_PUSHPULL,
        GPIO2 // TIM2--CH3
    );
    timer_disable_counter(TIM2);
    timer_reset(TIM2);

    timer_set_mode(
        TIM2,
        TIM_CR1_CKD_CK_INT,
        TIM_CR1_CMS_EDGE,
        TIM_CR1_DIR_UP
    );

    timer_set_prescaler(TIM2, 72000000/24000000 - 1);
    timer_enable_preload(TIM2);
    timer_set_period(TIM2, 29); // pwm frequency 72M/(ARR+1) *(PSC+1) Hz
    timer_continuous_mode(TIM2);

    timer_disable_oc_output(TIM2, TIM_OC1);
    timer_set_oc_mode(TIM2, TIM_OC1, TIM_OCM_PWM1);
    timer_enable_oc_preload(TIM2, TIM_OC1);
    timer_enable_oc_output(TIM2, TIM_OC1);
    timer_set_oc_value(TIM2, TIM_OC1, 0);  // pwm duty cycle  CCR1/ARR * 100%

    timer_disable_oc_output(TIM2, TIM_OC2);
    timer_set_oc_mode(TIM2, TIM_OC2, TIM_OCM_PWM1);
    timer_enable_oc_preload(TIM2, TIM_OC2);
    timer_enable_oc_output(TIM2, TIM_OC2);
    timer_set_oc_value(TIM2, TIM_OC2, 0);  // pwm duty cycle  CCR1/ARR * 100%

    timer_disable_oc_output(TIM2, TIM_OC3);
    timer_set_oc_mode(TIM2, TIM_OC3, TIM_OCM_PWM1);
    timer_enable_oc_preload(TIM2, TIM_OC3);
    timer_enable_oc_output(TIM2, TIM_OC3);
    timer_set_oc_value(TIM2, TIM_OC3, 0);  // pwm duty cycle  CCR1/ARR * 100%

    timer_enable_counter(TIM2);
    // nvic_enable_irq(NVIC_TIM2_IRQ);
    // timer_enable_irq(TIM2, TIM_DIER_CC1IE); // enable timer2 CCR1 isr
    timer_enable_irq(TIM2, TIM_DIER_CC1DE|TIM_DIER_CC2DE|TIM_DIER_CC3DE); // enable timer2 CCR1 DMA request
}

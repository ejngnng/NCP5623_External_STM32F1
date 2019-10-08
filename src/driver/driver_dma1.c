#include "driver_dma1.h"

#if (DEBUG_DMA == 1)
#include "driver_usart1.h"
#endif
void driver_dma1_setup(uint8_t channel){
    rcc_periph_clock_enable(RCC_DMA1);
    switch(channel){
        case DMA_CHANNEL1:
            driver_dma1_ch1_setup();
            break;
        case DMA_CHANNEL2:
            driver_dma1_ch2_setup();
            break;
        case DMA_CHANNEL3:
            driver_dma1_ch3_setup();
            break;
        case DMA_CHANNEL4:
            driver_dma1_ch4_setup();
            break;
        case DMA_CHANNEL5:
            driver_dma1_ch5_setup();
            break;
        case DMA_CHANNEL6:
            driver_dma1_ch6_setup();
            break;
        case DMA_CHANNEL7:
            driver_dma1_ch7_setup();
            break;
        default:
            break;
    }
}

void driver_tim2ch1_dma1ch5_transmit(uint8_t *tx_buf, int tx_len){
    /* Reset DMA channel */
    dma_disable_channel(DMA1, DMA_CHANNEL5);
    dma_set_memory_address(DMA1, DMA_CHANNEL5, (uint32_t)tx_buf);
    dma_set_number_of_data(DMA1, DMA_CHANNEL5, tx_len);
    dma_enable_channel(DMA1, DMA_CHANNEL5);
    timer_enable_counter(TIM2);
}

void driver_dma_transmit(uint8_t channel, uint8_t *tx_buf, uint8_t tx_len){
    dma_disable_channel(DMA1, channel);
    dma_set_memory_address(DMA1, channel, (uint32_t)tx_buf);
    dma_set_number_of_data(DMA1, channel, tx_len);
    dma_enable_channel(DMA1, channel);
}

void driver_dma_start(){
    dma_enable_channel(DMA1, DMA_CHANNEL5);
}

void driver_dma_stop(){
    dma_disable_channel(DMA1, DMA_CHANNEL5);
}

void driver_dma1_clock_setup(){
    rcc_periph_clock_enable(RCC_DMA1);
}

// TIM4_CH1 or TIM2_CH3
// only for Timer4 CH1
void driver_dma1_ch1_setup(){

    dma_channel_reset(DMA1,DMA_CHANNEL1);
    dma_set_peripheral_address(DMA1,DMA_CHANNEL1,(uint32_t)&TIM2_CCR3);
    dma_set_read_from_memory(DMA1,DMA_CHANNEL1);
    dma_enable_memory_increment_mode(DMA1,DMA_CHANNEL1);
    dma_set_peripheral_size(DMA1,DMA_CHANNEL1,DMA_CCR_PSIZE_16BIT);
    dma_set_memory_size(DMA1,DMA_CHANNEL1,DMA_CCR_MSIZE_8BIT);
    dma_set_priority(DMA1,DMA_CHANNEL1,DMA_CCR_PL_HIGH);
	dma_enable_transfer_complete_interrupt(DMA1,DMA_CHANNEL1);

	nvic_set_priority(NVIC_DMA1_CHANNEL1_IRQ, 0);
	nvic_enable_irq(NVIC_DMA1_CHANNEL1_IRQ);
}

// TIM3_CH3 or TIM1 CH1
// only for Timer3 CH3
void driver_dma1_ch2_setup(){
    dma_channel_reset(DMA1,DMA_CHANNEL2);
    dma_set_peripheral_address(DMA1,DMA_CHANNEL2,(uint32_t)&TIM3_CCR3);
    dma_set_read_from_memory(DMA1,DMA_CHANNEL2);
    dma_enable_memory_increment_mode(DMA1,DMA_CHANNEL2);
    dma_set_peripheral_size(DMA1,DMA_CHANNEL2,DMA_CCR_PSIZE_16BIT);
    dma_set_memory_size(DMA1,DMA_CHANNEL2,DMA_CCR_MSIZE_8BIT);
    dma_set_priority(DMA1,DMA_CHANNEL2,DMA_CCR_PL_HIGH);
	dma_enable_transfer_complete_interrupt(DMA1,DMA_CHANNEL2);

	nvic_set_priority(NVIC_DMA1_CHANNEL2_IRQ, 0);
	nvic_enable_irq(NVIC_DMA1_CHANNEL2_IRQ);
}

// TIM3_CH4 or TIM1_CH2
// only for Timer3 CH4
void driver_dma1_ch3_setup(){
    dma_channel_reset(DMA1,DMA_CHANNEL3);
    dma_set_peripheral_address(DMA1,DMA_CHANNEL3,(uint32_t)&TIM3_CCR4);
    dma_set_read_from_memory(DMA1,DMA_CHANNEL3);
    dma_enable_memory_increment_mode(DMA1,DMA_CHANNEL3);
    dma_set_peripheral_size(DMA1,DMA_CHANNEL3,DMA_CCR_PSIZE_16BIT);
    dma_set_memory_size(DMA1,DMA_CHANNEL3,DMA_CCR_MSIZE_8BIT);
    dma_set_priority(DMA1,DMA_CHANNEL3,DMA_CCR_PL_HIGH);
	dma_enable_transfer_complete_interrupt(DMA1,DMA_CHANNEL3);

	nvic_set_priority(NVIC_DMA1_CHANNEL3_IRQ, 0);
	nvic_enable_irq(NVIC_DMA1_CHANNEL3_IRQ);
}

// TIM4_CH2 or TIM1_CH4
// only for Timer4 CH2
void driver_dma1_ch4_setup(){
    dma_channel_reset(DMA1,DMA_CHANNEL4);
    dma_set_peripheral_address(DMA1,DMA_CHANNEL4,(uint32_t)&TIM4_CCR2);
    dma_set_read_from_memory(DMA1,DMA_CHANNEL4);
    dma_enable_memory_increment_mode(DMA1,DMA_CHANNEL4);
    dma_set_peripheral_size(DMA1,DMA_CHANNEL4,DMA_CCR_PSIZE_16BIT);
    dma_set_memory_size(DMA1,DMA_CHANNEL4,DMA_CCR_MSIZE_8BIT);
    dma_set_priority(DMA1,DMA_CHANNEL4,DMA_CCR_PL_HIGH);
	dma_enable_transfer_complete_interrupt(DMA1,DMA_CHANNEL4);

	nvic_set_priority(NVIC_DMA1_CHANNEL4_IRQ, 0);
	nvic_enable_irq(NVIC_DMA1_CHANNEL4_IRQ);
}

// TIM4_CH3 or TIM2_CH1
// only for Timer2 CH1
void driver_dma1_ch5_setup(){
    dma_channel_reset(DMA1,DMA_CHANNEL5);
    dma_set_peripheral_address(DMA1,DMA_CHANNEL5,(uint32_t)&TIM2_CCR1);
    dma_set_read_from_memory(DMA1,DMA_CHANNEL5);
    dma_enable_memory_increment_mode(DMA1,DMA_CHANNEL5);
    dma_set_peripheral_size(DMA1,DMA_CHANNEL5,DMA_CCR_PSIZE_16BIT);
    dma_set_memory_size(DMA1,DMA_CHANNEL5,DMA_CCR_MSIZE_8BIT);
    dma_set_priority(DMA1,DMA_CHANNEL5,DMA_CCR_PL_HIGH);
	dma_enable_transfer_complete_interrupt(DMA1,DMA_CHANNEL5);

	nvic_set_priority(NVIC_DMA1_CHANNEL5_IRQ, 0);
	nvic_enable_irq(NVIC_DMA1_CHANNEL5_IRQ);
}

// TIM3_CH1 or TIM1_CH3
// only for Timer3 CH1
void driver_dma1_ch6_setup(){
    dma_channel_reset(DMA1,DMA_CHANNEL6);
    dma_set_peripheral_address(DMA1,DMA_CHANNEL6,(uint32_t)&TIM3_CCR1);
    dma_set_read_from_memory(DMA1,DMA_CHANNEL6);
    dma_enable_memory_increment_mode(DMA1,DMA_CHANNEL6);
    dma_set_peripheral_size(DMA1,DMA_CHANNEL6,DMA_CCR_PSIZE_16BIT);
    dma_set_memory_size(DMA1,DMA_CHANNEL6,DMA_CCR_MSIZE_8BIT);
    dma_set_priority(DMA1,DMA_CHANNEL6,DMA_CCR_PL_HIGH);
	dma_enable_transfer_complete_interrupt(DMA1,DMA_CHANNEL6);

	nvic_set_priority(NVIC_DMA1_CHANNEL6_IRQ, 0);
	nvic_enable_irq(NVIC_DMA1_CHANNEL6_IRQ);
}

// TIM2_CH2 or TIM2_CH3
// only for Timer2 CH2
void driver_dma1_ch7_setup(){
    dma_channel_reset(DMA1,DMA_CHANNEL7);
    dma_set_peripheral_address(DMA1,DMA_CHANNEL7,(uint32_t)&TIM2_CCR2);
    dma_set_read_from_memory(DMA1,DMA_CHANNEL7);
    dma_enable_memory_increment_mode(DMA1,DMA_CHANNEL7);
    dma_set_peripheral_size(DMA1,DMA_CHANNEL7,DMA_CCR_PSIZE_16BIT);
    dma_set_memory_size(DMA1,DMA_CHANNEL7,DMA_CCR_MSIZE_8BIT);
    dma_set_priority(DMA1,DMA_CHANNEL7,DMA_CCR_PL_HIGH);
	dma_enable_transfer_complete_interrupt(DMA1,DMA_CHANNEL7);

	nvic_set_priority(NVIC_DMA1_CHANNEL7_IRQ, 0);
	nvic_enable_irq(NVIC_DMA1_CHANNEL7_IRQ);
}

void dma1_channel1_isr(){
    if(dma_get_interrupt_flag(DMA1, DMA_CHANNEL1, DMA_TCIF)){
        dma_clear_interrupt_flags(DMA1, DMA_CHANNEL1, DMA_TCIF);
    }
}

void dma1_channel2_isr(){
    if(dma_get_interrupt_flag(DMA1, DMA_CHANNEL2, DMA_TCIF)){
        dma_clear_interrupt_flags(DMA1, DMA_CHANNEL2, DMA_TCIF);
    }
}

void dma1_channel3_isr(){
    if(dma_get_interrupt_flag(DMA1, DMA_CHANNEL3, DMA_TCIF)){
        dma_clear_interrupt_flags(DMA1, DMA_CHANNEL3, DMA_TCIF);
    }
}

void dma1_channel4_isr(){
    if(dma_get_interrupt_flag(DMA1, DMA_CHANNEL4, DMA_TCIF)){
        dma_clear_interrupt_flags(DMA1, DMA_CHANNEL4, DMA_TCIF);
    }
}

void dma1_channel5_isr(){
   #if (DEBUG_DMA == 1)
    usart1_printf("DMA ch5 isr\n");
   #endif
    if(dma_get_interrupt_flag(DMA1, DMA_CHANNEL5, DMA_TCIF)){
        dma_clear_interrupt_flags(DMA1, DMA_CHANNEL5, DMA_TCIF);
        // timer_disable_irq(TIM2, TIM_DIER_CC1DE);
        // driver_dma_stop();
        // timer_disable_oc_output(TIM2, TIM_OC1);
        #if (DEBUG_DMA == 1)
        usart1_printf("DMA send complete\n");
        #endif
    }
}

void dma1_channel6_isr(){
    if(dma_get_interrupt_flag(DMA1, DMA_CHANNEL6, DMA_TCIF)){
        dma_clear_interrupt_flags(DMA1, DMA_CHANNEL6, DMA_TCIF);
    }
}

void dma1_channel7_isr(){
    if(dma_get_interrupt_flag(DMA1, DMA_CHANNEL7, DMA_TCIF)){
        dma_clear_interrupt_flags(DMA1, DMA_CHANNEL7, DMA_TCIF);
    }
}
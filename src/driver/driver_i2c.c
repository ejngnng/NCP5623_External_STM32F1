#include "driver_i2c.h"

#if (DEBUG_IIC == 1)
#include "driver_usart1.h"
#endif
/**
 * 
 * I2C1_SCL---PB6 
 * I2C1_SDA---PB7
 * 
 * 
 **/



rgb_t Colors;
static uint8_t counter;
bool update;


void driver_i2c1_setup(uint8_t addr){
    rcc_periph_clock_enable(RCC_GPIOB);
    rcc_periph_clock_enable(RCC_AFIO);
    rcc_periph_clock_enable(RCC_I2C1);

    gpio_set_mode(
        GPIOB,
        GPIO_MODE_OUTPUT_50_MHZ,
        GPIO_CNF_OUTPUT_ALTFN_OPENDRAIN,
        GPIO_I2C1_SCL | GPIO_I2C1_SDA
    );

    /* Disable the I2C before changing any configuration. */
	i2c_peripheral_disable(I2C1);
    i2c_reset(I2C1);
	/* APB1 is running at 36MHz. */
    i2c_set_clock_frequency(I2C1, I2C_CR2_FREQ_36MHZ);
    i2c_set_standard_mode(I2C1);

	i2c_set_own_7bit_slave_address(I2C1, addr);


    i2c_enable_interrupt(I2C1, I2C_CR2_ITEVTEN | I2C_CR2_ITBUFEN);
    nvic_enable_irq(NVIC_I2C1_EV_IRQ);

    /* If everything is configured -> enable the peripheral. */
	i2c_peripheral_enable(I2C1);
    i2c_enable_ack(I2C1);

}

// ANYLED for ardupilot
void i2c1_ev_isr(){
    uint32_t sr1, sr2;
    if(I2C_SR1(I2C1) & I2C_SR1_ADDR){
        sr1 = I2C_SR1(I2C1);
        sr2 = I2C_SR2(I2C1);
        (void)sr1;
        (void)sr2;
        #if (DEBUG_IIC==1)
        usart1_printf("Address matched\n");
        #endif
    }

    if(I2C_SR1(I2C1) & I2C_SR1_RxNE){
        uint8_t data = i2c_get_data(I2C1);
        switch(counter){
            case 0:
                Colors.r = data;
                counter ++;
                break;
            case 1:
                Colors.g = data;
                counter ++;
                break;
            case 2:
                Colors.b = data;
                counter = 0;
                update = true;
                break;
            default:
                break;
        }

    }

    if(I2C_SR1(I2C1) & I2C_SR1_STOPF){
        sr1 = I2C_SR1(I2C1);
        i2c_peripheral_enable(I2C1);
        #if (DEBUG_IIC==1)
        usart1_printf("Master stop, data: %02X\n", i2c_get_data(I2C1));
        #endif
    }

}

#if 0 // NCP5623 LED data
void i2c1_ev_isr(){
    uint32_t sr1, sr2;
    if(I2C_SR1(I2C1) & I2C_SR1_ADDR){
        sr1 = I2C_SR1(I2C1);
        sr2 = I2C_SR2(I2C1);
        (void)sr1;
        (void)sr2;
        #if (DEBUG_IIC==1)
        usart1_printf("Address matched\n");
        #endif
    }

    if(I2C_SR1(I2C1) & I2C_SR1_RxNE){
        uint8_t data = i2c_get_data(I2C1);
        switch(data & 0xE0){
            case 0:
                break;
            case 0x20:
                break;
            case 0x40:
                #if (DEBUG_IIC==1)
                usart1_printf("PWM1: %02X\n", data & 0x1F);
                #endif
                counter++;
                Colors.r = data & 0x1F;
                break;
            case 0x60:
                #if (DEBUG_IIC==1)
                usart1_printf("PWM2: %02X\n", data & 0x1F);
                #endif
                counter++;
                Colors.g = data & 0x1F;
                break;
            case 0x80:
                #if (DEBUG_IIC==1)
                usart1_printf("PWM3: %02X\n", data & 0x1F);
                #endif
                counter++;
                Colors.b = data & 0x1F;
                break;
            default:
                break;
        }
        if(counter >= 3){
            counter = 0;
            update = true;
        }
    }

    if(I2C_SR1(I2C1) & I2C_SR1_STOPF){
        sr1 = I2C_SR1(I2C1);
        i2c_peripheral_enable(I2C1);
        #if (DEBUG_IIC==1)
        usart1_printf("Master stop, data: %02X\n", i2c_get_data(I2C1));
        #endif
    }

}
#endif
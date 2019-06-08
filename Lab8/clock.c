/******************************************************************************
 * Name:    clock.c
 * Description: STM32 peripherals initialization and functions
 * Version: V1.00
 * Author: Daris Lychuk
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 *
 *----------------------------------------------------------------------------
 * History:
 *          V1.00 Initial Version
 *          V1.1 reformatted (kjn)
 *****************************************************************************/
 #include "lab8.h"
 #include "stm32f10x.h"

// CLOCK AND TIMING FUNCTIONS

/*
* Name:         void clockInit()
* Paramaters:   none
* Description: This function will initialize the device internal
               clock to 24 Mhz
*/
void clockInit(void)
{
    uint32_t temp = 0x00;
    //If you hover over the RCC you can go to the definition and then
    //see it is a structure of all the RCC registers.  Then you can
    //simply assign a value.
    RCC->CFGR = 0x07050002;     // Output PLL/2 as MCO,
                                // PLLMUL X3, PREDIV1 is PLL input

    RCC->CR =  0x01010081;      // Turn on PLL, HSE, HSI

    while (temp != 0x02000000)  // Wait for the PLL to stabilize
    {
        temp = RCC->CR & 0x02000000; //Check to see if the PLL lock bit is set
    }
		
    //Enable peripheral clocks for various ports and subsystems
    //Bit 4: Port C Bit3: Port B Bit 2: Port A
    RCC->APB2ENR |=  RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN | RCC_APB2ENR_IOPCEN;// | RCC_APB2ENR_USART1EN;
		RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;

		//Set the config and mode bits for Port C bit 9 and 8 so they will
    // be push-pull outputs (up to 50 MHz)
    GPIOC->CRH |= GPIO_CRH_MODE9 | GPIO_CRH_MODE8 ;
    GPIOC->CRH &= ~GPIO_CRH_CNF9 & ~GPIO_CRH_CNF8 ;
		
		GPIOB->CRH &= ~GPIO_CRH_CNF15_0 & ~GPIO_CRH_MODE15_0 & ~GPIO_CRH_CNF14_1 & ~GPIO_CRH_MODE14 & ~GPIO_CRH_CNF13_0 & ~GPIO_CRH_MODE13_0 & ~GPIO_CRH_CNF12;
		
		GPIOB->CRH |= GPIO_CRH_CNF15_1 | GPIO_CRH_MODE15_1 | GPIO_CRH_CNF14_0 | GPIO_CRH_CNF13_1 | GPIO_CRH_MODE13_1 | GPIO_CRH_MODE12;
    
}

void delay(uint32_t count)
{
    int i=0;
    for(i=0; i< count; ++i)
    {
    }
}

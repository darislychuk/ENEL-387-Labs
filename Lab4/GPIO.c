 #include "stm32f10x.h"
 #include "lab4.h"

// SWITCH AND LED I/O FUNCTIONS

void led_IO_init (void)
{
    //Enable peripheral clocks for various ports and subsystems
    //Bit 4: Port C Bit3: Port B Bit 2: Port A
    RCC->APB2ENR |=  RCC_APB2ENR_IOPCEN | RCC_APB2ENR_IOPBEN
        | RCC_APB2ENR_IOPAEN ;

    //Set the config and mode bits for Port C bit 9 and 8 so they will
    // be push-pull outputs (up to 50 MHz)
    GPIOC->CRH |= GPIO_CRH_MODE9 | GPIO_CRH_MODE8 ;
    GPIOC->CRH &= ~GPIO_CRH_CNF9 & ~GPIO_CRH_CNF8 ;
}

/*************************************************
* This function will alternate the LEDs on the VLDiscovery board
**************************************************/

void SysTick_init(void)
{
	SysTick->CTRL = 0x0;

	SysTick->VAL = 0x0 ;
	
	SysTick->LOAD = 0x16E3600;//some value i dont know
	
	SysTick->CTRL = 0x07;
	
}

void SysTick_Handler(void)
{
	GPIOC->ODR ^= GPIO_ODR_ODR9;
}

void EXTI0_IRQHandler(void)
{
	EXTI->PR |=EXTI_PR_PR0;
	GPIOC->ODR ^=GPIO_ODR_ODR8;
}

void EXTI0_IRQ_init(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	AFIO->EXTICR[0] &= AFIO_EXTICR1_EXTI0;
	EXTI->IMR |= EXTI_IMR_MR0;
	EXTI->FTSR |= EXTI_FTSR_TR0;
	NVIC->ISER[0] |= NVIC_ISER_SETENA_6;
}
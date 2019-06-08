
#include <stdint.h>


 //Functions available for public use

// Initialize the Cortex M3 clock using the RCC registers
  void clockInit(void);

// Initialize the clocks and IO pins for the LEDs and USER switch
  void led_IO_init (void);
	
	void SysTick_init(void);
	void SysTick_Handler(void);
	
	void EXTI0_IRQHandler(void);
	void EXTI0_IRQ_init(void);
/* Lab 4 */
/* Author –Daris Lychuk, Feb 2019 */

#include "lab4.h"

int main(void)
{
	clockInit();
	led_IO_init();
	SysTick_init();
	EXTI0_IRQ_init();
	
	while(1)
	{
	}
	EXTI0_IRQHandler();
}
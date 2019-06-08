#include "stm32f10x.h"
#include "lab8.h"

int main(void)
{
	uint16_t value = 0x2955;
	uint16_t receive;
	clockInit();
	spiInIt();
	
	while(1)
	{
		receive = spi2xfr8(value);
		delay(6000);
		
		if(receive == value)
			GPIOC->BSRR = GREEN_ON;
		else
			GPIOC->BSRR = GREEN_OFF;			
	}
}

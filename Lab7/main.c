#include "lab7.h"

int main(void)
{
	uint8_t value;
	clockInit();
	usartInit();
	lcd_IO_init();
	
	while(1)
	{
		for(uint8_t i=0x24;i<0xFF;i++)
		{
		transfer(i);
		value = receive();
		printToLCD(value);
		delay(5000000);
		}
			
	}
}
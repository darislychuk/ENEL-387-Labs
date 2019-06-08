/* Lab 4 */
/* Author –Daris Lychuk, Feb 2019 */

#include "lab5.h"

int main(void)
{
	int printed = 0;
	uint16_t readValue;
	clockInit();
	lcd_IO_init();
	ADCinit();

	
	while(1)
	{
		readValue = readTemp(0x2);
		printToLCD(readValue);

		delay(5000000);
	}

}
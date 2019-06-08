/* Second Program in C */
/* Author – Daris Lychuk, Jan 2019 */
#include "lab3.h"

int main(void)
{
	int printed = 0;
	int select_switch = 0;
	clockInit();
	lcd_IO_init();

	while(1)
	{
		//LED(read_DIP());
		select_switch = dip_switch(read_DIP(), select_switch);
		if(printed == 0) {
		stringToLCD("Daris Lychuk");
		commandToLCD(LCD_LN2);
		stringToLCD("200361245");
		printed = 1;
		}
		else
		{
		}
	}
}
/* Second Program in C */
/* Author – Daris Lychuk, Jan 2019 */
#include "lab2_lib.h"

int main(void)
{
	clockInit();
	led_IO_init();
	
	while(1)
	{
		LED(read_DIP());
	}
}
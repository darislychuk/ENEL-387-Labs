#include "lab6_PWM.h"

int main(void)
{
	clockInit();
	pwmInit();
	while(1)
	{
		checkButton();
	}
}
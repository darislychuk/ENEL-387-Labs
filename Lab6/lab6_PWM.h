#include <stdint.h>
#include "stm32f10x.h"


//Functions available for public use
// Initialize the Cortex M3 clock using the RCC registers
void clockInit(void);
void checkButton(void);

void pwmInit(void);
void pwmUpdate(unsigned int);
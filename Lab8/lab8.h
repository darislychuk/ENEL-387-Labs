#include <stdint.h>


#define GREEN_ON 0x00000200
#define GREEN_OFF 0x02000000

//Functions available for public use
void delay(uint32_t delay);
// Initialize the Cortex M3 clock using the RCC registers
void clockInit(void);

void spiInIt(void);

uint16_t spi2xfr8(uint16_t);

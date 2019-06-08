 #include "stm32f10x.h"
 #include "lab5.h"

//// SWITCH AND LED I/O FUNCTIONS


void ADCinit(void)
{
	RCC->APB2ENR |=  RCC_APB2ENR_ADC1EN | RCC_APB2ENR_AFIOEN | RCC_APB2ENR_IOPAEN;
	GPIOA->CRL &= ~GPIO_CRL_CNF1_0 & ~GPIO_CRL_CNF2_0 ;
	ADC1->CR2 |= 0x00000001;
}

uint16_t readTemp(uint16_t valToRead)
{
	//uint8_t hexval;
	ADC1->SQR3 |= 0x00000001;
	//ADC1->SQR3 |= 0x00000002;
	ADC1->CR2 |= 0x00000001;
	while (ADC_SR_EOC == 0)
	{
		valToRead = ADC1->DR;
	}
	return (ADC1->DR);

}

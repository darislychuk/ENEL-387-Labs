#include "lab7.h"

void usartInit(void){
	
	USART3->CR1 |= USART_CR1_UE;
	USART3->BRR = 0x9C4;
	USART3->CR1 |= USART_CR1_TE | USART_CR1_RE;
}

void transfer(uint8_t dataOut){
	
	if ((USART3->SR & USART_SR_TXE) == USART_SR_TXE)
		USART3->DR = dataOut;
}

uint8_t receive(void){
	
	uint8_t dataIn;
	if ((USART3->SR & USART_SR_RXNE) == USART_SR_RXNE)
		dataIn = USART3->DR;
	return dataIn;
}
 #include "stm32f10x.h"
 #include "lab8.h"
 
 void spiInIt(void){
	 
	 GPIOB->BSRR |= GPIO_BSRR_BS12; //Set pb12 to high
	 
	 SPI2->CR2 &= ~SPI_CR2_SSOE;
	 
	 SPI2->CR1 |= SPI_CR1_SSI | SPI_CR1_SSM;
	 
	 SPI2->CR1 |= SPI_CR1_BR_0 | SPI_CR1_BR_2;
	 
	 SPI2->CR1 |= SPI_CR1_DFF | SPI_CR1_MSTR;
	 
	 SPI2->CR1 |= SPI_CR1_SPE;	 
 }
 
 uint16_t spi2xfr8(uint16_t SPI_tx_data){
	 
	 uint16_t SPI_rx_data = 0;
	 
	 GPIOB->BSRR |= GPIO_BSRR_BR12; //slave select going low
	 
	 while(!(SPI2->SR & SPI_SR_TXE));
	 SPI2->DR = SPI_tx_data;
	 
	 while(!(SPI2->SR & SPI_SR_RXNE));
	 SPI_rx_data = SPI2->DR;
	 
	 GPIOB->BSRR |= GPIO_BSRR_BS12;//slave select going high
	 
	 return(SPI_rx_data);
 }
 
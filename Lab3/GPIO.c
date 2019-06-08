 #include "stm32f10x.h"
 #include "lab3.h"


// SWITCH AND LED I/O FUNCTIONS

//void led_IO_init (void)
//{
//    //Enable peripheral clocks for various ports and subsystems
//    //Bit 4: Port C Bit3: Port B Bit 2: Port A
//    RCC->APB2ENR |=  RCC_APB2ENR_IOPCEN | RCC_APB2ENR_IOPBEN
//        | RCC_APB2ENR_IOPAEN ;

//    //Set the config and mode bits for Port C bit 9 and 8 so they will
//    // be push-pull outputs (up to 50 MHz)
//    GPIOC->CRH |= GPIO_CRH_MODE9 | GPIO_CRH_MODE8 ;
//    GPIOC->CRH &= ~GPIO_CRH_CNF9 & ~GPIO_CRH_CNF8 ;
//}

uint16_t read_DIP(void)
{
	uint16_t sw_val;
	sw_val = (((GPIOA->IDR & (GPIO_IDR_IDR6 | GPIO_IDR_IDR7))>>6) | ((GPIOC->IDR & (GPIO_IDR_IDR10 | GPIO_IDR_IDR11))>>8) ) & 0x0F;
	
	//GPIOA->ODR = 0x1E00;
	return(sw_val);
}
int dip_switch(uint16_t x, int select_switch)
{
uint16_t button;

//button = read_DIP();
	
button = x & 0x0F;
	if((button == 0x01) && (select_switch != 1)){
		commandToLCD(LCD_CLR);
		stringToLCD("Dip1");
		select_switch = 1;
	}
	if((button == 0x02) && (select_switch != 2)){
		commandToLCD(LCD_CLR);
		stringToLCD("Dip2");
		select_switch = 2;
	}
	if((button == 0x04) && (select_switch != 3)){
		commandToLCD(LCD_CLR);
		stringToLCD("Dip3");
		select_switch = 3;
	}
	if((button == 0x08) && (select_switch != 4)){
		commandToLCD(LCD_CLR);
		stringToLCD("Dip4");
		select_switch = 4;
	}
	return select_switch;
//	if(button == 0x0F)
//		GPIOA->ODR = 0x1E00;

}
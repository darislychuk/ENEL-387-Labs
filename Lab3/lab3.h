/******************************************************************************
 * Name:    lab1_lib.h
 * Description: STM32 peripherals initialization
 * Version: V1.00
 * Authors: Dave Duguid / Trevor Douglas
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 *
 *----------------------------------------------------------------------------
 * History:
 *          V1.00 Initial Version
 *          V1.1 reformatted (kjn)
 *****************************************************************************/
#include <stdint.h>


////Bit masks for leds on STM32VLDiscovery board PC8 and PC9 using GPIOC_BSRR
//// Green LED is on bit 9 of port C, Blue LED is on bit 8.
// #define GREEN_ON	0X00000200 //
// #define GREEN_OFF	0x02000000 //
// #define BLUE_ON	0x00000100 //
// #define BLUE_OFF	0x01000000 //
//Commands for Hitachi 44780 compatible LCD controllers
#define LCD_8B2L 0x38 // ; Enable 8 bit data, 2 display lines
#define LCD_DCB 0x0F // ; Enable Display, Cursor, Blink
#define LCD_MCR 0x06 // ; Set Move Cursor Right
#define LCD_CLR 0x01 // ; Home and clear LCD
#define LCD_LN1 0x80 // ;Set DDRAM to start of line 1
#define LCD_LN2 0xC0 // ; Set DDRAM to start of line 2
// Control signal manipulation for LCDs on 352/384/387 board
// PB0:RS PB1:ENA PB5:R/W*
#define LCD_CM_ENA 0x00210002 //
#define LCD_CM_DIS 0x00230000 //
#define LCD_DM_ENA 0x00200003 //
#define LCD_DM_DIS 0x00220001 //


 //Functions available for public use

// Initialize the Cortex M3 clock using the RCC registers
  void clockInit(void);
// A general purpose countdown timer delay routine
  void delay(uint32_t delay);
// Initialize the clocks and IO pins for the LEDs and USER switch
  void led_IO_init (void);
	
	uint16_t read_DIP(void);
	
	void LED(uint16_t x);
	
	void stringToLCD(char * message);
	
	void lcd_IO_init (void);

	void commandToLCD(uint8_t data);
	
	void dataToLCD(uint8_t data);
	
	int dip_switch(uint16_t x, int select_switch);
//Using modifications of https://github.com/kates/msp430-lcd/blob/master/lcd.c


#include "LPC11xx.h"
#include "lcd.h"
#include <stdio.h>
#include <rt_misc.h> //for Serial monitor?
//Not sure how it uses them, but MUST copy serial.c and retarget.c.

/* Import external functions from Serial.c file                               */
extern void SER_init (void);


void configureGPIO()
{

	//enable clocks to GPIO block. pg 34 of manual.
	LPC_SYSCON->SYSAHBCLKCTRL |= (1UL <<  6);
	LPC_SYSCON->SYSAHBCLKCTRL |= (1UL <<  16);
}


int main()
{	
	SER_init();	
	configureGPIO();
  //lcd_init();	

//	printf("%x \n", ~(LCD_RS | LCD_RW | LCD_EN | LCD_DATA_PINS) );
//pins 4 and 5 are not working! check chapter 12.
	
	LCD_DIR |= LCD_RS | LCD_RW | LCD_EN | LCD_DATA_PINS; //set pins to output
  LCD_PORT &= ~(LCD_RS | LCD_RW | LCD_EN | LCD_DATA_PINS); //clear pins
	printf("After setting Pin Direction: %x \n",LCD_PORT);
  printf("After clearing pins: %x \n",LCD_PORT);
	LCD_PORT |= LCD_DATA_PINS;
	//LCD_PORT &= ~LCD_RS;
	printf("Current State of Register %x \n",LCD_PORT);
	
while(1);
	
	
  lcd_go_line(1);
  lcd_writeln("Hello");
  lcd_go_line(2);
  lcd_writeln("World");
  //_BIS_SR(LPM3_bits);
	while (1) {}
	return 0;
}

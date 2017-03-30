//Using modifications of https://github.com/kates/msp430-lcd/blob/master/lcd.c

#include <stdio.h>
#include "LPC11xx.h"
#include "lcd.h"



void configureGPIO()
{

	//enable clocks to GPIO block. pg 34 of manual.
	LPC_SYSCON->SYSAHBCLKCTRL |= (1UL <<  6);
	LPC_SYSCON->SYSAHBCLKCTRL |= (1UL <<  16);
}


int main()
{	
	configureGPIO();
  lcd_init();

	//LCD_PORT |= LCD_RS;

while(1);
  lcd_go_line(1);
  lcd_writeln("Hello");
  lcd_go_line(2);
  lcd_writeln("World");
  //_BIS_SR(LPM3_bits);
	while (1) {}
	return 0;
}

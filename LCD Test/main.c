//Using modifications of https://github.com/kates/msp430-lcd/blob/master/lcd.c

#include <stdio.h>
#include "LPC11xx.h"
#include <lcd.h>



void configureGPIO()
{
	int i;
	//enable clocks to GPIO block
	LPC_SYSCON->SYSAHBCLKCTRL |= (1UL <<  6);
	LPC_SYSCON->SYSAHBCLKCTRL |= (1UL <<  16);
}


int main()
{	
  lcd_init();
  lcd_go_line(1);
  lcd_writeln("Hello");
  lcd_go_line(2);
  lcd_writeln("World");
  _BIS_SR(LPM3_bits);
	while (1) {}
	return 0;
}

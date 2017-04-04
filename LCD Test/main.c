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
	
	printf("\n\nTest Serial at beginning\n");

  lcd_init();
	printf("init complete.\n");

	while(1);
  lcd_go_line(1);
  lcd_writeln("Hello");
	lcd_go_line(2);
  lcd_writeln("World");
	printf("Main.c complete.\n");
  //_BIS_SR(LPM3_bits);
	while (1) {}
	return 0;
}

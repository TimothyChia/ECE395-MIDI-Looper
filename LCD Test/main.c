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

void printPins(uint32_t reg)
{
	int i;
	int state;
	for(i=0;i<8;i++) //change break condition for more pins
	{
		state = (reg >> i) & 1;
		printf("Pin %x is %x\n",i,state);
	}
	return;
}


int main()
{	
	SER_init();	
	configureGPIO();
	
	//printPins(0xf1f);
	
  lcd_init();		
	
  lcd_go_line(1);
  lcd_writeln("Hello");
	lcd_go_line(2);
  lcd_writeln("World");
	printf("Main.c complete.\n");
  //_BIS_SR(LPM3_bits);
	while (1) {}
	return 0;
}

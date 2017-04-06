#include <stdio.h>
#include "LPC11xx.h"
#include <rt_misc.h>

extern void SER_init (void);

void configureGPIO()
{
	//enable clocks to GPIO block
	//LPC_SYSCON->SYSAHBCLKCTRL |= (1UL <<  6);
	//LPC_SYSCON->SYSAHBCLKCTRL |= (1UL <<  16); //doesn't seem relevant to this program?

	//LPC_SYSCON->SYSAHBCLKCTRL &= ~(1UL <<  6); //this is a good way to break the GPIO. 
	
	//set port 0_7 to output (high current drain in LPC1114)
    LPC_GPIO0->DIR |= (1<<7);
}

void ledOn()
{
	LPC_GPIO0->DATA &= ~(1<<7);
}

void ledOff()
{						 
	LPC_GPIO0->DATA |= (1<<7);
}

int main()
{
	int i, j = 0;
	SER_init();
	configureGPIO();
	while (1)
	{
		ledOn();
		printf("Led On, Iteration %d\n\r", j);
		for (i = 0; i < 0x0007FFFF; i++)
		{
		}
		ledOff();
		printf("Led Off, Iteration %d\n\r", j);
		for (i = 0; i < 0x0007FFFF; i++)
		{
		}
		j++;
	}
}

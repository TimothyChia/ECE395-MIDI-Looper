#include <stdio.h>
#include "LPC11xx.h"
#include <rt_misc.h>
#include "relay_config.h"

extern void SER_init (void);


uint16_t sel_pins[2] = {SEL_0, SEL_1};
uint16_t dir_pins[2] = {REL_RES, REL_SET};

void configureGPIO()
{
	//enable clocks to GPIO block
	LPC_SYSCON->SYSAHBCLKCTRL |= (1UL <<  6);
	LPC_SYSCON->SYSAHBCLKCTRL |= (1UL <<  16); //doesn't seem relevant to this program?

	//set port 0_7 to output (high current drain in LPC1114)
  //LPC_GPIO0->DIR |= (1<<7);
}

/*Inputs:num is the relay number. Call with dir=0 to reset, dir=1 to set */
void relSwitch(char num, char dir)
{
  int i;

  if(dir>1)
    return;
	

  /*Set the select pins. */
  for(i=0; i<2;i++)
  {
    if(num & (1 << i) )
    {REL_PORT |= sel_pins[i]; }
    else
    {REL_PORT &= ~sel_pins[i]; }
  }

  REL_PORT &= ~(dir_pins[dir]);
	/*Width of enable pulse.*/
  for(i=0;i<5000;i++) //5000 ish seems an acceptable width by trial and error.
  {}
		while(1); //tested current flow across relay, got 14 mA.
  REL_PORT |= dir_pins[dir];

  return;
}

void relayInit()
{
  int i;
	REL_DIR |= SEL_0 | SEL_1 | REL_RES | REL_SET;
	//REL_DIR &=  ~ (UP | DOWN);


	REL_PORT |= REL_SET | REL_RES;
	REL_PORT &= ~(SEL_0 | SEL_1);

	
		relSwitch(0,1);
	while(1);
	
  for(i=0;i<4;i++)
  {
    relSwitch(i,0);
  }
  return;
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
  relayInit();
	printf("Initialization complete.");


	
	//relSwitch(0,1);
	while (1)
	{
		relSwitch(0,1);
		printf("Led On, Iteration %d\n\r", j);
		for (i = 0; i < 0x0000FFFFF; i++)
		{
		}
		relSwitch(0,0);
		printf("Led Off, Iteration %d\n\r", j);
		for (i = 0; i < 0x0000FFFFF; i++)
		{
		}
		j++;
	}

}

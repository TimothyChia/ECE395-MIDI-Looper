#include <stdio.h>
#include "LPC11xx.h"
#include <rt_misc.h>
#include "relay_config.h"

#define DIM 4	//number of relays, presets

extern void SER_init (void);

int presets[DIM][DIM];

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

void recallPreset(int preset)
{

}

int main()
{
	int i, j = 0;
	SER_init();
	configureGPIO();
  relayInit();
	printf("Initialization complete.");

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

int draftnewMain()
{
	char FS;
	char itx;
	char[6] = {FS_NEXT, FS_PREV, FS_R0, FS_R1, FS_R2, FS_R3};


	char pre1 = 0;
	char pre2 = 3;
	char pre3 = 5;
	char pre4 = 7;

	char preAll[4] = {pre1,pre2,pre3,pre4};

	char currPre = 0;
	char localPre = 0;

	while(1)
	{
	 FS = pollFS();

	 if(FS == FS_NEXT)
		{
			currPre = (currPre+1)%4;
			writePre( preAll[currPre] );
		}
	else if(FS== FS_PREV)
else if()
else if()
else if()
else if()
else if()
	}
}

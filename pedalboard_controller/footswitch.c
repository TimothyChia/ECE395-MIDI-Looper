#include "footswitch.h"
#include <stdio.h>
#include <rt_misc.h>


char fsb_pins[3] = {FSB_0, FSB_1, FSB_2};
int cycles = 0;
int last_FS_Num = -1;

void FSinit()
{
  //Assume clocks and IOCON are set correctly. Double check this later.
  FS_DIR = ~(FSB_0 | FSB_1 | FSB_2 );

  LPC_GPIO0->DIR = ~( FS_SHIFT_R0);
}

/*Calculates which of the 8 FS is currently depressed. FS [0,7]. Returns -1 if none.*/
int pollFS()
{
  int FS_Num = -1;
  int FSB_out = 0;
  int itx;

  FS_Num = -1;
  //printf("%x\n",FS_PORT);

  /*Calculate input of encoder */
  for(itx=0; itx<3; itx++)
  {
    //Active low
    if( !(FS_PORT & fsb_pins[itx]) )
      FSB_out |= (1<<itx ) ;
  }

  if(FSB_out>0)
    FS_Num = FSB_out;

//  if( !(FS_PORT  & FS_SHIFT_R0) )
  if( !(  (LPC_GPIO0->DATA)  & FS_SHIFT_R0) )
  {
  //  FS_NUM += FS_SHIFT_VAL;
    FS_Num=0;
  }




  if (last_FS_Num != FS_Num) last_FS_Num = FS_Num;
  if (last_FS_Num == FS_Num) cycles++;

  if (cycles >= 200)
  {
    cycles = 0;
    return FS_Num;
  }
  return -1;
}

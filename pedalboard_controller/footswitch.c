#include footswitch.h

uint16_t fsb_pins[2] = {FSB_0, FSB_1, FSB_2};


void FSinit()
{
  //Assume clocks and IOCON are set correctly. Double check this later.
  FS_DIR = ~(FSB_0 | FSB_1 | FSB_2  | FS_SHIFT);
}

char pollFS()
{
  int FS_Num=0;
  int itx;

  for(itx=0; itx++; itx<3)
  {
    //Active low
    if( !(FSB_PORT & (1<<fsb_pins[itx])) )
      FS_NUM += (2^itx) ;

  }

  if(FSB_PORT  & (1<< FS_SHIFT) )
  {
    FS_NUM += FS_SHIFT_VAL;
  }

  return FS_Num;
}

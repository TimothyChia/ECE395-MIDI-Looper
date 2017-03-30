
/*
0
1
2
3
4
5
6
7
8 RS
9 R/W
10 E
*/

#define LCD_RS 8
#define LCD_RW 9
#define LCD_E 10

void delay(int a)
{
	int i;
for (i = 0; i < a*100000; i++)
		{
		}
}

void Nybble()
{
  LPC_GPIO0->DATA |= (1<< LCD_E); // E=1
  delay(1);
  LPC_GPIO0->DATA &= ~(1<< LCD_E); // E=0

}
void command(char i)
{
  LPC_GPIO0->DATA &= 0xFFFFFF00;
  LPC_GPIO0->DATA |= 0xFFFFFF00 + i;
  LPC_GPIO0->DATA &= ~(1<< LCD_RS); // RS=0
  LPC_GPIO0->DATA &= ~(1<< LCD_RW); // RW=0
  Nybble();
}

void write(char i)
{
  LPC_GPIO0->DATA &= 0xFFFFFF00;
  LPC_GPIO0->DATA |= 0xFFFFFF00 + i;
  LPC_GPIO0->DATA |= (1<< LCD_RS); // RS=1
  LPC_GPIO0->DATA &= ~(1<< LCD_RW); // RW=0
  Nybble();
}



void init()
{
  LPC_GPIO0->DATA &= ~(1<< LCD_E); // E=0
  delay(100);
  command(0x30);
  delay(30);
  command(0x30);
  delay(10);
  command(0x30);
  delay(10);
  command(0x38);
  command(0x10);
  command(0x0c);
  command(0x06);

  write(0x50); //capital P
}

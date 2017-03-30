#define LCD_D1 1
#define LCD_D2 2
#define LCD_D3 3
#define LCD_D4 4
#define LCD_D5 5
#define LCD_D6 6
#define LCD_D7 7
#define LCD_D8 8


#define LCD_RS 5
#define LCD_RW 6
#define LCD_E  7

int lcdDat [8] = {LCD_D1,LCD_D2,LCD_D3,LCD_D4,LCD_D5,LCD_D6,LCD_D7,LCD_D8};

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

//sends 
void lcd_send4(uint8_t data) {
	uint8_t i;
  LCD_PORT |= LCD_EN;
	for (i = 0; i < 4; i++) {
		if (data & (1 << i)){
			LCD_PORT |= lcd_pins[i];
		} 
		else {
			LCD_PORT &= ~lcd_pins[i];
		}
	}
  lcd_delay_us(1);
  LCD_PORT &= ~LCD_EN;
  LCD_PORT &= ~(LCD_DATA_PINS);
  lcd_delay_us(1);
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
/*
 * Define pins and ports here
 */

#define LCD_PORT LPC_GPIO0->DATA
#define LCD_DIR LPC_GPIO0->DIR

#define LCD_RS (1UL<<5)
#define LCD_RW (1UL<<6)
#define LCD_EN (1UL<<7)

#define LCD_D4 (1UL<<1)
#define LCD_D5 (1UL<<2)
#define LCD_D6 (1UL<<3)
#define LCD_D7 (1UL<<4)
#define LCD_FCPU 8000000

#define D4_IOCON LPC_IOCON->PIO0_1
#define D5_IOCON LPC_IOCON->PIO0_2
#define D6_IOCON LPC_IOCON->PIO0_3
#define D7_IOCON LPC_IOCON->PIO0_4
#define RS_IOCON LPC_IOCON->PIO0_5
#define RW_IOCON LPC_IOCON->PIO0_6
#define EN_IOCON LPC_IOCON->PIO0_7 //clear bit 4 to disable internal pullups

// how many rows and colums?
// default is 16x2

// #define LCD_COLUMNS 16
// #define LCD_ROWS 2

/*
 * Define pins and ports here
 */

#define LCD_PORT LPC_GPIO0->DATA
#define LCD_DIR LPC_GPIO0->DIR

#define LCD_RS 5
#define LCD_RW 6
#define LCD_EN 7

#define LCD_D4 1
#define LCD_D5 2
#define LCD_D6 3
#define LCD_D7 4
#define LCD_FCPU 8000000


// how many rows and colums?
// default is 16x2

// #define LCD_COLUMNS 16
// #define LCD_ROWS 2

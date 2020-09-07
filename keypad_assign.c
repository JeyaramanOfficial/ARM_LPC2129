// rows --> p1.17 to p1.20
//cols ---> p1.21 to p1.24

// ROWS as Input
// 0x0E --> r1
// 0x0D --> r2
// 0x0B --> r3
// 0x07 --> r4
// Make use of COL as input find out columns
// integrate both rows and cols
#include "../lcd_header.h"

#define ROW (0x0F<<21)    // p1.21 to p1.24 ---> 0x0001E000
#define COL (0x0F<<17)	  // p1.17 to p1.20
void row_key(void);
void col_key1(void);
void col_key2(void);
void col_key3(void);
void col_key4(void);
int main()
{
	lcd_config();
	while(1)
	{
		row_key();
	}	
}

void row_key(void)
{
		int val;
		IODIR1 = IODIR1 & ~(ROW);
		IODIR1 = IODIR1 | (COL);
		val = (IOPIN1 & ROW); // => [31 --- [24 23 22 21] --- 0]
		val = val >> 21;
		switch(val)
		{
			case 0x0E: 
				col_key1();  // 1 2 3 +
				break;
			case 0x0D:
				col_key2();  // 3 4 5 -
				break;
			case 0x0B:
				col_key3();  // 6 7 9 *
				break;
			case 0x07:
				col_key4();  // # 0 = /
				break;
//			default:
//				delay(500);
//				lcd_cmd(0x01);
		}
}

void col_key1(void)
{
		int val;
		IODIR1 = IODIR1 & ~(COL);  //col as i/p    
		IODIR1 = IODIR1 | (ROW);  //row as o/p
		val = (IOPIN1 & COL); // => [31 --- [24 23 22 21] --- 0]
		val = val >> 17;
		switch(val)
		{
			case 0x0E: 
				lcd_data('1');
				delay(500);
				break;
			case 0x0D:
				lcd_data('2');
				delay(500);
				break;
			case 0x0B:
				lcd_data('3');
				delay(500);
				break;
			case 0x07:
				lcd_data('+');
				delay(500);
				break;
						
		}
}

void col_key2(void)
{
		int val;
		IODIR1 = IODIR1 & ~(COL);  //col as i/p    
		IODIR1 = IODIR1 | (ROW);  //row as o/p
		val = (IOPIN1 & COL); // => [31 --- [24 23 22 21] --- 0]
		val = val >> 17;
		switch(val)
		{
			case 0x0E: 
				lcd_data('4');
				delay(500);
				break;
			case 0x0D:
				lcd_data('5');
				delay(500);
				break;
			case 0x0B:
				lcd_data('6');
				delay(500);
				break;
			case 0x07:
				lcd_data('-');
				delay(500);
				break;
					
		}
}
void col_key3(void)
{
		int val;
		IODIR1 = IODIR1 & ~(COL);  //col as i/p    
		IODIR1 = IODIR1 | (ROW);  //row as o/p
		val = (IOPIN1 & COL); // => [31 --- [24 23 22 21] --- 0]
		val = val >> 17;
		switch(val)
		{
			case 0x0E: 
				lcd_data('7');
				delay(500);
				break;
			case 0x0D:
				lcd_data('8');
				delay(500);
				break;
			case 0x0B:
				lcd_data('9');
				delay(500);
				break;
			case 0x07:
				lcd_data('*');
				delay(500);
				break;
						
		}
}

void col_key4(void)
{
		int val;
		IODIR1 = IODIR1 & ~(COL);  //col as i/p    
		IODIR1 = IODIR1 | (ROW);  //row as o/p
		val = (IOPIN1 & COL); // => [31 --- [24 23 22 21] --- 0]
		val = val >> 17;
		switch(val)
		{
			case 0x0E: 
				lcd_data('#');
				delay(500);
				break;
			case 0x0D:
				lcd_data('0');
				delay(500);
				break;
			case 0x0B:
				lcd_data('=');
				delay(500);
				break;
			case 0x07:
				lcd_data('/');
				delay(500);
				break;
						
		}
}

/*  1 2 3 +
    4 5 6 -
    7 8 9 *
    # 0 = /  */

/*  1 2 3 +
    1 2 3 +
    1 2 3 + 
    1 2 3 + */


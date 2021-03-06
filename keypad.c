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
void col_key(void);
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
				lcd_str("R1");
				col_key();
				break;
			case 0x0D:
				lcd_str("R2");
				col_key();
				break;
			case 0x0B:
				lcd_str("R3");
				col_key();
				break;
			case 0x07:
				lcd_str("R4");
				col_key();
				break;
			default:
				delay(1000);
				lcd_cmd(0x01);
		}
}

void col_key(void)
{
		int val;
		IODIR1 = IODIR1 & ~(COL);  //col as i/p    
		IODIR1 = IODIR1 | (ROW);  //row as o/p
	
		val = (IOPIN1 & COL); // => [31 --- [24 23 22 21] --- 0]
		val = val >> 17;
		lcd_cmd(0xC0);
		switch(val)
		{
			case 0x0E: 
				lcd_str("C1");
				delay(200);
				break;
			case 0x0D:
				lcd_str("C2");
				delay(200);
				break;
			case 0x0B:
				lcd_str("C3");
				delay(200);
				break;
			case 0x07:
				lcd_str("C4");
				delay(200);
				break;
			default:
				delay(1000);
				lcd_cmd(0x01);			
		}
}

/*  1 2 3 +
    4 5 6 -
    7 8 9 *
    # 0 = /  */
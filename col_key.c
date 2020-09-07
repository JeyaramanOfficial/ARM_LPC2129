// rows --> p1.17 to p1.20
//cols ---> p1.21 to p1.24

// COLS as Input

// Make use of COL as input find out columns
// integrate both rows and cols

// 0x0E --> r1,c1
// 0x0D --> r2,c2
// 0x0B --> r3,c3
// 0x07 --> r4,c4
#include "../lcd_header.h"

#define ROW (0x0F<<21)    // p1.21 to p1.24---> 0x0001E000 
#define COL (0x0F<<17)	 // p1.17 to p1.20
void rows(void);
void row_key(void);
void col_key(void);
int main()
{
	

	lcd_config();
	while(1)
	{
		col_key();
	}	
}


void col_key(void)
{
		int val;
		IODIR1 = IODIR1 & ~(COL);  //col as i/p    
		IODIR1 = IODIR1 | (ROW);  //row as o/p
	
		val = (IOPIN1 & COL); // => [31 --- [20 19 18 17] --- 0]
		val = val >> 17;
		
		switch(val)
		{
			case 0x0E: 
				lcd_str("C1");
				delay(500);
				break;
			case 0x0D:
				lcd_str("C2");
				delay(500);
				break;
			case 0x0B:
				lcd_str("C3");
				delay(500);
				break;
			case 0x07:
				lcd_str("C4");
				delay(500);
				break;
			default:
				delay(1000);
				lcd_cmd(0x01);
			
		}

}



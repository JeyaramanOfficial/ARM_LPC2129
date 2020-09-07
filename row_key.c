// rows --> p1.17 to p1.20
//cols ---> p1.21 to p1.24

// ROWS as Input

#include "../lcd_header.h"

#define ROW (0x0F<<17)   // p1.17 to p1.20 ---> 0x0001E000
#define COL (0x0F<<21)	 // p1.21 to p1.24

int main()
{
	int val;
	IODIR1 = IODIR1 & ~(ROW);
//	IODIR1 &= ~(ROW);
	IODIR1 = IODIR1 | (COL);
// 0x0E --> r1
// 0x0D --> r2
// 0x0B --> r3
// 0x07 --> r4
	lcd_config();
	while(1)
	{
		val = (IOPIN1 & ROW); // => [31 --- [20 19 18 17] --- 0]
		val = val >> 17;
//	  0x001E0000 --->
//	  0x00[23 22 21 20 19 18 17 16]0000
//		0x00[ 0  0  0  1  1  1  1 0 ]0000
//		0x001E 0000 --> no key pressed
//		val >> 17 ---> 0x0000 000F ---> no Key pressed
	
//		0x00[ 0  0  0  1  1  1  0 0 ]0000  ---> key1 
//	  val = 0x001C 0000
//    val >> 17 ---> 0x0000 000E --> key1
//		if(val ==  0x001C0000)
		if(val == 0x0E)
		{
			lcd_str("row1");
			delay(500);
		}
//		0x00[ 0  0  0  1  1  0  1 0 ]0000 ----> key2
//		val = 0x001A 0000
//		val >>17 ---> 0x0000 000D -->key2
		if(val == 0x0D)
		{
			lcd_str("row2");
			delay(500);
		}
//		0x00[ 0  0  0  1  0  1  1 0 ]0000 ----> key3
//		val = 0x0016 0000
//		val >> 17 --> 0x0000 000B --> key3
		if(val == 0x0B)
		{
			lcd_str("row3");
			delay(500);
		}
//		0x00[ 0  0  0  0  1  1  1 0 ]0000 ----> key4
//		val = 0x000E 0000
//		val >> 17 --> 0x0000 0007 --> key4
		if(val == 0x07)
		{
			lcd_str("Row4");
			delay(500);
		}
	   
//	 [31 --- [20 19 18 17] --- 0]
// 	 0x00[23 22 21 20 19 18 17 16]0000
//	 0x00[ 0  0  0  1  1  1  1 0 ]0000

//   [31  ---- ---------[3 2 1 0]]
//    0x0000 000[3 2 1 0]
//    0x0000 000[1 1 1 1]
//    0x0F
		lcd_cmd(0x01);
	
	}	
}

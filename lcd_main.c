#include "lcd_header.h"

int main()
{
	int i=0;
	lcd_config();
//	lcd_str("A");
//	lcd_cmd(0x85);
//	lcd_data('B');
//	lcd_cmd(0xc0);
//	lcd_data('c');
//	lcd_cmd(0xc5);
//	lcd_data('D');
	while(1)
	{
			i++;
			lcd_cmd(0x80+i);
			lcd_str("A");
			delay(1000);
			lcd_cmd(0x01);
			if(i==16)
				i=0;
	}
}

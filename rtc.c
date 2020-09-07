#include "../lcd_header.h"

int main()
{
	lcd_config();
	CCR = 1<<0;		//enable RTC clock
	PREINT = 456;
	PREFRAC = 25024;
	
	HOUR = 11;
	MIN = 12;
	SEC = 00;
	
	while(1)
	{
		lcd_num(HOUR);
		lcd_data(':');
		lcd_num(MIN);
		lcd_data(':');
		lcd_num(SEC);
		lcd_cmd(0x80);
	}
}

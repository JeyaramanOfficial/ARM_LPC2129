#include "lcd_header.h"


int main()
{
	int res,done = 1;
//	PINSEL1 |= 1<<22;
//	PINSEL1 &= ~(1<<23); //p0.27 | AIN0 //Potentiometer
	PINSEL1 |= 1<<24;
	PINSEL1 &= ~(1<<25); //p0.28 | AIN1 // Temperature Sensor
	lcd_config();
//	ADCR = (1<<0)|(4<<8)|(1<<16)|(1<<21);  //Channel Sel | clk div | burst | PDN
	ADCR = (1<<1)|(4<<8)|(1<<16)|(1<<21);  //Channel Sel | clk div | burst | PDN
	while(1)
	{
		//check conversion done
		// collect value
		while(!(ADDR & (done<<31)));
		res = ADDR & (0x3FF<<6);
		res = res>>6;
		res = res/3.3;  // convert 10bit digital value to Degree celcius
		lcd_num(res);
		delay(1000);
		lcd_cmd(0x01);
		
	}
}


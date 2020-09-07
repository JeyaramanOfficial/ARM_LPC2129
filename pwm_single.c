#include<lpc21xx.h>

void delay(int);
int main()
{
	PINSEL0 |= (1<<17);
	PINSEL0 &= ~(1<<16);  //P0.8 ---> channel4
	
//	PINSEL0 |= 0x00020000;
	
	PWMPR = 14;
	PWMMR0 = 10000;
	PWMLER = 1<<0;
	PWMMCR = (1<<1);   //reset Total time period //MR0
	PWMPCR &= ~(1<<4);  // --> select single edge for channel 4
	PWMPCR = (1<<12);
	PWMTCR = (1<<0)|(1<<3);  // Timer enable| PWM Enable
	
		while(1)
		{
			PWMMR4 = 2500;   //25% duty cycle
			PWMLER = 1<<4;
			delay(500);
			
			PWMMR4 = 5000;   //50% duty cycle
			PWMLER = 1<<4;
			delay(500);
			
			PWMMR4 = 7500;   //75% duty cycle
			PWMLER = 1<<4;
			delay(500);
			
			PWMMR4 = 10000;   //100% duty cycle
			PWMLER = 1<<4;
			delay(500);
		
	}
}

void delay(int ct)
{
	for(int i=0;i<ct;i++)
	{
		for(int j=0;j<6000;j++)
		{
		}
	}
}

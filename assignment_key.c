// Led pins --> p1.17 to p1.24/p0.8 // o/p pins --> 1
//button/switch --> p1.25  // i/p pins ---> 0
#include<lpc21xx.h>
#define LED_ALL (0xFF<<17)
void delay(int );
void blink_led(int );
int keyFlag = 1;
int main()
{
	IODIR1 = IODIR1 | LED_ALL ;  // O/P
	IODIR1 = IODIR1 & ~(1<<25);  //p1.25 as i/p.

	while(1)
	{
		if(IOPIN1 & (1<<25))
		{
			if(keyFlag)
			{	
				IOSET1 = 0x0F<<17;
				keyFlag = 0;
			}
			else
			{
				IOCLR1 = 0x0F<<17;
				keyFlag = 1;
			}
			delay(500);
		}		
	}
}

void blink_led(int led)
{
		IOSET1 = 1<<led;  // High
		delay(100);
		IOCLR1 = 1<<led;   // Low
		delay(100);
}

void delay(int ct)
{
	int i,j;
	for(i=0;i<ct;++i)
	{
		for(j=0;j<6000;++j)
		{}
	}
}

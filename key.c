// Led pins --> p1.17 to p1.24/p0.8 // o/p pins --> 1
//button/switch --> p1.25  // i/p pins ---> 0
#include<lpc21xx.h>
#define LED_ALL (0xFF<<17)
void delay(int );
void blink_led(int );

int main()
{
	IODIR1 = IODIR1 | LED_ALL ;  // O/P
	IODIR1 = IODIR1 & ~(1<<25);  //p1.25 as i/p.
//	IODIR1 &= ~((1<<25)|(1<<26));
//	
//	[28 27 26 25]
//	IODIR1 = IODIR1 & ~(0x0F<<25);
	while(1)
	{
		if(IOPIN1 & (1<<25))
		{
			IOSET1 = 0x0F<<17;
		}
		
	}
}
//loop()
// press button once --> high --> LED ON
// press button next --> low --> LED OFF
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

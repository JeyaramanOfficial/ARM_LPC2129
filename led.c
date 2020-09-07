//  LED Blinking ---> P1.17

#include<lpc21xx.h>

void delay(int);

int main()
{
	IODIR1 = 1<<17;  // setup p1.17 as o/p
	while(1)
	{
		IOSET1 = 1<<17;  // High
		delay(100);
		IOCLR1 = 1<<17;   // Low
		delay(100);
	}
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

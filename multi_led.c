//  LED Blinking ---> P1.17 & p1.18
// p1.17 --> p1.20

#include<lpc21xx.h>

void delay(int);
/*
int main()
{
//	IODIR1 = 1<<17;  // setup p1.17 as o/p
//	IODIR1 = IODIR1 | (1<<18);  // setup p1.18 as o/p
	IODIR1 = IODIR1 | (1<<17) | (1<<18);     
//	IODIR1 |= (1<<17)|(1<<18); 
	while(1)
	{
//		IOSET1 = 1<<17;  // High
//		IOSET1 = 1<<18;  // High
//		IOSET1 = IOSET1 | (1<<17)|(1<<18);
		IOSET1 = (1<<17)|(1<<18);
		delay(1000);
//		IOCLR1 = 1<<17;   // Low
//		IOCLR1 = 1<<18;
		IOCLR1 = (1<<17)|(1<<18);
		delay(1000);
	}
}*/


int main()
{
	IODIR1 = IODIR1 | (1<<17)|(1<<18);
	while(1)
	{
		IOSET1 = (1<<17)|(1<<18);
		delay(1000);
		IOCLR1 = (1<<17)|(1<<18);
		delay(1000);
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

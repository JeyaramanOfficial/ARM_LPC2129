// buzzer p0.11
#include<lpc21xx.h>

void delay(int);

int main()
{
	IODIR0 = IODIR0| (1<<11);
	while(1)
	{
		IOSET0 = 1<<11;
		delay(1000);
		IOCLR0 = 1<<11;
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

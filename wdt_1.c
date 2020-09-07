// WDT - To reset the system
// no reset value for WDT.

//WDMOD --> MODE --> EN,RST
//WDTC --> Const timer value --> timer initial value
//WDTV --> MR of Timer --> 
//WDFEED --> 0xAA,0x55 --> generate clock pulse

#include<lpc21xx.h>

void delay(int );
void blink_led(int);

int main()
{
	IODIR1 |= 0xFF<<17;
	WDMOD = (1<<1) | (1<<0);   // Reset | Enable
	WDTC = 0xFFFFFF;		//Constant value | Initial value
	blink_led(24);
	WDFEED = 0xAA; 
	WDFEED = 0x55;
	while(1)
	{
		if(WDTV <= 0xF00000)
		{
				WDFEED = 0xAA;			//reset WDT | Start from Timer constant.
				WDFEED = 0x55;
		}
		blink_led(17);
	}
}

void delay(int ct)
{
	for(int i=0;i<ct;i++)
	{
		for(int j=0;j<6000;j++)
		{}
	}
}

void blink_led(int led)
{
		IOSET1 = 1<<led;
		delay(500);    // Program got stuck
		IOCLR1 = 1<<led;
		delay(500);
}

// External interrupt
//p0.14 ---> EXT1
#include<lpc21xx.h>
#define LED_ALL (0xFF<<17)

void delay_ms(int );
void blink_led(int );
void intr_config(void);
void ext_isr(void)__irq;
int main()
{
	IODIR1 |= LED_ALL;
	PINSEL0 = PINSEL0 | (1<<29); //p0.14	// 10 --> 29|28
	PINSEL0 = PINSEL0 & ~(1<<28);
	intr_config();
	while(1)
	{
			blink_led(17);
	}
}

void intr_config(void)
{
	VICIntSelect &= ~(1<<15);   //EXT1 
	VICVectCntl2 = (1<<5)|15;
	VICVectAddr2 = (long)ext_isr;
	VICIntEnable = (1<<15);
	
	EXTMODE = 1<<1;  //p0.14//ISP --> EXT1 --> Edge Triggered
	//EXTPOLAR &= ~(1<<1); //falling edge
	EXTPOLAR = (1<<1); //rising edge
	
}

void ext_isr(void)__irq
{
	blink_led(24);
	EXTINT = 1<<1; //clear the intr flag bit.
	VICVectAddr = 0x00000000;
}

void blink_led(int led)
{
		IOSET1 = 1<<led;  // High
		delay_ms(100);
		IOCLR1 = 1<<led;   // Low
		delay_ms(100);
}

void delay_ms(int ct)
{
	int i,j;
	for(i=0;i<ct;++i)
	{
		for(j=0;j<6000;++j)
		{}
	}
}

/* EINT1 and EINT3 -->
   timer0 and timer1 */


/* Display Name upon interrupt */

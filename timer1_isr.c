// Timer0 as VIC
// timer0 ----> bit 4
// timer0 as IRQ

#include<lpc21xx.h>
#define LED_ALL (0xFF<<17)

void delay_ms(int );
void blink_led(int );
void timer1_isr(void)__irq;
void timer_config(void);
void intr_config(void);
//__irq void timer0_isr(void);
int main()
{
		IODIR1 = IODIR1| LED_ALL;
		timer_config();
		intr_config();
		while(1)
		{
			blink_led(17);
		}
}

void timer_config(void)
{
	/* Timer1  config   */
		T1PR = 14;
		T1MR0 = 2000000;
		T1MCR = (1<<0)|(1<<1);
		T1TCR = (1<<0);
}

void intr_config(void)
{
	/* Interrupt Config */
		VICIntSelect = VICIntSelect & ~((1<<4)|(1<<5)); //Timer 1 as IRQ	
		VICVectCntl1 = (1<<5)|5;   //ENABLE slot1 | timer1
		VICVectAddr1 = (long)&timer1_isr;		
		VICIntEnable = (1<<4)|(1<<5);   // Enable timer0
}
void timer1_isr(void)__irq
{
	IOSET1 = 1<<24;  // High
	delay_ms(100);
	IOCLR1 = 1<<24;   // Low
	delay_ms(100);
	T1IR = 1<<0;			//Flag bit clear
	VICVectAddr = 0x00000000;  //Address Reset
	
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

/* timer1 ISR */
/* configure both timer0 and timer1 as ISR */
/* configure timer0 as polling and timer1 as ISR */


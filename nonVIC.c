/* EINT1 and EINT3 -->
   timer0 and timer1 */


// Timer0 as VIC
// timer0 ----> bit 4
// timer0 as IRQ

#include<lpc21xx.h>
#define LED_ALL (0xFF<<17)

void delay_ms(int );
void blink_led(int );
void nonvic_isr(void)__irq;
void timer_config(void);
void intr_config(void);

//__irq void timer0_isr(void);
int main()
{
		IODIR1 = IODIR1| LED_ALL;
		PINSEL0 = PINSEL0 | (1<<29); //p0.14	// 10 --> 29|28
		PINSEL0 = PINSEL0 & ~(1<<28);
		timer_config();
		intr_config();
		while(1)
		{
			blink_led(17);
		}
}

void timer_config(void)
{
	/* Timer0 config   */
		T0PR = 14;
		T0MR0 = 3000000;
		T0MCR = (1<<0)|(1<<1);
		
	/* Timer1  config   */
		T1PR = 14;
		T1MR0 = 3500000;
		T1MCR = (1<<0)|(1<<1);
		T1TCR = (1<<0);
	
		T0TCR = (1<<0);
}

void intr_config(void)
{
	/* Interrupt Config */
		VICIntSelect = VICIntSelect & ~((1<<4)|(1<<5)|(1<<15)); //Timer0/1 and EXT1 as IRQ
	
		VICDefVectAddr = (long)nonvic_isr;
	
		VICIntEnable = (1<<5)|(1<<4)|(1<<15);   // Enable timer0
		
		EXTMODE = 1<<1; //edge triggered
		EXTPOLAR = 1<<1;	//rising edge
}

void nonvic_isr(void)__irq
{
	blink_led(24);
	T0IR = 1<<0;
	T1IR = 1<<0;
	EXTINT = 1<<1;
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

/* timer1 ISR */
/* configure both timer0 and timer1 as ISR */
/* configure timer0 as polling and timer1 as ISR */


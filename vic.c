// Timer0 as VIC
// timer0 ----> bit 4
// timer0 as IRQ

#include<lpc21xx.h>
#define LED_ALL (0xFF<<17)

void delay_ms(int );
void blink_led(int );
void timer0_isr(void)__irq;
//__irq void timer0_isr(void);
int main()
{
		IODIR1 = IODIR1| LED_ALL;
		/* Timer config   */
		T0PR = 14;
		T0MR0 = 2000000;
		T0MCR = (1<<0)|(1<<1);
		T0TCR = (1<<0);
		/* Interrupt Config */
		VICIntSelect = VICIntSelect & ~(1<<4); //Timer 0 as IRQ	
//		VICVectCntl1 = (1<<5)|4<<0; //[4 3 2 1 0] ---> [0 0 1 0 0]-> 4
//		VICVectCntl1 = (1<<5)|1<<2; //[4 3 2 1 0] ---> [0 0 1 0 0]	
		VICVectCntl1 = (1<<5)|4;   //ENABLE slot1 | timer0
		VICVectAddr1 = (long)&timer0_isr;		
		VICIntEnable = (1<<4);   // Enable timer0
		while(1)
		{
			blink_led(17);
		}
}

void timer0_isr(void)__irq
{
	IOSET1 = 1<<24;  // High
	delay_ms(100);
	IOCLR1 = 1<<24;   // Low
	delay_ms(100);
	T0IR = 1<<0;			//Flag bit clear
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


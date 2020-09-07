// Led blink for 1 sec
// timer0 --> MR0 ---> 1sec

#include<LPC21xx.h>
#define LED_ALL (0xFF<<17)

void blink_led(int);
void delay(int);

int main()
{
	IODIR1 = IODIR1 | LED_ALL ;  // O/P
	T0PR = 14;
	T0MR0 = 1000000;
	T0MR1 = 2000000;
	T0MCR = (1<<0)|(1<<3)|(1<<4); 	//[2 1 0]				//Inter --> 0 and reset --> 1
	T0TCR = (1<<1);		//Reset
	T0TCR = (1<<0);  //enable 
	while(1)
	{
		if(T0IR & (1<<0))  //[3 2 1 0] --> 0th bit --> MR0
		{
			IOSET1 = 1<<17;
			T0IR = (1<<0); //flag bit reset to 0//MR0 //IOCLR
		}
		else if(T0IR & (1<<1))  //[3 2 1 0] --> 0th bit --> MR0
		{
			IOCLR1 = 1<<17;
			T0IR = (1<<1); //flag bit reset to 0 //MR1
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

// Assign 1

// blink 17 continuously
// blink 24 for 3 sec

// Assign 2
//Turn on LSB 4 led ---> for 2 sec
//Turn off LSB 4 led ---> for 2 sec
//Turn on MSB 4 led -->1 sec
//Turn off MSB 4 led -->1 sec
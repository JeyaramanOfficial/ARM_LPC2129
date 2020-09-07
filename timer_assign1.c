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
	T0MR0 = 3000000;
	T0MCR = (1<<0)|(1<<1); 	//[2 1 0]				//Inter --> 0 and reset --> 1
	T0TCR = (1<<1);		//Reset
	T0TCR = (1<<0);  //enable 
	while(1)
	{
		blink_led(17);
//		if(T0IR & (1<<0))  //[3 2 1 0] --> 0th bit --> MR0
		while(!(T0IR & (1<<0))) //--> polling statement
		{}
				
			blink_led(24);
			T0IR = (1<<0); 

		blink_led(18);
		blink_led(19);
		blink_led(20);
		blink_led(21);

		
		//reset to 0 //IOCLR
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

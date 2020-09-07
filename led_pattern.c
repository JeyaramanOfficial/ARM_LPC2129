/* Assign 1 */
//0000 0001
//0000 0011
//0000 0111
//0000 1111
//0001 1111
//0011 1111
//0111 1111
//1111 1111

/* Assign 3 */
//0000 0001
//0000 0010
//0000 0011
//0000 0100
//0000 0101
//0000 0110
//....
//1111 1111

/*Assign 4*/
// p0.11 ---> o/p


#include<lpc21xx.h>
#define LED_ALL (0xff<<17)
#define LED1	(1<<17)			//pin1.17
#define LED2	(1<<18)			//pin1.18
void delay(int);

int main()
{
	IODIR1 = IODIR1 | LED_ALL;
	
	while(1)
	{
		for(int i=17; i<= 24;i++)
		{
		IOSET1 = 1<<i;
		delay(1000);
		}
		IOCLR1 = LED_ALL;
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

// Blinking 4 leds p1.17 to p1.20

// 1111 ---> [20 19 18 17]
// 0x0F ---> 17

// Blinking 8 leds p1.17 to p1.24
// 1111 1111 ---> [24 23 22 21 20 19 18 17]
// 0001 0000  ---> [24 23 22 21 20 19 18 17]
// 1010 0000  ---> [24 23 22 21 20 19 18 17]   
// 0xFF ---> 17

//0000 0001  ==  1<<17
//0000 0010  ==  1<<18
//0000 0100  ==  1<<19
//0000 1000  ==  1<<20

//0001 0000  ==  1<<21
//0010 0000  ==  1<<22
//0100 0000  ==  1<<23
//1000 0000  ==  1<<24

/* Assign 1 */
//0000 0001
//0000 0011
//0000 0111
//0000 1111
//0001 1111
//0011 1111
//0111 1111
//1111 1111

/* Assign 2 */
//1111 1111
//1110 0111
//1100 0011
//1000 0001

//1000 0001
//1100 0011
//1110 0111
//1111 1111

#include<lpc21xx.h>

void delay(int);

int main()
{
//	IODIR1 = IODIR1 | (1<<17) |(1<<24) |(1<<30) | (1<<20);
	IODIR1 = IODIR1 | (0xFF << 17);   // ALL 8 bits(p1.17 to p1.24) as o/p

	while(1)
	{
		for(int i=17;i<=24;++i)
		{
			IOSET1 = (1<<i);
			delay(100);
			IOCLR1 = (1<<i);
			delay(100);
		}
		
		for(int i=24;i>=17;--i)
		{
			IOSET1 = (1<<i);
			delay(100);
			IOCLR1 = (1<<i);
			delay(100);
		}
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
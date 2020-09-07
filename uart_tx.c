#include<lpc21xx.h>

int main()
{
	char var;
	PINSEL0 |= (1<<0)|(1<<2); 	//[3 2 1 0] ---> [0 1 0 1]
	PINSEL0 &= ~((1<<1)|(1<<3));
	
	U0LCR = (1<<7);		// enable DLAB
	U0DLL = 97;				//9600 Baud rate
	U0DLM = 0;
	U0LCR &= ~(1<<7);	//disable to access THR and RBR
	U0LCR = (1<<0)|(1<<1); //word length as 8 bit data.
	
	while(1)
	{
		while(!(U0LSR &(1<<5)));	//check THR is empty
			U0THR = var;			//MC to PC
	}
}

#include "..\lcd_header.h"

int main()
{
	char var;
	PINSEL0 |= (1<<0)|(1<<2); 	//[3 2 1 0] ---> [0 1 0 1]
	PINSEL0 &= ~((1<<1)|(1<<3));
	lcd_config();
	U0LCR = (1<<7);		// enable DLAB
	U0DLL = 97;				//9600 Baud rate
	U0DLM = 0;
	U0LCR &= ~(1<<7);	//disable to access THR and RBR
	U0LCR = (1<<0)|(1<<1); //word length as 8 bit data.
	
	while(1)
	{
		while(!(U0LSR & (1<<0)));   // LSR --> Line Status Register.
			var = U0RBR;			//PC to MC
			lcd_data(var);
	}
}

/* receive string store to var adn display in LCD */

// Assign 1

// PC to MC transmit char 'A' 
// MC to PC transmit char 1

// PC to MC transmit char 'B' 
// MC to PC transmit char 0

//Assign 2
/*var compare with existing */

//char pass[8] = "Password";

//if matched send string from MC to PC as "Matched"
//if not matched send string from MC to PC as "Not Matched"

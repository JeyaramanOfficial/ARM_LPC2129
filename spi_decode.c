//SPI LPC2129 as MAster//P0.4 - SCK ,p0.5 - MISO ,p0.6 - MOSI ,p0.7 -> SS

#include<lpc21xx.h>

void spi_data(int);

int main()
{
	PINSEL0 |= (1<<8)|(1<<10)|(1<<12); 	//SCK,MISO,MOSI
	PINSEL0 &= ~((1<<9)|(1<<11)|(1<<13));
	IODIR0 |= (1<<7);		//SS line
	
	S0SPCR = (1<<2)|(1<<3)|(1<<4)|(1<<5);		//bit EN | CPOL | CPHA | MASTER
	S0SPCCR = 8; 		//1.9 Mbps	
	spi_data(0x0C01);				//0x0c address  | 01 data	--> power on
	spi_data(0x0900);				//0x09 address  | 00 data  --> mode select --> No-decode mode
	spi_data(0x0A00);				//0x0A address | FF data	-->	intensity
	spi_data(0x0B03);				//0x0B address | 03 Data	--> scan limit
	
	spi_data(0x0177);		//A
	spi_data(0x021F);		//b
	spi_data(0x034E);		//C
	spi_data(0x043D);		//d
}

void spi_data(int data)
{
	IOCLR0	=	(1<<7);			//0 to SS
	S0SPDR = data;				// 16 bit data --> MSB 8-bit| LSB 8bit  ---> ADDRESS|DATA
	while(!(S0SPSR & (1<<7)));
	IOSET0 = (1<<7);			//1 to SS
}


// MAster Transmitter  mode
// I2c SDA --> p0.2 , SCL ---> p0.3

#include "../lcd_header.h"

void i2c_config(void);
void i2c_start(void);
void i2c_data(char );
char i2c_recv(void);
void i2c_stop(void);


int main()
{
	char data;
	lcd_config();
	i2c_config();
	/* Master Receiver mode */
	// | S | 0xA0 | 0 | 0x00 | 0 | RS | 0xA1 | 0 | B1 | 0 | ......  |Bn | 0 | stop |
	I2CONSET = 1<<2;		//Assert Acknowledge
	
	i2c_start();
	i2c_data(0xA0);
	i2c_data(0x00);			//change pointer address
	
	i2c_start();
	i2c_data(0xA1);			//read 
	data = i2c_recv();
	lcd_data(data);
	data = i2c_recv();
	lcd_data(data);
	data = i2c_recv();
	lcd_data(data);
	i2c_stop();
	
}

void i2c_config(void)
{
	PINSEL0 |= (1<<4)|(1<<6);			//p0.2,p0.3 as SDA and SCL
	PINSEL0 &= ~((1<<5)|(1<<7));
	
	I2CONSET	= 1<<6;		//Master mode
	I2SCLH = 75;				// 100 Kbps as bit freq.
	I2SCLL = 75;
}

void i2c_start(void)
{
	I2CONCLR = 1<<3;
	I2CONSET = 1<<5;		//start bit
	while(!(I2CONSET & (1<<3)));	//flag bit 
	I2CONCLR = 1<<3;		//Clear flag bit
	I2CONCLR = 1<<5;		//release Start bit
}

void i2c_data(char data)
{
	I2DAT = data;			//transmit byte
	while(!(I2CONSET & (1<<3)));	//flag bit 
	I2CONCLR = 1<<3;
}

char i2c_recv(void)
{
	char recv;
	while(!(I2CONSET & (1<<3)));	//flag bit 
	I2CONCLR = 1<<3;
	recv = I2DAT;
	return recv;
}

void i2c_stop(void)
{
	I2CONSET = 1<<4;	//Stop bit
}




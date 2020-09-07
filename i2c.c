// MAster Transmitter  mode
// I2c SDA --> p0.2 , SCL ---> p0.3

#include "../lcd_header.h"

void i2c_config(void);
void i2c_start(void);
void i2c_data(char );
void i2c_stop(void);


int main()
{
	lcd_config();
	i2c_config();
	/* Master Transmitter mode */
	// | S | 0xA0 | 0 | 0x00 | 0 | 'A' | 0 | 'B' | 0 | 'C' | 0 | Stop |
	i2c_start();
	i2c_data(0xA0);		//Slave Address ---> write
	i2c_data(0x00);		//Memory Address --> Page0 , 0th pos.
	i2c_data('D');
	i2c_data('E');
	i2c_data('F');
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
	I2DAT = data;
	while(!(I2CONSET & (1<<3)));	//flag bit 
	I2CONCLR = 1<<3;
}

void i2c_stop(void)
{
	I2CONSET = 1<<4;	//Stop bit
}




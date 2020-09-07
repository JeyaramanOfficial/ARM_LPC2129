#include "lcd_header.h"

void lcd_config(void)
{
	IODIR0 = IODIR0 | RS | RW | EN | DATA; //Pin Configuration
	// lcd configuration
	lcd_cmd(0x38);	// 2rows and 8 bit data(0x38)
	lcd_cmd(0x0E);	// turn on backlight and cursor on(0x0E)
	lcd_cmd(0x01);	// clear all data(0x01)
	lcd_cmd(0x80); 	// position to display(defaults to beginning)(0x80)
}

void lcd_cmd(char c)
{
	//0x38 ---> LCD --> datapins
	// 0011 1000 --> [22 21 20 19 18 17 16 15]
	//								[ 0 0 0 0 0 0 0 0 0]
	IOCLR0 = DATA;    
	IOSET0 = c<<15;
	IOCLR0 = RW;	//write --> RW -->0
	IOCLR0 = RS;	//register select RS--> 0
	IOSET0 = EN;
	delay(100);
	IOCLR0 = EN;	//ENable (1 --> 0)
}

void lcd_data(char d)
{
	IOCLR0 = DATA;
	IOSET0 = d <<15;
	IOCLR0 = RW;
	IOSET0 = RS;
	IOSET0 = EN;
	delay(100);
	IOCLR0 = EN;
}

void lcd_str(char str[])
{
	for(int i=0;str[i]!='\0';i++)
	{
		lcd_data(str[i]);
	}
//		while(*str)
//		{
//			lcd_data(*str++);
//			
//		}
}

void lcd_num(int num)
{
	if(num)
	{
		lcd_num(num/10);
		lcd_data(num%10 + 0x30);
	}
}

void delay(int ct)
{
	for(int i =0 ;i<ct; i++)
	{
		for(int j=0;j<6000;++j)
		{
		}
	}
}

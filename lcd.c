/*
1. configure LCD --> Config()
2. Cmd() function
3. data() function
4. main() function
*/
/* p0.10 --> RS
p0.12 --> RW 
p0.13 -->EN

p0.15 - p0.22 --> data_pins --> 0xFF<<15
*/
#include<lpc21xx.h>

#define RS (1<<10)
#define RW (1<<12)
#define EN (1<<13)
#define DATA (0xFF<<15)

void delay(int);
void lcd_config(void);
void lcd_cmd(char );
void lcd_data(char );
void lcd_str(char []);
void lcd_num(int );

int main()
{
//	char name[] = "CRANES Varsity Bangalore Karanataka-560001 India";
	int num = 12345678;
//	char number[] = "123456";
	lcd_config();
	
	lcd_num(num);
//	lcd_data(num + 48);   //5
//	lcd_data(num + 0x30); //5
//	lcd_data(num + '0');  //5
// 0 ---> decimal 48
// 0 ---> hexdec 0x30
// 0 ---> '0'
	
	
// first row 16 char remaing 24 char will be in buffer

//0x80 --> 8 --> first row 0 --> pos
//0xC0 ---> C --> second row	0 --> pos
//0x18 --> left shift 
//0x1C --> right shift
	

//	while(1)
//	{
//		lcd_cmd(0x1C);
//		lcd_str(name);
//	}
}

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

















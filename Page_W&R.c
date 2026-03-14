#include<LPC21XX.H>
#include<string.h>
typedef unsigned char u8;
#include "I2C_header.h"
#include "EEPROM_header.h"
#define SA 0x50
#define LEDR 1<<16
#define LEDG 1<<17

int main()
{
	u8 s[10];
	IODIR0|= LEDR|LEDG;
	I2C_INIT();
	i2c_eeprom_page_write(SA,0x00,"AKHILESH",8);
	i2c_eeprom_seq_read(SA,0x00,s,8);
	s[8] = '\0';
	delay_seconds(1);
	IOCLR0|=LEDG|LEDR;
	if(strcmp("AKHILESH",(const char*)s)==0)
	{
		IOSET0 = LEDG;
	}
	else
	{
		IOSET0 = LEDR;
	}
}

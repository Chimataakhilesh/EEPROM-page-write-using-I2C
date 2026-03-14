#include <LPC21xx.h>
#include "delay_header.h"
void i2c_eeprom_write(u8,u8,u8);
u8   i2c_eeprom_read(u8,u8);
void i2c_eeprom_page_write(u8 slaveAddr,u8 wBuffStartAddr,u8 *p,u8 nBytes);
void i2c_eeprom_seq_read(u8 slaveAddr,u8 rBuffStartAddr,u8 *p,u8 nBytes);

void i2c_eeprom_write(u8 slaveAddr,u8 wBuffAddr,u8 dat)
{
  I2C_Start();	
  I2C_Write(slaveAddr<<1); //slaveAddr + w
	I2C_Write(wBuffAddr);    //wBuffAddr
	I2C_Write(dat);    //wBuffAddr
	I2C_Stop();
	delay_ms(10);
}			 

u8 i2c_eeprom_read(u8 slaveAddr,u8 rBuffAddr) 
{
	u8 dat;
	I2C_Start();	
  I2C_Write(slaveAddr<<1); //slaveAddr + w
	I2C_Write(rBuffAddr);    //rBuffAddr
	I2C_Restart();	
	I2C_Write(slaveAddr<<1|1); //slaveAddr + r  
  dat=I2C_Nack();	
	I2C_Stop();
	return dat;
}

void i2c_eeprom_page_write(u8 slaveAddr,u8 wBuffStartAddr,
u8 *p,u8 nBytes)
{
  u8 i;
  I2C_Start();	
  I2C_Write(slaveAddr<<1);    //slaveAddr + w
	I2C_Write(wBuffStartAddr);  //wBuffStartAddr
	for(i=0;i<nBytes;i++)
	{
	   I2C_Write(p[i]);             //wBuffAddr
	}
	I2C_Stop();
	delay_ms(10);
}			 

void i2c_eeprom_seq_read(u8 slaveAddr,u8 rBuffStartAddr,u8 *p,
u8 nBytes)
{
	u8 i;
	I2C_Start();	
  I2C_Write(slaveAddr<<1); //slaveAddr + w
	I2C_Write(rBuffStartAddr);    //rBuffAddr
	I2C_Restart();	
	I2C_Write(slaveAddr<<1|1); //slaveAddr + r
	for(i=0;i<nBytes-1;i++)
	{
    p[i]=I2C_Masterack();	
	}
	p[i]=I2C_Nack();
	I2C_Stop();
}

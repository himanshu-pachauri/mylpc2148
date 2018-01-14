#include<lpc21xx.h>
void main()
{
unsigned int i;
IODIR1=0XFFFFFFFF;
IOCLR1=0xFFFFFFFF;
PINSEL0=0x50;
I2SCLH=0XFF;
I2SCLL=0XFF;
I2CONCLR=0X74;
I2CONSET=0X00000044;   //interface enable,interrupt flag
I2CONSET=0X00000064;   //+ start

while(!(I2CONSET&0x08));	  //chk the si bit value
I2DAT=0X40;                   //0-write,5-add of slave
I2CONCLR=0X28;				  

while(!(I2CONSET&0x08));
I2DAT=0xAA;
I2CONCLR=0X08;
while(I2STAT!=0X28);		 //status code of i2c interface
}

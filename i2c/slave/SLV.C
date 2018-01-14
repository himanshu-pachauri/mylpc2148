#include<lpc21xx.h>
void main()
{
unsigned int i;
I2ADR=0X61;				 //address of slave
IODIR1=0XFFFFFFFF;
PINSEL0=0x50;			 //x50 set in table(p-127)for i2sclr&i2scll
I2CONCLR=0X7C;
I2CONSET=0X44;

while(I2STAT!=0X60);
I2CONCLR=0x08;
while(I2STAT!=0X80);
IOSET1=(I2DAT<<16);
}

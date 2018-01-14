#include<lpc21xx.h>
void main()
{
unsigned int i;
I2ADR=0X50;				 //address of slave
IODIR1=0XFFFFFFFF;
IOCLR1=0XFFFFFFFF;
PINSEL0=0x50;			 //x50 set in table(p-127)for i2sclr&i2scll
I2CONSET=0X44;
while(I2STAT!=0xA8);
I2DAT=0xaa;
I2CONCLR=0x08;
while(I2STAT!=0Xc0);
IOSET1=I2DAT<<16;
}
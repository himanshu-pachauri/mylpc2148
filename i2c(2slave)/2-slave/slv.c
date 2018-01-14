#include<lpc21xx.h>
void main()
{
unsigned int i;
I2ADR=0X50;				 //address of slave
IODIR1=0XFFFFFFFF;
IOCLR1=0XFFFFFFFF;
PINSEL0=0x50;			 //x50 set in table(p-127)for i2sclr&i2scll
I2CONCLR=0X7C;
I2CONSET=0X44;
while(I2STAT!=0X60);
I2CONCLR=0x08;
while(I2STAT!=0X80);
IOSET1=0xFFFFFF;
IOCLR1=0xFFFFFFFF;
i=I2DAT;
IOSET1=(i<<16);
}
#include<lpc21xx.h>
void main()                      
{
unsigned int i;
IODIR0  = 0XFFFF0020;
IODIR1  = 0X00000000;
PINSEL0 = 0X00005500;		         	             
S0SPCR  = 0X08;	
while(1)
{
S0SPDR=((IOPIN1&0X10000)==0X10000);		          	    
while((S0SPSR&0X80)!=0X80);	       	//spif=1(status resister)
IOCLR0=0XFFFF0000;
IOSET0=S0SPDR<<16;
}
}

#include<lpc21xx.h>
void main()                      
{
unsigned int i;
IODIR0  = 0X00000020;
IODIR1  = 0XFFFFFFFF;
PINSEL0 = 0X00005500;		         	             
S0SPCR  = 0X08;	
S0SPDR=0xAA;		          	    
while((S0SPSR&0X80)!=0X80);	       	//spif=1(status resister)
IOSET1=S0SPDR<<16;
}

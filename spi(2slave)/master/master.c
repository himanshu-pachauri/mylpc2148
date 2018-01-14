#include<lpc21xx.h>
void main()                      
{
unsigned int x;
IODIR0  = 0XFFFF0050;
IODIR1  = 0xFFFFFFFF;
PINSEL0 = 0X00005500;
S0SPCCR = 0X08;	              //clk
S0SPCR  = 0X28;				   //Control Register
while(1)
{
S0SPDR  = (~x);  		       //data resister   
while((S0SPSR&0X80)!=0X80);	 //spif=1(status resister)
IOCLR0=0XFFFF0000;
x=S0SPDR;
IOSET0=x<<16;
if(x!=1)
{
IOSET1=1<<16;
IOCLR1=1<<17;
}
else if (x==1)
{ 
IOSET1=1<<17;
IOCLR1=1<<16 ;
}                      
}
}
#include<lpc21xx.h>
void main()                      
{
unsigned int x;
IODIR0  = 0X00000050;
IODIR1  = 0xFFFFFFFF;
PINSEL0 = 0X00005500;
S0SPCCR = 0X08;	              //clk
S0SPCR  = 0X28;				   //Control Register
for(x=0;x<65000;x++);
S0SPDR  = 0xF0;   		       //data resister   
while((S0SPSR&0X80)!=0X80);	 //spif=1(status resister)
IOSET1=S0SPDR<<16;                       
}
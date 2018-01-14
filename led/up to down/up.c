#include<lpc21xx.h>
void delay();		           // function declaration
void main()                      
{
while(1)			  //loop run infinite time (1,2)&(0) - not run
{
unsigned int x;
IODIR0=0XFFFFFFFF;	       //SET PORT 0 AS AN O/P & O/P resister value 0 at EACH PIN
for(x=0x00000001;x!=0;x = x<<1)		//? ,left shift 0001=1 next 00
{
IOSET0=x;	 //set port 0 resister value 1 ,f contain 4 bit (hexa decimal)f=1111(binary)(value=15 )
delay();
IOCLR0=0XFFFFFFFF;	   //reset port 0 resister value 0 ,f contain 4 bit (hexa decimal)f=1111(binary)(value=15 )
}
}
}
void delay()		   //create function for delay
{
unsigned int i;
for(i=0;i<=650000;i++);
}

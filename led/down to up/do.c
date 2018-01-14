#include<lpc21xx.h>
void delay();		    // function declaration
void main()
{
while(1)			  //loop run infinite time (1,2)&(0) - not run
{
unsigned int x,y;
IODIR0=0XFFFFFFFF;		            //SET PORT 0 ,1 AS AN O/P & O/P resister value 0 at EACH PIN
for(x=0x80000000;x!=0;x = x>>1)		//? ,left shift 0001=1 next 00
{					 
IOSET0=x;	 
delay(1);
IOCLR0= x<<1;

}
}
}
void delay()		   //create function for delay
{
unsigned int i;
for(i=0;i<=650000;i++);
}

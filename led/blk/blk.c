#include<lpc21xx.h>
#include"delay.h"
void delay();		           // function declaration
void main()                      
{

	while(1)			  //loop run infinite time (1,2)&(0) - not run
	{
		IODIR1=0XFFFFFFFF;	       //SET PORT 0 AS AN O/P & O/P resister value 0 at EACH PIN
		IOSET1=0XFFFFFFFF;	 //set port 0 resister value 1 ,f contain 4 bit (hexa decimal)f=1111(binary)(value=15 )
		delay();
		IOCLR1=0XFFFFFFFF;	   //reset port 0 resister value 0 ,f contain 4 bit (hexa decimal)f=1111(binary)(value=15 )
		delay();
	}
}

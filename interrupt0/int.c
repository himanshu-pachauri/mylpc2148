#include<lpc21xx.h>				   //pri define function
void delay()						   //create function for delay
{
     	unsigned int i;
       	for(i=0;i<95000;++i);
}
void led() __irq					  //interrupt function( __irq )-denote it is interrupt function 
{							
		IOSET1=0xFFFFFFFF;	 //set port 0 resister value 1 ,f contain 4 bit (hexa decimal)f=1111(binary)(value=15 )
	       EXTINT=0x02;
     }
void main()
  {
   IODIR1=0XFFFFFFFF;			 //SET PORT 0 AS AN O/P & O/P resister value 0 at EACH PIN
           	EXTINT=0X02;		   //external inperrupt flag resister&0x02-(page70)
             	PINSEL1=0X01;		       //(0x01)due to i/o in controller (p-128) & PINSEL1 give how we use pin 
	VICIntEnable=(0X01)<<14;		  //External Interrupt0(EINT0)i/0 use 14 & its indicate intpt on or off(p-100,t-45)
            VICVectCntl0=0X2E;		       //provide channel & 2 use its enabled & E=External Interrupt(p-103)
         VICVectAddr0=(unsigned)led;	//Address Registers 0-15 hold the addresses of intp function
   while(1)
     {			 
           
          
		delay();
            IOCLR1=0xFFFFFFF;
		 
		 }
		 }
             



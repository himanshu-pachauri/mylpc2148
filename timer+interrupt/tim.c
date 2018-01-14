#include<lpc21xx.h>
void led() __irq					  
{		
 	IOSET1=0xFFFFFFFF;
    IOCLR1=0xFFFFFFFF;
	T0TCR = 0x00;       
    T0PR  = 15;       
    T0MR0 = 1000000;
    T0IR  = 0xff;       
    T0MCR = 0x01;
	T0TCR = 0x01; 
    	
	    
     }
void main()
{
VPBDIV=0X00;
	T0TCR = 0x00;       
    T0PR  = 15;       
    T0MR0 = 1000000;
    T0IR  = 0xff;       
    T0MCR = 0x01;       
    


	VICIntEnable=((0X01)<<4); 
    VICVectCntl0=0X24;
	VICVectAddr0=(unsigned)led;
  	IODIR1=0XFFFFFFFF;
    IOSET1=0xFFFFFFFF;

	T0TCR = 0x01; 
	while(1)
	{
		
			
	   //IOSET1=0xFFFFFFFF;
	}
}

#include<lpc21xx.h>
volatile int x=0;
void led() __irq					  
{		
   T0TCR = 0x02;
		x++;
	if(x==1)
	   	IOCLR1=0xFFFFFFFF;
		else{
			IOSET1=0xFFFFFFFF;  
    		x=0;
			}
					T0TC=0;   
					
				T0TCR = 0x01; 
			  T0IR=0x01;
	    
     }
void main()
{
	unsigned int x;
	 VICIntEnable=((0X01)<<4); 
    VICVectCntl0=0X24;
	VICVectAddr0=(unsigned)led;
  	IODIR1=0XFFFFFFFF;
		   IOCLR1=0xFFFFFFFF;
	VPBDIV=0X02;
	T0TCR = 0x02;

	for(x=0x00000001;x!=0;x = x<<1)		    
{       
    T0PR  = x;       
    T0MR0 = 2500000;
    T0IR  = 0xff;       
    T0MCR = 0x01;       
    T0TCR = 0x01; 
	while(1)
	{
		
			
	   //IOSET1=0xFFFFFFFF;
	}
}  }

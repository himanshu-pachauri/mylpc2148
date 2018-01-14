#include<lpc21xx.h>
void main()                      
{
IODIR1=0XFFFFFFFF;
    	IODIR0=0X00000000;

	while(1)			 
	{
	    
	    	if((IOPIN0&0X00000001)==0X00000001)
		       IOSET1=0XFFFFFFFF;
		    if((IOPIN0&0X00000001)==0X00000000)	 
	        	IOCLR1=0XFFFFFFFF;	   
		
	}
	}
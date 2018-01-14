#include<lpc21xx.h>
#include"lcd.h"
unsigned char sq(unsigned char );
 void main()                      
  {
   unsigned char I,J,i;
        IODIR0 = 0XFFFFFFFF;
         init();
          while(1)			  
             {
	             	IOCLR0 = 0XFFFFFFFF;
	             	IOSET0 = 0X0000000F;
	       	while((IOPIN0&0X0000000F)==0X0000000F);
	             	I=IOPIN0;
	            	IOCLR0 = 0XFFFFFFFF;
	            	IOSET0 = 0X000000F0;
					J=IOPIN0;
	        while((IOPIN0&0X000000F0)!=0X000000F0);
				  		
					I=sq(0x0F&(~I));
					J=sq((~(J>>4))&0x0F);
					IOCLR1=0xFFFFFFFF;
					value(I+(4*J))	;
				
				
				
	}				  
  }
unsigned char sq(unsigned char x)
{
unsigned char n=0;
		 while(x>1)
		 {
		 x=x/2;
		 n++;
		 }
 return n;

}
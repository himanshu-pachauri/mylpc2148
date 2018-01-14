#include<lpc21xx.h>
#include"seg.h"
unsigned char sq(unsigned char );
 void main()                      
  {
   unsigned char I=0,J=0;
        IODIR0 = 0XFFFFFFFF;
          while(1)			  
             {
	             	IOCLR0 = 0XFFFFFFFF;
	             	IOSET0 = 0X0000000F;
	       	while((IOPIN0&0X0000000F)==0X0000000F)
					init(I+(4*J));

	             	I=IOPIN0;
	            	IOCLR0 = 0XFFFFFFFF;
	            	IOSET0 = 0X000000F0;
					J=IOPIN0;
	        while((IOPIN0&0X000000F0)!=0X000000F0);
				  		
					I=sq(0x0F&(~I));
					J=sq((~(J>>4))&0x0F);
					
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
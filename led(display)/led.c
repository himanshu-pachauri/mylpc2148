#include<lpc21xx.h>	
void sck();
void rck();
void delay(unsigned int ); 
void vl(unsigned char );       
void main()                      
    {

    IODIR1=0XFFFFFFFF;
    IODIR0=0XFFFFFFFF;
	IOSET1=0xFF<<16;
       while(1)			  
	     {
		 IOSET1=(0x41<<16);
	       vl(1);
		   sck();
		   rck();

		    vl(0);
		   sck();
		   rck();
		   IOSET1=(0xFF<<16);
		   delay(1150);
		   IOCLR1=(0xFF<<16);
		     delay(1150);

		   IOSET1=(0x41<<16);
		   sck();
		   rck();
		   delay(1150);
		   IOCLR1=(0xFF<<16);
			  delay(1150);
		    IOSET1=(0xFF<<16);
		   sck();
		   rck();
		   	 delay(1150);
           IOCLR1 = (0XFF<<16);

		    delay(1150);


			IOSET1=(0x41<<16);
		   sck();
		   rck();

		    delay(1150);
			IOCLR1 = (0XFF<<16);
			delay(1150);

		   
		   

		  


		  }
  }
void vl(unsigned char x)
    {
	IOCLR0|=0x01;
     IOSET0|=x;
  }
void sck()
    {

	 IOSET0=0x0100;
	 delay(100000);
	 IOCLR0=0x0100;
	 delay(100000);
  }

void rck()
	{
	 IOSET0=0x0200;
	 delay(100000);
	 IOCLR0=0x0200;
	 delay(100000);
  }
void delay(unsigned int x)
    {
	 unsigned int j ;
	     for(j=0;j<x;j++);
  }

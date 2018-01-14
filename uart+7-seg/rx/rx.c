#include<lpc21xx.h>
#include"seg.h"
void main()                      
{
        unsigned char i=0;
           PINSEL0=0X00040000;
           U1LCR=0X80;
           U1DLL=97;
           U1LCR=0X03;
                while(1)			  
                  {
		      while(!(U1LSR&0X01))
                                                 init(i);
	                             i=U1RBR;
               }
              }
											  
#include<lpc21xx.h>
void main()
{
      unsigned int j,i;
      unsigned char ar[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
           IODIR0=0XFFFFFFFF;
		   while(1)
		   {
		                 for(i=0;i<99;i++)
						 {
                         IOCLR0=0XFFFFFFFF;
                         IOSET0=(ar[i/10]);
                         IOSET0=0X00000080;
                         IOCLR0=0X00000100;
                             for(j=0;j<650000;j++);
                         IOCLR0=0XFFFFFFFF;
                         IOSET0=(ar[i%10]);
                         IOSET0=0X00000100;
                         IOCLR1=0X0000080;
                             for(j=0;j<650000;j++);
							 }
               
					 }}											  
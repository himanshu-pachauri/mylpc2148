#include<lpc21xx.h>
void init(unsigned char i)
{
      unsigned int j,b;
      unsigned char ar[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
           IODIR1=0XFFFFFFFF;
                         IOCLR1=0XFFFFFFFF;
                         IOSET1=((ar[i/10])<<16);
                         IOSET1=0X01000000;
                             for(j=0;j<25000;j++);
                         IOCLR1=0XFFFFFFFF;
                         IOSET1=((ar[i%10])<<16);
                         IOSET1=0X02000000;
                             for(j=0;j<25000;j++);
               
					 }											  
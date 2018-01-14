#include<lpc21xx.h>
void main()                      
{
unsigned int i;
IODIR1=0XFFFFFFFF;
PINSEL0=0X00040000;
U1LCR=0X80;
U1DLL=97;
U1LCR=0X03;
while(1)			  
{
while(!(U1LSR&0X01));
i=U1RBR;
IOCLR1=0XFFFFFFFF;
IOSET1=(i<<16);
}
}

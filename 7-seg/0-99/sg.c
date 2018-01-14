#include<lpc21xx.h>
void main()
{
unsigned int i,j;
unsigned char ar[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};	 
IODIR0=0XFFFFFFFF;
while(1)
{
for(i=0;i<=99;i++)
{
IOCLR0=0xFF;
IOSET0=ar[i%10];
IOCLR0=(0xFF)<<7;
IOSET0=(ar[i/10]<<7);
for(j=0;j<650000;j++);
}
}
}
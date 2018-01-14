#include<lpc21xx.h>
void main()                      
{
 unsigned int i,j;
PINSEL0=0X00010000;
U1LCR=0X80;
U1DLL=97;
U1LCR=0X03;

while(1)			  
{
U1FCR|=0X02;
for(i=0;i<=245;i++)
{
for(j=0;j<=905000;j++);
U1THR=i;
while(!(U1LSR&0X40));
}
}
}

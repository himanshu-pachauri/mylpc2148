#include<lpc21xx.h>
#include"lcd.h"
unsigned int a,i;		                 
void main()                      
{
ints();
while(1)
{
ADCR=0x01208101;                     //(p-239)sel-01,clk-11,burst-0,clk-00,pdn-1,test-00,start-001
while(!(ADDR&0x80000000));                  //done bit chk 
a=ADDR&0X0000FFC0;                      
a=(a>>6);                                   //we have 10bit for create msb we can shift			 
a=(a/3.1);
if(a<100)
{
sendstring("0.") ;
value(a);
sendstring("volt");
}
else
{
value(a);
sendstring("volt");
}
for(i=0;i<6500;i++);
cmd(0x01);
for(i=0;i<6500;i++);		
}
}
#include<lpc21xx.h>
#include"lcd.h"
void main()
{
unsigned int i,a,b,c;
init();
IODIR0=0xFFFFFFFF;
CCR= 0x01;
PCONP=0x200;
while(1)
{
PREINT    =  456;
PREFRAC   =  25024;
a=HOUR;
b=MIN;
c=SEC;
cmd(0x01);
for(i=0;i<6500;i++);
if(a<10)
{
sendstring("0");
}
value(a);
sendstring(":");
if(b<10)
{
sendstring("0");
}
value(b);
sendstring(":");
if(c<10)
{
sendstring("0");
}
value(c);
for(i=0;i<650000;i++);
}
}			
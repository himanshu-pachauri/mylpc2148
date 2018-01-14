ALSEC#include<lpc21xx.h>
#include"lcd.h"
void main()
{
unsigned int i,a,b,c,	d;
init();
for(i=0;i<65000;i++);
IODIR0=0xFFFFFFFF;
CCR= 0x01;
PCONP=0x200;
AMR - 0x00;
while(1)
{
PREINT    =  456;
PREFRAC   =  25024;
a=HOUR;
b=MIN;
c=SEC;
cmd(0x01);
for(i=0;i<6500;i++);
sendstring("clock=");
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
cmd(0xC0);
for(i=0;i<6500;i++);
sendstring("alarm=");
value(ALHOUR=00);
sendstring(":");
value(ALMIN=00);
sendstring(":");
value(ALSEC=1);
//sendstring(",o/p");
value(ILR);
if(c==ALSEC)
{
IOSET0=ILR;
}
if(c==ALSEC+1)
{
IOCLR0=0XFF;
}
for(i=0;i<650000;i++);
}}			
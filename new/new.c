#include<lpc21xx.h>
#include"lcd.h"
void send(unsigned char *x);
void main()
{ 
int i;
init();
for(i=0;i<6500;i++);
send("vijay");
}
void send(unsigned char *x)
{
int i;
cmd(0xC0);
while(*x!='\0')			// show null position
{
data(*x);
x++;
for(i=0;i<6500;i++);
}
}
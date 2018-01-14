#include<lpc21xx.h>
#include"lcd.h"	
unsigned int h,a=0;
void incr()
{
 		cmd(0X01);
		for(h=0;h<10000;++h);
	     a++;
		value(a);
		while((IOPIN1&0X00010000)==0);
}
void dcr()
{
		cmd(0X01);
		for(h=0;h<10000;++h);
		if(a==0)
		{
		value(a);
		}
		else if(a>0)
		{
	     a--;
		 
		 
		value(a);
		} 
		while((IOPIN1&0X00020000)==0);	
	    }             
void main()                      
{
init();
IODIR1=0X00000000;
value(a); 
while(1)
{
 if((IOPIN1&0X00010000)==0)
		{  
		   incr();
		}
		if((IOPIN1&0X00020000)==0)
		{
		dcr();
}	}
}





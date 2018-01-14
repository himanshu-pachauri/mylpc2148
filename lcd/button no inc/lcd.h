#include<lpc21xx.h>
void cmd(unsigned char);
void data(unsigned char);
void value(unsigned int x);
void delay();
unsigned int t,c,p,b;	
void init()                      
{
IODIR0=0XFFFFFFFF;			 
cmd(0x38);					 //we can take 8-bit,( 5x7 resolution)-per data lcd
cmd(0x0E);					  //display on ,curser off
cmd(0x06);					   //data coming curser right shift
cmd(0x01);						//clear screen
cmd(0x80);
}
void cmd(unsigned char x)
{
IOCLR0=0XFFFFFFFF;
IOSET0=x;
IOCLR0=0X00000100;	  //RS pin(resister select) = 0 (data select)
IOCLR0=0X00000200;		//rw pin(read and wright) =0 (wright)	// port0 set a value = 0	// take i/p from x  
IOSET0=0X00000400;	 //EN(ENABLE)=1(falling edge)
delay();			                              //}1 to 0 transfer data con to lcd (flip-flop condition) 
IOCLR0=0X00000400;	 //EN=0(rising edge)
}			  
void data(unsigned char x)
{
IOCLR0=0XFFFFFFFF;
IOSET0=x;
IOSET0=0X00000100;		  //rs = 1
IOCLR0=0X00000200;		   //rw=0
IOCLR0=0XFF;			   //port clear
IOSET0=x;					// set value of x at port
IOSET0=0X00000400;			 //en=1;
delay();
IOCLR0=0X00000400;			  //en=0;
}
void delay()
{
unsigned int j;																							
for(j=0;j<6500;j++);
}
void value(unsigned int a)
{	
	t=1;
	p=a;
	while(a>9)
	{
		t=t*10;
		a=a/10;
	}
	while(t>0)
	{
		data((p/t)+48);
		p=p%t;
		t=t/10;
	}
}



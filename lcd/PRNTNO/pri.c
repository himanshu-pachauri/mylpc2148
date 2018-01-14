#include<lpc21xx.h>
void cmd(unsigned char);
void data(unsigned char);
void value(unsigned int x);
void delay();
unsigned int t,c,p,a,b;		                 
void main()                      
{
while(1)
{
IODIR0 = 0XFFFFFFFF;
IODIR1 = 0XFFFFFFFF;			 
cmd(0x38);					 //we can take 8-bit,( 5x7 resolution)-per data lcd
cmd(0x0E);					  //display on ,curser off
cmd(0x06);					   //data coming curser right shift
cmd(0x01);						//clear screen
cmd(0x80);						 //coloum position
a=2;
value(a);
		}
}
void cmd(unsigned char x)
{
IOCLR0=0XFFFFFFFF;
IOSET0=x;
IOCLR1=0X00010000;	  //RS pin(resister select) = 0 (data select)
IOCLR1=0X00020000;		//rw pin(read and wright) =0 (wright)	// port0 set a value = 0	// take i/p from x  
IOSET1=0X00040000;	 //EN(ENABLE)=1(falling edge)
delay();			                              //}1 to 0 transfer data con to lcd (flip-flop condition) 
IOCLR1=0X00040000;	 //EN=0(rising edge)
}			  
void data(unsigned char x)
{
IOCLR0=0XFFFFFFFF;
IOSET0=x;
IOSET1=0X00010000;		  //rs = 1
IOCLR1=0X00020000;		   //rw=0
IOCLR0=0XFF;			   //port clear
IOSET0=x;					// set value of x at port
IOSET1=0X00040000;			 //en=1;
delay();
IOCLR1=0X00040000;			  //en=0;
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



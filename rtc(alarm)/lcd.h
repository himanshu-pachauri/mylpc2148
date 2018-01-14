#include<lpc21xx.h>
void cmd(unsigned char);
void data(unsigned char);
void value(unsigned int x);
void sendstring(unsigned char *x);
void delay();
unsigned int t,c,p,b;	
void init()                      
{
IODIR1=0XFFFFFFFF;			 
cmd(0x38);					 //we can take 8-bit,( 5x7 resolution)-per data lcd
cmd(0x0E);					  //display on ,curser off
cmd(0x06);					   //data coming curser right shift
cmd(0x01);						//clear screen

}
void cmd(unsigned char x)
{
IOCLR1=0XFFFFFFFF;
IOSET1=(x<<16);
IOCLR1=0X02000000;	  //RS pin(resister select) = 0 (data select)
IOCLR1=0X04000000;		//rw pin(read and wright) =0 (wright)	// port0 set a value = 0	// take i/p from x  
IOSET1=0X08000000;	 //EN(ENABLE)=1(falling edge)
delay();			                              //}1 to 0 transfer data con to lcd (flip-flop condition) 
IOCLR1=0X08000000;	 //EN=0(rising edge)
}			  
void data(unsigned char x)
{
IOCLR1=0XFFFFFFFF;
IOSET1=(x<<16);
IOSET1=0X02000000;		  //rs = 1
IOCLR1=0X04000000;		   //rw=0
IOCLR1=0XFF;			   //port clear
IOSET1=(x<<16);					// set value of x at port
IOSET1=0X08000000;			 //en=1;
delay();
IOCLR1=0X08000000;			  //en=0;
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
void sendstring(unsigned char *x)
{
while(*x!='\0')
{
data(*x);
x++;
delay();
}
}


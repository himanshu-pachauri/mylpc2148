#include<lpc21xx.h>
void cmd(unsigned char);
void data(unsigned char);
void sendstring(unsigned char *x);	   //*FOR ADDRESS OF DATA
void delay();		                 //function declaration
void main()
{
IODIR0 = 0XFFFFFFFF;
IODIR1 = 0XFFFFFFFF;			 
cmd(0x38);					 //we can take 8-bit,( 5x7 resolution)-per data lcd
cmd(0x0E);					  //display on ,curser off
cmd(0x66);					   //data coming curser right shift
cmd(0x61);						//clear screen
cmd(0x80);					//coloum position
sendstring("vijay");		 //0xc0-row position
while(1);
}
void cmd(unsigned char x)
{
IOCLR0=0XFFFFFFFF;
IOSET0=x;
IOCLR1=0X00010000;	  //RS pin(resister select) = 0 (data select)
IOCLR1=0X00020000;		//rw pin(read and wright) =0 (wright)	// port0 set a value = 0	// take i/p from x  
IOSET1=0X00040000;	 //EN(ENABLE)=1(falling edge)
delay();											 //}1 to 0 transfer data con to lcd (flip-flop condition) 
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
void sendstring(unsigned char *x)
{
while(*x!='\0')			// show null position
{
data(*x);
x++;
delay();
}
}
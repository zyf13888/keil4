//远程仓库
fix branch
 /*
#include<reg51.h>
#include<stdio.h>
void main()
{
	TI=1;
	while(1)
	{
	printf("hello China!\r\n");
	}
}
*/

//2.one led
 /*
#include<reg51.h>
sbit LED=P3^7;
void main()
{
	unsigned int i;
	while(1)
	{
		for(i=0;i<52000;i++)
		LED=~LED;
	}
}
*/

//3.eight led
/*
#include<reg51.h>												  
void delay()
{
	unsigned char i;
	for(i=0;i<50000;i++);
}
void main()
{
	unsigned int i;
	while(1)
	{
		for(i=0;i<8;i++)
		{
			P0=0x01<<i;
			delay();
		}
	}
}
*/

//4.TIMER
/*
#include<reg51.h>
sbit POUT=P1^0;
void main()
{
			TMOD=0x01;
			TH0=0xfc;
			TL0=0x18;
			TR0=1;
			while(1)
			{
				if(TF0==1)
				{
					TF0=0;
					TH0=0xfc;
					TL0=0x18;
					POUT=~POUT;
				}
			}
}
*/

//5.INTERRUPT
/*
#include<reg51.h>
sbit POUT=P1^0;
void main()
{
	TMOD=0x01;
	TH0=0xfc;
	TL0=0x18;
	TR0=1;
	EA=1;
	ET0=1;
	while(1);
}

void time0() interrupt 1
{
  	TH0=0xfc;				   
	TL0=0x18;
	POUT=~POUT;
}
*/

//6.单片机的串口发送
/*
#include<reg51.h>
#include<stdio.h>
unsigned char MESSAGE[]="My first serial data!\n" ;
unsigned char a;
void delay(unsigned int i)
{
	unsigned int j;
	for(i;i>0;i--)
		for(j=200;j>0;j--);
}     
void main()
{
	SCON=0x50;
	TMOD|=0x20;
	TH1=0xf4;
	TL1=0xf4;
	TR1=1;
	while(1)
	{
		a=0;
		while(MESSAGE[a]!='\0')
		{
			SBUF=MESSAGE[a];
			while(!TI);
			TI=0;
			a++;		
		}
		delay(1000);
	}
}
*/

//7.单片机的串口收发
/*
#include<reg51.h>
#define uchar unsigned char;
uchar a,flag;
void main()
{
	SCON=0x50;
	TMOD=0x20;
	TH1=0xf4;
	TL1=0xf4;
	TR1=1;
	EA=1;
	ES=1;
	while(1)
	{
		if(flag==1)
		{
			ES=0;
			flag=0;
			SBUF=a;
			while(!TI);
 			TI=0;
			ES=1;		
		}
	}
}

void serial() interrupt 4
{
	a=SBUF;
	flag=1;
	RI=0;
}
*/
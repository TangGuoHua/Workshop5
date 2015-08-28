/***************************************************************************
【版权声明】
Copyright(C) All Rights Reserved by Changhao Huang (HuangChangHao@gmail.com)
版权所有者：黄长浩 HuangChangHao@gmail.com

未经作者书面授权，不可以将本程序此程序用于任何商业目的。
用于学习与参考目的，请在引用处注明版权和作者信息。
****************************************************************************/

//STC11F04E 1T , 4MHz晶振

#include <reg52.h>
#include "nrf24L01Node.h"

sbit LED = P3^7;

sfr AUXR = 0x8E;


void initINT0(void)
{
	EA=1;
	EX0=1; // Enable int0 interrupt.
}


//NRF24L01开始进入接收模式
void startRecv()
{
	unsigned char myAddr[5]= {53, 69, 149, 231, 1}; //本节点的接收地址
	nrfSetRxMode( 96, 5, myAddr);
}


void main()
{

	AUXR = AUXR|0x80;  // T0, 1T Mode
	
	//
	LED = 1;
	
	//初始化INT0 
	initINT0();

	//初始化24L01
	nrf24L01Init();
	
	//进入接受状态
	startRecv();
	
	while(1)
	{
	}
}



//外部中断0处理程序
//用于处理来自24L01的中断
void interrupt24L01(void) interrupt 0
{
	unsigned char * receivedData;
	
	//获取接收到的数据
	receivedData = nrfGetReceivedData();
	
	LED = (*(receivedData+1) == 1)?0:1;
	
}

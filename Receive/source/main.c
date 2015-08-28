/***************************************************************************
����Ȩ������
Copyright(C) All Rights Reserved by Changhao Huang (HuangChangHao@gmail.com)
��Ȩ�����ߣ��Ƴ��� HuangChangHao@gmail.com

δ������������Ȩ�������Խ�������˳��������κ���ҵĿ�ġ�
����ѧϰ��ο�Ŀ�ģ��������ô�ע����Ȩ��������Ϣ��
****************************************************************************/

//STC11F04E 1T , 4MHz����

#include <reg52.h>
#include "nrf24L01Node.h"

sbit LED = P3^7;

sfr AUXR = 0x8E;


void initINT0(void)
{
	EA=1;
	EX0=1; // Enable int0 interrupt.
}


//NRF24L01��ʼ�������ģʽ
void startRecv()
{
	unsigned char myAddr[5]= {53, 69, 149, 231, 1}; //���ڵ�Ľ��յ�ַ
	nrfSetRxMode( 96, 5, myAddr);
}


void main()
{

	AUXR = AUXR|0x80;  // T0, 1T Mode
	
	//
	LED = 1;
	
	//��ʼ��INT0 
	initINT0();

	//��ʼ��24L01
	nrf24L01Init();
	
	//�������״̬
	startRecv();
	
	while(1)
	{
	}
}



//�ⲿ�ж�0�������
//���ڴ�������24L01���ж�
void interrupt24L01(void) interrupt 0
{
	unsigned char * receivedData;
	
	//��ȡ���յ�������
	receivedData = nrfGetReceivedData();
	
	LED = (*(receivedData+1) == 1)?0:1;
	
}

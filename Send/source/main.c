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

unsigned char onOff = 1;

sfr AUXR = 0x8E;

// Node ID
#define NODE_ID 250

void delay100ms(void)   //��� 0us
{
    unsigned char a,b,c;
    for(c=4;c>0;c--)
        for(b=116;b>0;b--)
            for(a=214;a>0;a--);
}

void delay500ms(void)   //��� 0us
{
    unsigned char a,b,c;
    for(c=167;c>0;c--)
        for(b=171;b>0;b--)
            for(a=16;a>0;a--);
}

void delay1s(void)   //��� 0us
{
    unsigned char a,b,c;
    for(c=127;c>0;c--)
        for(b=235;b>0;b--)
            for(a=32;a>0;a--);
}


void delay2s(void)   //��� 0us
{
    unsigned char a,b,c;
    for(c=252;c>0;c--)
        for(b=230;b>0;b--)
            for(a=33;a>0;a--);
}

void initINT0(void)
{
	EA=1;
	EX0=1; // Enable int0 interrupt.
}



//��������
void sendData()
{
	unsigned char sendData[16];
	//unsigned char toAddr[5]= {53, 69, 149, 231, 231}; //Pi
	unsigned char toAddr[5]= {53, 69, 149, 231, 1};
	unsigned char tmp;
	
	sendData[0] = NODE_ID;//Node ID
	sendData[1] = onOff;

	tmp = nrfSendData( 96, 5, toAddr, 16, sendData);//Pi, 96Ƶ����5�ֽڵ�ַ������16�ֽ�


}


void main()
{

	AUXR = AUXR|0x80;  // T0, 1T Mode	
	
	//��ʼ��INT0 
	initINT0();

	//��ʼ��24L01
	nrf24L01Init();
	
	//��ʼ��onOff
	onOff=1;
	
	
	while(1)
	{
		onOff=1;
		sendData();
		delay100ms();
		
		onOff=0;
		sendData();
		delay2s();
		//onOff = onOff==1?0:1;	
	}
}

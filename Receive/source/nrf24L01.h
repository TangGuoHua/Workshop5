/***************************************************************************
���޸���ʷ��

����            ����    ��ע
----------------------------------------------------------------------
2013��10��01��  �Ƴ���  ��ʼ�汾

����Ȩ������
Copyright(C) All Rights Reserved by Changhao Huang (HuangChangHao@gmail.com)
��Ȩ�����ߣ��Ƴ��� HuangChangHao@gmail.com

δ������������Ȩ�������Խ�������˳��������κ���ҵĿ�ġ�
����ѧϰ��ο�Ŀ�ģ��������ô�ע����Ȩ��������Ϣ��
****************************************************************************/

#ifndef __NRF24L01_H__
#define __NRF24L01_H__

/*******************����Ĵ���***************************/
#define  R_REGISTER      0x00//��ȡ���üĴ���
#define  W_REGISTER      0x20//д���üĴ���
#define  R_RX_PAYLOAD 	 0x61//��ȡRX��Ч����
#define  W_TX_PAYLOAD	 0xa0//дTX��Ч����
#define  FLUSH_TX		 0xe1//���TXFIFO�Ĵ���
#define  FLUSH_RX		 0xe2//���RXFIFO�Ĵ���
#define  REUSE_TX_PL     0xe3//����ʹ����һ����Ч����
#define  NOP             0xff//�ղ���
#define  W_TX_PAYLOAD_NOACK 0xB0	// Used in TX mode, Disable AUTOACK on this specific packet

/******************�Ĵ�����ַ****************************/
#define  CONFIG          0x00//���üĴ���
#define  EN_AA			 0x01//ʹ���Զ�Ӧ��
#define  EN_RXADDR       0x02//����ͨ��ʹ��0-5��ͨ��
#define  SETUP_AW        0x03//��������ͨ����ַ����3-5
#define  SETUP_RETR      0x04//�����Զ��ط�
#define  RF_CH           0x05//��Ƶͨ������
#define  RF_SETUP        0x06//��Ƶ�Ĵ���
#define  STATUS          0x07//״̬�Ĵ���
#define  OBSERVE_TX      0x08//���ͼ��Ĵ���
#define  CD              0x09//�ز�
#define  RX_ADDR_P0      0x0a//����ͨ��0���յ�ַ
#define  RX_ADDR_P1      0x0b//����ͨ��1���յ�ַ
#define  RX_ADDR_P2      0x0c//����ͨ��2���յ�ַ
#define  RX_ADDR_P3      0x0d//����ͨ��3���յ�ַ
#define  RX_ADDR_P4      0x0e//����ͨ��4���յ�ַ
#define  RX_ADDR_P5      0x0f//����ͨ��5���յ�ַ
#define  TX_ADDR         0x10//���͵�ַ
#define  RX_PW_P0        0x11//P0ͨ�����ݿ�������
#define  RX_PW_P1        0x12//P1ͨ�����ݿ�������
#define  RX_PW_P2        0x13//P2ͨ�����ݿ�������
#define  RX_PW_P3        0x14//P3ͨ�����ݿ�������
#define  RX_PW_P4        0x15//P4ͨ�����ݿ�������
#define  RX_PW_P5        0x16//P5ͨ�����ݿ�������
#define  FIFO_STATUS     0x17//FIFO״̬�Ĵ���
#define  FEATURE         0x1D// Additional features register, needed to enable the additional commands

/******************Ӳ������*******************************/
sbit CE =  P3^3; //Pin3
sbit CSN=  P1^0; //Pin4
sbit SCLK= P3^4; //Pin5
sbit MOSI= P1^1; //Pin6
sbit MISO= P1^2; //Pin7
sbit IRQ = P3^2; //Pin8

#endif
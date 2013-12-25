#include "SCCB.h"
#include "delay.h"
#include "stm32f10x_lib.h"
/*
-----------------------------------------------
   �\��: ��l�Ƽ���SCCB���f
   �Ѽ�: �L
 ��^��: �L
-----------------------------------------------
*/
void SCCB_GPIO_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
   /* Enable GPIOA  clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  SCCB_SIC_BIT|SCCB_SID_BIT;	//SCCB_SIC_BIT=GPIO_Pin_7; SCCB_SID_BIT=GPIO_Pin_6
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		  //GPIO_Mode_AIN = 0x0,     //������J
  GPIO_InitStructure.GPIO_Speed =GPIO_Speed_10MHz;		  //GPIO_Mode_IN_FLOATING = 0x04, //�a�ſ�J
  GPIO_Init(GPIOA, &GPIO_InitStructure);				  //GPIO_Mode_IPD = 0x28,    //�U�Կ�J
														  //GPIO_Mode_IPU = 0x48,    //�W�Կ�J
														  //GPIO_Mode_Out_OD = 0x14, //�}�|��X
														  //GPIO_Mode_Out_PP = 0x10,  //������X
														  //GPIO_Mode_AF_OD = 0x1C,   //�}�|�_��
														  //GPIO_Mode_AF_PP = 0x18    //�����_�� 
}
void SCCB_SID_GPIO_OUTPUT(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
   /* Enable GPIOA  clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  SCCB_SID_BIT;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
}
void SCCB_SID_GPIO_INPUT(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
   /* Enable GPIOA  clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  SCCB_SID_BIT;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
 // GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
}

/*
-----------------------------------------------
   �\��: start�R�O,SCCB���_�l�H��
   �Ѽ�: �L
 ��^��: �L
-----------------------------------------------
*/
void startSCCB(void)
{
    SCCB_SID_H();     //�ƾڽu���q��
    delay_us(500);

    SCCB_SIC_H();	   //�b�����u�����ɭԼƾڽu�Ѱ��ܧC
    delay_us(500);
 
    SCCB_SID_L();
    delay_us(500);

    SCCB_SIC_L();	 //�ƾڽu��_�C�q���A��ާ@��ƥ��n
    delay_us(500);


}
/*
-----------------------------------------------
   �\��: stop�R�O,SCCB������H��
   �Ѽ�: �L
 ��^��: �L
-----------------------------------------------
*/
void stopSCCB(void)
{
    SCCB_SID_L();
    delay_us(500);
 
    SCCB_SIC_H();	
    delay_us(500);
  

    SCCB_SID_H();	
    delay_us(500);
   
}

/*
-----------------------------------------------
   �\��: noAck,�Ω�s��Ū�������̫�@�ӵ����g��
   �Ѽ�: �L
 ��^��: �L
-----------------------------------------------
*/
void noAck(void)
{
	
	SCCB_SID_H();	
	delay_us(500);
	
	SCCB_SIC_H();	
	delay_us(500);
	
	SCCB_SIC_L();	
	delay_us(500);
	
	SCCB_SID_L();	
	delay_us(500);

}

/*
-----------------------------------------------
   �\��: �g�J�@�Ӧr�`���ƾڨ�SCCB
   �Ѽ�: �g�J�ƾ�
 ��^��: �o�e���\��^1�A�o�e���Ѫ�^0
-----------------------------------------------
*/
unsigned char SCCBwriteByte(unsigned char m_data)
{
	unsigned char j,tem;

	for(j=0;j<8;j++) //�`��8���o�e�ƾ�
	{
		if((m_data<<j)&0x80)
		{
			SCCB_SID_H();	
		}
		else
		{
			SCCB_SID_L();	
		}
		delay_us(500);
		SCCB_SIC_H();	
		delay_us(500);
		SCCB_SIC_L();	
		delay_us(500);

	}
	delay_us(100);
	SCCB_SID_IN;/*�]�mSDA����J*/
	delay_us(500);
	SCCB_SIC_H();	
	delay_us(100);
	if(SCCB_SID_STATE){tem=0;}   //SDA=1�o�e���ѡA��^0}
	else {tem=1;}   //SDA=0�o�e���\�A��^1
	SCCB_SIC_L();	
	delay_us(500);	
        SCCB_SID_OUT;/*�]�mSDA����X*/

	return (tem);  
}

/*
-----------------------------------------------
   �\��: �@�Ӧr�`�ƾ�Ū���åB��^
   �Ѽ�: �L
 ��^��: Ū���쪺�ƾ�
-----------------------------------------------
*/
unsigned char SCCBreadByte(void)
{
	unsigned char read,j;
	read=0x00;
	
	SCCB_SID_IN;/*�]�mSDA����J*/
	delay_us(500);
	for(j=8;j>0;j--) //�`��8�������ƾ�
	{		     
		delay_us(500);
		SCCB_SIC_H();
		delay_us(500);
		read=read<<1;
		if(SCCB_SID_STATE) 
		{
			read=read+1;
		}
		SCCB_SIC_L();
		delay_us(500);
	}	
	return(read);
}

/*******************************************************************************
*  Copyright (C) 2012 All Rights Reserved
*		
* �n��@��:	�M���a��
* ���v�Ҧ�: �M���q�l	
* �Ыؤ��:	2010�~6��10�� 
* �n����v:	2010�~11��2��ק�
			2012�~09��10��ק�
* Version:  3.0 
* Demo �^�_�a�}�Ghttp://qifeidz.taobao.com
**********************************************************************************************************************************************
�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i
�i�i�i�i�i�i�i�i�i�i�i�@�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�x�@�i�i�i�i�i�i�i�i�i�i�i�i�i�i�@�@�@�@�@�@�@�i�i�i�i�i�i�i
�i�i�x�@�@�@�@�i�@�@�@�@�@�@�G�i�i�i�i�x�@�@�@�@�@�@�@�@�i�i�i�i�i�i�i�i�i�|�F�i�i�@�@�i�i�i�@�i�i�i�i�i�i�i�i�i�@�@�@�@�|�|�@�@�@�i�i�i�i�i�i
�i�i�i�i�i�i�@�i�i�i�@�G�@�i�i�i�i�i�i�@�@�@�@�|�F�G�@�|�i�@�@�i�i�i�i�i�|�@�@�@�@�@�@�@�@�@�@�@�i�i�i�i�i�i�i�i�|�i�i�|�@�@�@�@�F�i�i�i�i�i�i
�i�i�i�|�F�F�@�i�i�F�i�i�i�|�i�i�i�i�i�i�i�i�i�i�i�x�@�i�@�@�i�i�i�i�i�i�i�@�@�F�F�@�@�F�F�F�@�@�i�i�i�i�i�i�F�F�F�F�F�F�@�@�F�F�F�i�i�i�i�i�i
�i�i�i�@�i�G�@�@�@�@�@�@�@�@�@�@�@�i�i�i�i�i�i�i�i�G�@�@�x�i�i�i�i�i�i�i�i�@�@�@�@�@�@�@�@�@�@�|�i�i�i�i�i�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�i�i�i
�i�i�i�@�@�@�@�@�F�G�@�@�F�@�i�F�i�i�i�i�i�i�i�i�i�@�@�@�@�@�i�i�i�i�i�i�i�@�@�i�i�@�@�i�i�i�@�x�i�i�i�i�i�@�@�|�i�i�i�i�@�@�i�i�x�@�@�|�i�i�i
�i�i�i�i�i�i�i�@�x�@�i�@�F�@�i�i�i�i�i�i�i�i�i�i�i�x�@�i�i�@�@�i�i�i�i�i�i�@�@�@�@�@�@�@�@�@�@�F�i�i�i�i�i�i�i�i�i�i�i�i�@�@�F�i�i�i�i�i�i�i�i
�i�G�@�@�@�i�|�x�F�@�@�@�F�@�i�i�i�i�i�i�i�i�i�i�i�i�@�@�i�i�i�i�i�i�i�i�i�i�i�i�i�|�@�F�i�i�i�i�i�i�@�i�i�i�i�i�i�i�i�i�@�@�F�i�i�i�i�i�i�i�i
�i�i�i�i�i�i�@�i�i�i�i�i�@�@�i�i�i�i�i�i�i�i�i�i�i�i�F�@�@�@�@�@�@�x�i�i�i�i�i�i�i�i�@�@�@�@�@�@�@�@�@�i�i�i�i�i�x�i�i�F�@�@�i�i�i�i�i�i�i�i�i
�i�i�i�i�@�@�@�i�i�x�@�@�@�@�i�i�i�i�i�i�i�i�i�i�i�i�i�i�@�@�@�@�@�i�i�i�i�i�i�i�i�i�i�@�@�@�@�@�@�@�i�i�i�i�i�i�i�@�@�@�@�|�i�i�i�i�i�i�i�i�i
�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i
**********************************************************************************************************************************************/

#include "OV7670.h"
#include "delay.h"
#include "stm32f10x_lib.h"

// GND         PIN1
// HREF  PC8   PIN2
// VSYNC       PIN3
// PWDN  GND   PIN4
// PCLK  PC9   PIN5 �S���Ψ�
// AVDD  2.8V  PIN6
// DVDD  2.8V  PIN7
// SIOD  PA6   PIN8
// XCLK1 PA8   PIN9
// SIOC  PA7   PIN10
// D0    PC0   PIN11
// D1    PC1   PIN12
// D2    PC2   PIN13
// D3    PC3   PIN14
// GND         PIN15
// D4    PC4   PIN16
// D5    PC5   PIN17
// D6    PC6   PIN18
// D7    PC7   PIN19
// RST   GND   PIN20

//extern const char change_reg[CHANGE_REG_NUM][2];
////////////////////////////
//�\��G����7670����
//��^�G�L

void CLK_init_ON(void)
{
  
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8; 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP ; 
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    RCC_MCOConfig(RCC_MCO_HSE  );//hsi
}
void CLK_init_OFF(void)
{
  
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8; 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}
void OV7670_GPIO_Init(void)
{
  
  GPIO_InitTypeDef GPIO_InitStructure;
   /* Enable GPIOC  clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  0X0BFF;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_AF_OD  GPIO_Mode_AF_PP GPIO_Mode_IPU	GPIO_Mode_IN_FLOATING   
  //GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
}
void OV7670_GPIO_CONTRL_CONFIG(void)
{
  
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = LCD_HREF_BIT|LCD_VSYNC_BIT|LCD_PCLK_BIT;
    //GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    RCC_MCOConfig(RCC_MCO_HSE  );//hsi
}
////////////////////////////
//�\��G�gOV7670�H�s��
//��^�G1-���\	0-����
unsigned char wrOV7670Reg(unsigned char regID, unsigned char regDat)
{
	startSCCB();
	if(0==SCCBwriteByte(0x42))
	{
		stopSCCB();
		return(0);
	}
	delay_us(100);
  	if(0==SCCBwriteByte(regID))
	{
		stopSCCB();
		return(0);
	}
	delay_us(100);
  	if(0==SCCBwriteByte(regDat))
	{
		stopSCCB();
		return(0);
	}
  	stopSCCB();
	
  	return(1);
}
////////////////////////////
//�\��GŪOV7670�H�s��
//��^�G1-���\	0-����
unsigned char rdOV7670Reg(unsigned char regID, unsigned char *regDat)
{
	//�q�L�g�ާ@�]�m�H�s���a�}
	startSCCB();
	if(0==SCCBwriteByte(0x42))
	{
		stopSCCB();
		return(0);
	}
	delay_us(100);
  	if(0==SCCBwriteByte(regID))
	{
		stopSCCB();
		return(0);
	}
	stopSCCB();
	
	delay_us(100);
	
	//�]�m�H�s���a�}��A�~�OŪ
	startSCCB();
	if(0==SCCBwriteByte(0x43))
	{
		stopSCCB();
		return(0);
	}
	delay_us(100);
  	*regDat=SCCBreadByte();
  	noAck();
  	stopSCCB();
  	return(1);
}


//(140,16,640,480) is good for VGA
//(272,16,320,240) is good for QVGA
/* config_OV7670_window */
void OV7670_config_window(unsigned int startx,unsigned int starty,unsigned int width, unsigned int height)
{
	unsigned int endx;
	unsigned int endy;// "v*2"����
	unsigned char temp_reg1, temp_reg2;
	unsigned char temp=0;
	
	endx=(startx+width);
	endy=(starty+height+height);// "v*2"����
        rdOV7670Reg(0x03, &temp_reg1 );
	temp_reg1 &= 0xf0;
	rdOV7670Reg(0x32, &temp_reg2 );
	temp_reg2 &= 0xc0;
	
	// Horizontal
	temp = temp_reg2|((endx&0x7)<<3)|(startx&0x7);
	wrOV7670Reg(0x32, temp );
	temp = (startx&0x7F8)>>3;
	wrOV7670Reg(0x17, temp );
	temp = (endx&0x7F8)>>3;
	wrOV7670Reg(0x18, temp );
	
	// Vertical
	temp =temp_reg1|((endy&0x3)<<2)|(starty&0x3);
	wrOV7670Reg(0x03, temp );
	temp = starty>>2;
	wrOV7670Reg(0x19, temp );
	temp = endy>>2;
	wrOV7670Reg(0x1A, temp );
}

set_OV7670reg(void)
{
	wrOV7670Reg(0x8c, 0x00);
	wrOV7670Reg(0x3a, 0x04);
	wrOV7670Reg(0x40, 0xd0);  //���10�A�q��COM15�A�]�m��X�ƾڽd��M��X�榡
	wrOV7670Reg(0x8c, 0x00);
	wrOV7670Reg(0x12, 0x14); //��X�榡QVGA,��]�m��0x14
	wrOV7670Reg(0x32, 0x80);
	wrOV7670Reg(0x17, 0x16);
	wrOV7670Reg(0x18, 0x04);
	wrOV7670Reg(0x19, 0x02);
	wrOV7670Reg(0x1a, 0x7b);//0x7a,  ���0x7b
	wrOV7670Reg(0x03, 0x06);//0x0a,  ���0x06
	wrOV7670Reg(0x0c, 0x04);//���0x04	   com3,�]�m�Y��A�ٹq�A�Ҧ���
	wrOV7670Reg(0x3e, 0x00);//	���0x00   com14�Adcw�Mpclk�Y��]�m�A�H�Τ��W��
	wrOV7670Reg(0x70, 0x3a); //���0x04
	wrOV7670Reg(0x71, 0x35); //���0x35
	wrOV7670Reg(0x72, 0x11); //���0x11
	wrOV7670Reg(0x73, 0x00);//���f0 �w��o�̧��ܫܭ��n
	wrOV7670Reg(0xa2, 0x00); //���0x02
	wrOV7670Reg(0x11, 0xff); //�����W�v�A�o�̧אּ�̤j�ȡA��Ӭ�0x81  �]���ܡ^
	//wrOV7670Reg(0x15 , 0x31);
	wrOV7670Reg(0x7a, 0x20); //���0x20 �H�s��7a--89���������u�]�m
	wrOV7670Reg(0x7b, 0x1c); //���0x1c
	wrOV7670Reg(0x7c, 0x28); //���0x28
	wrOV7670Reg(0x7d, 0x3c); //���0x3c
	wrOV7670Reg(0x7e, 0x55); //���0x55
	wrOV7670Reg(0x7f, 0x68); //���0x68
	wrOV7670Reg(0x80, 0x76); //���0x76
	wrOV7670Reg(0x81, 0x80); //���0x80
	wrOV7670Reg(0x82, 0x88); //���0x88
	wrOV7670Reg(0x83, 0x8f); //���0x8f
	wrOV7670Reg(0x84, 0x96); //���0x96
	wrOV7670Reg(0x85, 0xa3); //���0xa3
	wrOV7670Reg(0x86, 0xaf); //���0xaf
	wrOV7670Reg(0x87, 0xc4); //���0xc4
	wrOV7670Reg(0x88, 0xd7); //���0xd7
	wrOV7670Reg(0x89, 0xe8); //���0xe8 
	 
	wrOV7670Reg(0x32,0xb6);
	
	wrOV7670Reg(0x13, 0xff); //���0xe0 com13 AGC,AWB,AEC�ϯ౱��	 �]���ܡ^
	wrOV7670Reg(0x00, 0x00);//AGC //���0x00
	wrOV7670Reg(0x10, 0x00);//���0x00  �n����
	wrOV7670Reg(0x0d, 0x00);//���0x00	 COM4
	wrOV7670Reg(0x14, 0x4e);//���0x28, limit the max gain	�۰ʼW�q�]�m �S�ܤ�
	wrOV7670Reg(0xa5, 0x05); //���0x05 50Hz bangding step limting
	wrOV7670Reg(0xab, 0x07); //���0x07 60Hz bangding step limting
	wrOV7670Reg(0x24, 0x75); //���0x75 agc/aec-í�w�B��ϰ�W��
	wrOV7670Reg(0x25, 0x63); //���0x63 agc/aec-í�w�B��ϰ�U��
	wrOV7670Reg(0x26, 0xA5); //���0xa5 agc/aec-�ֳt�B��ϰ�
	wrOV7670Reg(0x9f, 0x78); //���0x78 ��󪽤�Ϫ�aec/agc������1
	wrOV7670Reg(0xa0, 0x68); //���0x68 ��󪽤�Ϫ�aec/agc������2
//	wrOV7670Reg(0xa1, 0x03);//0x0b,
	wrOV7670Reg(0xa6, 0xdf);//0xd8, ���0xdf ��󪽤�Ϫ�aec/agc������3
	wrOV7670Reg(0xa7, 0xdf);//0xd8, ���0xdf ��󪽤�Ϫ�aec/agc������4
	wrOV7670Reg(0xa8, 0xf0); //���0xf0  ��󪽤�Ϫ�aec/agc������5
	wrOV7670Reg(0xa9, 0x90);  //���0x90  ��󪽤�Ϫ�aec/agc������6
	wrOV7670Reg(0xaa, 0x94);  //���0x94  ��󪽤�Ϫ�aec/agc������7
	//wrOV7670Reg(0x13, 0xe5);  //���0xe5
	wrOV7670Reg(0x0e, 0x61);  //���0x61 COM5
	wrOV7670Reg(0x0f, 0x43);  //���0x4b COM6
	wrOV7670Reg(0x16, 0x02);  //���0x02 �O�d
	wrOV7670Reg(0x1e, 0x37);//0x07, ���0x37 �����蹳/�ݪ�½��ϯ�	 �]�m��01��o��½��
	wrOV7670Reg(0x21, 0x02);	//���0x02  �O�d
	wrOV7670Reg(0x22, 0x91);	//���0x91	�O�d
	wrOV7670Reg(0x29, 0x07);	//���0x07	�O�d
	wrOV7670Reg(0x33, 0x0b);	//���0x0b	href����A�אּ��l��80�ɧ���
	wrOV7670Reg(0x35, 0x0b);	//���0xe0	�O�d
	wrOV7670Reg(0x37, 0x3f);	//���0x1d	adc����
	wrOV7670Reg(0x38, 0x01);	//���0x71	adc�M�����@�ұ���
	wrOV7670Reg(0x39, 0x00);	//���0x2a	adc��������
	wrOV7670Reg(0x3c, 0x78);	//���0x78	 COM12
	wrOV7670Reg(0x4d, 0x40);	//���0x40	 �O�d
	wrOV7670Reg(0x4e, 0x20);	//���0x20	 �O�d
	wrOV7670Reg(0x69, 0x00);	//���0x00	  �T�w�W�q����
	wrOV7670Reg(0x6b, 0x4a);   //PLL���0x00	  pll����	���n�]�m
	wrOV7670Reg(0x74, 0x19);	//���0x19	��ʼƦr�W�q
	wrOV7670Reg(0x8d, 0x4f);	//���0x4f	�O�d
	wrOV7670Reg(0x8e, 0x00);	//���0x00	�O�d
	wrOV7670Reg(0x8f, 0x00);	//���0x00	�O�d
	wrOV7670Reg(0x90, 0x00);	//���0x00	�O�d
	wrOV7670Reg(0x91, 0x00);	//���0x00	�O�d
	wrOV7670Reg(0x92, 0x00);   //0x19,//0x66	 ���0x00 �Ŧ�C8��
	wrOV7670Reg(0x96, 0x00);	//���0x00	  �O�d
	wrOV7670Reg(0x9a, 0x80);	//���0x80	  �O�d
	wrOV7670Reg(0xb0, 0x84);	//���0xe0	  �O�d
	wrOV7670Reg(0xb1, 0x0c);	//���0x0c	 ablc�]�m
	wrOV7670Reg(0xb2, 0x0e);	//���0x0e	  �O�d
	wrOV7670Reg(0xb3, 0x82);	//���0x82	  ablc target
	wrOV7670Reg(0xb8, 0x0a);	//���0x0a	   �O�d
	wrOV7670Reg(0x43, 0x14);	//���0x14	  43-48���O�d
	wrOV7670Reg(0x44, 0xf0);	//���0xf0
	wrOV7670Reg(0x45, 0x34);	//���0x34
	wrOV7670Reg(0x46, 0x58);	//���0x58
	wrOV7670Reg(0x47, 0x28);	//���0x28
	wrOV7670Reg(0x48, 0x3a);	//���0x3a
	
	wrOV7670Reg(0x59, 0x88);	//���0x88	 51-5e�O�d
	wrOV7670Reg(0x5a, 0x88);	//���0x88
	wrOV7670Reg(0x5b, 0x44);	//���0x44
	wrOV7670Reg(0x5c, 0x67);	//���0x67
	wrOV7670Reg(0x5d, 0x49);	//���0x49
	wrOV7670Reg(0x5e, 0x0e);	//���0xe0
	
	wrOV7670Reg(0x64, 0x04);	//���0x04	  64-66���Y���v
	wrOV7670Reg(0x65, 0x20);	//���0x20
	wrOV7670Reg(0x66, 0x05);	//���0x05

	wrOV7670Reg(0x94, 0x04);	//���0x04	94-95���Y���v
	wrOV7670Reg(0x95, 0x08);	//���0x08	 

	wrOV7670Reg(0x6c, 0x0a);	//���0x0a	6c-6fawb�]�m
	wrOV7670Reg(0x6d, 0x55);	//���0x55
	wrOV7670Reg(0x6e, 0x11);	//���0x11
	wrOV7670Reg(0x6f, 0x9f);   //0x9e for advance AWB	  ���9f

	wrOV7670Reg(0x6a, 0x40);	//���0x40	g�q�Dawb�W�q
	wrOV7670Reg(0x01, 0x40);	//���0x40	b�q�Dawb�W�q����
	wrOV7670Reg(0x02, 0x40);	//���0x40	r�q�Dawb�W�q����
	
	//wrOV7670Reg(0x13, 0xe7);	//���0xe7
	wrOV7670Reg(0x15, 0x00);   //00  cmos10  �t��pclk��X���
	wrOV7670Reg(0x4f, 0x80);	//���0x80	�H�U����m�x�}�Y�Ƴ]�m
	wrOV7670Reg(0x50, 0x80);	//���0x80
	wrOV7670Reg(0x51, 0x00);	//���0x00
	wrOV7670Reg(0x52, 0x22);	//���0x22
	wrOV7670Reg(0x53, 0x5e);	//���0x5e
	wrOV7670Reg(0x54, 0x80);	//���0x80
	wrOV7670Reg(0x58, 0x9e);	//���0x9e

	wrOV7670Reg(0x41, 0x08);	//���0x08	com16 �H�U����t�]�m
	wrOV7670Reg(0x3f, 0x00);	//���0x00  ��t�W�j�վ�
	wrOV7670Reg(0x75, 0x05);	//���0x05
	wrOV7670Reg(0x76, 0xe1);	//���0xe1

	wrOV7670Reg(0x4c, 0x00);	//���0x00  ���n���j��
	wrOV7670Reg(0x77, 0x01);	//���0x01	���n�h������
	
	wrOV7670Reg(0x3d, 0xc1);	//0xc0,	   com13 ��X�]�m
	wrOV7670Reg(0x4b, 0x09);	//���0x09 �H�s��4b�]�m
	wrOV7670Reg(0xc9, 0x60);	//���0x60	 ���M�ױ���
	//wrOV7670Reg(0x41, 0x38);	//���0x38	  com16��t�]�m�]�m
	wrOV7670Reg(0x56, 0x40);//0x40,  change according to Jim's request	���ױ���
	wrOV7670Reg(0x34, 0x11);	//���0x11	  �P���}�C�Ѧҹq������
	wrOV7670Reg(0x3b, 0x02);//0x00,//���0x02,	  com11����
	wrOV7670Reg(0xa4, 0x89);//0x88, ���89 nt����  
	
	wrOV7670Reg(0x96, 0x00);	//���0x00  �H�U96-9c�O�d
	wrOV7670Reg(0x97, 0x30);	//���0x30
	wrOV7670Reg(0x98, 0x20);	//���0x20
	wrOV7670Reg(0x99, 0x30);	//���0x30
	wrOV7670Reg(0x9a, 0x84);	//���0x84
	wrOV7670Reg(0x9b, 0x29);	//���0x29
	wrOV7670Reg(0x9c, 0x03);	//���0x03
	wrOV7670Reg(0x9d, 0x4c);	//���0x4c	50HZ�����o�i����
	wrOV7670Reg(0x9e, 0x3f);	//���0x3f	60HZ�����o�i����

	wrOV7670Reg(0x09, 0x00);	//���0x00 �q�α��com2
	wrOV7670Reg(0x3b, 0xc2);//0x82,//0xc0,//���0xc2,	//night mode ���0xc2

}

/* OV7670_init() */
//��^1���\�A��^0����
unsigned char OV7670_init(void)
{
	unsigned char temp;	
	unsigned int i=0;

	OV7670_GPIO_Init();
	OV7670_GPIO_CONTRL_CONFIG();
	SCCB_GPIO_Config(); // io init..

    CLK_init_ON();
	temp=0x80;
	if(0==wrOV7670Reg(0x12, temp)) //Reset SCCB
	{
        return 0 ;
	}
	delay_ms(100);
  	set_OV7670reg();

	OV7670_config_window(272,12,320,240);// set 240*320
	return 0x01; //ok			  
} 
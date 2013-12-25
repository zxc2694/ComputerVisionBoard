/*******************************************************************************
*  Copyright (C) 2012 All Rights Reserved
*		
* 軟件作者:	騎飛家族
* 版權所有: 騎飛電子	
* 創建日期:	2010年6月10日 
* 軟件歷史:	2010年11月2日修改
			2012年09月10日修改
* Version:  3.0 
* Demo 淘寶地址：http://qifeidz.taobao.com
**********************************************************************************************************************************************
懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶
懶懶懶懶懶懶懶懶懶懶懶一懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶困一懶懶懶懶懶懶懶懶懶懶懶懶懶懶一一一一一一一懶懶懶懶懶懶懶
懶懶困一一一一懶一一一一一一二懶懶懶懶困一一一一一一一一懶懶懶懶懶懶懶懶懶四厲懶懶一一懶懶懶一懶懶懶懶懶懶懶懶懶一一一一四四一一一懶懶懶懶懶懶
懶懶懶懶懶懶一懶懶懶一二一懶懶懶懶懶懶一一一一四厲二一四懶一一懶懶懶懶懶四一一一一一一一一一一一懶懶懶懶懶懶懶懶四懶懶四一一一一厲懶懶懶懶懶懶
懶懶懶四厲厲一懶懶厲懶懶懶四懶懶懶懶懶懶懶懶懶懶懶困一懶一一懶懶懶懶懶懶懶一一厲厲一一厲厲厲一一懶懶懶懶懶懶厲厲厲厲厲厲一一厲厲厲懶懶懶懶懶懶
懶懶懶一懶二一一一一一一一一一一一懶懶懶懶懶懶懶懶二一一困懶懶懶懶懶懶懶懶一一一一一一一一一一四懶懶懶懶懶一一一一一一一一一一一一一一一懶懶懶
懶懶懶一一一一一厲二一一厲一懶厲懶懶懶懶懶懶懶懶懶一一一一一懶懶懶懶懶懶懶一一懶懶一一懶懶懶一困懶懶懶懶懶一一四懶懶懶懶一一懶懶困一一四懶懶懶
懶懶懶懶懶懶懶一困一懶一厲一懶懶懶懶懶懶懶懶懶懶懶困一懶懶一一懶懶懶懶懶懶一一一一一一一一一一厲懶懶懶懶懶懶懶懶懶懶懶懶一一厲懶懶懶懶懶懶懶懶
懶二一一一懶四困厲一一一厲一懶懶懶懶懶懶懶懶懶懶懶懶一一懶懶懶懶懶懶懶懶懶懶懶懶懶四一厲懶懶懶懶懶懶一懶懶懶懶懶懶懶懶懶一一厲懶懶懶懶懶懶懶懶
懶懶懶懶懶懶一懶懶懶懶懶一一懶懶懶懶懶懶懶懶懶懶懶懶厲一一一一一一困懶懶懶懶懶懶懶懶一一一一一一一一一懶懶懶懶懶困懶懶厲一一懶懶懶懶懶懶懶懶懶
懶懶懶懶一一一懶懶困一一一一懶懶懶懶懶懶懶懶懶懶懶懶懶懶一一一一一懶懶懶懶懶懶懶懶懶懶一一一一一一一懶懶懶懶懶懶懶一一一一四懶懶懶懶懶懶懶懶懶
懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶懶
**********************************************************************************************************************************************/

#include "OV7670.h"
#include "delay.h"
#include "stm32f10x_lib.h"

// GND         PIN1
// HREF  PC8   PIN2
// VSYNC       PIN3
// PWDN  GND   PIN4
// PCLK  PC9   PIN5 沒有用到
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
//功能：提供7670時鐘
//返回：無

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
//功能：寫OV7670寄存器
//返回：1-成功	0-失敗
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
//功能：讀OV7670寄存器
//返回：1-成功	0-失敗
unsigned char rdOV7670Reg(unsigned char regID, unsigned char *regDat)
{
	//通過寫操作設置寄存器地址
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
	
	//設置寄存器地址後，才是讀
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
	unsigned int endy;// "v*2"必須
	unsigned char temp_reg1, temp_reg2;
	unsigned char temp=0;
	
	endx=(startx+width);
	endy=(starty+height+height);// "v*2"必須
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
	wrOV7670Reg(0x40, 0xd0);  //原來10，通用COM15，設置輸出數據範圍和輸出格式
	wrOV7670Reg(0x8c, 0x00);
	wrOV7670Reg(0x12, 0x14); //輸出格式QVGA,原設置為0x14
	wrOV7670Reg(0x32, 0x80);
	wrOV7670Reg(0x17, 0x16);
	wrOV7670Reg(0x18, 0x04);
	wrOV7670Reg(0x19, 0x02);
	wrOV7670Reg(0x1a, 0x7b);//0x7a,  原來0x7b
	wrOV7670Reg(0x03, 0x06);//0x0a,  原來0x06
	wrOV7670Reg(0x0c, 0x04);//原來0x04	   com3,設置縮放，省電，模式等
	wrOV7670Reg(0x3e, 0x00);//	原來0x00   com14，dcw和pclk縮放設置，以及分頻等
	wrOV7670Reg(0x70, 0x3a); //原來0x04
	wrOV7670Reg(0x71, 0x35); //原來0x35
	wrOV7670Reg(0x72, 0x11); //原來0x11
	wrOV7670Reg(0x73, 0x00);//原來f0 已改這裡改變很重要
	wrOV7670Reg(0xa2, 0x00); //原來0x02
	wrOV7670Reg(0x11, 0xff); //時鐘頻率，這裡改為最大值，原來為0x81  （改變）
	//wrOV7670Reg(0x15 , 0x31);
	wrOV7670Reg(0x7a, 0x20); //原來0x20 寄存器7a--89為伽馬曲線設置
	wrOV7670Reg(0x7b, 0x1c); //原來0x1c
	wrOV7670Reg(0x7c, 0x28); //原來0x28
	wrOV7670Reg(0x7d, 0x3c); //原來0x3c
	wrOV7670Reg(0x7e, 0x55); //原來0x55
	wrOV7670Reg(0x7f, 0x68); //原來0x68
	wrOV7670Reg(0x80, 0x76); //原來0x76
	wrOV7670Reg(0x81, 0x80); //原來0x80
	wrOV7670Reg(0x82, 0x88); //原來0x88
	wrOV7670Reg(0x83, 0x8f); //原來0x8f
	wrOV7670Reg(0x84, 0x96); //原來0x96
	wrOV7670Reg(0x85, 0xa3); //原來0xa3
	wrOV7670Reg(0x86, 0xaf); //原來0xaf
	wrOV7670Reg(0x87, 0xc4); //原來0xc4
	wrOV7670Reg(0x88, 0xd7); //原來0xd7
	wrOV7670Reg(0x89, 0xe8); //原來0xe8 
	 
	wrOV7670Reg(0x32,0xb6);
	
	wrOV7670Reg(0x13, 0xff); //原來0xe0 com13 AGC,AWB,AEC使能控制	 （改變）
	wrOV7670Reg(0x00, 0x00);//AGC //原來0x00
	wrOV7670Reg(0x10, 0x00);//原來0x00  曝光值
	wrOV7670Reg(0x0d, 0x00);//原來0x00	 COM4
	wrOV7670Reg(0x14, 0x4e);//原來0x28, limit the max gain	自動增益設置 沒變化
	wrOV7670Reg(0xa5, 0x05); //原來0x05 50Hz bangding step limting
	wrOV7670Reg(0xab, 0x07); //原來0x07 60Hz bangding step limting
	wrOV7670Reg(0x24, 0x75); //原來0x75 agc/aec-穩定運行區域上限
	wrOV7670Reg(0x25, 0x63); //原來0x63 agc/aec-穩定運行區域下限
	wrOV7670Reg(0x26, 0xA5); //原來0xa5 agc/aec-快速運行區域
	wrOV7670Reg(0x9f, 0x78); //原來0x78 基於直方圖的aec/agc的控制1
	wrOV7670Reg(0xa0, 0x68); //原來0x68 基於直方圖的aec/agc的控制2
//	wrOV7670Reg(0xa1, 0x03);//0x0b,
	wrOV7670Reg(0xa6, 0xdf);//0xd8, 原來0xdf 基於直方圖的aec/agc的控制3
	wrOV7670Reg(0xa7, 0xdf);//0xd8, 原來0xdf 基於直方圖的aec/agc的控制4
	wrOV7670Reg(0xa8, 0xf0); //原來0xf0  基於直方圖的aec/agc的控制5
	wrOV7670Reg(0xa9, 0x90);  //原來0x90  基於直方圖的aec/agc的控制6
	wrOV7670Reg(0xaa, 0x94);  //原來0x94  基於直方圖的aec/agc的控制7
	//wrOV7670Reg(0x13, 0xe5);  //原來0xe5
	wrOV7670Reg(0x0e, 0x61);  //原來0x61 COM5
	wrOV7670Reg(0x0f, 0x43);  //原來0x4b COM6
	wrOV7670Reg(0x16, 0x02);  //原來0x02 保留
	wrOV7670Reg(0x1e, 0x37);//0x07, 原來0x37 水平鏡像/豎直翻轉使能	 設置為01後發生翻轉
	wrOV7670Reg(0x21, 0x02);	//原來0x02  保留
	wrOV7670Reg(0x22, 0x91);	//原來0x91	保留
	wrOV7670Reg(0x29, 0x07);	//原來0x07	保留
	wrOV7670Reg(0x33, 0x0b);	//原來0x0b	href控制，改為初始值80時改變
	wrOV7670Reg(0x35, 0x0b);	//原來0xe0	保留
	wrOV7670Reg(0x37, 0x3f);	//原來0x1d	adc控制
	wrOV7670Reg(0x38, 0x01);	//原來0x71	adc和模擬共模控制
	wrOV7670Reg(0x39, 0x00);	//原來0x2a	adc偏移控制
	wrOV7670Reg(0x3c, 0x78);	//原來0x78	 COM12
	wrOV7670Reg(0x4d, 0x40);	//原來0x40	 保留
	wrOV7670Reg(0x4e, 0x20);	//原來0x20	 保留
	wrOV7670Reg(0x69, 0x00);	//原來0x00	  固定增益控制
	wrOV7670Reg(0x6b, 0x4a);   //PLL原來0x00	  pll控制	重要設置
	wrOV7670Reg(0x74, 0x19);	//原來0x19	手動數字增益
	wrOV7670Reg(0x8d, 0x4f);	//原來0x4f	保留
	wrOV7670Reg(0x8e, 0x00);	//原來0x00	保留
	wrOV7670Reg(0x8f, 0x00);	//原來0x00	保留
	wrOV7670Reg(0x90, 0x00);	//原來0x00	保留
	wrOV7670Reg(0x91, 0x00);	//原來0x00	保留
	wrOV7670Reg(0x92, 0x00);   //0x19,//0x66	 原來0x00 空行低8位
	wrOV7670Reg(0x96, 0x00);	//原來0x00	  保留
	wrOV7670Reg(0x9a, 0x80);	//原來0x80	  保留
	wrOV7670Reg(0xb0, 0x84);	//原來0xe0	  保留
	wrOV7670Reg(0xb1, 0x0c);	//原來0x0c	 ablc設置
	wrOV7670Reg(0xb2, 0x0e);	//原來0x0e	  保留
	wrOV7670Reg(0xb3, 0x82);	//原來0x82	  ablc target
	wrOV7670Reg(0xb8, 0x0a);	//原來0x0a	   保留
	wrOV7670Reg(0x43, 0x14);	//原來0x14	  43-48為保留
	wrOV7670Reg(0x44, 0xf0);	//原來0xf0
	wrOV7670Reg(0x45, 0x34);	//原來0x34
	wrOV7670Reg(0x46, 0x58);	//原來0x58
	wrOV7670Reg(0x47, 0x28);	//原來0x28
	wrOV7670Reg(0x48, 0x3a);	//原來0x3a
	
	wrOV7670Reg(0x59, 0x88);	//原來0x88	 51-5e保留
	wrOV7670Reg(0x5a, 0x88);	//原來0x88
	wrOV7670Reg(0x5b, 0x44);	//原來0x44
	wrOV7670Reg(0x5c, 0x67);	//原來0x67
	wrOV7670Reg(0x5d, 0x49);	//原來0x49
	wrOV7670Reg(0x5e, 0x0e);	//原來0xe0
	
	wrOV7670Reg(0x64, 0x04);	//原來0x04	  64-66鏡頭補償
	wrOV7670Reg(0x65, 0x20);	//原來0x20
	wrOV7670Reg(0x66, 0x05);	//原來0x05

	wrOV7670Reg(0x94, 0x04);	//原來0x04	94-95鏡頭補償
	wrOV7670Reg(0x95, 0x08);	//原來0x08	 

	wrOV7670Reg(0x6c, 0x0a);	//原來0x0a	6c-6fawb設置
	wrOV7670Reg(0x6d, 0x55);	//原來0x55
	wrOV7670Reg(0x6e, 0x11);	//原來0x11
	wrOV7670Reg(0x6f, 0x9f);   //0x9e for advance AWB	  原來9f

	wrOV7670Reg(0x6a, 0x40);	//原來0x40	g通道awb增益
	wrOV7670Reg(0x01, 0x40);	//原來0x40	b通道awb增益控制
	wrOV7670Reg(0x02, 0x40);	//原來0x40	r通道awb增益控制
	
	//wrOV7670Reg(0x13, 0xe7);	//原來0xe7
	wrOV7670Reg(0x15, 0x00);   //00  cmos10  含有pclk輸出選擇
	wrOV7670Reg(0x4f, 0x80);	//原來0x80	以下為色彩矩陣係數設置
	wrOV7670Reg(0x50, 0x80);	//原來0x80
	wrOV7670Reg(0x51, 0x00);	//原來0x00
	wrOV7670Reg(0x52, 0x22);	//原來0x22
	wrOV7670Reg(0x53, 0x5e);	//原來0x5e
	wrOV7670Reg(0x54, 0x80);	//原來0x80
	wrOV7670Reg(0x58, 0x9e);	//原來0x9e

	wrOV7670Reg(0x41, 0x08);	//原來0x08	com16 以下為邊緣設置
	wrOV7670Reg(0x3f, 0x00);	//原來0x00  邊緣增強調整
	wrOV7670Reg(0x75, 0x05);	//原來0x05
	wrOV7670Reg(0x76, 0xe1);	//原來0xe1

	wrOV7670Reg(0x4c, 0x00);	//原來0x00  噪聲抑制強度
	wrOV7670Reg(0x77, 0x01);	//原來0x01	噪聲去除偏移
	
	wrOV7670Reg(0x3d, 0xc1);	//0xc0,	   com13 輸出設置
	wrOV7670Reg(0x4b, 0x09);	//原來0x09 寄存器4b設置
	wrOV7670Reg(0xc9, 0x60);	//原來0x60	 飽和度控制
	//wrOV7670Reg(0x41, 0x38);	//原來0x38	  com16邊緣設置設置
	wrOV7670Reg(0x56, 0x40);//0x40,  change according to Jim's request	對比度控制
	wrOV7670Reg(0x34, 0x11);	//原來0x11	  感光陣列參考電壓控制
	wrOV7670Reg(0x3b, 0x02);//0x00,//原來0x02,	  com11控制
	wrOV7670Reg(0xa4, 0x89);//0x88, 原來89 nt控制  
	
	wrOV7670Reg(0x96, 0x00);	//原來0x00  以下96-9c保留
	wrOV7670Reg(0x97, 0x30);	//原來0x30
	wrOV7670Reg(0x98, 0x20);	//原來0x20
	wrOV7670Reg(0x99, 0x30);	//原來0x30
	wrOV7670Reg(0x9a, 0x84);	//原來0x84
	wrOV7670Reg(0x9b, 0x29);	//原來0x29
	wrOV7670Reg(0x9c, 0x03);	//原來0x03
	wrOV7670Reg(0x9d, 0x4c);	//原來0x4c	50HZ條紋濾波的值
	wrOV7670Reg(0x9e, 0x3f);	//原來0x3f	60HZ條紋濾波的值

	wrOV7670Reg(0x09, 0x00);	//原來0x00 通用控制器com2
	wrOV7670Reg(0x3b, 0xc2);//0x82,//0xc0,//原來0xc2,	//night mode 原來0xc2

}

/* OV7670_init() */
//返回1成功，返回0失敗
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
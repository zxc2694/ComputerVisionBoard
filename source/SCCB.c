#include "SCCB.h"
#include "delay.h"
#include "stm32f10x_lib.h"
/*
-----------------------------------------------
   功能: 初始化模擬SCCB接口
   參數: 無
 返回值: 無
-----------------------------------------------
*/
void SCCB_GPIO_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
   /* Enable GPIOA  clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  SCCB_SIC_BIT|SCCB_SID_BIT;	//SCCB_SIC_BIT=GPIO_Pin_7; SCCB_SID_BIT=GPIO_Pin_6
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		  //GPIO_Mode_AIN = 0x0,     //模擬輸入
  GPIO_InitStructure.GPIO_Speed =GPIO_Speed_10MHz;		  //GPIO_Mode_IN_FLOATING = 0x04, //懸空輸入
  GPIO_Init(GPIOA, &GPIO_InitStructure);				  //GPIO_Mode_IPD = 0x28,    //下拉輸入
														  //GPIO_Mode_IPU = 0x48,    //上拉輸入
														  //GPIO_Mode_Out_OD = 0x14, //開漏輸出
														  //GPIO_Mode_Out_PP = 0x10,  //推挽輸出
														  //GPIO_Mode_AF_OD = 0x1C,   //開漏復用
														  //GPIO_Mode_AF_PP = 0x18    //推挽復用 
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
   功能: start命令,SCCB的起始信號
   參數: 無
 返回值: 無
-----------------------------------------------
*/
void startSCCB(void)
{
    SCCB_SID_H();     //數據線高電平
    delay_us(500);

    SCCB_SIC_H();	   //在時鐘線高的時候數據線由高至低
    delay_us(500);
 
    SCCB_SID_L();
    delay_us(500);

    SCCB_SIC_L();	 //數據線恢復低電平，單操作函數必要
    delay_us(500);


}
/*
-----------------------------------------------
   功能: stop命令,SCCB的停止信號
   參數: 無
 返回值: 無
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
   功能: noAck,用於連續讀取中的最後一個結束週期
   參數: 無
 返回值: 無
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
   功能: 寫入一個字節的數據到SCCB
   參數: 寫入數據
 返回值: 發送成功返回1，發送失敗返回0
-----------------------------------------------
*/
unsigned char SCCBwriteByte(unsigned char m_data)
{
	unsigned char j,tem;

	for(j=0;j<8;j++) //循環8次發送數據
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
	SCCB_SID_IN;/*設置SDA為輸入*/
	delay_us(500);
	SCCB_SIC_H();	
	delay_us(100);
	if(SCCB_SID_STATE){tem=0;}   //SDA=1發送失敗，返回0}
	else {tem=1;}   //SDA=0發送成功，返回1
	SCCB_SIC_L();	
	delay_us(500);	
        SCCB_SID_OUT;/*設置SDA為輸出*/

	return (tem);  
}

/*
-----------------------------------------------
   功能: 一個字節數據讀取並且返回
   參數: 無
 返回值: 讀取到的數據
-----------------------------------------------
*/
unsigned char SCCBreadByte(void)
{
	unsigned char read,j;
	read=0x00;
	
	SCCB_SID_IN;/*設置SDA為輸入*/
	delay_us(500);
	for(j=8;j>0;j--) //循環8次接收數據
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

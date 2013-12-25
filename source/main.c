/*******************************************************************************
*  Copyright (C) 2012 All Rights Reserved
*		
* ≥n•Ûß@™Ã:	√M≠∏Æa±⁄
* ™©≈v©“¶≥: √M≠∏πq§l	
* ≥–´ÿ§È¥¡:	2010¶~6§Î10§È 
* ≥n•Ûæ˙•v:	2010¶~11§Î2§È≠◊ßÔ
			2012¶~09§Î10§È≠◊ßÔ
* Version:  3.0 
* Demo ≤^ƒ_¶aß}°Ghttp://qifeidz.taobao.com
**********************************************************************************************************************************************
√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i
√i√i√i√i√i√i√i√i√i√i√i§@√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√ißx§@√i√i√i√i√i√i√i√i√i√i√i√i√i√i§@§@§@§@§@§@§@√i√i√i√i√i√i√i
√i√ißx§@§@§@§@√i§@§@§@§@§@§@§G√i√i√i√ißx§@§@§@§@§@§@§@§@√i√i√i√i√i√i√i√i√i•|ºF√i√i§@§@√i√i√i§@√i√i√i√i√i√i√i√i√i§@§@§@§@•|•|§@§@§@√i√i√i√i√i√i
√i√i√i√i√i√i§@√i√i√i§@§G§@√i√i√i√i√i√i§@§@§@§@•|ºF§G§@•|√i§@§@√i√i√i√i√i•|§@§@§@§@§@§@§@§@§@§@§@√i√i√i√i√i√i√i√i•|√i√i•|§@§@§@§@ºF√i√i√i√i√i√i
√i√i√i•|ºFºF§@√i√iºF√i√i√i•|√i√i√i√i√i√i√i√i√i√i√ißx§@√i§@§@√i√i√i√i√i√i√i§@§@ºFºF§@§@ºFºFºF§@§@√i√i√i√i√i√iºFºFºFºFºFºF§@§@ºFºFºF√i√i√i√i√i√i
√i√i√i§@√i§G§@§@§@§@§@§@§@§@§@§@§@√i√i√i√i√i√i√i√i§G§@§@ßx√i√i√i√i√i√i√i√i§@§@§@§@§@§@§@§@§@§@•|√i√i√i√i√i§@§@§@§@§@§@§@§@§@§@§@§@§@§@§@√i√i√i
√i√i√i§@§@§@§@§@ºF§G§@§@ºF§@√iºF√i√i√i√i√i√i√i√i√i§@§@§@§@§@√i√i√i√i√i√i√i§@§@√i√i§@§@√i√i√i§@ßx√i√i√i√i√i§@§@•|√i√i√i√i§@§@√i√ißx§@§@•|√i√i√i
√i√i√i√i√i√i√i§@ßx§@√i§@ºF§@√i√i√i√i√i√i√i√i√i√i√ißx§@√i√i§@§@√i√i√i√i√i√i§@§@§@§@§@§@§@§@§@§@ºF√i√i√i√i√i√i√i√i√i√i√i√i§@§@ºF√i√i√i√i√i√i√i√i
√i§G§@§@§@√i•|ßxºF§@§@§@ºF§@√i√i√i√i√i√i√i√i√i√i√i√i§@§@√i√i√i√i√i√i√i√i√i√i√i√i√i•|§@ºF√i√i√i√i√i√i§@√i√i√i√i√i√i√i√i√i§@§@ºF√i√i√i√i√i√i√i√i
√i√i√i√i√i√i§@√i√i√i√i√i§@§@√i√i√i√i√i√i√i√i√i√i√i√iºF§@§@§@§@§@§@ßx√i√i√i√i√i√i√i√i§@§@§@§@§@§@§@§@§@√i√i√i√i√ißx√i√iºF§@§@√i√i√i√i√i√i√i√i√i
√i√i√i√i§@§@§@√i√ißx§@§@§@§@√i√i√i√i√i√i√i√i√i√i√i√i√i√i§@§@§@§@§@√i√i√i√i√i√i√i√i√i√i§@§@§@§@§@§@§@√i√i√i√i√i√i√i§@§@§@§@•|√i√i√i√i√i√i√i√i√i
√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i√i
**********************************************************************************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_lib.h"
#include "ili9320.h"
#include "OV7670.h"
#include "delay.h"
#include <stdio.h>

ErrorStatus HSEStartUpStatus;

#define PIX_LONG     ((u32)0x12c00)

#define GUI_CONST_STORAGE const 
/* Private function prototypes -----------------------------------------------*/
void Demo_Init(void);
/* Private functions ---------------------------------------------------------*/


/*******************************************************************************
* Function Name  : main
* Description    : Main program
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/


int main(void)
{

    static unsigned long TimerCnt = 0;
    static unsigned int temp7670 = 0;					 
	u16 value,val,val1,val2;
	
	Demo_Init();
    ili9320_Initializtion();
    ili9320_Clear(0xffff);
    delay_ms(100);
 	ili9320_SetCursor(0,0);
    LCD_WriteReg(0x0050, 0);
    LCD_WriteReg(0x0052, 0);
    LCD_WriteReg(0x0051, 239);
    LCD_WriteReg(0x0053, 319);
    LCD_WriteRAM_Prepare(); // ∂}≈„¶s
	//delay_ms(10);   
	
	while(1!=OV7670_init());	
    while(1) 
    {
        TimerCnt = 0;
        temp7670 = 0;
        CLK_init_ON(); // OV7670 XCLK ∂}
        while(value & 0x0800)    value = GPIOC->IDR;   // Vsync=H    
        while((~value) & 0x0800) value = GPIOC->IDR;   // Vhync=L 
        
        CLK_init_OFF(); //OV7670 XCLK √ˆ
		while(TimerCnt < 76800)
        {
			XCLK_L; 
            XCLK_H;
			value = GPIOC->IDR;
			temp7670 ++;
            
			if(value & 0x0100) // HREF = H ||(LCD_PCLK_STATE)
            {	
			  	 //value = GPIOC->IDR;
			  	 //display[TimerCnt]=value; 
			  
			   if((temp7670 == 1))// ∞™¶r∏`||(value & 0x0200) ||(LCD_PCLK_STATE) 
                {
                  	val1=value& 0x00ff;

                }
                else // ßC¶r∏`	 if((temp7670 != 1)||(LCD_PCLK_STATE))  
                {
                   	val2= value<<8  ; 	 //
					val =ili9320_BGR2RGB(val1 |val2);
                    temp7670 = 0;
                    LCD_WriteRAM(val); //TFT GRAM º∆æ⁄
                    TimerCnt ++;
                }
            } 
		
				
		}
  }  
}


/*******************************************************************************
* Function Name  : Demo_Init
* Description    : Initializes the demonstration application.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void Demo_Init(void)
{
  /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration -----------------------------*/   
  /* RCC system reset(for debug purpose) */
  RCC_DeInit();

  /* Enable HSE */
  RCC_HSEConfig(RCC_HSE_ON);

  /* Wait till HSE is ready */
  HSEStartUpStatus = RCC_WaitForHSEStartUp();

  if(HSEStartUpStatus == SUCCESS)
  {
    /* Enable Prefetch Buffer */
    FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);

    /* Flash 2 wait state */
    FLASH_SetLatency(FLASH_Latency_2);
    
    /* HCLK = SYSCLK */
    RCC_HCLKConfig(RCC_SYSCLK_Div1); 
  
    /* PCLK2 = HCLK */
    RCC_PCLK2Config(RCC_HCLK_Div1); 
 
    /* PCLK1 = HCLK/2 */
    RCC_PCLK1Config(RCC_HCLK_Div2);
 
    /* PLLCLK = 8MHz * 9 = 72 MHz */
    RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_16);
 
    /* Enable PLL */ 
    RCC_PLLCmd(ENABLE);
 
    /* Wait till PLL is ready */
    while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
    {
    }
 
    /* Select PLL as system clock source */
    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
 
    /* Wait till PLL is used as system clock source */
    while(RCC_GetSYSCLKSource() != 0x08)
    {
    }
      /* Enable USART1 and GPIOA clock */
     RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);
  }

  /* Enable GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF, GPIOG and AFIO clocks */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB |RCC_APB2Periph_GPIOC 
         | RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE | RCC_APB2Periph_GPIOF | RCC_APB2Periph_GPIOG 
         | RCC_APB2Periph_AFIO, ENABLE);
 
/*------------------- Resources Initialization -----------------------------*/
     /* ADCCLK = PCLK2/8 */
   RCC_ADCCLKConfig(RCC_PCLK2_Div8);
    
    /* Enable DMA clock */
   RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

   /* Enable ADC1 and GPIOC clock */
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_ALL, ENABLE);

  /* If HSE is not detected at program startup */
  if(HSEStartUpStatus == ERROR)
  {
    /* Generate NMI exception */
    NVIC_SetSystemHandlerPendingBit(SystemHandler_NMI);
  }  
   

}


#ifdef  DEBUG
/*******************************************************************************
* Function Name  : assert_failed
* Description    : Reports the name of the source file and the source line number
*                  where the assert_param error has occurred.
* Input          : - file: pointer to the source file name
*                  - line: assert_param error line source number
* Output         : None
* Return         : None
*******************************************************************************/
void assert_failed(u8* file, u32 line)
{ 
    /* User can add his own implementation to report the file name and line number */
}
#endif


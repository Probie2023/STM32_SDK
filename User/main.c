/**
  ******************************************************************************
  * @file    main.c
  * @author  野火
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   STM32 SPI-FLASH USB MASS STORAGE 实验(模拟U盘)
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 F103-霸道 STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
  
#include "stm32f10x.h"
#include "./flash/fatfs_flash_spi.h"
#include "./usart/bsp_usart.h"	
#include "./led/bsp_led.h"  
#include "hw_config.h" 
#include "usb_lib.h"

int main(void)
{
	 /* USART config */
	USART_Config();
	
	LED_GPIO_Config();
	
	/*初始化*/
	Set_System();

	/*USB初始化*/
	ut_usb_test_entry();
 
}

/* -------------------------------------end of file -------------------------------------------- */

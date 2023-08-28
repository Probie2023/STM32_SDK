/**
  ******************************************************************************
  * @file    main.c
  * @author  Ұ��
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   STM32 SPI-FLASH USB MASS STORAGE ʵ��(ģ��U��)
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� F103-�Ե� STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
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
	
	/*��ʼ��*/
	Set_System();

	/*USB��ʼ��*/
	ut_usb_test_entry();
 
}

/* -------------------------------------end of file -------------------------------------------- */

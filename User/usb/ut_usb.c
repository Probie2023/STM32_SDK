/**
  ******************************************************************************
  * @file    usb_init.c
  * @author  MCD Application Team
  * @version V3.4.0
  * @date    29-June-2012
  * @brief   Initialization routines & global variables
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "usb_lib.h"
#include "hw_config.h"
#include "stm32f10x_rcc.h"
#include "usb_prop.h"
#include "led/bsp_led.h"  
#include "usb_pwr.h"
#include "usart/bsp_usart.h"	

/* Private macro -------------------------------------------------------------*/
#define TEST_USB_MSG

/*******************************************************************************
* Function Name  : Set_USBClock
* Description    : Configures USB Clock input (48MHz)
* Input          : None.
* Return         : None.
*******************************************************************************/
void Set_USBClock(void)
{

	RCC_USBCLKConfig(RCC_USBCLKSource_PLLCLK_1Div5);
	
	/* Enable the USB clock */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USB, ENABLE);

}

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/*  The number of current endpoint, it will be used to specify an endpoint */
uint8_t	EPindex;
/*  The number of current device, it is an index to the Device_Table */
/* uint8_t	Device_no; */
/*  Points to the DEVICE_INFO structure of current device */
/*  The purpose of this register is to speed up the execution */
DEVICE_INFO *pInformation;
/*  Points to the DEVICE_PROP structure of current device */
/*  The purpose of this register is to speed up the execution */
DEVICE_PROP *pProperty;
/*  Temporary save the state of Rx & Tx status. */
/*  Whenever the Rx or Tx state is changed, its value is saved */
/*  in this variable first and will be set to the EPRB or EPRA */
/*  at the end of interrupt process */
uint16_t	SaveState ;
uint16_t  wInterrupt_Mask;
DEVICE_INFO	Device_Info;
USER_STANDARD_REQUESTS  *pUser_Standard_Requests;

/* Extern variables ----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

static void USB_Delay(__IO uint32_t nCount)
{
	for(; nCount != 0; nCount--);
}

void usb_msg_test_entry()
{
	//u32 ret;
	MASS_init();

	while (bDeviceState != CONFIGURED);	 //等待配置完成
	   
	printf("\r\n 野火 F103-霸道 STM32 USB MASS STORAGE 实验\r\n");

	while (1)
	{
		LED2_TOGGLE;
		USB_Delay(0x0FFFFF);
	}

}


/*******************************************************************************
* Function Name  : USB_Init
* Description    : USB system initialization
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void ut_usb_test_entry(void)
{
	/*Set the USB clock to 48 MB*/
	Set_USBClock();

	/*Set USB interrupts (including SDIO interrupts)*/
	USB_Interrupts_Config();

	pInformation = &Device_Info;
	pInformation->ControlState = 2;
	pProperty = &Device_Property;
	pUser_Standard_Requests = &User_Standard_Requests;

	/* Initialize devices one by one */
	//pProperty->Init();

#ifdef TEST_USB_MSG
	usb_msg_test_entry();
#endif

#ifdef TEST_USB_CUSTOM
	usb_custom_test_entry();
#endif


}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

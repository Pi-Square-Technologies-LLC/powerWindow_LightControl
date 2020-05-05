/**
  ******************************************************************************
  * @file    main.c
  * @author  Auto-generated by STM32CubeIDE
  * @version V1.0
  * @brief   Default main function.
  ******************************************************************************
*/

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#include"main.h"

#define HIGH 					1
#define BTN_PRESSED 			LOW
static void GPIO_InOut_Init(void);
void delay(void)
{
	for(uint32_t i = 0; i < 500000; i++);
}

int main(void)
{
	GPIO_InOut_Init();
	RapidUpFrontLeftBtn();
	RapidUpDriverBtn();
	while(1);
	{
		LC_GlobeBoxStatus(1);
	}
}
static void GPIO_InOut_Init(void)
{
	GPIO_Handle_t GPIO_InStruct;
	/*GPIO ports clock enable*/
	GPIO_PCLK_Control(GPIOG, ENABLE);
	GPIO_PCLK_Control(GPIOD, ENABLE);
	GPIO_PCLK_Control(GPIOC, ENABLE);

	/*Configuring GPIO pin: PD12 PD13 PD14 PD15 */
	GPIO_InStruct.GPIO_PinConfig.GPIO_PinNumber 	 = GPIO_PIN_NO_12|GPIO_PIN_NO_13|GPIO_PIN_NO_14|GPIO_PIN_NO_15;
	GPIO_InStruct.GPIO_PinConfig.GPIO_PinMode 		 = GPIO_MODE_OUTPUT;  // GPIO output mode is configured as Output
	GPIO_InStruct.GPIO_PinConfig.GPIO_PinSpeed 		 = GPIO_SPEED_FAST;  // Fast Speed is Selected
	GPIO_InStruct.GPIO_PinConfig.GPIO_PinOPType 	 = GPIO_OUT_TYPE_PP;  // Push Pull Configuration
	GPIO_InStruct.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;    // No Pull Up or No Pull Down
	GPIO_Init(GPIOD,&GPIO_InStruct);

	/*Configuring GPIO pin: PC12 PC13 PC14 PC15 */
	GPIO_InStruct.GPIO_PinConfig.GPIO_PinNumber 	 = GPIO_PIN_NO_12|GPIO_PIN_NO_13|GPIO_PIN_NO_14|GPIO_PIN_NO_15;
	GPIO_InStruct.GPIO_PinConfig.GPIO_PinMode 		 = GPIO_MODE_OUTPUT;  // GPIO output mode is configured as Output
	GPIO_InStruct.GPIO_PinConfig.GPIO_PinSpeed  	 = GPIO_SPEED_FAST;  // Fast Speed is Selected
	GPIO_InStruct.GPIO_PinConfig.GPIO_PinOPType 	 = GPIO_OUT_TYPE_PP;  // Push Pull Configuration
	GPIO_InStruct.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;    // No Pull Up or No Pull Down
	GPIO_Init(GPIOC,&GPIO_InStruct);


	/*Configuring GPIO pin: PD0 PD1 PD2 PD3 PD4 PD5 PD6 PD7 */
		GPIO_InStruct.GPIO_PinConfig.GPIO_PinNumber 	= GPIO_PIN_NO_0|GPIO_PIN_NO_1|GPIO_PIN_NO_2|GPIO_PIN_NO_3|GPIO_PIN_NO_4|GPIO_PIN_NO_5|GPIO_PIN_NO_6|GPIO_PIN_NO_7;
	GPIO_InStruct.GPIO_PinConfig.GPIO_PinMode 			= GPIO_MODE_INPUT;  // GPIO output mode is configured as Output
	//GPIO_Input.GPIO_PinConfig.GPIO_PinSpeed			= GPIO_SPEED_FAST;  // Fast Speed is Selected
	//GPIO_Input.GPIO_PinConfig.GPIO_PinOPType 			= GPIO_OUT_TYPE_PP;  // Push Pull Configuration
	GPIO_InStruct.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_NO_PUPD;    // No Pull Up or No Pull Down
	GPIO_Init(GPIOD,&GPIO_InStruct);
}
void EXTI9_5_IRQHandler(void)
{
    //delay(); //200ms . wait till button de-bouncing gets over
	GPIO_IRQHandling(GPIO_PIN_NO_5); //clear the pending event from exti line
	LC_HeadLampStatus(1);
}

void EXTI0_IRQHandler(void)
{
    //delay(); //200ms . wait till button de-bouncing gets over
	GPIO_IRQHandling(GPIO_PIN_NO_0); //clear the pending event from exti line
	LC_ReadingLight(2);
}


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


void delay(void)
{
	for(uint32_t i = 0; i < 500000; i++);
}

int main(void)
{
	PCLK_Enable();
	GPIO_PW_Output_Init();
	GPIO_LC_Output_Init();
	GPIO_PW_Input_Init();
	GPIO_LC_Input_Init();

	while(1)
	{

	}
}

=======

void EXTI9_5_IRQHandler(void)
{
  	if(EXTI->PR & (1 << GPIO_PIN_NO_7))
	{
		GPIO_IRQHandling(GPIO_PIN_NO_7);
		LC_GlobeBoxStatus();
		//clear the pending event from exti line
	}
	if(EXTI->PR & (1 << GPIO_PIN_NO_8))
	{
		GPIO_IRQHandling(GPIO_PIN_NO_8);
		LC_FogLightStatus();
		 //clear the pending event from exti line
	}
	if(EXTI->PR & (1 << GPIO_PIN_NO_9))
	{
		GPIO_IRQHandling(GPIO_PIN_NO_9);
		LC_FogLightStatus();
		//clear the pending event from exti line
	}
}
void EXTI15_10_IRQHandler(void)
{
	if(EXTI->PR & (1 << GPIO_PIN_NO_10))
	{
		GPIO_IRQHandling(GPIO_PIN_NO_10);
		LC_GlobeBoxStatus();
		//clear the pending event from exti line
	}
	if(EXTI->PR & (1 << GPIO_PIN_NO_11))
	{
		GPIO_IRQHandling(GPIO_PIN_NO_10);
		LC_FogLightStatus();
		 //clear the pending event from exti line
	}
	if(EXTI->PR & (1 << GPIO_PIN_NO_12))
	{
		GPIO_IRQHandling(GPIO_PIN_NO_12);
		LC_FogLightStatus();
			//clear the pending event from exti line
	}
	if(EXTI->PR & (1 << GPIO_PIN_NO_13))
	{
		GPIO_IRQHandling(GPIO_PIN_NO_13);
		LC_FogLightStatus();
		//clear the pending event from exti line
	}
	if(EXTI->PR & (1 << GPIO_PIN_NO_14))
	{
		GPIO_IRQHandling(GPIO_PIN_NO_14);
		LC_FogLightStatus();
		//clear the pending event from exti line
	}
}
void PCLK_Enable(void)
{
	GPIO_PCLK_Control(GPIOA, ENABLE);
	GPIO_PCLK_Control(GPIOB, ENABLE);
	GPIO_PCLK_Control(GPIOC, ENABLE);
	GPIO_PCLK_Control(GPIOD, ENABLE);
	GPIO_PCLK_Control(GPIOE, ENABLE);
}

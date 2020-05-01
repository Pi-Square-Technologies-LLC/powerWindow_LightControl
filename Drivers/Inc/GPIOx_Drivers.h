/*
 * GPIOx_Drivers.h
 *
 *  Created on: Mar 14, 2020
 *      Author: vicky
 */

#ifndef INC_GPIOX_DRIVERS_H_
#define INC_GPIOX_DRIVERS_H_

#include"STM32F429xx.h"
/*
 * GPIOx Pin Configuration Structure
 */

typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;

/*
 * Handle Structure for a GPIO pin
 */


typedef struct
{
	GPIO_RegDef_t *pGPIOx;
	GPIO_PinConfig_t GPIO_PinConfig;


}GPIO_Handle_t;

/*
 * @GPIO_PIN_NUMBERS
 * GPIO pin numbers
 */
#define GPIO_PIN_NO_0						0
#define GPIO_PIN_NO_1						1
#define GPIO_PIN_NO_2						2
#define GPIO_PIN_NO_3						3
#define GPIO_PIN_NO_4						4
#define GPIO_PIN_NO_5						5
#define GPIO_PIN_NO_6						6
#define GPIO_PIN_NO_7						7
#define GPIO_PIN_NO_8						8
#define GPIO_PIN_NO_9						9
#define GPIO_PIN_NO_10						10
#define GPIO_PIN_NO_11						11
#define GPIO_PIN_NO_12						12
#define GPIO_PIN_NO_13						13
#define GPIO_PIN_NO_14						14
#define GPIO_PIN_NO_15						15



/*
 *  GPIOs Pin possible modes
 */

#define GPIO_MODE_INPUT						0
#define GPIO_MODE_OUTPUT					1
#define GPIO_MODE_ALTFN	  					2
#define GPIO_MODE_ANALOG					3
#define GPIO_MODE_IN_FT						4
#define GPIO_MODE_IN_RT						5
#define GPIO_MODE_IN_RFT					6

/*
 *  GPIOs Output types
 */

#define GPIO_OUT_TYPE_PP					0
#define GPIO_OUT_TYPE_OD					1


/*
 * GPIOs Speed modes
 */
#define GPIO_SPEED_LOW						0
#define GPIO_SPEED_MEDIUM					1
#define GPIO_SPEED_FAST						2
#define GPIO_SPEED_HIGH						3

/*
 * GPIOs Pin PullUp and PullDown Macros
 */

#define GPIO_NO_PUPD						0
#define GPIO_PIN_PU							1
#define GPIO_PIN_PD							2





/*****************************************************************************
 * 							APIs Supported by this driver
 *****************************************************************************/
/*
 * Peripheral Clock Setup
 */

void GPIO_PCLK_Control(GPIO_RegDef_t *pGPIOx, uint8_t EorDi);

/*
 * Init and DeInit
 */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * Reading From Pin and Port
 */

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t  GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);

/*
 * Writing to Pin and Port
 */

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);

/*
 * Toggle GPIO
 */

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*
 * IRQ Configuration and ISR Handling
 */

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void GPIO_IRQHandling(uint8_t PinNumber);



#endif /* INC_GPIOX_DRIVERS_H_ */

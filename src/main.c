/**
  ******************************************************************************
  * @file    main.c
  * @author  Huizhe Zheng
  * @version V1.0
  * @date    05-October-2019
  * @brief   UART intro project.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_usart.h"
#include <string.h>

#define NO_INTERRUPT
void USART2_IRQHandler(void);
void USART_PutChar(char c);
uint16_t USART_GetChar();
void USART_PutString(char *s);



void System_Init(void) {
	/* Enable clock for GPIOA and USART2 use function below
     * RCC_AHBxPeriphClockCmd();
     * RCC_APBxPeriphClockCmd();
     * USART_Cmd();
     */

    /* Write your code here */

	/**
	 * Tell pins PA2 and PA3 which alternating function you will use
	 * @important Make sure, these lines are before pins configuration!
     * Use GPIO_PinAFConfig();
	 */

    /* Write your code here */

	// Initialize GPIO pins as alternating function.
    GPIO_InitTypeDef GPIO_InitStruct;

    /* Write your code here */

	/**
	 * Set Baudrate to value you pass to function
	 * Disable Hardware Flow control
	 * Set Mode To TX and RX, so USART will work in full-duplex mode
	 * Disable parity bit
	 * Set 1 stop bit
	 * Set Data bits to 8
	 *
	 * Initialize USART2 Below
	 * Activate USART2
	 */
    USART_InitTypeDef USART_InitStruct;

    /* Write your code here */

#ifdef INTERRUPT_METHOD
	/** If you wanna more challenge, initialize the NVCR interrupt,
	 * The correspond function for this has been finished at the end of main.c, USART2_IRQHandler(void).
	 * Is just simply toggle the LED by send UART message from your laptop.
	 *
	 *
	 *
	 * Set Channel to USART2
	 * Set Channel Cmd to enable. That will enable USART2 channel in NVIC
	 * Set Both priorities to 0. This means high priority
	 * Initialize NVIC
	 * Enable RX interrupt
	 */

    /* Write your code here. USART_ITConfig */


	NVIC_InitTypeDef NVIC_InitStruct;
    /* Write your code here, write your init here*/


#endif

}

int main(void) {
	uint16_t c;
	System_Init();

#ifdef NO_INTERRUPT
	USART_PutString("Welcome to the UMSAE Software System\n\r");
	while (1) {
		/* Get character from internal buffer */
		c = USART_GetChar();
		if (c) {
			/* If anything received, put it back to terminal */
			USART_SendData(USART2, c);
		}
	}

#endif

#ifdef INTERRUPT_METHOD
	while (1) {

	}

#endif

}

void USART_PutChar(char c) {
// Wait until transmit data register is empty, use USART_GetFlagStatus to get register status


// Send a char using USART2 use USART_SendData()

}

uint16_t USART_GetChar() {
	// Wait until data is received use USART_GetFlagStatus();

	// Read received char use USART_ReceiveData

}

/*
 * This is just a simple Comp2160 function how to concat a bunch of chars to string
 */
void USART_PutString(char *s) {
	while (*s) {
		USART_PutChar(*s++);
	}
}


#ifdef INTERRUPT_METHOD
/**********************************************************
 * USART2 interrupt request handler: on reception of a
 * character 't', toggle LED and transmit a character 'T'
 *********************************************************/
void USART2_IRQHandler(void)
{
	/* RXNE handler */
	uint16_t c;;
	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
	{
		c = USART_GetChar();
		if (c) {
			/* If anything received, put it back to terminal */
			USART_SendData(USART2, c);
		}
	}
}
#endif

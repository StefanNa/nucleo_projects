/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_hal.h"
#include "string.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;
SPI_HandleTypeDef hspi2;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

int LED;
uint8_t lightAllLeds [28] ={0x96, 0xDF, 0xFF, 0xFF, 0x20, 0xFF, 0x20, 0xFF, 0x20, 0xFF, 0x20, 0xFF, 0x20, 0xFF, 0x20, 0xFF, 0x20, 0xFF, 0x20, 0xFF, 0x20, 0xFF, 0x20, 0xFF, 0x20, 0xFF,0x20,0xFF};
uint8_t lightNoLeds [28] ={0x96, 0xDF, 0xFF, 0xFF,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint8_t LEDinit [28];// ={0x96, 0xDF, 0xFF, 0xFF,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint8_t LED1 [28] ={0x96, 0xDF, 0xFF, 0xFF,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x20,0xFF};
uint8_t LED2 [28] ={0x96, 0xDF, 0xFF, 0xFF,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x20,0xFF,0,0};
uint8_t LED3 [28] ={0x96, 0xDF, 0xFF, 0xFF,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x20,0xFF,0,0,0,0};
uint8_t LED4 [28] ={0x96, 0xDF, 0xFF, 0xFF,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x20,0xFF,0,0,0,0,0,0};
uint8_t LED5 [28] ={0x96, 0xDF, 0xFF, 0xFF,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x20,0xFF,0,0,0,0,0,0,0,0};
uint8_t LED6 [28] ={0x96, 0xDF, 0xFF, 0xFF,0,0,0,0,0,0,0,0,0,0,0,0,0x20,0xFF,0,0,0,0,0,0,0,0,0,0};
uint8_t LED7 [28] ={0x96, 0xDF, 0xFF, 0xFF,0,0,0,0,0,0,0,0,0,0,0x20,0xFF,0,0,0,0,0,0,0,0,0,0,0,0};
uint8_t LED8 [28] ={0x96, 0xDF, 0xFF, 0xFF,0,0,0,0,0,0,0,0,0x20,0xFF,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint8_t LED9 [28] ={0x96, 0xDF, 0xFF, 0xFF,0,0,0,0,0,0,0x20,0xFF,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint8_t LED10 [28] ={0x96, 0xDF, 0xFF, 0xFF,0,0,0,0,0x20,0xFF,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	uint8_t lightUP [28]={150, 223, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};

	
	/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI2_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_SPI1_Init(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */
char MSG[30]; //indicates all is read
		char debug[30];
		
		void debug_array(uint8_t *LEDinit){
			sprintf(debug,"\n\rarray:\t");
			HAL_UART_Transmit(&huart1, (uint8_t *)debug, 30, 65);

			for(int pos=0; pos<28;pos++)
				{
					sprintf(debug,"%u\t",LEDinit[pos]);
			HAL_UART_Transmit(&huart1, (uint8_t *)debug, 30, 65);
				}
					sprintf(debug,"\n\r");
			HAL_UART_Transmit(&huart1, (uint8_t *)debug, 30, 65);
		}
		
		void AddOneLight(void)
		{
			uint8_t	LEDinit [28] ={0x96, 0xDF, 0xFF, 0xFF,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

		for(LED=0;LED<10;LED++)
			{
		LEDinit[27-LED*2]= 0xFF;
		LEDinit[26-LED*2]= 0x20;
				
		debug_array(LEDinit);
				
			sprintf(MSG, "\rLED nr. %i: %u\n\r", LED,LEDinit[28-LED*2]);
	HAL_UART_Transmit(&huart1, (uint8_t *)MSG, 30, 65);
			sprintf(MSG, "\rLED nr. %i: %u\n\r", LED,LEDinit[27-LED*2]);
	HAL_UART_Transmit(&huart1, (uint8_t *)MSG, 30, 65);
		
		HAL_SPI_Transmit(&hspi1, LEDinit, 28, 10);
			HAL_Delay(1000);
		}
}
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI2_Init();
  MX_USART2_UART_Init();
  MX_USART1_UART_Init();
  MX_SPI1_Init();

  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */
	sprintf(MSG, "\rLEDs will blink!\n\r");
	HAL_UART_Transmit(&huart1, (uint8_t *)MSG, 30, 65);

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
  /* USER CODE END WHILE */
//	char x[1];
//	HAL_UART_Receive(&huart1,x,1,HAL_MAX_DELAY);
//		
	sprintf(MSG, "\rstart SPI\n\r");
	HAL_UART_Transmit(&huart1, (uint8_t *)MSG, 30, 65);
	
		
	HAL_SPI_Transmit(&hspi1, lightAllLeds, 28, 10);
			HAL_Delay(1000);

	HAL_SPI_Transmit(&hspi1, lightNoLeds, 28, 10);
			HAL_Delay(1000);
	
	AddOneLight();
		
		
//		HAL_SPI_Transmit(&hspi1, LEDinit, 28, 10);
//			HAL_Delay(1000);
//	debug_array();
//		LED=0;
//		LEDinit[28-LED*2]= 0xFF;
//		LEDinit[27-LED*2]= 0;
//		debug_array();

//			sprintf(MSG, "\rLED nr. %i: %u\n\r", LED,LEDinit[28-LED*2]);
//	HAL_UART_Transmit(&huart1, (uint8_t *)MSG, 30, 65);
//			sprintf(MSG, "\rLED nr. %i: %u\n\r", LED,LEDinit[28-LED*2]);
//	HAL_UART_Transmit(&huart1, (uint8_t *)MSG, 30, 65);
//		
//		HAL_SPI_Transmit(&hspi1, LEDinit, 28, 10);
//			HAL_Delay(1000);
//		
//		LED=1;
//		LEDinit[28-LED*2]= 0xFF;
//		LEDinit[27-LED*2]= 0;
//			debug_array();

//			sprintf(MSG, "\rLED nr. %i: %u\n\r", LED,LEDinit[28-LED*2]);
//	HAL_UART_Transmit(&huart1, (uint8_t *)MSG, 30, 65);
//			sprintf(MSG, "\rLED nr. %i: %u\n\r", LED,LEDinit[28-LED*2]);
//	HAL_UART_Transmit(&huart1, (uint8_t *)MSG, 30, 65);
//		
//		HAL_SPI_Transmit(&hspi1, LEDinit, 28, 10);
//			HAL_Delay(1000);
//		
//		LED=2;
//		LEDinit[28-LED*2]= 0xFF;
//		LEDinit[27-LED*2]= 0;
//			sprintf(MSG, "\rLED nr. %i: %u\n\r", LED,LEDinit[28-LED*2]);
//	HAL_UART_Transmit(&huart1, (uint8_t *)MSG, 30, 65);
//			sprintf(MSG, "\rLED nr. %i: %u\n\r", LED,LEDinit[28-LED*2]);
//	HAL_UART_Transmit(&huart1, (uint8_t *)MSG, 30, 65);
//		
//		HAL_SPI_Transmit(&hspi1, LEDinit, 28, 10);
//			HAL_Delay(1000);
//			
//		LED=3;
//		LEDinit[28-LED*2]= 0xFF;
//		LEDinit[27-LED*2]= 0;
//			sprintf(MSG, "\rLED nr. %i: %u\n\r", LED,LEDinit[28-LED*2]);
//	HAL_UART_Transmit(&huart1, (uint8_t *)MSG, 30, 65);
//			sprintf(MSG, "\rLED nr. %i: %u\n\r", LED,LEDinit[28-LED*2]);
//	HAL_UART_Transmit(&huart1, (uint8_t *)MSG, 30, 65);
//		
//		HAL_SPI_Transmit(&hspi1, LEDinit, 28, 10);
//			HAL_Delay(1000);
//		
//		LED=4;
//		LEDinit[28-LED*2]= 0xFF;
//		LEDinit[27-LED*2]= 0x20;
//			sprintf(MSG, "\rLED nr. %i: %u\n\r", LED,LEDinit[28-LED*2]);
//	HAL_UART_Transmit(&huart1, (uint8_t *)MSG, 30, 65);
//			sprintf(MSG, "\rLED nr. %i: %u\n\r", LED,LEDinit[28-LED*2]);
//	HAL_UART_Transmit(&huart1, (uint8_t *)MSG, 30, 65);
//		
//		HAL_SPI_Transmit(&hspi1, LEDinit, 28, 10);
//			HAL_Delay(1000);
//			
//		LED=5;
//		LEDinit[28-LED*2]= 0xFF;
//		LEDinit[27-LED*2]= 0x20;
//			sprintf(MSG, "\rLED nr. %i: %u\n\r", LED,LEDinit[28-LED*2]);
//	HAL_UART_Transmit(&huart1, (uint8_t *)MSG, 30, 65);
//			sprintf(MSG, "\rLED nr. %i: %u\n\r", LED,LEDinit[28-LED*2]);
//	HAL_UART_Transmit(&huart1, (uint8_t *)MSG, 30, 65);
//		
//		HAL_SPI_Transmit(&hspi1, LEDinit, 28, 10);
//			HAL_Delay(1000);
//			
//		LED=6;
//		LEDinit[28-LED*2]= 0xFF;
//		LEDinit[27-LED*2]= 0x20;
//			sprintf(MSG, "\rLED nr. %i: %u\n\r", LED,LEDinit[28-LED*2]);
//	HAL_UART_Transmit(&huart1, (uint8_t *)MSG, 30, 65);
//			sprintf(MSG, "\rLED nr. %i: %u\n\r", LED,LEDinit[28-LED*2]);
//	HAL_UART_Transmit(&huart1, (uint8_t *)MSG, 30, 65);
//		
//		HAL_SPI_Transmit(&hspi1, LEDinit, 28, 10);
//			HAL_Delay(1000);
//			
//		LED=7;
//		LEDinit[28-LED*2]= 0xFF;
//		LEDinit[27-LED*2]= 0x20;
//			sprintf(MSG, "\rLED nr. %i: %u\n\r", LED,LEDinit[28-LED*2]);
//	HAL_UART_Transmit(&huart1, (uint8_t *)MSG, 30, 65);
//			sprintf(MSG, "\rLED nr. %i: %u\n\r", LED,LEDinit[28-LED*2]);
//	HAL_UART_Transmit(&huart1, (uint8_t *)MSG, 30, 65);
//		
//		HAL_SPI_Transmit(&hspi1, LEDinit, 28, 10);
//			HAL_Delay(1000);
//			
//		LED=8;
//		LEDinit[28-LED*2]= 0xFF;
//		LEDinit[27-LED*2]= 0x20;
//			sprintf(MSG, "\rLED nr. %i: %u\n\r", LED,LEDinit[28-LED*2]);
//	HAL_UART_Transmit(&huart1, (uint8_t *)MSG, 30, 65);
//			sprintf(MSG, "\rLED nr. %i: %u\n\r", LED,LEDinit[28-LED*2]);
//	HAL_UART_Transmit(&huart1, (uint8_t *)MSG, 30, 65);
//		
//		HAL_SPI_Transmit(&hspi1, LEDinit, 28, 10);
//			HAL_Delay(1000);
//			
//		LED=9;
//		LEDinit[28-LED*2]= 0xFF;
//		LEDinit[27-LED*2]= 0x20;
//			sprintf(MSG, "\rLED nr. %i: %u\n\r", LED,LEDinit[28-LED*2]);
//	HAL_UART_Transmit(&huart1, (uint8_t *)MSG, 30, 65);
//			sprintf(MSG, "\rLED nr. %i: %u\n\r", LED,LEDinit[28-LED*2]);
//	HAL_UART_Transmit(&huart1, (uint8_t *)MSG, 30, 65);
//				
//		HAL_SPI_Transmit(&hspi1, LEDinit, 28, 10);
//			HAL_Delay(1000);
  /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */

}
/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* SPI1 init function */
static void MX_SPI1_Init(void)
{

  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_1LINE;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_HIGH;
  hspi1.Init.CLKPhase = SPI_PHASE_2EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* SPI2 init function */
static void MX_SPI2_Init(void)
{

  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_HIGH;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* USART1 init function */
static void MX_USART1_UART_Init(void)
{

  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* USART2 init function */
static void MX_USART2_UART_Init(void)
{

  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

	
	  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pin : PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_7;
	
	
	
  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, CS4_Pin|CS3_Pin|CS9_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, CS8_Pin|CS7_Pin|CS2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, CS1_Pin|CS5_Pin|CS6_Pin|CS10_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : CS4_Pin CS3_Pin CS9_Pin */
  GPIO_InitStruct.Pin = CS4_Pin|CS3_Pin|CS9_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : CS8_Pin CS7_Pin CS2_Pin */
  GPIO_InitStruct.Pin = CS8_Pin|CS7_Pin|CS2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : CS1_Pin CS5_Pin CS6_Pin CS10_Pin */
  GPIO_InitStruct.Pin = CS1_Pin|CS5_Pin|CS6_Pin|CS10_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void _Error_Handler(char * file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler_Debug */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
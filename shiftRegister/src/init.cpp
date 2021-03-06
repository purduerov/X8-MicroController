<<<<<<< Updated upstream:shiftRegister/src/init.cpp
/*This folder will be used to hold all code used to initialize pins */

#include "init.h"
#include "stm32f4xx_hal.h"

//configures the system clcok
void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* Enable Power Control clock */
  __HAL_RCC_PWR_CLK_ENABLE();
  

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
  
  /* Enable HSI Oscillator and activate PLL with HSI as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 0x10;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 400;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;  
  if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

//function used to handle errors
void Error_Handler(void)
{
  while(1)
  {
  }
}
=======
<<<<<<< Updated upstream
//put all of your #includes into main.h file
#include "main.h"


/* structure used to initialize the gpio pin */
static GPIO_InitTypeDef  GPIO_InitStruct;


/* function declarations */
static void SystemClock_Config(void);
static void Error_Handler(void);

int main(void)  
{
	  //must be included to initially configure the library
	  HAL_Init();
	  
	  /* Configure the system clock to 100 MHz */
	  SystemClock_Config();
	  
	//enable the led clock
	 __HAL_RCC_GPIOD_CLK_ENABLE();
		
  
	  //configures the led pin  
	  GPIO_InitStruct.Pin = GPIO_PIN_5;  //pin 5
	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_PULLUP;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
	  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);  //initializes the pin A5 based on the settings your created earlier




	while (1)
	{

		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
		
	
		/* Insert a 500ms delay */
		HAL_Delay(500);
	}
}

//configures the system clcok
static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* Enable Power Control clock */
  __HAL_RCC_PWR_CLK_ENABLE();
  

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
  
  /* Enable HSI Oscillator and activate PLL with HSI as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 0x10;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 400;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;  
  if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

//function used to handle errors
static void Error_Handler(void)
{
  while(1)
  {
  }
}


=======
//put all of your #includes into main.h file

#include "main.h"







/* structure used to initialize the gpio pin */

static GPIO_InitTypeDef  GPIO_InitStruct;







/* function declarations */

static void SystemClock_Config(void);

static void Error_Handler(void);




int main(void)  

{

	  //must be included to initially configure the library

	  HAL_Init();

	  

	  /* Configure the system clock to 100 MHz */

	  SystemClock_Config();

	  

	//enable the led clock

	 __HAL_RCC_GPIOD_CLK_ENABLE();

		

  

	  //configures the led pin  

	  GPIO_InitStruct.Pin = GPIO_PIN_5;  //pin 5

	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;

	  GPIO_InitStruct.Pull = GPIO_PULLUP;

	  GPIO_InitStruct.Speed = GPIO_SPEED_FAST;

	  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);  //initializes the pin A5 based on the settings your created earlier













	while (1)

	{

		//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);

		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);

		

	

		/* Insert a 500ms delay */

		HAL_Delay(500);

	}

}




//configures the system clcok

static void SystemClock_Config(void)

{

  RCC_ClkInitTypeDef RCC_ClkInitStruct;

  RCC_OscInitTypeDef RCC_OscInitStruct;




  /* Enable Power Control clock */

  __HAL_RCC_PWR_CLK_ENABLE();

  




  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  

  /* Enable HSI Oscillator and activate PLL with HSI as source */

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;

  RCC_OscInitStruct.HSIState = RCC_HSI_ON;

  RCC_OscInitStruct.HSICalibrationValue = 0x10;

  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;

  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;

  RCC_OscInitStruct.PLL.PLLM = 16;

  RCC_OscInitStruct.PLL.PLLN = 400;

  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;

  RCC_OscInitStruct.PLL.PLLQ = 7;

  if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)

  {

    Error_Handler();

  }

  

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 

     clocks dividers */

  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);

  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;

  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;

  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;  

  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;  

  if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)

  {

    Error_Handler();

  }

}




//function used to handle errors

static void Error_Handler(void)

{

  while(1)

  {

  }

}
>>>>>>> Stashed changes
>>>>>>> Stashed changes:stm32cube_starter/main.cpp

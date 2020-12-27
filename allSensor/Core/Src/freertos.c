/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "hr04.h"
#include "dht11.h"
#include "light.h"
#include "main.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId HR04TaskHandle;
osThreadId DHT11TaskHandle;
osThreadId lightTask03Handle;
osThreadId peopleTask04Handle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartHR04Task(void const * argument);
void StartDHT11Task(void const * argument);
void StartLightTask03(void const * argument);
void StartPeopleTask04(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of HR04Task */
  osThreadDef(HR04Task, StartHR04Task, osPriorityBelowNormal, 0, 128);
  HR04TaskHandle = osThreadCreate(osThread(HR04Task), NULL);

  /* definition and creation of DHT11Task */
  osThreadDef(DHT11Task, StartDHT11Task, osPriorityHigh, 0, 128);
  DHT11TaskHandle = osThreadCreate(osThread(DHT11Task), NULL);

  /* definition and creation of lightTask03 */
  osThreadDef(lightTask03, StartLightTask03, osPriorityIdle, 0, 128);
  lightTask03Handle = osThreadCreate(osThread(lightTask03), NULL);

  /* definition and creation of peopleTask04 */
  osThreadDef(peopleTask04, StartPeopleTask04, osPriorityIdle, 0, 128);
  peopleTask04Handle = osThreadCreate(osThread(peopleTask04), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartHR04Task */
/**
  * @brief  Function implementing the HR04Task thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartHR04Task */
void StartHR04Task(void const * argument)
{
  /* USER CODE BEGIN StartHR04Task */
	double dist=0.0;
	//int i;
	printf("超声波传感器测试开始！\r\n");
  /* Infinite loop */
  for(;;)
  {
		printf("超声波传感器测试开始！\r\n");
    dist = Hcsr04_StateRead();
		printf("超声波测试距离是 :%f cm\r\n",dist);
		if(dist <= 20){
			HAL_GPIO_WritePin(BEEP_GPIO_Port,BEEP_Pin,GPIO_PIN_SET);			
		}
		else{
			HAL_GPIO_WritePin(BEEP_GPIO_Port,BEEP_Pin,GPIO_PIN_RESET);			
		}
		osDelay(2000);
  }
  /* USER CODE END StartHR04Task */
}

/* USER CODE BEGIN Header_StartDHT11Task */
/**
* @brief Function implementing the DHT11Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartDHT11Task */
void StartDHT11Task(void const * argument)
{
  /* USER CODE BEGIN StartDHT11Task */
	DHT11_Data_TypeDef DHT11_Data;
	printf("DHT11高精度温湿度传感器数据读取。\r\n"); 
	DHT11_Init();
  /* Infinite loop */
  for(;;)
  {
		
		printf("dht11传感器测试开始！\r\n");
    if(DHT11_Read_TempAndHumidity(&DHT11_Data)==SUCCESS)
    {
      printf("读取DHT11成功!-->湿度为%.1f ％RH ，温度为 %.1f℃ \n",DHT11_Data.humidity,DHT11_Data.temperature);
    }
    else
    {
      printf("读取DHT11信息失败\n");      
    }
    //HAL_Delay(3000);
		//vTaskDelay(100);
		osDelay(2000);
  }
  /* USER CODE END StartDHT11Task */
}

/* USER CODE BEGIN Header_StartLightTask03 */
/**
* @brief Function implementing the lightTask03 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartLightTask03 */
void StartLightTask03(void const * argument)
{
  /* USER CODE BEGIN StartLightTask03 */
	int light = 0;
  /* Infinite loop */
  for(;;)
  {
		printf("光照传感器测试开始！\r\n");
		light = get_light();
		printf("光照强度 :%d\r\n",light);
    osDelay(2000);
  }
  /* USER CODE END StartLightTask03 */
}

/* USER CODE BEGIN Header_StartPeopleTask04 */
/**
* @brief Function implementing the peopleTask04 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartPeopleTask04 */
void StartPeopleTask04(void const * argument)
{
  /* USER CODE BEGIN StartPeopleTask04 */
	int isPeople = 0;
  /* Infinite loop */
  for(;;)
  {
		printf("人体红外传感器测试开始！\r\n");
		if(HAL_GPIO_ReadPin(isPeople_GPIO_Port,isPeople_Pin)==1)
		{
			isPeople = 1;
		}
		else
		{
			isPeople = 0;
		}
		printf("是否有人 :%d\r\n",isPeople);
    osDelay(2000);
  }
  /* USER CODE END StartPeopleTask04 */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

/* ����ͷ�ļ� ----------------------------------------------------------------*/
#include "hr04.h"
#include "gpio.h"
#include "delay.h"
/* ˽�����Ͷ��� --------------------------------------------------------------*/
/* ˽�к궨�� ----------------------------------------------------------------*/
/* ˽�б��� ------------------------------------------------------------------*/
/* ��չ���� ------------------------------------------------------------------*/
/* ˽�к���ԭ�� --------------------------------------------------------------*/
/* ������ --------------------------------------------------------------------*/

/**
  * ��������: ��ȡ���ŵ�״̬
  * �����������
  * �� �� ֵ: ����
  * ˵    �����ޡ�
  */
double Hcsr04_StateRead(void)
{
	uint32_t distance = 0;
	
	HAL_GPIO_WritePin(TRIG_GPIO_Port, TRIG_Pin, GPIO_PIN_SET);
	
	Delay_us(10);
	
	HAL_GPIO_WritePin(TRIG_GPIO_Port, TRIG_Pin, GPIO_PIN_RESET);
	
	while(HAL_GPIO_ReadPin(ECHO_GPIO_Port,ECHO_Pin)==GPIO_PIN_RESET);
	
	while(HAL_GPIO_ReadPin(ECHO_GPIO_Port,ECHO_Pin)==GPIO_PIN_SET)
	{
		Delay_us(10);
		distance++;
	}
	
	return (distance/2)*0.34;
}

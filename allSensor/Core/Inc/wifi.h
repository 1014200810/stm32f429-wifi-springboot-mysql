/*
 * @Description: 
 * @Version: 2.0
 * @Autor: 葛璐豪
 * @Date: 2020-12-05 12:30:53
 * @LastEditors: Seven
 * @LastEditTime: 2020-12-05 12:56:48
 */
#ifndef _WIFI_H_
#define _WIFI_H_
#include "usart.h"
#include "string.h"
#include "stdio.h"

/* wifi 对应的串口 */
#define wifiUsart huart3
#define wifiInterrupt USART3

uint8_t wifi_config(void);
uint8_t wifi_sendCmd(char *cmd,int timeout);
uint8_t wifi_reset(int timeout);
#endif


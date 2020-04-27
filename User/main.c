/*
 * @Descripttion: 
 * @version: 
 * @Author: ��ĳ��
 * @Date: 2020-04-26 14:52:14
 * @LastEditors: ��ĳ��
 * @LastEditTime: 2020-04-26 21:39:32
 */

#include "stm32f4xx.h"
#include "bsp_led.h"
#include "bsp_uart_fifo.h"
#include "delay.h"
#include "bsp_timer.h"
#include "modbus_slave.h"
/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{
    delay_init();
    LED_GPIO_Config();
    bsp_InitUart();
    bsp_InitHardTimer();
    while (1)
    {
        MODS_Poll();
    }
}

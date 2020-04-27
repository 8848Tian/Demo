/*
 * @Descripttion: 
 * @version: 
 * @Author: 宣某人
 * @Date: 2020-04-26 14:52:14
 * @LastEditors: 宣某人
 * @LastEditTime: 2020-04-26 21:39:32
 */

#include "stm32f4xx.h"
#include "bsp_led.h"
#include "bsp_uart_fifo.h"
#include "delay.h"
#include "bsp_timer.h"
#include "modbus_slave.h"
/**
  * @brief  主函数
  * @param  无
  * @retval 无
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

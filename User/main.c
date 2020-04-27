/*
 * @Descripttion: 
 * @version: 
 * @Author:
 * @Date: 2020-04-26 14:52:14
 * @LastEditors: 宣某人
 * @LastEditTime: 2020-04-28 03:03:21
 */

#include "stm32f4xx.h"
#include "bsp_led.h"
#include "bsp_uart_fifo.h"
#include "delay.h"
#include "bsp_timer.h"
#include "modbus_slave.h"
/**
 * @name: 
 * @test: test font
 * @msg: 
 * @param {type} 
 * @return: 
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

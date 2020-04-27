# ifndef _DELAY_H
# define _DELAY_H
#include "stm32f4xx.h"

void delay_init(void);
void delay_us(uint16_t delay);
void delay_ms(uint16_t delay);

#endif


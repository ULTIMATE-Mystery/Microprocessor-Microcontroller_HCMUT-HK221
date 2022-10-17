/*
 * hardware_control.c
 *
 *  Author: Phạm Duy Quang
 */

#include "hardware_control.h"

void initGPIO()
{
  HAL_GPIO_WritePin(GPIOA, LED_RED_Pin | EN0_Pin | EN1_Pin, 1);
  HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin |
                           SEG3_Pin | SEG4_Pin | SEG5_Pin |
						   SEG6_Pin, 1);
}

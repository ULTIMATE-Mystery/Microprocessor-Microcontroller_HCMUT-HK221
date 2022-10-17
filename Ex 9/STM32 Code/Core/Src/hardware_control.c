/*
 * hardware_control.c
 *
 *  Author: Phạm Duy Quang
 */

#include "hardware_control.h"

/* init state of all GPIO */
void initGPIO()
{
  HAL_GPIO_WritePin(GPIOA, LED_RED_Pin | ENM0_Pin | ENM1_Pin |
                           ENM2_Pin | ENM3_Pin | ENM4_Pin |
						   ENM5_Pin | ENM6_Pin | ENM7_Pin |
						   DOT_Pin | EN0_Pin | EN1_Pin | EN2_Pin | EN3_Pin, 1);
  HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin |
                           SEG3_Pin | SEG4_Pin | SEG5_Pin |
						   SEG6_Pin | ROW0_Pin | ROW1_Pin |
						   ROW2_Pin | ROW3_Pin | ROW4_Pin |
						   ROW5_Pin | ROW6_Pin | ROW7_Pin, 1);
}

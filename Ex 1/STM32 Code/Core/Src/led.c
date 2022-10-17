/*
 * led.c
 *
 *  Author: Phạm Duy Quang
 */

#include "led.h"

int EN_state = 0;

/* 7SEGMENT Fuction */
void clear7SEG(){
	HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin |
			SEG3_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin, 1);
}
void display7SEG(int num){
	if(num >= 0 && num < 10){
		switch (num) {
			case 0:
				HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin |
										 SEG3_Pin | SEG4_Pin | SEG5_Pin, 0);
				break;
			case 1:
				HAL_GPIO_WritePin(GPIOB, SEG1_Pin | SEG2_Pin, 0);
				break;
			case 2:
				HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG3_Pin |
										 SEG4_Pin | SEG6_Pin, 0);
				break;
			case 3:
				HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin |
										 SEG3_Pin | SEG6_Pin, 0);
				break;
			case 4:
				HAL_GPIO_WritePin(GPIOB, SEG1_Pin | SEG2_Pin |
										 SEG5_Pin | SEG6_Pin, 0);
				break;
			case 5:
				HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG2_Pin |
										 SEG3_Pin | SEG5_Pin | SEG6_Pin, 0);
				break;
			case 6:
				HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG2_Pin | SEG3_Pin |
										 SEG4_Pin | SEG5_Pin | SEG6_Pin, 0);
				break;
			case 7:
				HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin, 0);
				break;
			case 8:
				HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin |
										 SEG3_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin, 0);
				break;
			case 9:
				HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin |
										 SEG3_Pin | SEG5_Pin | SEG6_Pin, 0);
				break;
		}
	}
}

/* Blink Led */
void blinkLED()
{
  HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
}

/* EN GPIO control */
void changeEN()
{
  switch (EN_state) {
	case 0:
	  EN_state = 1;
	  HAL_GPIO_TogglePin(GPIOA, EN0_Pin);
	  clear7SEG();
	  display7SEG(1);
	  break;
	case 1:
	  EN_state = 2;
	  HAL_GPIO_TogglePin(GPIOA, EN0_Pin | EN1_Pin);
	  clear7SEG();
	  display7SEG(2);
	  break;
	case 2:
	  EN_state = 1;
	  HAL_GPIO_TogglePin(GPIOA, EN0_Pin | EN1_Pin);
	  clear7SEG();
	  display7SEG(1);
	  break;
	default:
	  break;
}
}

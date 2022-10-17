/*
 * led.c
 *
 *  Author: Phạm Duy Quang
 */

#include "led.h"

int EN_state = 0; //Enable GPIO state

/* buffer variable */
const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {1 , 2 , 3 , 4};

/* clock variable */
int hour = 7, minute = 6, second = 56;

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
  HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin | DOT_Pin);
}

/* EN GPIO control */
void changeEN()
{
  switch (EN_state)
  {
	case 0:
	  EN_state = 1;
	  HAL_GPIO_TogglePin(GPIOA, EN0_Pin);
	  clear7SEG();
	  display7SEG(led_buffer[0]);
	  break;
	case 1:
	  EN_state = 2;
	  HAL_GPIO_TogglePin(GPIOA, EN0_Pin | EN1_Pin);
	  clear7SEG();
	  display7SEG(led_buffer[1]);
	  break;
	case 2:
	  EN_state = 3;
	  HAL_GPIO_TogglePin(GPIOA, EN1_Pin | EN2_Pin);
	  clear7SEG();
	  display7SEG(led_buffer[2]);
	  break;
	case 3:
	  EN_state = 4;
	  HAL_GPIO_TogglePin(GPIOA, EN2_Pin | EN3_Pin);
	  clear7SEG();
	  display7SEG(led_buffer[3]);
	  break;
	case 4:
	  EN_state = 1;
	  HAL_GPIO_TogglePin(GPIOA, EN3_Pin | EN0_Pin);
	  clear7SEG();
	  display7SEG(led_buffer[0]);
	  break;
	default:
	  break;
  }
}

/* display buffer */
void update7SEG(int index)
{
  switch (index)
  {
	case 0:
	  changeEN();
	  break;
	case 1:
	  changeEN();
	  break;
	case 2:
	  changeEN();
	  break;
	case 3:
      changeEN();
	  break;
	default:
	  break;
  }
}

/* update buffer */
void updateClockBuffer()
{
	led_buffer[0] = hour / 10;
	led_buffer[1] = hour % 10;
	led_buffer[2] = minute / 10;
	led_buffer[3] = minute % 10;
}

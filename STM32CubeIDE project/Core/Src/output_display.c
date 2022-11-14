/*
 * output_display.c
 *
 *  Created on: Nov 8, 2022
 *      Author: lephu
 */

#include "output_display.h"

/* Init -----*/
/* LED Pin */
uint16_t LED[NO_LED] = {RED1_Pin, YELLOW1_Pin, GREEN1_Pin,
                        RED2_Pin, YELLOW2_Pin, GREEN2_Pin};
/* EN Pin */
uint16_t EN[NO_EN] = {EN0_Pin, EN1_Pin, EN2_Pin, EN3_Pin};
/* LED 7SEG */
/* Register for num 0 to 9 for display 7SEG
 * num[0] = 0x003f
 * set a,b,c,d,e,f to 0 and g to 1
 */
uint16_t SEG7[10] = {0x003f, 0x0006, 0x005b, 0x004f, 0x0066,
		             0x006d, 0x007d, 0x0007, 0x007f, 0x006f};

uint16_t offSEG7[10] = {0x0040, 0x0079, 0x0024, 0x0030, 0x0019,
		             0x0012, 0x0002, 0x0078, 0x0000, 0x0010};
//LED 7SEG buffer
int SEG_buffer[4] = {0};
/* Function -----*/
/* LED */
//Turn on LED have "color"
void LED_on_road1(int color) {
  if(checkIndex(color, NO_COLOR)) {
	HAL_GPIO_WritePin(GPIOA, LED[color], 0);
	for(int i = 0; i < NO_COLOR; i++) {
	  if(i != color) {
	    HAL_GPIO_WritePin(GPIOA, LED[i], 1);
	  }
	}
  }
}
void LED_on_road2(int color) {
  if(checkIndex(color, NO_COLOR)) {
	HAL_GPIO_WritePin(GPIOA, LED[NO_COLOR + color], 0);
	for(int i = 0; i < NO_COLOR; i++) {
	  if(i != color) {
	    HAL_GPIO_WritePin(GPIOA, LED[NO_COLOR + i], 1);
	  }
	}
  }
}
//Turn off all LED
void LED_off(void) {
  for(int i = 0; i < NO_LED; i++) {
    HAL_GPIO_WritePin(GPIOA, LED[i], 1);
  }
}
/* EN */
//turn on EN[index] pin
void EN_on(int index) {
  for(int i = 0; i < NO_EN; i++) {
    if(i == index) {
      HAL_GPIO_WritePin(GPIOA, EN[i], 0);
    }
    else {
      HAL_GPIO_WritePin(GPIOA, EN[i], 1);
    }
  }
}
/* LED 7SEG */
//update LED 7SEG buffer
void updateBuffer(void) {
  SEG_buffer[0] = time_road1 / 10;
  SEG_buffer[1] = time_road1 % 10;
  SEG_buffer[2] = time_road2 / 10;
  SEG_buffer[3] = time_road2 % 10;
}
/* 7SEG LED control */
//display 7 SEGMENT LED
void display7SEG(int num) {
  if(checkIndex(num, 10)) {
	HAL_GPIO_WritePin(GPIOB, offSEG7[num], SET);
    HAL_GPIO_WritePin(GPIOB, SEG7[num], RESET);
  }
}

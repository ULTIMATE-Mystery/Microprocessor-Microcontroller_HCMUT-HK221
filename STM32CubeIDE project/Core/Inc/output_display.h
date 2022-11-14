/*
 * output_display.h
 *
 *  Created on: Nov 8, 2022
 *      Author: lephu
 */

#ifndef INC_OUTPUT_DISPLAY_H_
#define INC_OUTPUT_DISPLAY_H_

/* Include -----*/
#include "main.h"
#include "stdint.h"
#include "global.h"

/* Init -----*/
extern int SEG_buffer[4];

/* Function -----*/
/* LED */
//Turn on LED have "color"
void LED_on_road1(int color);
void LED_on_road2(int color);
//Turn off all LED
void LED_off(void);
/* EN */
//turn on EN[index] pin
void EN_on(int index);
/* LED 7SEG */
//update LED 7SEG buffer
void updateBuffer(void);
//display 7 SEGMENT LED
void display7SEG(int num);

#endif /* INC_OUTPUT_DISPLAY_H_ */

/*
 * led.h
 *
 *  Author: Phạm Duy Quang
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "main.h"

extern int EN_state;

void clear7SEG();
void display7SEG(int num);
void blinkLED();
void changeEN();

#endif /* INC_LED_H_ */

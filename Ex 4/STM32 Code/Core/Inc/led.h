/*
 * led.h
 *
 *  Author: Phạm Duy Quang
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "main.h"

extern int EN_state;
extern const int MAX_LED;
extern int index_led;
extern int led_buffer[4];

void clear7SEG();
void display7SEG(int num);
void blinkLED();
void changeEN();
void update7SEG(int index);

#endif /* INC_LED_H_ */

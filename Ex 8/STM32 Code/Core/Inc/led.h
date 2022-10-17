/*
 * led.h
 *
 *  Author: Phạm Duy Quang
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "main.h"

extern int hour;
extern int minute;
extern int second;

void clear7SEG();
void display7SEG(int num);
void initState();
void clearEN();
void openEN(int state);
void displayClock(int hour, int minute);
void blinkLED();
void updateClockBuffer();
#endif /* INC_LED_H_ */

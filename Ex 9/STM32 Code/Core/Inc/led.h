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
extern uint8_t matrix_buffer[8];

void clear7SEG();
void display7SEG(int num);
void initState();
void clearEN();
void openEN(int state);
void displayClock(int hour, int minute);
void blinkLED();
void updateClockBuffer();
void getBuffer(uint8_t buffer);
void openENM(int index);
void clearENM();
#endif /* INC_LED_H_ */

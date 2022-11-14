/*
 * timer_interrupt.h
 *
 *  Created on: Nov 8, 2022
 *      Author: lephu
 */

#ifndef INC_TIMER_INTERRUPT_H_
#define INC_TIMER_INTERRUPT_H_

/* Includes -----*/
#include "global.h"

/* Define -----*/
//Timer index description
#define EN_TIMER 0
#define ROAD1_TIMER 1
#define ROAD2_TIMER 2
#define CLOCK_TIMER1 3
#define CLOCK_TIMER2 4
#define MODE1_TIMER 5
#define BLINK_TIMER 6

/* Function -----*/
//Set time on timer[index] = duration
void setTimer(int duration, int index);
//Check timer out on timer[index]
int isTimerOut(int index);
//Run timer (counter on timer)
void timerRun(void);

#endif /* INC_TIMER_INTERRUPT_H_ */

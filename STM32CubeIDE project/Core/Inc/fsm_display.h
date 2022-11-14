/*
 * fsm_display.h
 *
 *  Created on: Nov 9, 2022
 *      Author: lephu
 */

#ifndef INC_FSM_DISPLAY_H_
#define INC_FSM_DISPLAY_H_

/* Include -----*/
#include "global.h"
#include "output_display.h"
#include "timer_interrupt.h"

/* Function -----*/
//Set restart 7SEG display
void restartDisplay(void);
//7SEG LED display
void fsm_display(void);
//Blinky LED have 'color'
void blinkLED(int color);
#endif /* INC_FSM_DISPLAY_H_ */

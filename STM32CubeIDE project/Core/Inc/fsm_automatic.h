/*
 * fsm_automatic.h
 *
 *  Created on: Nov 9, 2022
 *      Author: lephu
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

/* Include -----*/
#include "global.h"
#include "output_display.h"
#include "timer_interrupt.h"

/* Function -----*/
void fsm_auto_road1(void);
void fsm_auto_road2(void);
//Set state to INIT
void setInit(void);
#endif /* INC_FSM_AUTOMATIC_H_ */

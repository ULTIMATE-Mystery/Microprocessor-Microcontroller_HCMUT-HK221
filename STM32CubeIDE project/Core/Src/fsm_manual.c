/*
 * fsm_manual.c
 *
 *  Created on: Nov 9, 2022
 *      Author: lephu
 */

#include "fsm_manual.h"

/* Define -----*/
//State of fsm
#define MODE1 1
#define MODE2 2
#define MODE3 3
#define MODE4 4
//Time for fsm
#define RETURN_MODE1 10000

/* Init -----*/
int status_manual = MODE1;

/* Function ----*/
//Auto return to MODE1
void returnMODE1(void) {
  status_manual = MODE1;
  setInit();
}
//Increasing time
void inc_time(void) {
  time_road2++;
  if(time_road2 > 99) {
    time_road2 = 0;
  }
}
//state machine
void fsm_manual(void) {
  switch(status_manual) {
  case MODE1:
    fsm_auto_road1();
    fsm_auto_road2();
    if(isButtonPressed(SELECT_BUTTON) == 1) {
      status_manual = MODE2;
      time_road1 = MODE2;
      time_road2 = time_red;
      restartDisplay();
      setTimer(RETURN_MODE1, MODE1_TIMER);
    }
    break;
  case MODE2:
	blinkLED(RED);
	if(isButtonPressed(SELECT_BUTTON) == 1) {
	  status_manual = MODE3;
	  time_road1 = MODE3;
	  time_road2 = time_yellow;
      restartDisplay();
	  setTimer(RETURN_MODE1, MODE1_TIMER);
	}
	if(isButtonPressed(MODIFY_BUTTON) == 1) {
	  inc_time();
	  setTimer(RETURN_MODE1, MODE1_TIMER);
	}
	if(isButtonPressed(SET_BUTTON) == 1) {
	  time_red = time_road2;
	  setTimer(RETURN_MODE1, MODE1_TIMER);
	}
	if(isTimerOut(MODE1_TIMER) == 1) {
	  restartDisplay();
	  returnMODE1();
	}
	break;
  case MODE3:
	blinkLED(YELLOW);
	if(isButtonPressed(SELECT_BUTTON) == 1) {
	  status_manual = MODE4;
	  time_road1 = MODE4;
	  time_road2 = time_green;
      restartDisplay();
	  setTimer(RETURN_MODE1, MODE1_TIMER);
	}
	if(isButtonPressed(MODIFY_BUTTON) == 1) {
	  inc_time();
	  setTimer(RETURN_MODE1, MODE1_TIMER);
	}
	if(isButtonPressed(SET_BUTTON) == 1) {
	  time_yellow = time_road2;
	  setTimer(RETURN_MODE1, MODE1_TIMER);
	}
	if(isTimerOut(MODE1_TIMER) == 1) {
	  restartDisplay();
	  returnMODE1();
	}
	break;
  case MODE4:
	blinkLED(GREEN);
	if(isButtonPressed(SELECT_BUTTON) == 1) {
	  status_manual = MODE1;
      restartDisplay();
	  setInit();
	}
	if(isButtonPressed(MODIFY_BUTTON) == 1) {
	  inc_time();
	  setTimer(RETURN_MODE1, MODE1_TIMER);
	}
	if(isButtonPressed(SET_BUTTON) == 1) {
	  time_green = time_road2;
	  setTimer(RETURN_MODE1, MODE1_TIMER);
	}
	if(isTimerOut(MODE1_TIMER) == 1) {
	  restartDisplay();
	  returnMODE1();
	}
	break;
  }
}

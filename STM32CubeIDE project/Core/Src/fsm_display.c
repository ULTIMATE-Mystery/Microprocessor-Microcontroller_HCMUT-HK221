/*
 * fsm_display.c
 *
 *  Created on: Nov 9, 2022
 *      Author: lephu
 */

#include "fsm_display.h"

/* Define -----*/
//State of 7SEG display fsm
#define INIT 0
#define EN0 1
#define EN1 2
#define EN2 3
#define EN3 4
//state for blink LED fsm
#define LED_ON 1
#define LED_OFF 2
//Time
#define SCANNING_TIME 250
#define BLINK_TIME 500

/* Init ------*/
int status_display = INIT;
int status_blink = INIT;

/* Function -----*/
//Set restart 7SEG display
void restartDisplay(void) {
  status_display = INIT;
}
//7SEG LED display
void fsm_display(void) {
  updateBuffer();
  switch(status_display) {
  case INIT:
    status_display = EN0;
    setTimer(SCANNING_TIME, EN_TIMER);
    break;
  case EN0:
    EN_on(EN0 - 1);
    display7SEG(SEG_buffer[EN0 - 1]);
    if(isTimerOut(EN_TIMER) == 1) {
      status_display = EN1;
      setTimer(SCANNING_TIME, EN_TIMER);
    }
    break;
  case EN1:
	EN_on(EN1 - 1);
    display7SEG(SEG_buffer[EN1 - 1]);
	if(isTimerOut(EN_TIMER) == 1) {
	  status_display = EN2;
	  setTimer(SCANNING_TIME, EN_TIMER);
	}
	break;
  case EN2:
	EN_on(EN2 - 1);
    display7SEG(SEG_buffer[EN2 - 1]);
	if(isTimerOut(EN_TIMER) == 1) {
	  status_display = EN3;
	  setTimer(SCANNING_TIME, EN_TIMER);
	}
	break;
  case EN3:
	EN_on(EN3 - 1);
    display7SEG(SEG_buffer[EN3 - 1]);
	if(isTimerOut(EN_TIMER) == 1) {
	  status_display = EN0;
	  setTimer(SCANNING_TIME, EN_TIMER);
	}
	break;
  }
}
//Blinky LED have 'color'
void blinkLED(int color) {
  switch(status_blink) {
  case INIT:
    status_blink = LED_ON;
    setTimer(BLINK_TIME, BLINK_TIMER);
    break;
  case LED_ON:
	LED_on_road1(color);
	LED_on_road2(color);
	if(isTimerOut(BLINK_TIMER) == 1) {
	  status_blink = LED_OFF;
	  setTimer(BLINK_TIME, BLINK_TIMER);
	}
	break;
  case LED_OFF:
	LED_off();
	if(isTimerOut(BLINK_TIMER) == 1) {
	  status_blink = LED_ON;
	  setTimer(BLINK_TIME, BLINK_TIMER);
	}
	break;
  }
}

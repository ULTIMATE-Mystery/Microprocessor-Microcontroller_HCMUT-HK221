/*
 * fsm_manual.c
 *
 *  Created on: Oct 7, 2022
 *      Author: LENOVO
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch(status){
	case MAN_RED:
		if(timer1_flag == 1){
			status = AUTO_RED;
			setTimer1(RED_TIME);
		}
		if(button1_flag == 1){
			clearTimer1();
			status = MAN_GREEN;
			setTimer1(1000);
		}
		break;
	case MAN_GREEN:
		if(timer1_flag == 1){
			status = AUTO_GREEN;
			setTimer1(GREEN_TIME);
		}
		if(button1_flag == 1){
			clearTimer1();
			status = MAN_YELLOW;
			setTimer1(1000);
		}
		break;
	case MAN_YELLOW:
		if(timer1_flag == 1){
			status = AUTO_YELLOW;
			setTimer1(YELLOW_TIME);
		}
		if(button1_flag == 1){
			clearTimer1();
			status = MAN_RED;
			setTimer1(1000);
		}
		break;
	default:

		break;
	}
}

/*
 * fsm.c
 *
 *  Created on: Sep 30, 2022
 *      Author: LENOVO
 */


#include "fsm.h"

void fsm_automatic_run(){
	switch(status){
	case INIT:
		if(timer1_flag == 1){
			status = AUTO_RED;
			setTimer1(500);
		}
		break;
	case AUTO_RED:
		if(timer1_flag == 1){
			//TODO
			status = AUTO_GREEN;
			setTimer1(300);
		}
		if(button1_flag == 1){
			button1_flag = 0;
			//TODO
			status = MAN_RED;
			setTimer1(1000);
		}
		break;
	case AUTO_GREEN:
		if(timer1_flag == 1){
			status = AUTO_YELLOW;
			setTimer1(200);
		}
		break;
	case AUTO_YELLOW:
		//TODO
		if(timer1_flag == 1){
			status = AUTO_RED;
			// set timer for next
			setTimer1(500); //Nho dinh nghia hang so o global
		}
		break;
	default:
		break;
	}
}

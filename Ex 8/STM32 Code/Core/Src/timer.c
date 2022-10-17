/*
 * timer.c
 *
 *  Author: Phạm Duy Quang
 */

#include "timer.h"

int EN_counter = 0;
int LED_counter = 0;
int EN_flag = 0;
int LED_flag = 0;

void setTimer_EN(int duration){
	EN_counter = duration / 10;
	EN_flag = 0;
}
void setTimer_LED(int duration){
	LED_counter = duration / 10;
	LED_flag = 0;
}
void timerRun(){
	if(EN_counter > 0){
		EN_counter--;
		if(EN_counter <= 0){
			EN_flag = 1;
		}
	}
	if(LED_counter > 0){
		LED_counter--;
		if(LED_counter <= 0){
			LED_flag = 1;
		}
	}
}

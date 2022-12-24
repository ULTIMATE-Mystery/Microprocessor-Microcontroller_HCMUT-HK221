
#include"software_timer.h"

int timer_flag = 0;
int counter = 0;

void setTimer(int duration){
	counter = duration / PERIOD;
	timer_flag = 0;
}

void timerRun(){
	if (counter > 0){
		counter--;
		if (counter <= 0){
			timer_flag = 1;
		}
	}
}

int flagRaised(){
	return timer_flag;
}

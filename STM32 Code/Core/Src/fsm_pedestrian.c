
#include "fsm_pedestrian.h"

int PWM = 0;

void fsm_pedestrian_run(){
	switch(pedestrianStatus) {
		case INIT:
			clearPedestrian();
			pedestrianStatus = PED_NONE;
			break;
		case PED_NONE:
			if(isButtonPressed(0)){
				if(status == AUTO_RED_GREEN || status == AUTO_RED_YELLOW){
					pedestrianStatus = PED_GREEN;
					setPedestrianGreen();
					setTimer2(250);
				}
				else if (status == AUTO_GREEN_RED || status == AUTO_YELLOW_RED){
					pedestrianStatus = PED_RED;
					setPedestrianRed();
				}
			}
			break;
		case PED_RED:
			if(timer2_flag){
				timer2_flag = 0;
				pedestrianStatus = PED_NONE;
				clearPedestrian();
				break;
			}
			else if(status == AUTO_RED_GREEN){
				pedestrianStatus = PED_GREEN;
				setPedestrianGreen();
				setTimer2(250);
			}
			break;
		case PED_GREEN:
			if(timer2_flag){
				if(PWM == 0){
					PWM = 63-63*counter/(double)max_red1;
					__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,PWM);
				} else {
					PWM = 0;
					__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,PWM);
				}
				setTimer2(250);
			}
			if(status == AUTO_GREEN_RED || status == AUTO_YELLOW_RED){
				pedestrianStatus = PED_RED;
				setTimer2(2000);
				setPedestrianRed();
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,0);
			}
			break;
		default:
			break;
	}
}

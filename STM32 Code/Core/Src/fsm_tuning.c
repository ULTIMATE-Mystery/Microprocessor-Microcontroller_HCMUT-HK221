
#include "fsm_tuning.h"

void fsm_tuning_run(){
	switch(status){
	case TUNING_RED1:

		if(timer1_flag){
			timer1_flag = 0;
			setTimer1(500);
			toggleTraffic1Red();
		}

		if(isButtonPressed(1)){
			status = AUTO_RED_GREEN;
			acceptTraffic1Red();
			setTimer1(1000);
			counter = max_red1;
			displayCounter();
			setTraffic1Red();
			setTraffic2Green();
			break;
		}

		if(isButtonPressed(2)){
			status = TUNING_RED2;
			setTimer1(1000);
			acceptTraffic1Red();
			counter = max_red2;
			displayCounter();
			clearTraffic1();
			clearTraffic2();
			break;
		}

		if(isButtonPressed(3)){
			counter++;
			if(counter > 99){
				counter = 2;
			}
			displayCounter();
		}

		break;
	case TUNING_RED2:
		if(timer1_flag){
			timer1_flag = 0;
			setTimer1(500);
			toggleTraffic2Red();
		}

		if(isButtonPressed(1)){
			acceptTraffic2Red();
			status = AUTO_RED_GREEN;
			setTimer1(1000);
			counter = max_red1;
			displayCounter();
			setTraffic2Red();
			setTraffic2Green();
			break;
		}

		if(isButtonPressed(2)){
			status = TUNING_GREEN1;
			setTimer1(1000);
			acceptTraffic2Red();
			counter = max_green1;
			displayCounter();
			clearTraffic1();
			clearTraffic2();
			break;
		}

		if(isButtonPressed(3)){
			counter++;
			if(counter > 99){
				counter = 2;
			}
			displayCounter();
		}
		break;
	case TUNING_GREEN1:

		if(timer1_flag){
			timer1_flag = 0;
			setTimer1(500);
			toggleTraffic1Green();
		}

		if(isButtonPressed(1)){
			acceptTraffic1Green();
			status = AUTO_RED_GREEN;
			setTimer1(1000);
			counter = max_red1;
			displayCounter();
			setTraffic1Red();
			setTraffic2Green();
			break;
		}

		if(isButtonPressed(2)){
			status = TUNING_GREEN2;
			setTimer1(1000);
			acceptTraffic1Green();
			counter = max_green2;
			displayCounter();
			clearTraffic1();
			clearTraffic2();
			break;
		}

		if(isButtonPressed(3)){
			counter++;
			if(counter == max_red2){
				counter = 1;
			}
			displayCounter();
		}
		break;
	case TUNING_GREEN2:

		if(timer1_flag){
			timer1_flag = 0;
			setTimer1(500);
			toggleTraffic2Green();
		}

		if(isButtonPressed(1)){
			status = AUTO_RED_GREEN;
			acceptTraffic2Green();
			setTimer1(1000);
			counter = max_red1;
			displayCounter();
			setTraffic1Red();
			setTraffic2Green();
			break;
		}

		if(isButtonPressed(2)){
			status = TUNING_YELLOW1;
			setTimer1(1000);
			acceptTraffic2Green();
			counter = max_yellow1;
			displayCounter();
			clearTraffic1();
			clearTraffic2();
			break;
		}

		if(isButtonPressed(3)){
			counter++;
			if(counter == max_red1){
				counter = 1;
			}
			displayCounter();
		}
		break;
	case TUNING_YELLOW1:
		if(timer1_flag){
			timer1_flag = 0;
			setTimer1(500);
			toggleTraffic1Yellow();
		}
		if(isButtonPressed(1)){
			status = AUTO_RED_GREEN;
			acceptTraffic1Yellow();
			setTimer1(1000);
			counter = max_red1;
			displayCounter();
			setTraffic1Red();
			setTraffic2Green();
			break;
		}

		if(isButtonPressed(2)){
			status = TUNING_YELLOW2;
			setTimer1(1000);
			acceptTraffic1Yellow();
			counter = max_yellow2;
			displayCounter();
			clearTraffic1();
			clearTraffic2();
			break;
		}

		if(isButtonPressed(3)){
			counter++;
			if(counter == max_red2){
				counter = 1;
			}
			displayCounter();
		}
		break;
	case TUNING_YELLOW2:
		if(timer1_flag){
			timer1_flag = 0;
			setTimer1(500);
			toggleTraffic2Yellow();
		}

		if(isButtonPressed(1)){
			status = AUTO_RED_GREEN;
			acceptTraffic2Yellow();
			setTimer1(1000);
			counter = max_red1;
			displayCounter();
			setTraffic1Red();
			setTraffic2Green();
			break;
		}

		if(isButtonPressed(2)){
			status = TUNING_RED1;
			setTimer1(1000);
			acceptTraffic2Yellow();
			counter = max_red1;
			displayCounter();
			clearTraffic1();
			clearTraffic2();
			break;
		}

		if(isButtonPressed(3)){
			counter++;
			if(counter == max_red1){
				counter = 1;
			}
			displayCounter();
		}
		break;
	default:
		break;
	}
}

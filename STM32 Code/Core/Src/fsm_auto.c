

#include "fsm_auto.h"

void fsm_auto_run(){
	switch (status)
	{
	case INIT:
		status=AUTO_RED_GREEN;
		setTimer1(1000);
		counter = max_red1;
		displayCounter();
		setTraffic1Red();
		setTraffic2Green();
		break;
	case AUTO_RED_GREEN:
		if(timer1_flag == 1){
			counter--;
			setTimer1(1000);
			if(counter == max_yellow2){
				setTraffic2Yellow();
				status=AUTO_RED_YELLOW;
			}
			displayCounter();
		}

		if(isButtonPressed(1)){
			//isButtonPressed(2);
			//isButtonPressed(3);
			status=MAN_RED_GREEN;
			setTimer1(30000);
			setTraffic1Red();
			setTraffic2Green();
			counter = 0;
			displayCounter();
			break;
		}
		break;
	case AUTO_RED_YELLOW:
		if(timer1_flag == 1){
			counter--;
			setTimer1(1000);
			if(counter == 0){
				counter = max_green1;
				setTraffic1Green();
				setTraffic2Red();
				status=AUTO_GREEN_RED;
			}
			displayCounter();
		}

		if(isButtonPressed(1)){
			//isButtonPressed(2);
			//isButtonPressed(3);
			status=MAN_RED_GREEN;
			setTimer1(30000);
			setTraffic1Red();
			setTraffic2Green();
			counter = 0;
			displayCounter();
			break;
		}
		break;

	case AUTO_GREEN_RED:
		if(timer1_flag == 1){
			counter--;
			setTimer1(1000);
			if(counter == 0){
				counter = max_yellow1;
				setTraffic1Yellow();
				status=AUTO_YELLOW_RED;
			}
			displayCounter();
		}

		if(isButtonPressed(1)){
			//isButtonPressed(2);
			//isButtonPressed(3);
			status=MAN_RED_GREEN;
			setTimer1(30000);
			setTraffic1Red();
			setTraffic2Green();
			counter = 0;
			displayCounter();
			break;
		}
		break;

	case AUTO_YELLOW_RED:

		if(timer1_flag == 1){
			counter--;
			setTimer1(1000);
			if(counter == 0){
				counter = max_red1;
				setTraffic1Red();
				setTraffic2Green();
				status=AUTO_RED_GREEN;
			}
			displayCounter();
		}

		if(isButtonPressed(1)){
			//isButtonPressed(2);
			//isButtonPressed(3);
			status=MAN_RED_GREEN;
			setTimer1(30000);
			setTraffic1Red();
			setTraffic2Green();
			counter = 0;
			displayCounter();
			break;
		}
		break;
	}

}


#include "fsm_manual.h"

void fsm_manual_run(){
	switch (status) {
		case MAN_RED_GREEN:
			isButtonPressed(3);
			if(timer1_flag) {
				status = AUTO_RED_YELLOW;
				setTimer1(1000);
				counter = max_yellow2;
				displayCounter();
				setTraffic1Red();
				setTraffic2Yellow();
			}

			if(isButtonPressed(1)){
				isButtonPressed(2);
				status = TUNING_RED1;
				setTimer1(1000);
				counter = max_red1;
				displayCounter();
				clearTraffic1();
				clearTraffic2();
				break;
			}

			if (isButtonPressed(2)) {
				status = MAN_RED_YELLOW;
				setTraffic1Red();
				setTraffic2Yellow();
				setTimer1(60000);
			}
			break;

		case MAN_RED_YELLOW:
			isButtonPressed(3);
			if(timer1_flag) {
				status = AUTO_GREEN_RED;
				setTimer1(1000);
				counter = max_green1;
				displayCounter();
				setTraffic1Green();
				setTraffic2Red();
			}

			if(isButtonPressed(1)) {
				isButtonPressed(2);
				status = TUNING_RED1;
				setTimer1(1000);
				counter = max_red1;
				displayCounter();
				clearTraffic1();
				clearTraffic2();
				isButtonPressed(2);
			}

			if (isButtonPressed(2)) {
				status = MAN_GREEN_RED;
				setTraffic1Green();
				setTraffic2Red();
				setTimer1(60000);
			}


			break;

		case MAN_GREEN_RED:
			isButtonPressed(3);
			if(timer1_flag) {
				status = AUTO_YELLOW_RED;
				setTimer1(1000);
				counter = max_yellow1;
				displayCounter();
				setTraffic1Yellow();
				setTraffic2Red();
			}

			if(isButtonPressed(1)) {
				isButtonPressed(2);
				status = TUNING_RED1;
				setTimer1(1000);
				counter = max_red1;
				displayCounter();
				clearTraffic1();
				clearTraffic2();
				isButtonPressed(2);
			}

			if (isButtonPressed(2)) {
				status = MAN_YELLOW_RED;
				setTraffic1Yellow();
				setTraffic2Red();
				setTimer1(60000);
			}

			break;

		case MAN_YELLOW_RED:
			isButtonPressed(3);
			if(timer1_flag) {
				status = AUTO_RED_GREEN;
				setTimer1(1000);
				counter = max_red1;
				displayCounter();
				setTraffic1Red();
				setTraffic2Green();
			}

			if(isButtonPressed(1)) {
				isButtonPressed(2);
				status = TUNING_RED1;
				setTimer1(1000);
				counter = max_red1;
				displayCounter();
				clearTraffic1();
				clearTraffic2();
				break;
			}

			if (isButtonPressed(2)) {
				status = MAN_RED_GREEN;
				setTraffic1Red();
				setTraffic2Green();
				setTimer1(60000);
			}


			break;
		default:
			break;
	}
}



#include "traffic.h"

void setTraffic1Red(){
	HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_RESET);

}

void setTraffic2Red(){
	HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_RESET);
}

void setTraffic1Green(){
	HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_SET);
}

void clearTraffic1(){
	HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_RESET);
}


void setTraffic2Green(){
	HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_SET);
}

void setTraffic1Yellow(){
	HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_SET);
}

void setTraffic2Yellow(){
	HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_SET);
}

void clearTraffic2(){
	HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_RESET);
}

void setPedestrianRed(){
	HAL_GPIO_WritePin(PedestrianLight_0_GPIO_Port, PedestrianLight_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(PedestrianLight_1_GPIO_Port, PedestrianLight_1_Pin, GPIO_PIN_RESET);
}

void setPedestrianGreen(){
	HAL_GPIO_WritePin(PedestrianLight_0_GPIO_Port, PedestrianLight_0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(PedestrianLight_1_GPIO_Port, PedestrianLight_1_Pin, GPIO_PIN_SET);
}

void setPedestrianYellow(){
	HAL_GPIO_WritePin(PedestrianLight_0_GPIO_Port, PedestrianLight_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(PedestrianLight_1_GPIO_Port, PedestrianLight_1_Pin, GPIO_PIN_SET);
}

void clearPedestrian(){
	HAL_GPIO_WritePin(PedestrianLight_0_GPIO_Port, PedestrianLight_0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(PedestrianLight_1_GPIO_Port, PedestrianLight_1_Pin, GPIO_PIN_RESET);
}

void toggleTraffic1Red(){
	// Only use when led is clear or red.
	HAL_GPIO_TogglePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin);
}

void toggleTraffic2Red(){
	// Only use when led is clear or red.
	HAL_GPIO_TogglePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin);
}

void toggleTraffic1Green(){
	// Only use when led is clear or green.
	HAL_GPIO_TogglePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin);
}

void toggleTraffic2Green(){
	// Only use when led is clear or green.
	HAL_GPIO_TogglePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin);
}

void toggleTraffic1Yellow(){
	// Only use when led is clear or yellow.
	HAL_GPIO_TogglePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin);
	HAL_GPIO_TogglePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin);
}

void toggleTraffic2Yellow(){
	// Only use when led is clear or yellow.
	HAL_GPIO_TogglePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin);
	HAL_GPIO_TogglePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin);
}

void acceptTraffic1Red(){
	max_red1 = counter;
	if(max_red1 <= max_yellow2) max_yellow2 = 1;
	max_green2 = max_red1 - max_yellow2;
}

void acceptTraffic2Red(){
	max_red2 = counter;
	if(max_red2 <= max_yellow1) max_yellow1 = 1;
	max_green1 = max_red2 - max_yellow1;
}

void acceptTraffic1Green(){
	max_green1 = counter;
	max_yellow1 = max_red2 - max_green1;
}

void acceptTraffic2Green(){
	max_green2 = counter;
	max_yellow2 = max_red1 - max_green2;
}

void acceptTraffic1Yellow(){
	max_yellow1 = counter;
	max_green1 = max_red2 - max_yellow1;
}

void acceptTraffic2Yellow(){
	max_yellow2 = counter;
	max_green2 = max_red1 - max_yellow2;
}

void displayCounter(){
	sprintf(str, "!7SEG:%d%d#", counter/10, counter%10);
	HAL_UART_Transmit_IT(&huart2, (void*)str, 9);
}

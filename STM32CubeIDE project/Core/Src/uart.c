
#include "uart.h"

uint8_t temp = 0;
uint32_t ADC_value = 0;
uint8_t buffer_flag = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;

int uart_status = IDLE;

void uart_communication_fsm(){
	switch(uart_status){
	case IDLE:
		if (cmd_flag == FLAG_1){		//RST
			uart_status = SEND;
			HAL_ADC_Start(&hadc1);
			ADC_value = HAL_ADC_GetValue(&hadc1);
		}
		break;
	case SEND:
		if (cmd_flag == FLAG_1){
			HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "!ADC=%d#\r\n", ADC_value), 1000);
			HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			uart_status = LOOP;
			setTimer(3000);
		}
		else if (cmd_flag == FLAG_2){	//OK
			uart_status = IDLE;
		}
		break;
	case LOOP:
		if (flagRaised()){
			HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "!ADC=%d#\r\n", ADC_value), 1000);
			HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			uart_status = LOOP;
			setTimer(3000);
		}
		if (cmd_flag == FLAG_2){
			uart_status = IDLE;
		}
		break;
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if (huart->Instance == USART2){
//		HAL_UART_Transmit(&huart2, &temp, 1, 50);
		buffer[index_buffer++] = temp;
		if (index_buffer == 30) index_buffer = 0;
		buffer_flag = 1;
		HAL_UART_Receive_IT(&huart2, &temp, 1);
	}
}

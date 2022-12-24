
#include "command.h"

char str[30];

int cmd_status = CM_START;
int cmd_flag = CM_INIT;

void command_parser_fsm(){
	switch(cmd_status){
	case CM_START:
		if (buffer[index_buffer-1] == '!'){
			HAL_UART_Transmit(&huart2, &buffer[index_buffer-1], 1, 50);
			cmd_status = CM_FIRST;
		}
		break;
	case CM_FIRST:
		if (buffer[index_buffer-1] == '!'){
			cmd_status = CM_FIRST;
		}
		else if (buffer[index_buffer-1] == 'R' || buffer[index_buffer-1] == 'r'){
			HAL_UART_Transmit(&huart2, &buffer[index_buffer-1], 1, 50);
			cmd_status = CM_R;
		}
		else if (buffer[index_buffer-1] == 'O' || buffer[index_buffer-1] == 'o'){
			HAL_UART_Transmit(&huart2, &buffer[index_buffer-1], 1, 50);
			cmd_status = CM_O;
		}
		else cmd_status = CM_START;
		break;
	case CM_R:
		if (buffer[index_buffer-1] == 'R' || buffer[index_buffer-1] == 'r'){
			cmd_status = CM_R;
		}
		else if (buffer[index_buffer-1] == 'S' || buffer[index_buffer-1] == 's'){
			HAL_UART_Transmit(&huart2, &buffer[index_buffer-1], 1, 50);
			cmd_status = CM_S;
		}
		else cmd_status = CM_START;
		break;
	case CM_S:
		if (buffer[index_buffer-1] == 'S' || buffer[index_buffer-1] == 's'){
			cmd_status = CM_S;
		}
		else if (buffer[index_buffer-1] == 'T' || buffer[index_buffer-1] == 't'){
			HAL_UART_Transmit(&huart2, &buffer[index_buffer-1], 1, 50);
			cmd_status = CM_T;
		}
		else cmd_status = CM_START;
		break;
	case CM_T:
		if (buffer[index_buffer-1] == 'T' || buffer[index_buffer-1] == 't'){
			cmd_status = CM_T;
		}
		else if (buffer[index_buffer-1] == '#'){
			HAL_UART_Transmit(&huart2, &buffer[index_buffer-1], 1, 50);
			cmd_status = CM_RST_FINISHED;
		}
		else cmd_status = CM_START;
		break;
	case CM_RST_FINISHED:
		HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "\r\n"), 1000);
		cmd_flag = FLAG_1;
		cmd_status = CM_START;
		break;
	case CM_O:
		if (buffer[index_buffer-1] == 'O' || buffer[index_buffer-1] == 'o'){
			cmd_status = CM_O;
		}
		else if (buffer[index_buffer-1] == 'K' || buffer[index_buffer-1] == 'k'){
			HAL_UART_Transmit(&huart2, &buffer[index_buffer-1], 1, 50);
			cmd_status = CM_K;
		}
		else cmd_status = CM_START;
		break;
	case CM_K:
		if (buffer[index_buffer-1] == 'K' || buffer[index_buffer-1] == 'k'){
			cmd_status = CM_K;
		}
		else if (buffer[index_buffer-1] == '#'){
			HAL_UART_Transmit(&huart2, &buffer[index_buffer-1], 1, 50);
			cmd_status = CM_OK_FINISHED;
		}
		else cmd_status = CM_START;
		break;
	case CM_OK_FINISHED:
		HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "\r\n"), 1000);
		cmd_flag = FLAG_2;
		cmd_status = CM_START;
		break;
	}
}

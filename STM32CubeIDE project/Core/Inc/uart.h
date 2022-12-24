
#ifndef INC_UART_H_
#define INC_UART_H_

#include "global.h"

#define MAX_BUFFER_SIZE	30

#define	IDLE	0
#define	SEND	1
#define LOOP	2

extern int uart_status;
extern uint8_t temp;
extern uint8_t buffer_flag;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;

void uart_communication_fsm();
void HAL_UART_RxCpltCallback(UART_HandleTypeDef*);

#endif /* INC_UART_H_ */

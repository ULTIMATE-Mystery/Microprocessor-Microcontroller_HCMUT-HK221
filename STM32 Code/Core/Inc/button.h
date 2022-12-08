

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "timer.h"

#define NO_OF_BUTTONS 4
#define TIME_OUT_FOR_KEY_PRESSED 200
#define WAITING_TIME 1000

#define PRESSED_STATE 0
#define RELEASED_STATE 1

#define BUTTON_IS_PRESSED 11
#define BUTTON_IS_RELEASED 12
#define BUTTON_IS_LONG_PRESSED 13

void button_reading();
void button_process(int);
int isButtonPressed(int);

#endif /* INC_BUTTON_H_ */

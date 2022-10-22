/*
 * button.h
 *
 *  Created on: Sep 24, 2022
 *      Author: LENOVO
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"


#define NORMAL_STATE SET
#define PRESSED_STATE RESET

extern int button1_flag;
void getKeyInput();

#endif /* INC_BUTTON_H_ */

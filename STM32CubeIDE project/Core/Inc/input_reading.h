/*
 * input_reading.h
 *
 *  Created on: Nov 9, 2022
 *      Author: lephu
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

/* Include -----*/
#include "global.h"
#include "stdint.h"
#include "main.h"

/* Define -----*/
#define SELECT_BUTTON 0
#define MODIFY_BUTTON 1
#define SET_BUTTON 2

/* Function -----*/
/* Button reading and debounce */
//debounce button
void getKeyInput();

/* Check button is pressed or not
 * Check button[index]
 */
int isButtonPressed(int index);

#endif /* INC_INPUT_READING_H_ */

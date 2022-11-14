/*
 * global.h
 *
 *  Created on: Nov 8, 2022
 *      Author: lephu
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

/* Traffic Time ----- */
extern int time_road1;
extern int time_road2;
extern int time_red;
extern int time_yellow;
extern int time_green;

/* Timer -----*/
#define NO_Timer 7 //Number of timer
#define TIME_CYCLE 10 //Time Cycle = 10ms
#define TIME_UNIT 1000 //1s = 1000ms

/* LED -----*/
#define NO_LED 6 //Number of LED
#define NO_EN 4 //Number of 7SEG LED
/* Color */
#define NO_COLOR 3
#define RED 0
#define YELLOW 1
#define GREEN 2

/* BUTTON -----*/
#define NO_BUTTON 3

/* Function -----*/
//Check index (0 <= Index < max)
int checkIndex(int index, int max);

#endif /* INC_GLOBAL_H_ */

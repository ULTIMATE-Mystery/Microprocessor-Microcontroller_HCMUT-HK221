/*
 * software_timer.h
 *
 *  Created on: Oct 7, 2022
 *      Author: LENOVO
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag; //Check if timer timeout. Extern khong khoi tao
extern int timer2_flag;
void setTimer1(int duration);
void timerRun();
void clearTimer1();
void setTimer2(int duration);


#endif /* INC_SOFTWARE_TIMER_H_ */

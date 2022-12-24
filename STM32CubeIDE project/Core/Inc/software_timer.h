
#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "global.h"

#define PERIOD	10

extern int timer_flag;

void setTimer(int);
void timerRun();
int flagRaised();

#endif /* INC_SOFTWARE_TIMER_H_ */

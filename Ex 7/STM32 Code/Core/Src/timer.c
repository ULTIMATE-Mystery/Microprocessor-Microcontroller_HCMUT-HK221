/*
 * timer.c
 *
 *  Author: Phạm Duy Quang
 */

#include "timer.h"

int clock_flag = 0;
int clock_timer = 0;

void setTimer(int duration)
{
	clock_timer = duration / 10;
	clock_flag = 0;
}

void timerRun()
{
	if(clock_timer > 0)
	{
		clock_timer--;
		if(clock_timer <= 0)
		{
			clock_timer = 0;
			clock_flag = 1;
		}
	}
}

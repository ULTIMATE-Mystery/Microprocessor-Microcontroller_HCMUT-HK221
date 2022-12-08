
#include "scheduler.h"

sTask SCH_tasks_G[SCH_MAX_TASKS];

void SCH_Init(void){
	unsigned char i;
	for(i = 0; i < SCH_MAX_TASKS; i++){
		SCH_Delete_Task(i);
	}
}

void SCH_Update(void){
	uint32_t index;
	for(index = 0; index < SCH_MAX_TASKS; index++){
		if(SCH_tasks_G[index].pTask){
			if(SCH_tasks_G[index].Delay > 0){
				SCH_tasks_G[index].Delay--;
			} else {
				SCH_tasks_G[index].RunMe += 1;
				SCH_tasks_G[index].Delay = SCH_tasks_G[index].Period;
			}
		}
	}
}

uint32_t SCH_Add_Task(void(*pFunc)(), uint32_t delay, uint32_t period){
	uint32_t index = 0;
	while(SCH_tasks_G[index].pTask != 0 && index < SCH_MAX_TASKS) index++;
	if(index == SCH_MAX_TASKS){
		return SCH_MAX_TASKS;
	}
	SCH_tasks_G[index].pTask = pFunc;
	SCH_tasks_G[index].Period = period/TIMER_CYCLE;
	SCH_tasks_G[index].Delay = delay;
	SCH_tasks_G[index].RunMe = 0;
	SCH_tasks_G[index].TaskID = index;
	return index;
}

void SCH_Dispatch_Tasks(void){
	for(int index = 0; index < SCH_MAX_TASKS; index++){
		if(SCH_tasks_G[index].RunMe > 0){
			SCH_tasks_G[index].RunMe--;
			(*SCH_tasks_G[index].pTask)();
			if(SCH_tasks_G[index].Period == 0) SCH_Delete_Task(index);
		}
	}
	SCH_Go_To_Sleep();
}

uint8_t SCH_Delete_Task(uint32_t index){
	if(SCH_tasks_G[index].pTask == 0){
		return 0;
	} else {
		SCH_tasks_G[index].pTask = 0;
		SCH_tasks_G[index].Delay = 0;
		SCH_tasks_G[index].Period = 0;
		SCH_tasks_G[index].RunMe = 0;
		return 1;
	}
}

void SCH_Go_To_Sleep(void){
	HAL_SuspendTick();
	HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);
//	HAL_ResumeTick();
}

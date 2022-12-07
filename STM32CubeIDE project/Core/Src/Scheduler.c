
#include "scheduler.h"

sTasks SCH_tasks_G[SCH_MAX_TASKS];


void SCH_Init(void){
	for(int i = 0; i < SCH_MAX_TASKS; i++){
		SCH_Delete_Task(i);
	}
}

unsigned char SCH_Add_Task ( void (*pFunction)() , uint32_t DELAY, uint32_t PERIOD){
	unsigned char Index = 0;
	/* Find valid index to insert task */
	while((SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS)){
		Index++;
	}
	/* Check the valid index */
	if(Index == SCH_MAX_TASKS){
		return Index;
	}
	/* Add task */
	SCH_tasks_G[Index].pTask = pFunction;
	SCH_tasks_G[Index].Delay = DELAY;
	SCH_tasks_G[Index].Period = PERIOD;
	SCH_tasks_G[Index].RunMe = 0;
	/* Return position of task */
	return Index;

}
void SCH_Update(void){
	unsigned char Index;

	for(Index = 0; Index < SCH_MAX_TASKS; Index++){
		/* Check if there is a task in this index */
		if(SCH_tasks_G[Index].pTask){
			if(SCH_tasks_G[Index].Delay == 0){
				/* Inc. the RunMe flag */
				SCH_tasks_G[Index].RunMe += 1;
				if(SCH_tasks_G[Index].Period){
					/* Schedule periodic tasks to run again */
					SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
				}
			}
			else{
				SCH_tasks_G[Index].Delay--;
				if(SCH_tasks_G[Index].Delay == 0){
					/* Inc. the RunMe flag */
					SCH_tasks_G[Index].RunMe += 1;
					if(SCH_tasks_G[Index].Period){
						/* Schedule periodic tasks to run again */
						SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
					}
				}
			}
		}
	}
}
void SCH_Dispatch_Tasks(void){
	unsigned char Index;
	/* Dispatches next task */
	for(Index = 0; Index < SCH_MAX_TASKS; Index++){
		if(SCH_tasks_G[Index].RunMe > 0){
			/* Run the task */
			(*SCH_tasks_G[Index].pTask) ();
			/* Reduce RunMe flag */
			SCH_tasks_G[Index].RunMe -= 1;
			/* Remove one-shot task */
			if(SCH_tasks_G[Index].Period == 0){
				SCH_Delete_Task(Index);
			}
		}
	}
}
void SCH_Delete_Task(uint32_t ID){
	if(SCH_tasks_G[ID].pTask != 0){
		SCH_tasks_G[ID].pTask = 0x0000;
		SCH_tasks_G[ID].Delay = 0;
		SCH_tasks_G[ID].Period = 0;
		SCH_tasks_G[ID].RunMe = 0;
	}
}

/*
 * Scheduler.c
 *
 *  Created on: Nov 16, 2022
 *      Author: lephu
 */


#include "Scheduler.h"

typedef struct {
  void (*pTask)();
  uint32_t Delay;
  uint32_t Period;
  uint32_t RunMe;
  uint32_t TaskID;
}sTask;

#define SCH_MAX_TASKS 5

sTask SCH_tasks_G[SCH_MAX_TASKS];
uint32_t current_index_task = 0;

void SCH_Init(void) {
  current_index_task = 0;
}

void SCH_Update(void) {
  for(int i = 0; i < current_index_task; i++) {
    if(SCH_tasks_G[i].Delay > 0) {
      SCH_tasks_G[i].Delay--;
    }
    else {
      SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
      SCH_tasks_G[i].RunMe++;
    }
  }
}

void SCH_Add_Task(void (*pFunction)(), uint32_t Delay, uint32_t Period) {
  if(current_index_task < SCH_MAX_TASKS) {
    SCH_tasks_G[current_index_task].pTask = pFunction;
    SCH_tasks_G[current_index_task].Delay = Delay;
    SCH_tasks_G[current_index_task].Period = Period;
    SCH_tasks_G[current_index_task].RunMe = 0;
    SCH_tasks_G[current_index_task].TaskID = current_index_task;

    current_index_task++;
  }
}

void SCH_Dispatch_Tasks(void) {
  for(int i = 0; i < current_index_task; i++) {
    if(SCH_tasks_G[i].RunMe > 0) {
      SCH_tasks_G[i].RunMe--;
      (*SCH_tasks_G[i].pTask)();
      if(SCH_tasks_G[i].Period == 0)
    	  SCH_Delete_Task(i);
    }
  }
}
void SCH_Delete_Task(uint32_t ID)
{
  if(ID < current_index_task - 1)
  {
	for(int i = ID; i < current_index_task - 1; i++)
	{
		SCH_tasks_G[i].pTask = SCH_tasks_G[i].pTask;
		SCH_tasks_G[i].Delay = SCH_tasks_G[i].Delay;
		SCH_tasks_G[i].Period = SCH_tasks_G[i].Period;
		SCH_tasks_G[i].RunMe = SCH_tasks_G[i].RunMe;
		SCH_tasks_G[i].TaskID = SCH_tasks_G[i].TaskID;
	}
  }
  current_index_task--;
}

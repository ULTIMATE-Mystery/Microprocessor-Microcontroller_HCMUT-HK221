/*
 * Scheduler.h
 *
 *  Created on: Nov 16, 2022
 *      Author: lephu
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "stdint.h"

void SCH_Init(void);
void SCH_Update(void);
void SCH_Add_Task(void (*pFunction)(), uint32_t Delay, uint32_t Period);
void SCH_Dispatch_Tasks(void);
void SCH_Delete_Task(uint32_t ID);

#endif /* INC_SCHEDULER_H_ */


#ifndef INC_COMMAND_H_
#define INC_COMMAND_H_

#include "global.h"

#define 	CM_INIT					0
#define 	CM_START				1
#define		CM_FIRST				2

#define		CM_R					3
#define 	CM_S					4
#define 	CM_T					5
#define		CM_RST_FINISHED			6

#define		CM_O					13
#define 	CM_K					14
#define		CM_OK_FINISHED			15

#define		FLAG_1					21		//RST
#define		FLAG_2					22		//OK

extern int cmd_flag;
extern int cmd_status;

void command_parser_fsm();

#endif /* INC_COMMAND_H_ */

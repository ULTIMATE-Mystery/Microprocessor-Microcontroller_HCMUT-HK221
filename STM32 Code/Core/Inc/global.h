

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "timer.h"
#include "main.h"
#include "button.h"
#include "traffic.h"
#include "scheduler.h"

#define	INIT			1
#define	AUTO_RED_GREEN	2
#define	AUTO_RED_YELLOW	3
#define	AUTO_GREEN_RED	4
#define	AUTO_YELLOW_RED	5

#define	MAN_RED_GREEN	11
#define	MAN_RED_YELLOW	12
#define	MAN_GREEN_RED	13
#define	MAN_YELLOW_RED	14

#define	TUNING_RED1		21
#define	TUNING_RED2		22
#define	TUNING_GREEN1	23
#define	TUNING_GREEN2	24
#define	TUNING_YELLOW1	25
#define	TUNING_YELLOW2	26

#define	PED_NONE	2
#define PED_RED		3
#define PED_GREEN	4

extern int status;
extern int pedestrianStatus;
extern int counter;

extern int max_red1;
extern int max_green1;
extern int max_yellow1;

extern int max_red2;
extern int max_green2;
extern int max_yellow2;

extern char str[];

extern int ped_red_flag;
extern int ped_green_flag;

#endif /* INC_GLOBAL_H_ */

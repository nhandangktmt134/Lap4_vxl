/*
 * Scheduler.h
 *
 *  Created on: Dec 5, 2022
 *      Author: tirua
 */


#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "main.h"
#include <stdint.h>
#include <stdlib.h>

#define NO_TASK_ID  0

typedef struct sTask{
	//
	void(*pTask)(void);
	//
	uint32_t Delay;
	//
	uint32_t Period;
	//
	uint32_t RunMe;
	//
	uint32_t TaskID;

	struct sTask* pNext;
};

typedef struct sTask STASK;

typedef struct list{
	STASK* head;
	STASK* tail;
};


typedef struct list LIST;

unsigned char SCH_Delete_Task_Index (unsigned char TASK_INDEX);
unsigned char SCH_Delete_Task_ID (unsigned char TASK_ID);
void SHC_Init (void);
void SHC_Add_Task(void (*pFunction)() , unsigned int DELAY, unsigned int PERIOD);
void SHC_Update(void);
void SCH_Dispatch_Tasks(void);



#endif /* INC_SCHEDULER_H_ */

/*
 * Scheduler.c
 *
 *  Created on: Dec 5, 2022
 *      Author: tirua
 */
#include "Scheduler.h"
#include "Task.h"
#include "main.h"
LIST* listTask;
uint32_t taskID=0;

unsigned char SCH_Delete_Task_Index (unsigned char TASK_INDEX){
	unsigned char Return_code;
	if (TASK_INDEX == 0){
		STASK* pDel = listTask-> head;
		listTask-> head = listTask-> head->pNext;
		free(pDel);
	}
	else if (TASK_INDEX >= taskID -1){
			STASK* pTemp = listTask-> head;
			while(pTemp != NULL && pTemp ->pNext != listTask-> tail){
				pTemp = pTemp-> pNext;
			}
			free(listTask-> tail);
			listTask-> tail = pTemp;
			listTask-> tail -> pNext = NULL;
		} else {
			STASK* pTemp = listTask-> head;
			while(-- TASK_INDEX>0) pTemp = pTemp->pNext;
			STASK* pDel = pTemp ->pNext;
			pTemp ->pNext = pTemp ->pNext ->pNext;
			free(pDel);
		}
	return Return_code;
};
unsigned char SCH_Delete_Task_ID (unsigned char TASK_ID){
	unsigned char Return_code;
	uint32_t index =0;
	STASK* pTemp = listTask-> head;
	while (pTemp != NULL && pTemp->TaskID != TASK_ID){
		pTemp = pTemp -> pNext;
		index++;
	};
	if (pTemp == NULL) {
		return Return_code;
	}else {
		SCH_Delete_Task_Index(index);
	};
	return Return_code;
};
void SCH_Init (void){
	listTask-> head = NULL;
	listTask-> tail = NULL;
};
void SCH_Add_Task(void (*pFunction)() , unsigned int DELAY, unsigned int PERIOD){
	if (listTask-> head == NULL){
		STASK* new = (STASK*)malloc(sizeof(STASK));

		new->pTask = pFunction;
		new->Delay = DELAY;
		new->Period= PERIOD;
		new->RunMe = 0;
		new->TaskID = taskID;
		taskID ++;
		new->pNext = NULL;

		listTask-> head = new;
		listTask-> tail = new;
	}
	else{
		STASK* new = (STASK*)malloc(sizeof(STASK));

		new->pTask = pFunction;
		new->Delay = DELAY;
		new->Period= PERIOD;
		new->RunMe = 0;
		new->TaskID = taskID;
		taskID ++;
		new->pNext = NULL;

		listTask-> tail->pNext = new;
		listTask-> tail = new;
	}
};
void SCH_Update(void){
	STASK* pRun = listTask-> head;
	while (pRun != NULL){
		if(pRun->Delay>0){
			pRun->Delay--;
		}else {
			pRun->Delay = pRun->Period;
			pRun->RunMe += 1;
		}
		pRun = pRun->pNext;
	}
};
void SCH_Dispatch_Tasks(void){
	STASK* pRun = listTask-> head;
	while (pRun != NULL){
		if(pRun->RunMe>0 && pRun->TaskID == 4){
			pRun->RunMe --;
			(*pRun ->pTask)();
			SCH_Delete_Task_ID(4);
		}else {
			pRun->RunMe --;
			(*pRun ->pTask)();
		}
		pRun = pRun->pNext;
	}
};


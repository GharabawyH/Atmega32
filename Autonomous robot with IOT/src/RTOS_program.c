#include "LSTD_TYPES.h"

#include "MTIM1_interface.h"

#include "RTOS_interface.h"

#define TasksNumber 2


Task SysTasks[TasksNumber];
static volatile u32 TickCount = 0;

void Scheduler(void);

void RTOS_Initialize(void)
{
	MTIM0_SetCallBack(Scheduler);
}


void RTOS_CreateTask(u8 ID , u16 Period , void (*Func)(void))
{
	SysTasks[ID].Periodicity = Period;
	SysTasks[ID].TaskHandler = Func;
	MTIM0_Initialize();
}

void Scheduler(void)
{
	u8 LoopCounter;
	TickCount++;
	for (LoopCounter = 0 ; LoopCounter < TasksNumber ; LoopCounter++)
	{
		if((TickCount % SysTasks[LoopCounter].Periodicity)==0)
		{
			SysTasks[LoopCounter].TaskHandler();
		}
	}
}

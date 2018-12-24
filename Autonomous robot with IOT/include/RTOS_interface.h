#ifndef _RTOS_INTERFACE_H
#define _RTOS_INTERFACE_H

typedef struct
{
	void (*TaskHandler)(void);
	u16 Periodicity;
}Task;

void RTOS_CreateTask(u8 ID , u16 Period , void (*Func)(void));
void RTOS_Initialize(void);



#endif
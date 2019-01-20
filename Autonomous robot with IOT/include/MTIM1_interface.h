#ifndef MTIM1_INTERFACE_H
#define MTIM1_INTERFACE_H


void MTIM1_Initialize(void);
void MTIM1_SetCallBack(void(*Ptr)(void));
void MTIM1_PWM_Initialize(void);
void MTIM1_PWM_Output_ChannelA(u16 ChannelA);
void MTIM1_PWM_Output_ChannelB(u16 ChannelB);



#endif

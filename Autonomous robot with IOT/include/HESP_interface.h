#ifndef HESP_INTERFACE_H
#define HESP_INTERFACE_H

void HESP_INIT(void);
void HESP_ConnectToHost(void);
void HESP_SendData(f64 Temp , u16 Press , f64 Alt ,u8 Hum);
void HESP_DisconnectFromHost(void);






#endif

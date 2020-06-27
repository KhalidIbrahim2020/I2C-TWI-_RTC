/*
 * TWI.h
 *
 * Created: 08/06/2020 01:17:28 م
 *  Author: Khalid
 */ 


#ifndef TWI_H_
#define TWI_H_
#ifndef F_CPU#define F_CPU	8000000UL#endif
#include "avr/interrupt.h"
#include	"avr/io.h"#include	"data_types.h"#include	"bit_handle.h"#include	"util/delay.h"


//control status code
#define SC_START           0X08
#define SC_RESTART         0X10
//MASTER TRASMIT STATUS CODE
#define SC_MT_SLA_ACK      0X18
#define SC_MT_SLA_NOTACK   0X20
#define SC_MT_DATA_ACK     0X28
#define SC_MT_DATA_NOTACK  0X30
//MASTER RECIVE STATUS CODE
#define SC_MR_SLA_ACK      0X40
#define SC_MR_SLA_NOTACK   0X48
#define SC_MR_DATA_ACK     0X50
#define SC_MR_DATA_NOTACK  0X58
// 100khz
void TWI_Init(void);
BOOL TWI_Start(void);
BOOL TWI_Restart(void);
void TWI_Stop(void);
void TWI_Wait(void);
BOOL TWI_WriteByte(INT8U u8Byte , INT8U u8StatusCode);
BOOL TWI_ReadByte(INT8U* P8Byte , INT8U u8StatusCode);


#endif /* TWI_H_ */
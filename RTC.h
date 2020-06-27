/*
 * RTC.h
 *
 * Created: 08/06/2020 03:24:12 م
 *  Author: Khalid
 */ 


#ifndef RTC_H_
#define RTC_H_

#include "TWI.h"

#define RTC_SLA_W  0B11010000
#define RTC_SLA_R  0B11010001


typedef struct{
	INT8U RTC_RegValues[7];//10,20,23,5,22....
	INT8U RTC_Time[9];  //"10:20:23"
	INT8U RTC_Date[11]; //"10//11/2020"
	}RTC_Struct;
void RTC_Init(void);
RTC_Struct* RTC_Update(void);
#endif /* RTC_H_ */
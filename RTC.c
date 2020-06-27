/*
 * RTC.c
 *
 * Created: 08/06/2020 03:24:23 م
 *  Author: Khalid
 */ 
#include "RTC.h"
static RTC_Struct RTC;
void RTC_Init(void){	TWI_Init();}RTC_Struct* RTC_Update(void){	INT8U ind = 0;	INT8U data = 0;	INT8U rtcRegisters[7] = {0};			TWI_Start();	TWI_WriteByte(RTC_SLA_W, SC_MT_SLA_ACK);	TWI_WriteByte(0x00, SC_MT_DATA_ACK);	TWI_Restart();		TWI_WriteByte(RTC_SLA_R, SC_MR_SLA_ACK);		for (ind = 0; ind < 6; ind++)	{		TWI_ReadByte(&data,SC_MR_DATA_ACK);		rtcRegisters[ind] = data;	}	TWI_ReadByte(&data,SC_MR_DATA_NOTACK);	TWI_Stop();	rtcRegisters[ind] = data;	   //CONVERT	/* SEC */	RTC.RTC_RegValues[0]  = rtcRegisters[0]&0x0F;	RTC.RTC_RegValues[0] += ((rtcRegisters[0]&0x70)>>4)*10;		/* Min */	RTC.RTC_RegValues[1]  = rtcRegisters[1]&0x0F;	RTC.RTC_RegValues[1] += ((rtcRegisters[1]&0x70)>>4)*10;	//HR	RTC.RTC_RegValues[2]  = rtcRegisters[2]&0x0F;	RTC.RTC_RegValues[2] += ((rtcRegisters[2]&0x30)>>4)*10;//0b0110000 to get hr mask 	return &RTC;}

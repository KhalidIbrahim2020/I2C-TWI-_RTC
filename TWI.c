/*
 * TWI.c
 *
 * Created: 08/06/2020 01:17:43 م
 *  Author: Khalid
 */ 
#include "TWI.h"

void TWI_Init(void){
	TWBR=32;//100KHZ,TWPS1:0 IF I WANT 8 ITS OK IF PRESCALE =0
	
}
BOOL TWI_Start(void){
	
	TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	TWI_Wait();
	return ((TWSR&0XF8)==SC_START);
}
BOOL TWI_Restart(void){
	TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	TWI_Wait();
	return ((TWSR&0XF8)==SC_RESTART);
	
}
void TWI_Stop(void){
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
	
}
void TWI_Wait(void){
	while (!(TWCR & (1<<TWINT)));//WAIT TILL TWINT==1
}
BOOL TWI_WriteByte(INT8U u8Byte , INT8U u8StatusCode){
	TWDR = u8Byte;
	TWCR = (1<<TWINT) | (1<<TWEN);
	TWI_Wait();
	return ((TWSR&0XF8)==u8StatusCode);
}
BOOL TWI_ReadByte(INT8U* P8Byte , INT8U u8StatusCode){
	BOOL Result=FALSE;
	TWCR = (1<<TWINT)|(1<<TWEN);
	//RETURN ACK FOR THE SLAVE IF WANTED
	if (u8StatusCode == SC_MR_DATA_ACK)
	{
		TWCR|= (1<<TWEA);
	}
	TWI_Wait();
	//CHECK THAT THE OPERATION DONE SUCC
	if (((TWSR&0XF8)==u8StatusCode))
	{
		(* P8Byte)=TWDR;
		Result=TRUE ;
	}
	return Result;
}
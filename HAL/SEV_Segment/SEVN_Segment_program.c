/*
* _7segment_program.c
*
* Created: 3/1/2024 2:28:54 PM
*  Author: ahmed
*/

#define  F_CPU  16000000
#include <util/delay.h>

#include "SEVN_Segment_interface.h"
void Sev_segment_init(void)
{
	#if SEVENSEGMET_MODE ==_4_MODE
	/* seven segments pins*/
	DIO_voidSetPinDirection(SEVSEGMENT4_PORT,SEVSEGMENT_PIN1, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SEVSEGMENT4_PORT,SEVSEGMENT_PIN2, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SEVSEGMENT4_PORT,SEVSEGMENT_PIN3, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SEVSEGMENT4_PORT,SEVSEGMENT_PIN4, DIO_PIN_OUTPUT);
	

	
	#elif SEVENSEGMET_MODE ==_8_MODE
	DIO_voidSetPortDirection(SEVSEGMENT8_PORT , DIO_PORT_OUTPUT);
	
	#endif
	
	#if  MAX_NUMBER==SEVSEGMENT_MAX_1
	DIO_voidSetPinDirection(COM_PORT2, COM_PIN1, DIO_PIN_OUTPUT);
	DIO_voidSetPinValue(COM_PORT2, COM_PIN1,DIO_PIN_LOW);
	#elif  MAX_NUMBER==SEVSEGMENT_MAX_2
	DIO_voidSetPinDirection(COM_PORT2, COM_PIN1, DIO_PIN_OUTPUT);
	DIO_voidSetPinValue(COM_PORT2, COM_PIN1,DIO_PIN_LOW);
	DIO_voidSetPinDirection(COM_PORT2, COM_PIN2, DIO_PIN_OUTPUT);
	DIO_voidSetPinValue(COM_PORT2, COM_PIN2,DIO_PIN_LOW);
	
	#elif  MAX_NUMBER==SEVSEGMENT_MAX_3
	DIO_voidSetPinDirection(COM_PORT2, COM_PIN1, DIO_PIN_OUTPUT);
	DIO_voidSetPinValue(COM_PORT2, COM_PIN1,DIO_PIN_LOW);
	DIO_voidSetPinDirection(COM_PORT2, COM_PIN2, DIO_PIN_OUTPUT);
	DIO_voidSetPinValue(COM_PORT2, COM_PIN2,DIO_PIN_LOW);
	DIO_voidSetPinDirection(COM_PORT1, COM_PIN3, DIO_PIN_OUTPUT);
	DIO_voidSetPinValue(COM_PORT1, COM_PIN3,DIO_PIN_LOW);
	
	#elif  MAX_NUMBER ==SEVSEGMENT_MAX_4
	DIO_voidSetPinDirection(COM_PORT2, COM_PIN1, DIO_PIN_OUTPUT);
	DIO_voidSetPinValue    (COM_PORT2, COM_PIN1,DIO_PIN_LOW);
	DIO_voidSetPinDirection(COM_PORT2, COM_PIN2, DIO_PIN_OUTPUT);
	DIO_voidSetPinValue    (COM_PORT2, COM_PIN2,DIO_PIN_LOW);
	DIO_voidSetPinDirection(COM_PORT1, COM_PIN3, DIO_PIN_OUTPUT);
	DIO_voidSetPinValue       (COM_PORT1, COM_PIN3,DIO_PIN_LOW);
	DIO_voidSetPinDirection(COM_PORT1, COM_PIN4,DIO_PIN_OUTPUT);
	DIO_voidSetPinValue    (COM_PORT1, COM_PIN4,DIO_PIN_LOW);
	//DIO_voidSetPortDirection(DIO_PORTB, DIO_PIN6,DIO_PIN_LOW);
	#endif
}


void SevenSegment_voidWriteNumber(u16 copy_u8Number)
{
	u16 local_u8Temp ;
	u8 local_u8OneBit ;
	#if SEVENSEGMET_MODE ==_8_MODE
	unsigned char arr[]={ 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};
	#if SEVSEGMENT_8_U8_COM_MODE==SEVSEGMENT_COM_CATHODE
	
	DIO_voidSetPinValue    (COM_PORT2, COM_PIN2,DIO_PIN_HIGH);
	DIO_voidSetPinValue    (COM_PORT1, COM_PIN3,DIO_PIN_HIGH);
	DIO_voidSetPinValue    (COM_PORT1, COM_PIN4,DIO_PIN_HIGH);
	
	
	local_u8Temp = copy_u8Number %10;
	copy_u8Number=copy_u8Number /10;
	DIO_voidSetPinValue    (COM_PORT2, COM_PIN1,DIO_PIN_LOW);
	DIO_voidSetPortValue(SEVSEGMENT8_PORT,arr[local_u8Temp]);
	_delay_ms(1);
	DIO_voidSetPinValue    (COM_PORT2, COM_PIN1,DIO_PIN_HIGH);
	DIO_voidSetPinValue    (COM_PORT1, COM_PIN3,DIO_PIN_HIGH);
	DIO_voidSetPinValue    (COM_PORT1, COM_PIN4,DIO_PIN_HIGH);
	
	
	local_u8Temp = copy_u8Number %10;
	copy_u8Number=copy_u8Number /10;
	DIO_voidSetPinValue    (COM_PORT2, COM_PIN2,DIO_PIN_LOW);
	DIO_voidSetPortValue(SEVSEGMENT8_PORT,arr[local_u8Temp]);
	_delay_ms(1);
	DIO_voidSetPinValue    (COM_PORT2, COM_PIN1,DIO_PIN_HIGH);
	DIO_voidSetPinValue    (COM_PORT2, COM_PIN2,DIO_PIN_HIGH);
	DIO_voidSetPinValue    (COM_PORT1, COM_PIN4,DIO_PIN_HIGH);
	
	
	local_u8Temp = copy_u8Number %10;
	copy_u8Number=copy_u8Number /10;
	DIO_voidSetPinValue    (COM_PORT1, COM_PIN3,DIO_PIN_LOW);
	DIO_voidSetPortValue(SEVSEGMENT8_PORT,arr[local_u8Temp]);
	_delay_ms(1);
	DIO_voidSetPinValue    (COM_PORT2, COM_PIN1,DIO_PIN_HIGH);
	DIO_voidSetPinValue    (COM_PORT2, COM_PIN2,DIO_PIN_HIGH);
	DIO_voidSetPinValue    (COM_PORT1, COM_PIN3,DIO_PIN_HIGH);
	
	local_u8Temp = copy_u8Number %10;
	copy_u8Number=copy_u8Number /10;
	DIO_voidSetPinValue    (COM_PORT1, COM_PIN4,DIO_PIN_LOW);
	DIO_voidSetPortValue(SEVSEGMENT8_PORT,arr[local_u8Temp]);
	_delay_ms(1);
	
	#elif SEVSEGMENT_8_U8_COM_MODE==SEVSEGMENT_COM_ANODE
	DIO_voidSetPinValue    (COM_PORT2, COM_PIN2,DIO_PIN_HIGH);
	DIO_voidSetPinValue    (COM_PORT1, COM_PIN3,DIO_PIN_HIGH);
	DIO_voidSetPinValue    (COM_PORT1, COM_PIN4,DIO_PIN_HIGH);
	
	
	local_u8Temp = copy_u8Number %10;
	copy_u8Number=copy_u8Number /10;
	DIO_voidSetPinValue    (COM_PORT2, COM_PIN1,DIO_PIN_LOW);
	DIO_voidSetPortValue(SEVSEGMENT8_PORT,~arr[local_u8Temp]);
	_delay_ms(1);
	DIO_voidSetPinValue    (COM_PORT2, COM_PIN1,DIO_PIN_HIGH);
	DIO_voidSetPinValue    (COM_PORT1, COM_PIN3,DIO_PIN_HIGH);
	DIO_voidSetPinValue    (COM_PORT1, COM_PIN4,DIO_PIN_HIGH);
	
	
	local_u8Temp = copy_u8Number %10;
	copy_u8Number=copy_u8Number /10;
	DIO_voidSetPinValue    (COM_PORT2, COM_PIN2,DIO_PIN_LOW);
	DIO_voidSetPortValue(SEVSEGMENT8_PORT,~arr[local_u8Temp]);
	_delay_ms(1);
	DIO_voidSetPinValue    (COM_PORT2, COM_PIN1,DIO_PIN_HIGH);
	DIO_voidSetPinValue    (COM_PORT2, COM_PIN2,DIO_PIN_HIGH);
	DIO_voidSetPinValue    (COM_PORT1, COM_PIN4,DIO_PIN_HIGH);
	
	
	local_u8Temp = copy_u8Number %10;
	copy_u8Number=copy_u8Number /10;
	DIO_voidSetPinValue    (COM_PORT1, COM_PIN3,DIO_PIN_LOW);
	DIO_voidSetPortValue(SEVSEGMENT8_PORT,~arr[local_u8Temp]);
	_delay_ms(1);
	DIO_voidSetPinValue    (COM_PORT2, COM_PIN1,DIO_PIN_HIGH);
	DIO_voidSetPinValue    (COM_PORT2, COM_PIN2,DIO_PIN_HIGH);
	DIO_voidSetPinValue    (COM_PORT1, COM_PIN3,DIO_PIN_HIGH);
	
	local_u8Temp = copy_u8Number %10;
	copy_u8Number=copy_u8Number /10;
	DIO_voidSetPinValue    (COM_PORT1, COM_PIN4,DIO_PIN_LOW);
	DIO_voidSetPortValue(SEVSEGMENT8_PORT,~arr[local_u8Temp]);
	_delay_ms(1);
	#endif
	
	
	
	
	/* with BCD */
	#elif SEVENSEGMET_MODE ==_4_MODE
	
	
		DIO_voidSetPinValue    (COM_PORT2, COM_PIN2,DIO_PIN_HIGH);
		DIO_voidSetPinValue    (COM_PORT1, COM_PIN3,DIO_PIN_HIGH);
		DIO_voidSetPinValue    (COM_PORT1, COM_PIN4,DIO_PIN_HIGH);
		local_u8Temp = copy_u8Number %10;
		copy_u8Number=copy_u8Number /10;
		DIO_voidSetPinValue    (COM_PORT2, COM_PIN1,DIO_PIN_LOW);
		local_u8OneBit = READ_BIT(local_u8Temp,BIT_NUMBER1);
		DIO_voidSetPinValue(DIO_PORTB,SEVSEGMENT_PIN1  ,local_u8OneBit);
		local_u8OneBit = READ_BIT(local_u8Temp,BIT_NUMBER2);
		DIO_voidSetPinValue(DIO_PORTB,SEVSEGMENT_PIN2  ,local_u8OneBit);
		local_u8OneBit = READ_BIT(local_u8Temp,BIT_NUMBER3);
		DIO_voidSetPinValue(DIO_PORTB,SEVSEGMENT_PIN3  ,local_u8OneBit);
		local_u8OneBit = READ_BIT(local_u8Temp,BIT_NUMBER4);
		DIO_voidSetPinValue(DIO_PORTB,SEVSEGMENT_PIN4  ,local_u8OneBit);
		_delay_ms(1);
		
		DIO_voidSetPinValue    (COM_PORT2, COM_PIN1,DIO_PIN_HIGH);
		DIO_voidSetPinValue    (COM_PORT1, COM_PIN3,DIO_PIN_HIGH);
		DIO_voidSetPinValue    (COM_PORT1, COM_PIN4,DIO_PIN_HIGH);
		local_u8Temp = copy_u8Number %10;
		copy_u8Number=copy_u8Number /10;
		DIO_voidSetPinValue    (COM_PORT2, COM_PIN2,DIO_PIN_LOW);
		local_u8OneBit = READ_BIT(local_u8Temp,BIT_NUMBER1);
		DIO_voidSetPinValue(DIO_PORTB,SEVSEGMENT_PIN1  ,local_u8OneBit);
		local_u8OneBit = READ_BIT(local_u8Temp,BIT_NUMBER2);
		DIO_voidSetPinValue(DIO_PORTB,SEVSEGMENT_PIN2  ,local_u8OneBit);
		local_u8OneBit = READ_BIT(local_u8Temp,BIT_NUMBER3);
		DIO_voidSetPinValue(DIO_PORTB,SEVSEGMENT_PIN3  ,local_u8OneBit);
		local_u8OneBit = READ_BIT(local_u8Temp,BIT_NUMBER4);
		DIO_voidSetPinValue(DIO_PORTB,SEVSEGMENT_PIN4  ,local_u8OneBit);
		_delay_ms(1);
		
		DIO_voidSetPinValue    (COM_PORT2, COM_PIN1,DIO_PIN_HIGH);
		DIO_voidSetPinValue    (COM_PORT2, COM_PIN2,DIO_PIN_HIGH);
		DIO_voidSetPinValue    (COM_PORT1, COM_PIN4,DIO_PIN_HIGH);
		local_u8Temp = copy_u8Number %10;
		copy_u8Number=copy_u8Number /10;
		
		local_u8OneBit = READ_BIT(local_u8Temp,BIT_NUMBER1);
		DIO_voidSetPinValue    (COM_PORT1, COM_PIN3,DIO_PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTB,SEVSEGMENT_PIN1  ,local_u8OneBit);
		local_u8OneBit = READ_BIT(local_u8Temp,BIT_NUMBER2);
		DIO_voidSetPinValue(DIO_PORTB,SEVSEGMENT_PIN2  ,local_u8OneBit);
		local_u8OneBit = READ_BIT(local_u8Temp,BIT_NUMBER3);
		DIO_voidSetPinValue(DIO_PORTB,SEVSEGMENT_PIN3  ,local_u8OneBit);
		local_u8OneBit = READ_BIT(local_u8Temp,BIT_NUMBER4);
		DIO_voidSetPinValue(DIO_PORTB,SEVSEGMENT_PIN4  ,local_u8OneBit);
		_delay_ms(1);
		
		DIO_voidSetPinValue    (COM_PORT2, COM_PIN1,DIO_PIN_HIGH);
		DIO_voidSetPinValue    (COM_PORT2, COM_PIN2,DIO_PIN_HIGH);
		DIO_voidSetPinValue    (COM_PORT1, COM_PIN3,DIO_PIN_HIGH);
		
		local_u8Temp = copy_u8Number %10;
		copy_u8Number=copy_u8Number /10;
		
		local_u8OneBit = READ_BIT(local_u8Temp,BIT_NUMBER1);
		DIO_voidSetPinValue    (COM_PORT1, COM_PIN4,DIO_PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTB,SEVSEGMENT_PIN1  ,local_u8OneBit);
		local_u8OneBit = READ_BIT(local_u8Temp,BIT_NUMBER2);
		DIO_voidSetPinValue(DIO_PORTB,SEVSEGMENT_PIN2  ,local_u8OneBit);
		local_u8OneBit = READ_BIT(local_u8Temp,BIT_NUMBER3);
		DIO_voidSetPinValue(DIO_PORTB,SEVSEGMENT_PIN3  ,local_u8OneBit);
		local_u8OneBit = READ_BIT(local_u8Temp,BIT_NUMBER4);
		DIO_voidSetPinValue(DIO_PORTB,SEVSEGMENT_PIN4  ,local_u8OneBit);
		_delay_ms(1);
	
	
	#endif
}


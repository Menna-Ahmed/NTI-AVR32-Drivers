/*
* DIO_program.c
*
* Created: 3/1/2024 10:09:48 AM
*  Author: ahmed
*/
#include "../StdTypes.h"
#include "../MemMap.h"
#include "../Utils.h"
#include "DIO_interface.h"

void DIO_voidSetPinDirection(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinDirection)
{
	switch(copy_u8PinDirection)
	{
		case DIO_PIN_INPUT:
		switch(copy_u8PortId)
		{
			case  DIO_PORTA:
			CLR_BIT(DDRA,copy_u8PinId);
			break;
			case  DIO_PORTB:
			CLR_BIT(DDRB,copy_u8PinId);
			break;
			case  DIO_PORTC:
			CLR_BIT(DDRC,copy_u8PinId);
			break;
			case  DIO_PORTD:
			CLR_BIT(DDRD,copy_u8PinId);
			break;
		}
		break;
	}
	switch(copy_u8PinDirection)
	{
		case DIO_PIN_OUTPUT:
		switch(copy_u8PortId)
		{
			case  DIO_PORTA:
			SET_BIT(DDRA,copy_u8PinId);
			break;
			case  DIO_PORTB:
			SET_BIT(DDRB,copy_u8PinId);
			break;
			case  DIO_PORTC:
			SET_BIT(DDRC,copy_u8PinId);
			break;
			case  DIO_PORTD:
			SET_BIT(DDRD,copy_u8PinId);
			break;
		}
		break;
	}
	
}
void DIO_voidSetPinValue(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinValue)
{
	switch (copy_u8PinValue)
	{
		case DIO_PIN_LOW:
		switch(copy_u8PortId)
		{
			case DIO_PORTA:
			CLR_BIT(PORTA, copy_u8PinId);
			break;
			case DIO_PORTB:
			CLR_BIT(PORTB, copy_u8PinId);
			break;
			case DIO_PORTC:
			CLR_BIT(PORTC, copy_u8PinId);
			break;
			case DIO_PORTD:
			CLR_BIT(PORTD, copy_u8PinId);
			break;
		}
		break;
		case DIO_PIN_HIGH:
		switch(copy_u8PortId)
		{
			case DIO_PORTA:
			SET_BIT(PORTA, copy_u8PinId);
			break;
			case DIO_PORTB:
			SET_BIT(PORTB, copy_u8PinId);
			break;
			case DIO_PORTC:
			SET_BIT(PORTC, copy_u8PinId);
			break;
			case DIO_PORTD:
			SET_BIT(PORTD, copy_u8PinId);
			break;
		}
		break;
	}
}
void DIO_voidGetPinValue(u8 copy_u8PortId, u8 copy_u8PinId, u8* copy_pu8PinValue)
{
	switch (copy_u8PortId)
	{
		case DIO_PORTA:
		*copy_pu8PinValue = READ_BIT(PINA, copy_u8PinId);
		break;
		case DIO_PORTB:
		*copy_pu8PinValue = READ_BIT(PINB, copy_u8PinId);
		break;
		case DIO_PORTC:
		*copy_pu8PinValue = READ_BIT(PINC, copy_u8PinId);
		break;
		case DIO_PORTD:
		*copy_pu8PinValue = READ_BIT(PIND, copy_u8PinId);
		break;
	}
}
void DIO_voidTogglePinValue(u8 copy_u8PortId, u8 copy_u8PinId)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA:
		TOG_BIT(PORTA, copy_u8PinId);
		break;
		case DIO_PORTB:
		TOG_BIT(PORTB, copy_u8PinId);
		break;
		case DIO_PORTC:
		TOG_BIT(PORTC, copy_u8PinId);
		break;
		case DIO_PORTD:
		TOG_BIT(PORTD, copy_u8PinId);
		break;
	}
}
void DIO_voidActivePinInPullUpResistance(u8 copy_u8PortId, u8 copy_u8PinId)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA:
		SET_BIT(PORTA, copy_u8PinId);
		break;
		case DIO_PORTB:
		SET_BIT(PORTB, copy_u8PinId);
		break;
		case DIO_PORTC:
		SET_BIT(PORTC, copy_u8PinId);
		break;
		case DIO_PORTD:
		SET_BIT(PORTD, copy_u8PinId);
		break;
	}
}
//
///* Port Apis */
void DIO_voidSetPortDirection(u8 copy_u8PortId, u8 copy_u8PortDirection)
{
	switch(copy_u8PortDirection)
	{
		case DIO_PORT_INPUT:
		switch(copy_u8PortId)
		{
			case DIO_PORTA:
			DDRA = DIO_PORT_LOW ;
			break;
			case DIO_PORTB:
			DDRB = DIO_PORT_LOW ;
			break;
			case DIO_PORTC:
			DDRC = DIO_PORT_LOW ;
			break;
			case DIO_PORTD:
			DDRD = DIO_PORT_LOW ;
			break;
		}
		break;
		case DIO_PORT_OUTPUT:
		switch(copy_u8PortId)
		{
			case DIO_PORTA:
			DDRA = DIO_PORT_HIGH ;
			break;
			case DIO_PORTB:
			DDRB = DIO_PORT_HIGH ;
			break;
			case DIO_PORTC:
			DDRC = DIO_PORT_HIGH ;
			break;
			case DIO_PORTD:
			DDRD = DIO_PORT_HIGH ;
			break;
		}
		break;
	}
}
void DIO_voidSetPortValue(u8 copy_u8PortId, u8 copy_u8PortValue)
{
	switch(copy_u8PortId)
	{
		
		case DIO_PORTA:
		PORTA = copy_u8PortValue ;
		break;
		case DIO_PORTB:
		PORTB = copy_u8PortValue ;
		break;
		case DIO_PORTC:
		PORTC = copy_u8PortValue ;
		break;
		case DIO_PORTD:
		PORTD = copy_u8PortValue ;
		break;
	}
}

void DIO_voidGetPortValue(u8 copy_u8PortId, u8* copy_pu8PortValue)
{
	switch(copy_u8PortId)
	{
		
		case DIO_PORTA:
		*copy_pu8PortValue = PORTA  ;
		break;
		case DIO_PORTB:
		*copy_pu8PortValue = PORTB ;
		break;
		case DIO_PORTC:
		*copy_pu8PortValue = PORTC ;
		break;
		case DIO_PORTD:
		*copy_pu8PortValue = PORTD ;
		break;
	}
}
void DIO_voidTogglePortValue(u8 copy_u8PortId)
{
	switch(copy_u8PortId)
	{
		
		case DIO_PORTA:
		 PORTA^= DIO_PORT_HIGH  ;
		break;
		case DIO_PORTB:
		PORTB^= DIO_PORT_HIGH ;
		break;
		case DIO_PORTC:
		PORTC^= DIO_PORT_HIGH  ;
		break;
		case DIO_PORTD:
		PORTD^= DIO_PORT_HIGH  ;
		break;
	}
}
void DIO_voidActivePortInPullUpResistance(u8 copy_u8PortId)
{
	switch(copy_u8PortId)
	{
		
		case DIO_PORTA:
		PORTA =DIO_PORT_HIGH  ;
		break;
		case DIO_PORTB:
		PORTB =DIO_PORT_HIGH ;
		break;
		case DIO_PORTC:
		PORTC =DIO_PORT_HIGH  ;
		break;
		case DIO_PORTD:
		PORTD =DIO_PORT_HIGH  ;
		break;
	}
}
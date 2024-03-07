/*
* LCD_program.c
*
* Created: 3/2/2024 11:33:54 AM
*  Author: ahmed
*/


#include "../StdTypes.h"
#include "../Utils.h"
#include "DIO_interface.h"
#include "LCD_Interface.h"
#define  F_CPU  16000000
#include <util/delay.h>

#if LCD_MODE==_4_BIT

void LCD_voidInit(void)
{
	DIO_voidSetPinDirection(LCD_DATA_PORT, D4, LCD_OUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, D5, LCD_OUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, D6, LCD_OUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, D7, LCD_OUT);
	
	DIO_voidSetPinDirection(LCD_CNTRL_PORT, RS, LCD_OUT);
	DIO_voidSetPinDirection(LCD_CNTRL_PORT, EN, LCD_OUT);
	_delay_ms(20);
	
	LCD_voidWriteCommand(0x02);
	LCD_voidWriteCommand(0x28);//5*7 2 lines
	LCD_voidWriteCommand(0x0c);//0x0c,0x0e,0x0f cursor
	LCD_voidWriteCommand(0x06);// increment DDRAM address, no shift
	LCD_voidWriteCommand(0x01);//clear screen
	
	
	
}

void LCD_voidWriteData(u8 copy_u8data)
{
	DIO_voidSetPinValue(LCD_CNTRL_PORT,RS,LCD_HIGH);
	DIO_voidSetPinValue(DIO_PORTB ,D7,READ_BIT(copy_u8data,7));
	DIO_voidSetPinValue(DIO_PORTB ,D6,READ_BIT(copy_u8data,6));
	DIO_voidSetPinValue(DIO_PORTB ,D5,READ_BIT(copy_u8data,5));
	DIO_voidSetPinValue(DIO_PORTB ,D4,READ_BIT(copy_u8data,4));
	DIO_voidSetPinValue(LCD_CNTRL_PORT, EN,  LCD_HIGH);
	_delay_us(1);
	DIO_voidSetPinValue(LCD_CNTRL_PORT, EN,  LCD_LOW);
	_delay_us(200);
	
	DIO_voidSetPinValue(DIO_PORTB ,D7,READ_BIT(copy_u8data,3));
	DIO_voidSetPinValue(DIO_PORTB ,D6,READ_BIT(copy_u8data,2));
	DIO_voidSetPinValue(DIO_PORTB ,D5,READ_BIT(copy_u8data,1));
	DIO_voidSetPinValue(DIO_PORTB ,D4,READ_BIT(copy_u8data,0));
	
	DIO_voidSetPinValue(LCD_CNTRL_PORT, EN,  LCD_HIGH);
	_delay_us(1);
	DIO_voidSetPinValue(LCD_CNTRL_PORT, EN,  LCD_LOW);
	_delay_ms(2);
}

void LCD_voidWriteCommand(u8 copy_u8Command)
{
	DIO_voidSetPinValue(LCD_CNTRL_PORT,RS,LCD_LOW);
	
	DIO_voidSetPinValue(DIO_PORTB ,D7,READ_BIT(copy_u8Command,7));
	DIO_voidSetPinValue(DIO_PORTB ,D6,READ_BIT(copy_u8Command,6));
	DIO_voidSetPinValue(DIO_PORTB ,D5,READ_BIT(copy_u8Command,5));
	DIO_voidSetPinValue(DIO_PORTB ,D4,READ_BIT(copy_u8Command,4));
	DIO_voidSetPinValue(LCD_CNTRL_PORT, EN,  LCD_HIGH);
	_delay_us(1);
	DIO_voidSetPinValue(LCD_CNTRL_PORT, EN,  LCD_LOW);
	_delay_us(200);
	//DIO_voidSetPinValue(LCD_CNTRL_PORT,RS,LCD_LOW);
	DIO_voidSetPinValue(DIO_PORTB ,D7,READ_BIT(copy_u8Command,3));
	DIO_voidSetPinValue(DIO_PORTB ,D6,READ_BIT(copy_u8Command,2));
	DIO_voidSetPinValue(DIO_PORTB ,D5,READ_BIT(copy_u8Command,1));
	DIO_voidSetPinValue(DIO_PORTB ,D4,READ_BIT(copy_u8Command,0));
	
	DIO_voidSetPinValue(LCD_CNTRL_PORT, EN,  LCD_HIGH);
	_delay_us(1);
	DIO_voidSetPinValue(LCD_CNTRL_PORT, EN,  LCD_LOW);
	_delay_ms(2);
	
	
}


#elif MODE == _8_BIT


void LCD_voidInit(void)
{
	DIO_voidSetPortDirection(LCD_PORT,DIO_PORT_OUTPUT);
	_delay_ms(50);
	
	LCD_voidWriteCommand(0x38);//5*7 2 lines
	LCD_voidWriteCommand(0x0c);//0x0c,0x0e,0x0f cursor
	LCD_voidWriteCommand(0x01);//clear screen
	_delay_ms(1);
	LCD_voidWriteCommand(0x06);// increment DDRAM address, no shif
}

void LCD_voidWriteData(u8 copy_u8data)
{
	DIO_voidSetPinValue(RS,DIO_PIN_HIGH);
	DIO_voidSetPortValue(LCD_8PORT,copy_u8data);
	DIO_voidSetPinValue(EN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(EN,DIO_PIN_LOW);
	_delay_ms(1);
}

void LCD_voidWriteCommand(u8 copy_u8Command)
{
	DIO_voidSetPinValue(RS,DIO_PIN_LOW);
	DIO_voidSetPortValue(LCD_8PORT,copy_u8Command);
	DIO_voidSetPinValue(EN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(EN,DIO_PIN_LOW);
	_delay_ms(1);
	
	
}

#endif

void LCD_voidWriteString(u8 * copy_str)
{
	while (*copy_str != '\0')
	{
		LCD_voidWriteData(*copy_str);
		copy_str++;
	}
}

void LCD_voidGoToXY(u8 copy_u8Row,u8 copy_u8Col)
{
	u8 local_u8Address =0;
	if(copy_u8Row == 0){
		local_u8Address = 0x00;
	}
	if(copy_u8Row == 1){
		local_u8Address = 0x40;
	}
	if(copy_u8Row == 2){
		local_u8Address = 0x14;
	}
	if(copy_u8Row == 3){
		local_u8Address = 0x54;
	}
	if(copy_u8Col < 20){
		local_u8Address += copy_u8Col;
	}
	LCD_voidWriteCommand(0x80+local_u8Address);
}

void LCD_voidClear(void)
{
	LCD_voidWriteCommand(0x01);
}

void LCD_voidWriteNumber( u32 Copy_u8num )
{
	
	u8 str[10]={0},i=0 ,j;
	if(Copy_u8num==0)
	{
		LCD_voidWriteData('0');
		return;
	}
	if(Copy_u8num<0)
	{
		Copy_u8num=Copy_u8num*(-1);
		LCD_voidWriteData('-');
	}
	
	while(Copy_u8num!=0)
	{
		str[i]=Copy_u8num%10 +'0';
		Copy_u8num=Copy_u8num/10;
		i++;
		
	}
	
	for (j=i;j>0;j--)
	{
		LCD_voidWriteData(str[j-1]);
	}
}

void LCD_voidWriteSpecialCharToCGRAM(u8 * copy_u8data , u8 copy_u8ByteNum )
{
	LCD_voidWriteCommand(0x40+copy_u8ByteNum*8);
	for(u8 i=0;i<8;i++)
	{
		LCD_voidWriteData(copy_u8data[i]);
	}
	LCD_voidWriteCommand(0x80);
}

void LCD_voidDisplaySpecialChar(u8 copy_u8ByteNum ) 
{
	LCD_voidWriteData(copy_u8ByteNum);
}
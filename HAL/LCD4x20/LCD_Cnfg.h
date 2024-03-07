/*
 * LCD_Cnfg.h
 *
 * Created: 3/2/2024 11:41:16 AM
 *  Author: ahmed
 */ 





#ifndef LCD_CNFG_H_
#define LCD_CNFG_H_
#define LCD_DATA_PORT  DIO_PORTB
#define LCD_CNTRL_PORT DIO_PORTA

#define _4_BIT   0
#define _8_BIT   1

#define   MODE    _4_BIT
 
#define  EN          DIO_PIN2
#define  RS          DIO_PIN3
               
#define  D4          DIO_PIN0 
#define  D5          DIO_PIN1
#define  D6          DIO_PIN2
#define  D7          DIO_PIN4
#define  LCD_OUT     DIO_PIN_OUTPUT


#define LCD_LOW        DIO_PIN_LOW             
#define LCD_HIGH      DIO_PIN_HIGH
//#define  LCD_OUT     DIO_PIN_OUTPUT
#define  LCD_PORT     DIO_PORTA
#define  LCD_8PORT     DIO_PORTC




#endif /* LCD_CNFG_H_ */
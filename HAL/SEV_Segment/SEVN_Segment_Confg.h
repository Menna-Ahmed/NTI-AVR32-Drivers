/*
 * _7segment_Confg.h
 *
 * Created: 3/1/2024 2:28:21 PM
 *  Author: ahmed
 */ 


#ifndef _7SEGMENT_CONFG_H_
#define _7SEGMENT_CONFG_H_

#define        SEVSEGMENT_COM_CATHODE              1
#define	       SEVSEGMENT_COM_ANODE                0

#define        _4_MODE                             0
#define        _8_MODE                             1 
#define        SEVENSEGMET_MODE                  _4_MODE


#define      SEVSEGMENT4_PORT                      DIO_PORTB
#define      SEVSEGMENT_PIN1                       DIO_PIN0
#define      SEVSEGMENT_PIN2                       DIO_PIN1
#define      SEVSEGMENT_PIN3                       DIO_PIN2
#define      SEVSEGMENT_PIN4                       DIO_PIN4


#define      SEVSEGMENT8_PORT                       DIO_PORTC

 #define        SEVSEGMENT_MAX_1                    1
 #define 		SEVSEGMENT_MAX_2                    2 
 #define		SEVSEGMENT_MAX_3                    3
 #define		SEVSEGMENT_MAX_4                    4
 
#define        MAX_NUMBER                          SEVSEGMENT_MAX_4

#define        COM_PORT2                           DIO_PORTA
#define        COM_PORT1                           DIO_PORTB
/* PORTB*/
#define        COM_PIN4                           DIO_PIN6
#define        COM_PIN3                           DIO_PIN5

/* PORTA*/
#define        COM_PIN2                           DIO_PIN2
#define        COM_PIN1                           DIO_PIN3


#define      SEVSEGMENT_4_U8_COM_MODE	          SEVSEGMENT_COM_ANODE
#define      SEVSEGMENT_8_U8_COM_MODE	          SEVSEGMENT_COM_CATHODE

#define      BIT_NUMBER1                             0
#define      BIT_NUMBER2                             1
#define      BIT_NUMBER3                             2
#define      BIT_NUMBER4                             3

#endif /* _7SEGMENT_CONFG_H_ */
/*
 * DIO_Private.h
 *
 * Created: 4/2/2023 5:58:28 AM
 *  Author: ahmed
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_


extern const DIO_PinStatus_type PinsStatusArray[TOTAL_PINS];
static void DIO_voidInitPin(DIO_Pin_type pin,DIO_PinStatus_type status);


#endif /* DIO_PRIVATE_H_ */
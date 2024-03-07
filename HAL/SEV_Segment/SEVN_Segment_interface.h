/*
 * _7segment_interface.h
 *
 * Created: 3/1/2024 2:27:27 PM
 *  Author: ahmed
 */ 


#ifndef SEGMENT_INTERFACE_H_
#define SEGMENT_INTERFACE_H_
#include "../StdTypes.h"
#include "../MemMap.h"
#include "../Utils.h"
#include "DIO_interface.h"
#include "SEVN_Segment_Confg.h"


void Sev_segment_init(void);
void SevenSegment_voidWriteNumber(u16 copy_u8Number);

#endif /* SEGMENT_INTERFACE_H_ */
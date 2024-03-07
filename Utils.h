/*
 * Utils.h
 *
 * Created: 4/2/2023 6:25:50 AM
 *  Author: ahmed
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define  READ_BIT(reg,bit)  ((reg>>bit)&1)
#define  SET_BIT(reg,bit)     (reg=reg|(1<<bit))
#define  CLR_BIT(reg,bit)     (reg=reg&~(1<<bit))
#define  TOG_BIT(reg,bit)     (reg=reg^(1<<bit))




#endif /* UTILS_H_ */
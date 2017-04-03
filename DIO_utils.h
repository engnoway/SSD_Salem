/*
 * DIO_utils.h
 *
 *  Created on: ???/???/????
 *      Author: Ismailia Laptop
 */

#ifndef DIO_UTILS_H_
#define DIO_UTILS_H_

#define setReg(Reg)                 Reg=0XFF
#define clrReg(reg)                 Reg=0X00
#define toggleReg(Reg)              Reg^=0XFF
#define AssignReg(Reg,val)          Reg=val
#define AssignBit(reg,BitNu, BitVal)	reg=((~(1<<BitNu))&reg)|(BitVal<<BitNu)

#define GetLowNibble(Reg)           Reg&F0
#define SetLowNibble(Reg)           Reg^FF
#define ClrLowNibble(Reg)           Reg&F0
#define AssignLowNibble(Reg,val)    Reg=val

#define GetHighnib(Reg)             reg|0xf0
#define ClrHighnib(reg)             reg&0x0f
#define SetHighnib(reg)             reg&0xf0
#define Assignhighnib(reg,value)   reg = value

#define getbit(reg,bitno)          0x01&(reg>>bitno)
#define Clrbit(reg,bitno)          reg|0xf0
#define setbit(reg,bitno)         reg|(0x01<<bitno)
#define Togglebit(reg,bitno)          reg^(0x01<<bitno)




#endif /* DIO_UTILS_H_ */

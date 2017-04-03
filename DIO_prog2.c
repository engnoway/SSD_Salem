/*
 * DIO_prog2.c
 *
 *  Created on: ???/???/????
 *      Author: Ismailia Laptop
 */

#include "types.h"
#include "DIO_utils.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include "DIO_interface.h"



/*
 * DIO_prog.c
*/


/*************************************************************/
/*****************************MAIN PROGRAM*************************/
/*************************************************************/

/*
 initialization of all pins and ports
 */
static volatile u8* const DIO_u8PORTArr[4]={ DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD};//array of constant pointers
static volatile u8* const DIO_u8DDRArr[4]={ DIO_u8DDRA, DIO_u8DDRB, DIO_u8DDRC, DIO_u8DDRD};
static volatile u8* const DIO_u8PINArr[4]={ DIO_u8PINA, DIO_u8PINB, DIO_u8PINC, DIO_u8PIND};

void DIO_voidInit(void)
{
	//DETERMINING INPUT AND OUTPUT
	*DIO_u8DDRA =DIO_u8PortADIR;
	*DIO_u8DDRB=DIO_u8PortBDIR;
	*DIO_u8DDRC=DIO_u8PortCDIR;
	*DIO_u8DDRD=DIO_u8PortDDIR;
	//DETERMINING LOW AND HIGH
	*DIO_u8PORTA  = (*DIO_u8PORTA &~*DIO_u8DDRA) | (DIO_u8PortADIR & DIO_u8PORTA_VAL);
	*DIO_u8PORTB  = (*DIO_u8PORTB &~*DIO_u8DDRB)  | (DIO_u8PortBDIR & DIO_u8PORTB_VAL);
	*DIO_u8PORTC  = (*DIO_u8PORTC &~*DIO_u8DDRC) | (DIO_u8PortCDIR & DIO_u8PORTC_VAL);
	*DIO_u8PORTD = (*DIO_u8PORTD &~*DIO_u8DDRD) | (DIO_u8PortDDIR & DIO_u8PORTD_VAL);
	return;
}

/*
 reading pins of all ports
 */
u8 DIO_u8ReadPinVal(u8 Copy_u8PinIdx,u8* Copy_u8PtrToVal)
{
	u8 local_u8flag=u8_NOERROR;
	if(Copy_u8PinIdx<=LastPinNum)
	{
		*Copy_u8PtrToVal=getbit((*DIO_u8PINArr[(Copy_u8PinIdx/8)]), Copy_u8PinIdx %8);
		 local_u8flag=u8_NOERROR;
	}
	else
	{
		 local_u8flag=u8_ERROR;
	}
 	return local_u8flag ;
}
//writing values to pins
u8 DIO_u8WritePinVal(u8 Copy_u8PinIdx,u8 Copy_u8PinVal)
{
u8 local_u8flag=u8_NOERROR;
if(Copy_u8PinIdx<=LastPinNum)
			{
				*DIO_u8PORTArr[(Copy_u8PinIdx/8)]=AssignBit((*DIO_u8PORTArr[(Copy_u8PinIdx/8)]), Copy_u8PinIdx%8, Copy_u8PinVal);
				local_u8flag=u8_NOERROR;
			}
			else
			{
				local_u8flag=u8_ERROR;
			}
		return local_u8flag;
}

// reading port
u8 DIO_u8ReadPortVal(u8 Copy_u8PortIdx,u8* Copy_u8PtrToVal)
{
 u8 local_u8flag=u8_NOERROR;

 if(Copy_u8PortIdx<=LastPortNum)
 					{

 						*Copy_u8PtrToVal=*DIO_u8PINArr[Copy_u8PortIdx];
 						local_u8flag=u8_NOERROR;
 					}
 					else
 					{
 						local_u8flag=u8_ERROR;
 					}
 return local_u8flag;
}

//writing values on port
u8 DIO_u8WritePortVal(u8 Copy_u8PortIdx,u8 Copy_u8PortVal)
{
u8 local_u8flag=u8_NOERROR;

switch(Copy_u8PortIdx)
{
case DIO_u8PORT0:
	*DIO_u8PORTA=Copy_u8PortVal;
break;

case DIO_u8PORT1:
	*DIO_u8PORTB=Copy_u8PortVal;
break;

case DIO_u8PORT2:
	*DIO_u8PORTC=Copy_u8PortVal;
break;

case DIO_u8PORT3:
	*DIO_u8PORTD=Copy_u8PortVal;
break;

default:
local_u8flag=u8_ERROR;
}
	return local_u8flag ;
}

// writing pin direction
u8 DIO_u8WritePinDir(u8 Copy_u8PinIdx,u8 Copy_u8PinDir)
{
u8 local_u8flag=u8_NOERROR;

if(Copy_u8PinIdx<=LastPinNum)
					{
						*DIO_u8DDRArr[(Copy_u8PinIdx/8)]=AssignBit((*DIO_u8DDRArr[(Copy_u8PinIdx/8)]), Copy_u8PinIdx%8, Copy_u8PinDir);
						local_u8flag=u8_NOERROR;
					}
					else
					{
						local_u8flag=u8_ERROR;
					}
return local_u8flag ;
}

//writing port direction
u8 DIO_u8WritePortDir(u8 Copy_u8PortIdx,u8 Copy_u8PortDir)
{
u8 local_u8flag=u8_NOERROR;

if(Copy_u8PortIdx<=LastPortNum)
							{
								*DIO_u8DDRArr[Copy_u8PortIdx]= Copy_u8PortDir;
								local_u8flag=u8_NOERROR;

							}
							else
							{
								local_u8flag=u8_ERROR;
							}
 	return local_u8flag ;
}

// reading port direction
u8 DIO_u8ReadPortDir(u8 Copy_u8PortIdx,u8* Copy_u8PortDir)

{
 u8 local_u8flag=u8_NOERROR;

 if(Copy_u8PortIdx<=LastPortNum)
 						{

 							*Copy_u8PortDir=*DIO_u8DDRArr[Copy_u8PortIdx];
 							local_u8flag=u8_NOERROR;

 						}
 						else
 						{
 							local_u8flag=u8_ERROR;

 						}
	return local_u8flag ;
}

u8 DIO_u8ReadPinDir(u8 Copy_u8PinIdx,u8* Copy_u8PinDir)

{
	u8 local_u8flag=u8_NOERROR;
	if(Copy_u8PinIdx>=0 && Copy_u8PinIdx<=7)
	{
		   * Copy_u8PinDir=getbit(*DIO_u8DDRA,Copy_u8PinIdx);
	}
	else if(Copy_u8PinIdx>=8 && Copy_u8PinIdx<=15)
	{
		* Copy_u8PinDir=getbit(*DIO_u8DDRB,Copy_u8PinIdx);
	}
	else if(Copy_u8PinIdx>=16 && Copy_u8PinIdx<=23)
	{
			* Copy_u8PinDir=getbit(*DIO_u8DDRC,Copy_u8PinIdx);
	}
	else if(Copy_u8PinIdx>=24 && Copy_u8PinIdx<=31)
	{
			* Copy_u8PinDir=getbit(*DIO_u8DDRD,Copy_u8PinIdx);
	}
	else
	{
		local_u8flag=u8_ERROR;
	}
 	return local_u8flag ;
}


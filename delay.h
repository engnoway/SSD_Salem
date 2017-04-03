/*
 * delay.h
 *
 *  Created on: ???/???/????
 *      Author: Ismailia Laptop
 */





#ifndef _delay_H_
#define _delay_H_
                                //125msec gives me 100msec
#include "Delay_config.h"

#define Delay_ms(Copy_u64DelayMs)   do{ u32 Local_u32LoopCounter;  u64 Local_u64DelayCounter; \
                                    for( Local_u64DelayCounter = Copy_u64DelayMs/4;  Local_u64DelayCounter > 0;  Local_u64DelayCounter-- ){ \
                                    for ( Local_u32LoopCounter = ((Delay_SysClock * 1000)/8);  Local_u32LoopCounter > 0;  Local_u32LoopCounter-- ){ \
                                   __asm__("NOP"); }  \
                                  } \
                                  }while(0)


/*
#define Delay_ms(Copy_u64DelayMs)  do{ u64 Copy_u64DelayM; u64 Local_u64DelayCounter;\
u64 Copy_u64DelayMx=((Copy_u64DelayM)*(4000));\
for(Local_u64DelayCounter = Copy_u64DelayMx;Local_u64DelayCounter>0;Local_u64DelayCounter--){\
	 __asm__("NOP");	}\
} while(0)
*/






#endif /* DELAY_H_ */

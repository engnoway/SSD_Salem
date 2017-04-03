/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: Ismailia Laptop
 */

#include "types.h"
//#include "DIO_config.h"
#include "DIO_interface.h"
#include "SSD_interface.h"
//#include "SSD_config.h"

#include "delay.h"

int  main(void)
{
	//u8 x;
	DIO_voidInit();//dio init
	SSD_voidInit();
//	SSD_u8TurnOn(SSD_u8DISP1);
	//SSD_u8TurnOn(SSD_u8DISP1);
 //SSD_u8Display(SSD_u8DISP1,SSD_u8NUM3);
       	//}

    while(1)
    {
    	    	SSD_u8TurnOn(SSD_u8DISP1);
    	    	SSD_u8Display(SSD_u8DISP1,5);
    	    	SSD_u8TurnOff(SSD_u8DISP2);
    	    	Delay_ms(20);
    	    	SSD_u8TurnOn(SSD_u8DISP2);
    	    	SSD_u8Display(SSD_u8DISP2,3);
    	    	SSD_u8TurnOff(SSD_u8DISP1);
    	    	Delay_ms(20);

    	//SSD_u8TurnOff(SSD_u8DISP1);
          // 	Delay_ms(500);
          // 	SSD_u8TurnOn(SSD_u8DISP1);
          //	SSD_u8TurnOn(SSD_u8DISP2);
        	//Delay_ms(500);
        //	SSD_u8TurnOff(SSD_u8DISP1);
        	  //        	Delay_ms(500);
    	//if(SSD_u8GetVal(SSD_u8DISP2,SSD_u8NUM5)==u8_NOERROR)
    //	{
    	//SSD_u8GetVal(SSD_u8DISP1,&x);

   // SSD_u8Display(SSD_u8DISP2,x);
    	//}
    	//else
    	//{

    }
    return 0 ;
}


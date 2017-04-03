/*
 * SSD_prog.c
 *
 *  Created on: ???/???/????
 *      Author: Ismailia Laptop
 */

#include "types.h"
#include "DIO_interface.h"
#include "SSD_Config.h"
#include "SSD_Interface.h"
#include "SSD_Private.h"

static const u8 SSD_Digits_ComCath[10][7] = { { 1, 1, 1, 1, 1, 1, 0 },  // = 0
		{ 0, 1, 1, 0, 0, 0, 0 },  // = 1
		{ 1, 1, 0, 1, 1, 0, 1 },  // = 2
		{ 1, 1, 1, 1, 0, 0, 1 },  // = 3
		{ 0, 1, 1, 0, 0, 1, 1 },  // = 4
		{ 1, 0, 1, 1, 0, 1, 1 },  // = 5 //abcdefg
		{ 1, 0, 1, 1, 1, 1, 1 },  // = 6
		{ 1, 1, 1, 0, 0, 0, 0 },  // = 7
		{ 1, 1, 1, 1, 1, 1, 1 },  // = 8
		{ 1, 1, 1, 1, 0, 1, 1 }   // = 9
};

static const u8 SSD_Digits_ComAnod[10][7] = { { 0, 0, 0, 0, 0, 0, 1 },  // = 0
		{ 1, 0, 0, 1, 1, 1, 1 },  // = 1
		{ 0, 0, 1, 0, 0, 1, 0 },  // = 2
		{ 0, 0, 0, 0, 1, 1, 0 },  // = 3
		{ 1, 0, 0, 1, 1, 0, 0 },  // = 4
		{ 0, 1, 0, 0, 1, 0, 0 },  // = 5
		{ 0, 1, 0, 0, 0, 0, 0 },  // = 6
		{ 0, 0, 0, 1, 1, 1, 1 },  // = 7
		{ 0, 0, 0, 0, 0, 0, 0 },  // = 8
		{ 0, 0, 0, 0, 1, 0, 0 }   // = 9
};

static volatile u8 SSD_CurrentVal[SSD_u8TOTALSSDS] = { SSD_u8DISP1_INITVAL,
SSD_u8DISP2_INITVAL, SSD_u8DISP3_INITVAL, SSD_u8DISP4_INITVAL,
SSD_u8DISP5_INITVAL, SSD_u8DISP6_INITVAL };

/*Comment!: Function to Display a Specific Num on a Specific Display*/
extern u8 SSD_u8Display(u8 Copy_u8DispIdx, u8 Copy_u8DispVal) {
  u8 Local_u8RetrunStatus;

  switch (Copy_u8DispIdx) {
#if (SSD_u8DISP1_INITSTATE==SSD_u8ONSTATE)
#if (SSD_u8DISP1_TYPE==SSD_u8COMCATH)

    case SSD_u8DISP1:

      DIO_u8WritePinVal(SSD_u8DISP1_COM, SSD_u8DISP1_TYPE);
      DIO_u8WritePinVal(16, SSD_Digits_ComCath[Copy_u8DispVal][0]);
      DIO_u8WritePinVal(17, SSD_Digits_ComCath[Copy_u8DispVal][1]);
      DIO_u8WritePinVal(18, SSD_Digits_ComCath[Copy_u8DispVal][2]);
      DIO_u8WritePinVal(19, SSD_Digits_ComCath[Copy_u8DispVal][3]);
      DIO_u8WritePinVal(20, SSD_Digits_ComCath[Copy_u8DispVal][4]);
      DIO_u8WritePinVal(21, SSD_Digits_ComCath[Copy_u8DispVal][5]);
      DIO_u8WritePinVal(22, SSD_Digits_ComCath[Copy_u8DispVal][6]);
      Local_u8RetrunStatus = u8_NOERROR;
      break;
#elif (SSD_u8DISP1_TYPE==SSD_u8COMANOD)
    case SSD_u8DISP1:
      DIO_u8WritePinVal(SSD_u8DISP1_COM, SSD_u8DISP1_TYPE);
      DIO_u8WritePinVal(SSD_u8DISP1_SEGA, SSD_Digits_ComAnod[Copy_u8DispVal][0]);
      DIO_u8WritePinVal(SSD_u8DISP1_SEGB, SSD_Digits_ComAnod[Copy_u8DispVal][1]);
      DIO_u8WritePinVal(SSD_u8DISP1_SEGC, SSD_Digits_ComAnod[Copy_u8DispVal][2]);
      DIO_u8WritePinVal(SSD_u8DISP1_SEGD, SSD_Digits_ComAnod[Copy_u8DispVal][3]);
      DIO_u8WritePinVal(SSD_u8DISP1_SEGE, SSD_Digits_ComAnod[Copy_u8DispVal][4]);
      DIO_u8WritePinVal(SSD_u8DISP1_SEGF, SSD_Digits_ComAnod[Copy_u8DispVal][5]);
      DIO_u8WritePinVal(SSD_u8DISP1_SEGG, SSD_Digits_ComAnod[Copy_u8DispVal][6]);
      Local_u8RetrunStatus = u8_NOERROR;
      break;
#endif
#endif
#if (SSD_u8DISP2_INITSTATE==SSD_u8ONSTATE)
#if (SSD_u8DISP2_TYPE==SSD_u8COMCATH)
    case SSD_u8DISP2:
      DIO_u8WritePinVal(SSD_u8DISP2_COM, SSD_u8DISP2_TYPE);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGA, SSD_Digits_ComCath[Copy_u8DispVal][0]);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGB, SSD_Digits_ComCath[Copy_u8DispVal][1]);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGC, SSD_Digits_ComCath[Copy_u8DispVal][2]);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGD, SSD_Digits_ComCath[Copy_u8DispVal][3]);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGE, SSD_Digits_ComCath[Copy_u8DispVal][4]);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGF, SSD_Digits_ComCath[Copy_u8DispVal][5]);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGG, SSD_Digits_ComCath[Copy_u8DispVal][6]);
      Local_u8RetrunStatus = u8_NOERROR;
      break;
#elif (SSD_u8DISP2_TYPE==SSD_u8COMANOD)
    case SSD_u8DISP2:
      DIO_u8WritePinVal(SSD_u8DISP2_COM, SSD_u8DISP2_TYPE);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGA, SSD_Digits_ComAnod[Copy_u8DispVal][0]);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGB, SSD_Digits_ComAnod[Copy_u8DispVal][1]);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGC, SSD_Digits_ComAnod[Copy_u8DispVal][2]);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGD, SSD_Digits_ComAnod[Copy_u8DispVal][3]);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGE, SSD_Digits_ComAnod[Copy_u8DispVal][4]);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGF, SSD_Digits_ComAnod[Copy_u8DispVal][5]);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGG, SSD_Digits_ComAnod[Copy_u8DispVal][6]);
      Local_u8RetrunStatus = u8_NOERROR;
      break;
#endif
#endif
#if (SSD_u8DISP3_INITSTATE==SSD_u8ONSTATE)
#if (SSD_u8DISP3_TYPE==SSD_u8COMCATH)
    case SSD_u8DISP3:
      DIO_u8WritePinVal(SSD_u8DISP3_COM, SSD_u8DISP3_TYPE);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGA, SSD_Digits_ComCath[Copy_u8DispVal][0]);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGB, SSD_Digits_ComCath[Copy_u8DispVal][1]);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGC, SSD_Digits_ComCath[Copy_u8DispVal][2]);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGD, SSD_Digits_ComCath[Copy_u8DispVal][3]);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGE, SSD_Digits_ComCath[Copy_u8DispVal][4]);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGF, SSD_Digits_ComCath[Copy_u8DispVal][5]);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGG, SSD_Digits_ComCath[Copy_u8DispVal][6]);
      Local_u8RetrunStatus = u8_NOERROR;
      break;
#elif (SSD_u8DISP3_TYPE==SSD_u8COMANOD)
    case SSD_u8DISP3:
      DIO_u8WritePinVal(SSD_u8DISP3_COM, SSD_u8DISP3_TYPE);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGA, SSD_Digits_ComAnod[Copy_u8DispVal][0]);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGB, SSD_Digits_ComAnod[Copy_u8DispVal][1]);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGC, SSD_Digits_ComAnod[Copy_u8DispVal][2]);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGD, SSD_Digits_ComAnod[Copy_u8DispVal][3]);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGE, SSD_Digits_ComAnod[Copy_u8DispVal][4]);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGF, SSD_Digits_ComAnod[Copy_u8DispVal][5]);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGG, SSD_Digits_ComAnod[Copy_u8DispVal][6]);
      Local_u8RetrunStatus = u8_NOERROR;
      break;
#endif
#endif
#if (SSD_u8DISP4_INITSTATE==SSD_u8ONSTATE)
#if (SSD_u8DISP4_TYPE==SSD_u8COMCATH)
    case SSD_u8DISP4:
      DIO_u8WritePinVal(SSD_u8DISP4_COM, SSD_u8DISP4_TYPE);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGA, SSD_Digits_ComCath[Copy_u8DispVal][0]);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGB, SSD_Digits_ComCath[Copy_u8DispVal][1]);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGC, SSD_Digits_ComCath[Copy_u8DispVal][2]);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGD, SSD_Digits_ComCath[Copy_u8DispVal][3]);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGE, SSD_Digits_ComCath[Copy_u8DispVal][4]);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGF, SSD_Digits_ComCath[Copy_u8DispVal][5]);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGG, SSD_Digits_ComCath[Copy_u8DispVal][6]);
      Local_u8RetrunStatus = u8_NOERROR;
      break;
#elif (SSD_u8DISP4_TYPE==SSD_u8COMANOD)
    case SSD_u8DISP4:
      DIO_u8WritePinVal(SSD_u8DISP4_COM, SSD_u8DISP4_TYPE);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGA, SSD_Digits_ComAnod[Copy_u8DispVal][0]);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGB, SSD_Digits_ComAnod[Copy_u8DispVal][1]);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGC, SSD_Digits_ComAnod[Copy_u8DispVal][2]);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGD, SSD_Digits_ComAnod[Copy_u8DispVal][3]);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGE, SSD_Digits_ComAnod[Copy_u8DispVal][4]);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGF, SSD_Digits_ComAnod[Copy_u8DispVal][5]);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGG, SSD_Digits_ComAnod[Copy_u8DispVal][6]);
      Local_u8RetrunStatus = u8_NOERROR;
      break;
#endif
#endif
#if (SSD_u8DISP5_INITSTATE==SSD_u8ONSTATE)
#if (SSD_u8DISP5_TYPE==SSD_u8COMCATH)
    case SSD_u8DISP5:
      DIO_u8WritePinVal(SSD_u8DISP5_COM, SSD_u8DISP5_TYPE);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGA, SSD_Digits_ComCath[Copy_u8DispVal][0]);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGB, SSD_Digits_ComCath[Copy_u8DispVal][1]);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGC, SSD_Digits_ComCath[Copy_u8DispVal][2]);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGD, SSD_Digits_ComCath[Copy_u8DispVal][3]);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGE, SSD_Digits_ComCath[Copy_u8DispVal][4]);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGF, SSD_Digits_ComCath[Copy_u8DispVal][5]);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGG, SSD_Digits_ComCath[Copy_u8DispVal][6]);
      Local_u8RetrunStatus = u8_NOERROR;
      break;
#elif (SSD_u8DISP5_TYPE==SSD_u8COMANOD)
    case SSD_u8DISP5:
      DIO_u8WritePinVal(SSD_u8DISP5_COM, SSD_u8DISP5_TYPE);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGA, SSD_Digits_ComAnod[Copy_u8DispVal][0]);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGB, SSD_Digits_ComAnod[Copy_u8DispVal][1]);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGC, SSD_Digits_ComAnod[Copy_u8DispVal][2]);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGD, SSD_Digits_ComAnod[Copy_u8DispVal][3]);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGE, SSD_Digits_ComAnod[Copy_u8DispVal][4]);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGF, SSD_Digits_ComAnod[Copy_u8DispVal][5]);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGG, SSD_Digits_ComAnod[Copy_u8DispVal][6]);
      Local_u8RetrunStatus = u8_NOERROR;
      break;
#endif
#endif
#if (SSD_u8DISP6_INITSTATE==SSD_u8ONSTATE)
#if (SSD_u8DISP6_TYPE==SSD_u8COMCATH)
    case SSD_u8DISP6:
      DIO_u8WritePinVal(SSD_u8DISP6_COM, SSD_u8DISP6_TYPE);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGA, SSD_Digits_ComCath[Copy_u8DispVal][0]);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGB, SSD_Digits_ComCath[Copy_u8DispVal][1]);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGC, SSD_Digits_ComCath[Copy_u8DispVal][2]);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGD, SSD_Digits_ComCath[Copy_u8DispVal][3]);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGE, SSD_Digits_ComCath[Copy_u8DispVal][4]);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGF, SSD_Digits_ComCath[Copy_u8DispVal][5]);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGG, SSD_Digits_ComCath[Copy_u8DispVal][6]);
      Local_u8RetrunStatus = u8_NOERROR;
      break;
#elif (SSD_u8DISP6_TYPE==SSD_u8COMANOD)
    case SSD_u8DISP6:
      DIO_u8WritePinVal(SSD_u8DISP6_COM, SSD_u8DISP6_TYPE);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGA, SSD_Digits_ComAnod[Copy_u8DispVal][0]);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGB, SSD_Digits_ComAnod[Copy_u8DispVal][1]);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGC, SSD_Digits_ComAnod[Copy_u8DispVal][2]);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGD, SSD_Digits_ComAnod[Copy_u8DispVal][3]);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGE, SSD_Digits_ComAnod[Copy_u8DispVal][4]);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGF, SSD_Digits_ComAnod[Copy_u8DispVal][5]);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGG, SSD_Digits_ComAnod[Copy_u8DispVal][6]);
      Local_u8RetrunStatus = u8_NOERROR;
      break;
#endif
#endif
    default:
      Local_u8RetrunStatus = u8_ERROR;
      break;
  }
  return Local_u8RetrunStatus;
}

/*Comment!: */
extern u8 SSD_u8GetVal(u8 Copy_u8DispIdx, u8* Copy_u8DispVal) {
//maybe we use DIO_u8ReadPinVal then check value with the fixed array
	u8 Local_u8RetrunStatus;
	if( (Copy_u8DispIdx >= SSD_u8DISP1) && (Copy_u8DispIdx <= SSD_u8DISP6) ){
		*Copy_u8DispVal = SSD_CurrentVal[Copy_u8DispIdx];
		Local_u8RetrunStatus = u8_NOERROR;
	}else{
		Local_u8RetrunStatus = u8_ERROR;
	}
	return Local_u8RetrunStatus;
}

/*Comment!: Function to Turn ON a Specific Display*/
extern u8 SSD_u8TurnOn(u8 Copy_u8DispIdx) {
	u8 Local_u8RetrunStatus;
		switch (Copy_u8DispIdx) {
	#if (SSD_u8DISP1_INITSTATE==SSD_u8ONSTATE)
	#if (SSD_u8DISP1_TYPE==SSD_u8COMCATH)
		case SSD_u8DISP1:
			DIO_u8WritePinVal(SSD_u8DISP1_COM, SSD_u8DISP1_TYPE);
			Local_u8RetrunStatus = u8_NOERROR;
			break;
	#elif (SSD_u8DISP1_TYPE==SSD_u8COMANOD)
			case SSD_u8DISP1:
			DIO_u8WritePinVal(SSD_u8DISP1_COM, SSD_u8DISP1_TYPE);
			Local_u8RetrunStatus = u8_NOERROR;
			break;
	#endif
	#endif
	#if (SSD_u8DISP2_INITSTATE==SSD_u8ONSTATE)
	#if (SSD_u8DISP2_TYPE==SSD_u8COMCATH)
			case SSD_u8DISP2:
			DIO_u8WritePinVal(SSD_u8DISP2_COM, SSD_u8DISP2_TYPE);
			Local_u8RetrunStatus = u8_NOERROR;
			break;
	#elif (SSD_u8DISP2_TYPE==SSD_u8COMANOD)
		case SSD_u8DISP2:
			DIO_u8WritePinVal(SSD_u8DISP2_COM, SSD_u8DISP2_TYPE);
			Local_u8RetrunStatus = u8_NOERROR;
			break;
	#endif
	#endif
	#if (SSD_u8DISP3_INITSTATE==SSD_u8ONSTATE)
	#if (SSD_u8DISP3_TYPE==SSD_u8COMCATH)
			case SSD_u8DISP3:
			DIO_u8WritePinVal(SSD_u8DISP3_COM, SSD_u8DISP3_TYPE);
			Local_u8RetrunStatus = u8_NOERROR;
			break;
	#elif (SSD_u8DISP3_TYPE==SSD_u8COMANOD)
			case SSD_u8DISP3:
			DIO_u8WritePinVal(SSD_u8DISP3_COM, SSD_u8DISP3_TYPE);
			Local_u8RetrunStatus = u8_NOERROR;
			break;
	#endif
	#endif
	#if (SSD_u8DISP4_INITSTATE==SSD_u8ONSTATE)
	#if (SSD_u8DISP4_TYPE==SSD_u8COMCATH)
			case SSD_u8DISP4:
			DIO_u8WritePinVal(SSD_u8DISP4_COM, SSD_u8DISP4_TYPE);
			Local_u8RetrunStatus = u8_NOERROR;
			break;
	#elif (SSD_u8DISP4_TYPE==SSD_u8COMANOD)
			case SSD_u8DISP4:
			DIO_u8WritePinVal(SSD_u8DISP4_COM, SSD_u8DISP4_TYPE);
			Local_u8RetrunStatus = u8_NOERROR;
			break;
	#endif
	#endif
	#if (SSD_u8DISP5_INITSTATE==SSD_u8ONSTATE)
	#if (SSD_u8DISP5_TYPE==SSD_u8COMCATH)
			case SSD_u8DISP5:
			DIO_u8WritePinVal(SSD_u8DISP5_COM, SSD_u8DISP5_TYPE);
			Local_u8RetrunStatus = u8_NOERROR;
			break;
	#elif (SSD_u8DISP5_TYPE==SSD_u8COMANOD)
			case SSD_u8DISP5:
			DIO_u8WritePinVal(SSD_u8DISP5_COM, SSD_u8DISP5_TYPE);
			Local_u8RetrunStatus = u8_NOERROR;
			break;
	#endif
	#endif
	#if (SSD_u8DISP6_INITSTATE==SSD_u8ONSTATE)
	#if (SSD_u8DISP6_TYPE==SSD_u8COMCATH)
			case SSD_u8DISP6:
			DIO_u8WritePinVal(SSD_u8DISP6_COM, SSD_u8DISP6_TYPE);
			Local_u8RetrunStatus = u8_NOERROR;
			break;
	#elif (SSD_u8DISP6_TYPE==SSD_u8COMANOD)
			case SSD_u8DISP6:
			DIO_u8WritePinVal(SSD_u8DISP6_COM, SSD_u8DISP6_TYPE);
			Local_u8RetrunStatus = u8_NOERROR;
			break;
	#endif
	#endif
		default:
			Local_u8RetrunStatus = u8_ERROR;
			break;
		}
		return Local_u8RetrunStatus;
}

/*Comment!: Function to Turn OFF a Specific Display*/
extern u8 SSD_u8TurnOff(u8 Copy_u8DispIdx) {
	u8 Local_u8RetrunStatus;
	switch (Copy_u8DispIdx) {
#if (SSD_u8DISP1_INITSTATE==SSD_u8ONSTATE)
#if (SSD_u8DISP1_TYPE==SSD_u8COMCATH)
	case SSD_u8DISP1:
		DIO_u8WritePinVal(SSD_u8DISP1_COM, ~SSD_u8DISP1_TYPE);
		Local_u8RetrunStatus = u8_NOERROR;
		break;
#elif (SSD_u8DISP1_TYPE==SSD_u8COMANOD)
		case SSD_u8DISP1:
		DIO_u8WritePinVal(SSD_u8DISP1_COM, ~SSD_u8DISP1_TYPE);
		Local_u8RetrunStatus = u8_NOERROR;
		break;
#endif
#endif
#if (SSD_u8DISP2_INITSTATE==SSD_u8ONSTATE)
#if (SSD_u8DISP2_TYPE==SSD_u8COMCATH)
		case SSD_u8DISP2:
		DIO_u8WritePinVal(SSD_u8DISP2_COM, ~SSD_u8DISP2_TYPE);
		Local_u8RetrunStatus = u8_NOERROR;
		break;
#elif (SSD_u8DISP2_TYPE==SSD_u8COMANOD)
	case SSD_u8DISP2:
		DIO_u8WritePinVal(SSD_u8DISP2_COM, ~SSD_u8DISP2_TYPE);
		Local_u8RetrunStatus = u8_NOERROR;
		break;
#endif
#endif
#if (SSD_u8DISP3_INITSTATE==SSD_u8ONSTATE)
#if (SSD_u8DISP3_TYPE==SSD_u8COMCATH)
		case SSD_u8DISP3:
		DIO_u8WritePinVal(SSD_u8DISP3_COM, ~SSD_u8DISP3_TYPE);
		Local_u8RetrunStatus = u8_NOERROR;
		break;
#elif (SSD_u8DISP3_TYPE==SSD_u8COMANOD)
		case SSD_u8DISP3:
		DIO_u8WritePinVal(SSD_u8DISP3_COM, ~SSD_u8DISP3_TYPE);
		Local_u8RetrunStatus = u8_NOERROR;
		break;
#endif
#endif
#if (SSD_u8DISP4_INITSTATE==SSD_u8ONSTATE)
#if (SSD_u8DISP4_TYPE==SSD_u8COMCATH)
		case SSD_u8DISP4:
		DIO_u8WritePinVal(SSD_u8DISP4_COM, ~SSD_u8DISP4_TYPE);
		Local_u8RetrunStatus = u8_NOERROR;
		break;
#elif (SSD_u8DISP4_TYPE==SSD_u8COMANOD)
		case SSD_u8DISP4:
		DIO_u8WritePinVal(SSD_u8DISP4_COM, ~SSD_u8DISP4_TYPE);
		Local_u8RetrunStatus = u8_NOERROR;
		break;
#endif
#endif
#if (SSD_u8DISP5_INITSTATE==SSD_u8ONSTATE)
#if (SSD_u8DISP5_TYPE==SSD_u8COMCATH)
		case SSD_u8DISP5:
		DIO_u8WritePinVal(SSD_u8DISP5_COM, ~SSD_u8DISP5_TYPE);
		Local_u8RetrunStatus = u8_NOERROR;
		break;
#elif (SSD_u8DISP5_TYPE==SSD_u8COMANOD)
		case SSD_u8DISP5:
		DIO_u8WritePinVal(SSD_u8DISP5_COM, ~SSD_u8DISP5_TYPE);
		Local_u8RetrunStatus = u8_NOERROR;
		break;
#endif
#endif
#if (SSD_u8DISP6_INITSTATE==SSD_u8ONSTATE)
#if (SSD_u8DISP6_TYPE==SSD_u8COMCATH)
		case SSD_u8DISP6:
		DIO_u8WritePinVal(SSD_u8DISP6_COM, ~SSD_u8DISP6_TYPE);
		Local_u8RetrunStatus = u8_NOERROR;
		break;
#elif (SSD_u8DISP6_TYPE==SSD_u8COMANOD)
		case SSD_u8DISP6:
		DIO_u8WritePinVal(SSD_u8DISP6_COM, ~SSD_u8DISP6_TYPE);
		Local_u8RetrunStatus = u8_NOERROR;
		break;
#endif
#endif
	default:
		Local_u8RetrunStatus = u8_ERROR;
		break;
	}
	return Local_u8RetrunStatus;
}

/*Comment!: Initialization Function*/
extern void SSD_voidInit(void) {
	#if (SSD_u8DISP1_INITSTATE==SSD_u8ONSTATE)
	#if (SSD_u8DISP1_TYPE==SSD_u8COMCATH)
	      DIO_u8WritePinVal(SSD_u8DISP1_COM, SSD_u8DISP1_TYPE);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGA, SSD_Digits_ComCath[SSD_u8DISP1_INITVAL][0]);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGB, SSD_Digits_ComCath[SSD_u8DISP1_INITVAL][1]);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGC, SSD_Digits_ComCath[SSD_u8DISP1_INITVAL][2]);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGD, SSD_Digits_ComCath[SSD_u8DISP1_INITVAL][3]);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGE, SSD_Digits_ComCath[SSD_u8DISP1_INITVAL][4]);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGF, SSD_Digits_ComCath[SSD_u8DISP1_INITVAL][5]);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGG, SSD_Digits_ComCath[SSD_u8DISP1_INITVAL][6]);
	#elif (SSD_u8DISP1_TYPE==SSD_u8COMANOD)
	      DIO_u8WritePinVal(SSD_u8DISP1_COM, SSD_u8DISP1_TYPE);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGA, SSD_Digits_ComAnod[SSD_u8DISP1_INITVAL][0]);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGB, SSD_Digits_ComAnod[SSD_u8DISP1_INITVAL][1]);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGC, SSD_Digits_ComAnod[SSD_u8DISP1_INITVAL][2]);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGD, SSD_Digits_ComAnod[SSD_u8DISP1_INITVAL][3]);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGE, SSD_Digits_ComAnod[SSD_u8DISP1_INITVAL][4]);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGF, SSD_Digits_ComAnod[SSD_u8DISP1_INITVAL][5]);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGG, SSD_Digits_ComAnod[SSD_u8DISP1_INITVAL][6]);
	#endif
	#endif
	#if (SSD_u8DISP2_INITSTATE==SSD_u8ONSTATE)
	#if (SSD_u8DISP2_TYPE==SSD_u8COMCATH)
	      DIO_u8WritePinVal(SSD_u8DISP2_COM, SSD_u8DISP2_TYPE);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGA, SSD_Digits_ComCath[SSD_u8DISP2_INITVAL][0]);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGB, SSD_Digits_ComCath[SSD_u8DISP2_INITVAL][1]);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGC, SSD_Digits_ComCath[SSD_u8DISP2_INITVAL][2]);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGD, SSD_Digits_ComCath[SSD_u8DISP2_INITVAL][3]);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGE, SSD_Digits_ComCath[SSD_u8DISP2_INITVAL][4]);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGF, SSD_Digits_ComCath[SSD_u8DISP2_INITVAL][5]);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGG, SSD_Digits_ComCath[SSD_u8DISP2_INITVAL][6]);
	#elif (SSD_u8DISP2_TYPE==SSD_u8COMANOD)
	      DIO_u8WritePinVal(SSD_u8DISP2_COM, SSD_u8DISP2_TYPE);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGA, SSD_Digits_ComAnod[SSD_u8DISP2_INITVAL][0]);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGB, SSD_Digits_ComAnod[SSD_u8DISP2_INITVAL][1]);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGC, SSD_Digits_ComAnod[SSD_u8DISP2_INITVAL][2]);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGD, SSD_Digits_ComAnod[SSD_u8DISP2_INITVAL][3]);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGE, SSD_Digits_ComAnod[SSD_u8DISP2_INITVAL][4]);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGF, SSD_Digits_ComAnod[SSD_u8DISP2_INITVAL][5]);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGG, SSD_Digits_ComAnod[SSD_u8DISP2_INITVAL][6]);
	#endif
	#endif
	#if (SSD_u8DISP3_INITSTATE==SSD_u8ONSTATE)
	#if (SSD_u8DISP3_TYPE==SSD_u8COMCATH)
	      DIO_u8WritePinVal(SSD_u8DISP3_COM, SSD_u8DISP3_TYPE);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGA, SSD_Digits_ComCath[SSD_u8DISP3_INITVAL][0]);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGB, SSD_Digits_ComCath[SSD_u8DISP3_INITVAL][1]);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGC, SSD_Digits_ComCath[SSD_u8DISP3_INITVAL][2]);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGD, SSD_Digits_ComCath[SSD_u8DISP3_INITVAL][3]);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGE, SSD_Digits_ComCath[SSD_u8DISP3_INITVAL][4]);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGF, SSD_Digits_ComCath[SSD_u8DISP3_INITVAL][5]);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGG, SSD_Digits_ComCath[SSD_u8DISP3_INITVAL][6]);
	#elif (SSD_u8DISP3_TYPE==SSD_u8COMANOD)
	      DIO_u8WritePinVal(SSD_u8DISP3_COM, SSD_u8DISP3_TYPE);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGA, SSD_Digits_ComAnod[SSD_u8DISP3_INITVAL][0]);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGB, SSD_Digits_ComAnod[SSD_u8DISP3_INITVAL][1]);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGC, SSD_Digits_ComAnod[SSD_u8DISP3_INITVAL][2]);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGD, SSD_Digits_ComAnod[SSD_u8DISP3_INITVAL][3]);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGE, SSD_Digits_ComAnod[SSD_u8DISP3_INITVAL][4]);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGF, SSD_Digits_ComAnod[SSD_u8DISP3_INITVAL][5]);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGG, SSD_Digits_ComAnod[SSD_u8DISP3_INITVAL][6]);
	#endif
	#endif
	#if (SSD_u8DISP4_INITSTATE==SSD_u8ONSTATE)
	#if (SSD_u8DISP4_TYPE==SSD_u8COMCATH)
	      DIO_u8WritePinVal(SSD_u8DISP4_COM, SSD_u8DISP4_TYPE);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGA, SSD_Digits_ComCath[SSD_u8DISP4_INITVAL][0]);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGB, SSD_Digits_ComCath[SSD_u8DISP4_INITVAL][1]);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGC, SSD_Digits_ComCath[SSD_u8DISP4_INITVAL][2]);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGD, SSD_Digits_ComCath[SSD_u8DISP4_INITVAL][3]);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGE, SSD_Digits_ComCath[SSD_u8DISP4_INITVAL][4]);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGF, SSD_Digits_ComCath[SSD_u8DISP4_INITVAL][5]);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGG, SSD_Digits_ComCath[SSD_u8DISP4_INITVAL][6]);
	#elif (SSD_u8DISP4_TYPE==SSD_u8COMANOD)
	      DIO_u8WritePinVal(SSD_u8DISP4_COM, SSD_u8DISP4_TYPE);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGA, SSD_Digits_ComAnod[SSD_u8DISP4_INITVAL][0]);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGB, SSD_Digits_ComAnod[SSD_u8DISP4_INITVAL][1]);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGC, SSD_Digits_ComAnod[SSD_u8DISP4_INITVAL][2]);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGD, SSD_Digits_ComAnod[SSD_u8DISP4_INITVAL][3]);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGE, SSD_Digits_ComAnod[SSD_u8DISP4_INITVAL][4]);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGF, SSD_Digits_ComAnod[SSD_u8DISP4_INITVAL][5]);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGG, SSD_Digits_ComAnod[SSD_u8DISP4_INITVAL][6]);
	      Local_u8RetrunStatus = u8OK;
	#endif
	#endif
	#if (SSD_u8DISP5_INITSTATE==SSD_u8ONSTATE)
	#if (SSD_u8DISP5_TYPE==SSD_u8COMCATH)
	      DIO_u8WritePinVal(SSD_u8DISP5_COM, SSD_u8DISP5_TYPE);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGA, SSD_Digits_ComCath[SSD_u8DISP5_INITVAL][0]);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGB, SSD_Digits_ComCath[SSD_u8DISP5_INITVAL][1]);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGC, SSD_Digits_ComCath[SSD_u8DISP5_INITVAL][2]);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGD, SSD_Digits_ComCath[SSD_u8DISP5_INITVAL][3]);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGE, SSD_Digits_ComCath[SSD_u8DISP5_INITVAL][4]);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGF, SSD_Digits_ComCath[SSD_u8DISP5_INITVAL][5]);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGG, SSD_Digits_ComCath[SSD_u8DISP5_INITVAL][6]);
	      Local_u8RetrunStatus = u8OK;
	#elif (SSD_u8DISP5_TYPE==SSD_u8COMANOD)
	      DIO_u8WritePinVal(SSD_u8DISP5_COM, SSD_u8DISP5_TYPE);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGA, SSD_Digits_ComAnod[SSD_u8DISP5_INITVAL][0]);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGB, SSD_Digits_ComAnod[SSD_u8DISP5_INITVAL][1]);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGC, SSD_Digits_ComAnod[SSD_u8DISP5_INITVAL][2]);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGD, SSD_Digits_ComAnod[SSD_u8DISP5_INITVAL][3]);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGE, SSD_Digits_ComAnod[SSD_u8DISP5_INITVAL][4]);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGF, SSD_Digits_ComAnod[SSD_u8DISP5_INITVAL][5]);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGG, SSD_Digits_ComAnod[SSD_u8DISP5_INITVAL][6]);
	#endif
	#endif
	#if (SSD_u8DISP6_INITSTATE==SSD_u8ONSTATE)
	#if (SSD_u8DISP6_TYPE==SSD_u8COMCATH)
	      DIO_u8WritePinVal(SSD_u8DISP6_COM, SSD_u8DISP6_TYPE);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGA, SSD_Digits_ComCath[SSD_u8DISP6_INITVAL][0]);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGB, SSD_Digits_ComCath[SSD_u8DISP6_INITVAL][1]);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGC, SSD_Digits_ComCath[SSD_u8DISP6_INITVAL][2]);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGD, SSD_Digits_ComCath[SSD_u8DISP6_INITVAL][3]);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGE, SSD_Digits_ComCath[SSD_u8DISP6_INITVAL][4]);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGF, SSD_Digits_ComCath[SSD_u8DISP6_INITVAL][5]);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGG, SSD_Digits_ComCath[SSD_u8DISP6_INITVAL][6]);
	      Local_u8RetrunStatus = u8_NOERROR;
	      break;
	#elif (SSD_u8DISP6_TYPE==SSD_u8COMANOD)
	      DIO_u8WritePinVal(SSD_u8DISP6_COM, SSD_u8DISP6_TYPE);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGA, SSD_Digits_ComAnod[SSD_u8DISP6_INITVAL][0]);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGB, SSD_Digits_ComAnod[SSD_u8DISP6_INITVAL][1]);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGC, SSD_Digits_ComAnod[SSD_u8DISP6_INITVAL][2]);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGD, SSD_Digits_ComAnod[SSD_u8DISP6_INITVAL][3]);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGE, SSD_Digits_ComAnod[SSD_u8DISP6_INITVAL][4]);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGF, SSD_Digits_ComAnod[SSD_u8DISP6_INITVAL][5]);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGG, SSD_Digits_ComAnod[SSD_u8DISP6_INITVAL][6]);
	#endif
	#endif
}




#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "DIO.h"

#define PORTA * ( (u8*) 0x3B)
#define DDRA  * ( (u8*) 0x3A)
#define PINA  * ( (u8*) 0x39)
#define PORTB * ( (u8*) 0x38)
#define DDRB  * ( (u8*) 0x37)
#define PINB  * ( (u8*) 0x36)
#define PORTC * ( (u8*) 0x35)
#define DDRC  * ( (u8*) 0x34)
#define PINC  * ( (u8*) 0x33)
#define PORTD * ( (u8*) 0x32)
#define DDRD  * ( (u8*) 0x31)
#define PIND  * ( (u8*) 0x30)



void DIO_voidSetPinMode(u8 Copy_u8Pin, u8 Copy_u8Mode)
{
    u8 Local_u8ReqPort = Copy_u8Pin/8;
    u8 Local_u8ReqPin = Copy_u8Pin%8;
    
    switch (Local_u8ReqPort)
    {
      case 0: ASSIGN_BIT(DDRA,Local_u8ReqPin,Copy_u8Mode); break;
      case 1: ASSIGN_BIT(DDRB,Local_u8ReqPin,Copy_u8Mode); break;
      case 2: ASSIGN_BIT(DDRC,Local_u8ReqPin,Copy_u8Mode); break;
      case 3: ASSIGN_BIT(DDRD,Local_u8ReqPin,Copy_u8Mode); break;
    }
}


void DIO_voidSetPinValue(u8 Copy_u8Pin, u8 Copy_u8Value)
{
    u8 Local_u8ReqPort = Copy_u8Pin/8;
    u8 Local_u8ReqPin = Copy_u8Pin%8;
    
    switch (Local_u8ReqPort)
    {
      case 0: ASSIGN_BIT(PORTA,Local_u8ReqPin,Copy_u8Value); break;
      case 1: ASSIGN_BIT(PORTB,Local_u8ReqPin,Copy_u8Value); break;
      case 2: ASSIGN_BIT(PORTC,Local_u8ReqPin,Copy_u8Value); break;
      case 3: ASSIGN_BIT(PORTD,Local_u8ReqPin,Copy_u8Value); break;
    }
}



u8 DIO_u8GetPinValue(u8 Copy_u8Pin)
{
  
    u8 Local_u8ReqPort = Copy_u8Pin/8;
    u8 Local_u8ReqPin = Copy_u8Pin%8;
    
    u8 Local_u8Result;
    
    switch (Local_u8ReqPort)
    {
      case 0: Local_u8Result = GET_BIT(PINA,Local_u8ReqPin); break;
      case 1: Local_u8Result = GET_BIT(PINB,Local_u8ReqPin); break;
      case 2: Local_u8Result = GET_BIT(PINC,Local_u8ReqPin); break;
      case 3: Local_u8Result = GET_BIT(PIND,Local_u8ReqPin); break;
    }

  return Local_u8Result;
}

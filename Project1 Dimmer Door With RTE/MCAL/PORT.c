

#include "../LIB/STD_TYPES.h"

#include "PORT.h"
#include "PORT_cfg.h"

#define DDRA    *((u8*)0x3A)
#define DDRB    *((u8*)0x37)
#define DDRC    *((u8*)0x34)
#define DDRD    *((u8*)0x31)

#define PORTA * ( (u8*) 0x3B)
#define PORTB * ( (u8*) 0x38)
#define PORTC * ( (u8*) 0x35)
#define PORTD * ( (u8*) 0x32)

void PORT_voidPortInitialize(void)
{
  
  DDRA = PORT_u8_PORTA_DIR;
  DDRB = PORT_u8_PORTB_DIR;
  DDRC = PORT_u8_PORTC_DIR;
  DDRD = PORT_u8_PORTD_DIR;
  
  PORTA = PORT_u8_PORTA_INITIALVALUE;
  PORTB = PORT_u8_PORTB_INITIALVALUE;
  PORTC = PORT_u8_PORTC_INITIALVALUE;
  PORTD = PORT_u8_PORTD_INITIALVALUE;
}

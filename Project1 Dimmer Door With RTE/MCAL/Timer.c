



#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "Timer.h"



static void (*Timer_pfunc)(void);

void __vector_11(void) __attribute__((signal));


#define TIMER_TCCR0 	*((volatile u8*)0x53)
#define TIMER_TCNT0 	*((volatile u8*)0x52)
#define TIMER_TIMSK 	*((volatile u8*)0x59)
#define TIMER_TIFR 		*((volatile u8*)0x58)


#define SREG             *((volatile u8*)0x5F) /* Status Register */
#define SREG_I             7                      /* Global Interrupt Enable Bit */

void TIMER0_voidInit(void)
{
	// Set mode -> normal mode
	// enable ovf int
	// enable global int
	// set preload
	// set prescaler    // last step as it start counting after put any value on 3 bits of prescalar

	SET_BIT(TIMER_TIMSK,0);
	// enable interrupt
	  SET_BIT(SREG,SREG_I);
	 TIMER_TCNT0 = PRELOAD_VAL;
	// set prescalar ->64

	CLR_BIT(TIMER_TCCR0,2);
	SET_BIT(TIMER_TCCR0,1);
	SET_BIT(TIMER_TCCR0,0);
}


void Timer0_voidSetCallback(void(*pfunc)(void))
{
	Timer_pfunc=pfunc;
}
void Timer0_voidSetTime(u8 Copy_u8TimeMs)
{
	/*f32 Desired_Time = 0.5;
	f32 Cov ;
	f32 FloatValue_Cov ;
	f32 Tov;
	u32 Preload;
	Tov = (16777216 * (Prescaler/Sys_Frequency));
	Cov = (Desired_Time *(1/Tov));
	FloatValue_Cov =Cov-(u32)Cov;
	Preload = (u32)(16777216 * FloatValue_Cov);
*/
}

void __vector_11(void)
{
	static u16 Local_u16Counter;
	Local_u16Counter++;
	if (Local_u16Counter == 1000)
	{
		Timer_pfunc();
		Local_u16Counter=0;
	}
	 TIMER_TCNT0 = PRELOAD_VAL;

}


#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/DELAY_MS.h"

#include "../MCAL/DIO.h"
#include "../MCAL/PORT.h"

#include "../RTE/RTE.h"

#include "../APP/SWC_leftDoor.h"
#include "../APP/SWC_rightDoor.h"
#include "../APP/SWC_doorContact.h"
#include "../APP/SWC_dimmer.h"
#include "../APP/SWC_lamp.h"

int main (void)
{

	PORT_voidPortInitialize();
	lampInit();

	while (1)
	{
		updatingLeftDoorStatus();
		updatingRightDoorStatus();
		updatingDoorContactStatus();
		updatingDimmerStatus();
		updatingLampStatus();

		Delay_ms(50);
	}

	return 0;
}

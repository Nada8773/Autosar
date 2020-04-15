
#include "../LIB/STD_TYPES.h"
#include "../RTE/RTE.h"
#include "SWC_dimmer.h"

STD_TYPES_ERROR updatingDimmerStatus(void)
{
	u8 doorContactStatus;

	Rte_Read_DoorsStatus(&doorContactStatus);

	if (DOOR_CLOSED == doorContactStatus)
	{
		Rte_Write_LampStatus(LIGHT_OFF);
	}
	else if (DOOR_OPEN == doorContactStatus)
	{
		Rte_Write_LampStatus(LIGHT_ON);
	}

	return STD_TYPES_ERROR_OK;
}

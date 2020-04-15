
#include "../LIB/STD_TYPES.h"
#include "../RTE/RTE.h"
#include "SWC_doorContact.h"


STD_TYPES_ERROR updatingDoorContactStatus (void)
{
	u8 rightDoorStatus;
	u8 leftDoorStatus;
	u8 doorContactStatus;

	Rte_Read_RightDoorStatus (&rightDoorStatus);
	Rte_Read_LeftDoorStatus(&leftDoorStatus);

	if (DOOR_OPEN == rightDoorStatus || DOOR_OPEN == leftDoorStatus)
	{
		doorContactStatus = DOOR_OPEN;
	}
	else
	{
		doorContactStatus = DOOR_CLOSED;
	}

	Rte_write_DoorsStatus(doorContactStatus);

	return STD_TYPES_ERROR_OK;
}

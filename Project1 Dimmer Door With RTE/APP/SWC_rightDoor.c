

#include "../LIB/STD_TYPES.h"
#include "../RTE/RTE.h"
#include "SWC_rightDoor.h"


STD_TYPES_ERROR updatingRightDoorStatus (void)
{
	u8 rightDoorStatus;

	Rte_Call_RightDoorGetStatus (&rightDoorStatus);
	Rte_write_RightDoorStatus(rightDoorStatus);

	return STD_TYPES_ERROR_OK;
}

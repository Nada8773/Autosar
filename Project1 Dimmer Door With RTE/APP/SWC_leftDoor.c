
#include "../LIB/STD_TYPES.h"
#include "../RTE/RTE.h"
#include "SWC_leftDoor.h"


STD_TYPES_ERROR updatingLeftDoorStatus (void)
{
	u8 leftDoorStatus;

	Rte_Call_LeftDoorGetStatus (&leftDoorStatus);
	Rte_write_LeftDoorStatus(leftDoorStatus);

	return STD_TYPES_ERROR_OK;
}

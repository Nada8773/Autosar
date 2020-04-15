
#include "../LIB/STD_TYPES.h"
#include "../RTE/RTE.h"
#include "SWC_lamp.h"


STD_TYPES_ERROR lampInit(void)
{
	Rte_Call_LampOFF();
	return STD_TYPES_ERROR_OK;
}

STD_TYPES_ERROR updatingLampStatus(void)
{
	u8 lampStatus;

	Rte_Read_LampStatus (&lampStatus);

	if (LIGHT_ON == lampStatus)
	{
		Rte_Call_LampON();
	}
	else if (LIGHT_OFF == lampStatus)
	{
		Rte_Call_LampOFF();
	}
	return STD_TYPES_ERROR_OK;
}

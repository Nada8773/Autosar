
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO.h"
#include "../MCAL/PORT.h"

#include "RTE.h"

/*RTE Variables*/
static u8 Rte_RightDoor = DOOR_OPEN;
static u8 Rte_LeftDoor = DOOR_OPEN;
static u8 Rte_DoorsStatus = DOOR_OPEN;
static u8 Rte_LampStatus = LIGHT_ON;


/*Sender-Receiver RTE Ports*/

STD_TYPES_ERROR Rte_write_RightDoorStatus(u8 Data)
{
	Rte_RightDoor = Data;
	return STD_TYPES_ERROR_OK;
}

STD_TYPES_ERROR Rte_write_LeftDoorStatus(u8 Data)
{
	Rte_LeftDoor = Data;
	return STD_TYPES_ERROR_OK;
}

STD_TYPES_ERROR Rte_Read_RightDoorStatus(u8 *Data)
{
	*Data = Rte_RightDoor;
	return STD_TYPES_ERROR_OK;
}

STD_TYPES_ERROR Rte_Read_LeftDoorStatus(u8 *Data)
{
	*Data = Rte_LeftDoor;
	return STD_TYPES_ERROR_OK;
}

STD_TYPES_ERROR Rte_write_DoorsStatus(u8 Data)
{
	Rte_DoorsStatus = Data;
	return STD_TYPES_ERROR_OK;
}

STD_TYPES_ERROR Rte_Read_DoorsStatus(u8 *Data)
{
	*Data = Rte_DoorsStatus;
	return STD_TYPES_ERROR_OK;
}

STD_TYPES_ERROR Rte_Write_LampStatus(u8 Data)
{
	Rte_LampStatus = Data;
	return STD_TYPES_ERROR_OK;
}

STD_TYPES_ERROR Rte_Read_LampStatus(u8 *Data)
{
	*Data = Rte_LampStatus;
	return STD_TYPES_ERROR_OK;
}

/*client-Server RTE Ports*/

STD_TYPES_ERROR Rte_Call_RightDoorGetStatus(u8* Data)
{
	*Data =  DIO_u8GetPinValue(DIO_u8_PIN0);
	return STD_TYPES_ERROR_OK;
}

STD_TYPES_ERROR Rte_Call_LeftDoorGetStatus(u8* Data)
{
	*Data =  DIO_u8GetPinValue(DIO_u8_PIN1);
	return STD_TYPES_ERROR_OK;
}

STD_TYPES_ERROR Rte_Call_LampON()
{
	DIO_voidSetPinValue(DIO_u8_PIN2, PIN_HIGH);
	return STD_TYPES_ERROR_OK;
}

STD_TYPES_ERROR Rte_Call_LampOFF()
{
	DIO_voidSetPinValue(DIO_u8_PIN2, PIN_LOW);
	return STD_TYPES_ERROR_OK;
}

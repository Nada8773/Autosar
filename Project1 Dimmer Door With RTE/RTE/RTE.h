
#ifndef RTE_H_
#define RTE_H_

/*RTE Enumeration */
# define DOOR_OPEN     0
# define DOOR_CLOSED   1
# define LIGHT_ON	   0
# define LIGHT_OFF     1



/*Sender-Receiver RTE Ports*/

STD_TYPES_ERROR Rte_write_RightDoorStatus(u8 Data);

STD_TYPES_ERROR Rte_write_LeftDoorStatus(u8 Data);

STD_TYPES_ERROR Rte_Read_RightDoorStatus(u8 *Data);

STD_TYPES_ERROR Rte_Read_LeftDoorStatus(u8 *Data);

STD_TYPES_ERROR Rte_write_DoorsStatus(u8 Data);

STD_TYPES_ERROR Rte_Read_DoorsStatus(u8 *Data);

STD_TYPES_ERROR Rte_Write_LampStatus(u8 Data);

STD_TYPES_ERROR Rte_Read_LampStatus(u8 *Data);

/*client-Server RTE Ports*/

STD_TYPES_ERROR Rte_Call_RightDoorGetStatus(u8* Data);
STD_TYPES_ERROR Rte_Call_LeftDoorGetStatus(u8* Data);

STD_TYPES_ERROR Rte_Call_LampON();

STD_TYPES_ERROR Rte_Call_LampOFF();

#endif /* RTE_H_ */

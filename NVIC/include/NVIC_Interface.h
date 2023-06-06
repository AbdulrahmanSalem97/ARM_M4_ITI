/******************************************************************************/
/***************  Name    :   Abdulrahman Salem  ******************************/
/***************  Date    :   10/5/2023          ******************************/
/**************   Version :   1.0V               ******************************/
/**************   SWC     :   NVIC               ******************************/
/******************************************************************************/
#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

void NVIC_voidEnablePerInt(u8 copyInt_Id);
void NVIC_voidDisablePerInt(u8 copyInt_Id);
void NVIC_voidSetPendingFlag(u8 copyInt_Id);
void NVIC_voidClrPendingFlag(u8 copyInt_Id);
void NVIC_voidSetPriorityConfig(u8 copy_u8PriorityOption);
void NVIC_voidSetIntPriority(u8 copyInt_Id,u8 copy_u8GrpPri,u8 copy_u8Subpri);


#define GROUP4BITS_SUBGROUP0BITS  0b011
#define GROUP3BITS_SUBGROUP1BITS  0b100
#define GROUP2BITS_SUBGROUP2BITS  0b101
#define GROUP1BITS_SUBGROUP3BITS  0b110
#define GROUP0BITS_SUBGROUP4BITS  0b111


#endif /* NVIC_INTERFACE_H_ */

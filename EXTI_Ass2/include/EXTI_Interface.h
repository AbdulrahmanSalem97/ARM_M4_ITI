#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_
#define EXTI_u8_GPIOA   0
#define EXTI_u8_GPIOB   1
#define EXTI_u8_GPIOC   2

#define EXTI_u8_PIN0   0
#define EXTI_u8_PIN1   1
#define EXTI_u8_PIN2   2
#define EXTI_u8_PIN3   3
#define EXTI_u8_PIN4   4
#define EXTI_u8_PIN5   5
#define EXTI_u8_PIN6   6
#define EXTI_u8_PIN7   7
#define EXTI_u8_PIN8   8
#define EXTI_u8_PIN9   9
#define EXTI_u8_PIN10  10
#define EXTI_u8_PIN11  11
#define EXTI_u8_PIN12  12
#define EXTI_u8_PIN13  13
#define EXTI_u8_PIN14  14
#define EXTI_u8_PIN15  15
#define EXTI_u8_RISING_EDGE          0
#define EXTI_u8_FALLING_EDGE         1
#define EXTI_u8_ANY_LOGOCAL_CHANGE   2

typedef struct
{
	u8 PortId;
	u8 PinId;
	u8 TriggerLevel;
	void (*Pf)(void);
}EXTI_PinConfig_t;
void EXTI_voidPinIniit            (const EXTI_PinConfig_t*copy_pstrPinInit);
void EXTI_voidIntEnable           (u8 copy_u8EXTI_ID);
void EXTI_voidIntdisable          (u8 copy_u8EXTI_ID);
void EXTI_voidClearPendingFlag    (u8 copy_u8EXTI_ID);


#endif

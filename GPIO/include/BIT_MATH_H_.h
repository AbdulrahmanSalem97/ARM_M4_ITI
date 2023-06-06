#ifndef BIT_MATH_H__H_
#define BIT_MATH_H__H_

#define Set_Bit(reg,bit) reg|=1<<bit
#define Clr_Bit(reg,bit) reg&=~(1<<bit)
#define Get_Bit(reg,bit) ((reg>>bit)&1)
#define Tog_Bit(reg,bit) reg^=1<<bit




#endif
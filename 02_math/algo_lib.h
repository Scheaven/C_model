
#ifndef ALGO_LIB_H    
#define ALGO_LIB_H 

#include <stdint.h>

//*****************************************************************************
// Fast Math Utils for SmartShoes Algorithms 
//              Added 2017.7.2 by xftang
//
//*****************************************************************************

//-----------------------------------------------------------------------------
//Macros
//-----------------------------------------------------------------------------
#define I16_CAP_VALUE(val)    (((val) > (INT16_MAX) ? (INT16_MAX) : (val)))

//Fast square root
void algo_lib_f32_sqrt(float in, float * pOut);
uint16_t algo_lib_int_sqrt(uint32_t* p_u32);
uint16_t algo_lib_int_sqrt_ext(uint32_t input, int32_t highest_nz_bit);

//Shrink to fit
int16_t algo_lib_shrink_i32_to_i16(int32_t* p_i32);
uint32_t algo_lib_shrink_u64_to_u32(uint64_t* p_u64);

//Unsigned Right-Shift Divide Functions
void algo_lib_rs_divide_u64(uint64_t* p_ui64, uint8_t shift);
void algo_lib_rs_divide_u32(uint32_t* p_ui32, uint8_t shift);
void algo_lib_rs_divide_u16(uint16_t* p_ui16, uint8_t shift);

//Signed Right-Shift Divide Functions
void algo_lib_rs_divide_i64(int64_t* p_i64, uint8_t shift);
void algo_lib_rs_divide_i32(int32_t* p_i32, uint8_t shift);
void algo_lib_rs_divide_i16(int16_t* p_i16, uint8_t shift);

//Signed Left-Shift Multiply Functions
void algo_lib_ls_multiply_i64(int64_t* p_i64, uint8_t shift);
void algo_lib_ls_multiply_i32(int32_t* p_i32, uint8_t shift);
void algo_lib_ls_multiply_i16(int16_t* p_i16, uint8_t shift);

//Unsigned Divide Functions
uint32_t algo_lib_fixed_point_divide_u32(uint32_t numerator, uint32_t denominator);
uint16_t algo_lib_fixed_point_divide_u16(uint16_t numerator, uint16_t denominator);

//Unsigned Divide Functions
int32_t algo_lib_fixed_point_divide_i32(int32_t numerator, int32_t denominator);
int16_t algo_lib_fixed_point_divide_i16(int16_t numerator, int16_t denominator);

int32_t _labs(int32_t v);
int16_t _abs(int16_t v);


#define fdiv(src1, src2) ((src1)/(src2))
#define f2i(src) ((int32_t)(src))
#define i2f ((float)(src))
#define fsqrt(src) sqrt(src)
#define fcmp_eq(src1, src2) ((src1) == (src2)) //return: 1 equal, otherwise 0
#define fcmp_lt(src1, src2) ((src1) < (src2))  //return: 1 less than, otherwise 0
#define fcmp_gt(src1, src2) ((src1) > (src2))  //return: 1 greater than, otherwise 0

#endif

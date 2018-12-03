#include "algo_lib.h"
#include <stdlib.h>

/*F32 square root*/
void algo_lib_f32_sqrt(float in, float * pOut)
{
   int ntimes = 50;
   float x;
   x = in * 0.5f;
   while (ntimes--)
   {
       x = (x + in / x) * 0.5f;
   }
   *pOut = x;
}


/* U32 square root */
uint16_t algo_lib_int_sqrt(uint32_t* p_u32)
{
   uint32_t input;
   uint32_t result;
   uint32_t bit_field;

   //Is the input zero?
   if(*p_u32 == 0)
   {
      //Agorithm breaks down, return result
      return (0);
   }

   //Grap a local copy of the input
   input = *p_u32;

   //Initialize result and bit field (2nd to top bit set)
   result = 0;
   bit_field = (0x00000001L << 30);

   //Adjust the bit field for the input
   while(bit_field > input)
   {
      bit_field >>= 2;
   }

   //Continue while the bit filed is non-zero
   while(bit_field != 0)
   {
      //Is the input still larger than result plus the bit field?
      if (input >= (result + bit_field))
      {
         //Subtract the result plus the bit field
         input -= (result + bit_field);

         //Adjust the result
         result = ((result >> 1) + bit_field);
      }
      //Must be smaller
      else
      {
         //Shift the result
         result >>= 1;
      }

      //Shift the bit field
      bit_field >>= 2;
   }

   //Return the result
   return (result);
}

/****************************************************************************
* U32 square root ext, your can save CPU times by specify highest possible non-zero bit of input
* highest_nz_bit needs to be even number.
*****************************************************************************/
uint16_t algo_lib_int_sqrt_ext(uint32_t input, int32_t highest_nz_bit)
{
    uint32_t resultX2s;
    uint32_t t;
    uint32_t shift_b_sqr;

    shift_b_sqr = 1 << highest_nz_bit;
    resultX2s = 0;
    while (shift_b_sqr)
    {
        t = resultX2s + shift_b_sqr;
        if (input >= t)
        {
            resultX2s = (resultX2s >> 1) + shift_b_sqr;
            input -= t;
        }else
            resultX2s >>= 1;
        shift_b_sqr >>= 2;
    }
    return resultX2s;
}


//-----------------------------------------------------------------------------
//Function Name:
//Description:
//
//-----------------------------------------------------------------------------
int16_t algo_lib_shrink_i32_to_i16(int32_t* p_i32)
{
   //Is the i32 bigger than the largest I16?
   if(*p_i32 > (int16_t)((uint16_t)(0xFFFF >> 1) - 1))
   {
      //Clamp it and return
      return ((int16_t)((uint16_t)(0xFFFF >> 1) - 1));
   }
   //Or is it smaller than the smallest I16?
   else if(*p_i32 < -(int16_t)(uint16_t)(0xFFFF >> 1))
   {
      //Clamp it amd return
      return ((int16_t)(uint16_t)(0xFFFF >> 1));
   }
   //Ok to return shrunk version
   else
   {
      return ((int16_t)*p_i32);
   }
}

uint32_t algo_lib_shrink_u64_to_u32(uint64_t* p_u64)
{
   //Is the i32 bigger than the largest I16?
   if(*p_u64 > 4294967295UL)
   {
      //Clamp it and return
      return (4294967295UL);
   }
   //Ok to return shrunk version
   else
   {
      return ((uint32_t)*p_u64);
   }
}

void algo_lib_rs_divide_u64(uint64_t* p_ui64, uint8_t shift)
{
   //Perform shift as normal
   *p_ui64 += ((1 << shift) >> 1);
   *p_ui64 >>= shift;
}


void algo_lib_rs_divide_u32(uint32_t* p_ui32, uint8_t shift)
{
   //Perform shift as normal
   *p_ui32 += ((1 << shift) >> 1);
   *p_ui32 >>= shift;
}

void algo_lib_rs_divide_u16(uint16_t* p_ui16, uint8_t shift)
{
   //Reduce resolution to fixed point
   *p_ui16 += ((1 << shift) >> 1);
   *p_ui16 >>= shift;
}

void algo_lib_rs_divide_i64(int64_t* p_i64, uint8_t shift)
{
   //Is it positive?
   if(*p_i64 >= 0)
   {
      //Perform shift as normal
      *p_i64 += ((1 << shift) >> 1);
      *p_i64 >>= shift;
   }
   //It must be negative
   else
   {
      //Flip sign, perform shift, and return sign
      *p_i64 = -*p_i64;
      *p_i64 += ((1 << shift) >> 1);
      *p_i64 >>= shift;
      *p_i64 = -*p_i64;
   }
}

void algo_lib_rs_divide_i32(int32_t* p_i32, uint8_t shift)
{
   //Is it positive?
   if(*p_i32 >= 0)
   {
      //Perform shift as normal
      *p_i32 += ((1 << shift) >> 1);
      *p_i32 >>= shift;
   }
   //It must be negative
   else
   {
      //Flip sign, perform shift, and return sign
      *p_i32 = -*p_i32;
      *p_i32 += ((1 << shift) >> 1);
      *p_i32 >>= shift;
      *p_i32 = -*p_i32;
   }
}

void algo_lib_rs_divide_i16(int16_t* p_i16, uint8_t shift)
{
   //Is it positive?
   if(*p_i16 >= 0)
   {
      //Perform shift as normal
      *p_i16 += ((1 << shift) >> 1);
      *p_i16 >>= shift;
   }
   //It must be negative
   else
   {
      //Flip sign, perform shift, and return sign
      *p_i16 = -*p_i16;
      *p_i16 += ((1 << shift) >> 1);
      *p_i16 >>= shift;
      *p_i16 = -*p_i16;
   }
}

void algo_lib_ls_multiply_i64(int64_t* p_i64, uint8_t shift)
{
   //Is it positive?
   if(*p_i64 >= 0)
   {
      //Perform shift as normal
      *p_i64 <<= shift;
   }
   //It must be negative
   else
   {
      //Flip sign, perform shift, re-flip
      *p_i64 = -*p_i64;
      *p_i64 <<= shift;
      *p_i64 = -*p_i64;
   }
}

void algo_lib_ls_multiply_i32(int32_t* p_i32, uint8_t shift)
{
   uint64_t temp_result;

   //Is it positive?
   if(*p_i32 >= 0)
   {
      //Perform shift as normal
      temp_result = *p_i32;
      temp_result <<= shift;

      //Did the result overflow?
      if(temp_result >= 2147483647)
      {
         //Clamp the result to I16 max
         *p_i32 = 2147483647;
      }
      //No overflow
      else
      {
         //Use actual result
         *p_i32 = (int32_t)temp_result;
      }
   }
   //It must be negative
   else
   {
      //Flip sign, perform shift
      temp_result = (uint64_t)-*p_i32;
      temp_result <<= shift;

      //Did the result overflow?
      if(temp_result >= 2147483648)
      {
         //Clamp the result to I16 max
         *p_i32 = -2147483647 - 1;
      }
      //No overflow
      else
      {
         //Use actual result with reapplied sign
         *p_i32 = -(int32_t)temp_result;
      }
   }
}

void algo_lib_ls_multiply_i16(int16_t* p_i16, uint8_t shift)
{
   uint32_t temp_result;

   //Is it positive?
   if(*p_i16 >= 0)
   {
      //Perform shift as normal
      temp_result = *p_i16;
      temp_result <<= shift;

      //Did the result overflow?
      if(temp_result >= 32767)
      {
         //Clamp the result to I16 max
         *p_i16 = 32767;
      }
      //No overflow
      else
      {
         //Use actual result
         *p_i16 = (int16_t)temp_result;
      }
   }
   //It must be negative
   else
   {
      //Flip sign, perform shift
      temp_result = (uint32_t)-*p_i16;
      temp_result <<= shift;

      //Did the result overflow?
      if(temp_result >= 32768)
      {
         //Clamp the result to I16 max
         *p_i16 = -32768;
      }
      //No overflow
      else
      {
         //Use actual result with reapplied sign
         *p_i16 = -(int16_t)temp_result;
      }
   }
}

uint32_t algo_lib_fixed_point_divide_u32(uint32_t numerator, uint32_t denominator)
{
   uint32_t result;

   //Perform the division with half-bit rounding
   result = ((numerator + (denominator >> 1)) / denominator);

   //Return result
   return result;
}


uint16_t algo_lib_fixed_point_divide_u16(uint16_t numerator, uint16_t denominator)
{
   uint16_t result;

   //Perform the division with half-bit rounding
   result = ((numerator + (denominator >> 1)) / denominator);

   //Return result
   return result;
}

int32_t algo_lib_fixed_point_divide_i32(int32_t numerator, int32_t denominator)
{
   int32_t result;

   //Is the numerator positive?
   if(numerator > 0)
   {
       //Add the half-bit rounding
       numerator += (_labs(denominator) >> 1);
   }
   //Must be negative
   else
   {
       //Subtract the half-bit rounding
       numerator -= (_labs(denominator) >> 1);
   }

   //Perform the division with half-bit rounding
   result = (numerator / denominator);

   //Return result
   return result;
}

int16_t algo_lib_fixed_point_divide_i16(int16_t numerator, int16_t denominator)
{
   int16_t result;

   //Is the numerator positive?
   if(numerator > 0)
   {
      //Add the half-bit rounding
      numerator += (_abs(denominator) >> 1);
   }
   //Must be negative
   else
   {
      //Subtract the half-bit rounding
      numerator -= (_abs(denominator) >> 1);
   }

   //Perform the division with half-bit rounding
   result = ((numerator + (denominator >> 1)) / denominator);

   //Return result
   return result;
}

int32_t _labs(int32_t v)
{
    if (v < 0) return -v;
    else return v;
}

int16_t _abs(int16_t v)
{
    if (v < 0) return -v;
    else return v;
}
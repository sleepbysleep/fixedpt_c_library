/*
 Copyright 2011 Hoyoung Lee.

 This program is free software; you can redistribute it and/or modify it
 under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful, but
 WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
 License for more details.

 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, please visit www.gnu.org.
*/
#ifndef __FIXED32_H__
#define __FIXED32_H__

#include <inttypes.h>
#include <math.h>

/* Q is a fixed point number format
 * where the number of fractional bits (and optionally the number of integer bits) is specified.
 * For example, a Q15 number has 15 fractional bits;
 * a Q1.14 number has 1 integer bit and 14 fractional bits.
 * and in applications that require constant resolution.
 * - from wikipedia.com
 * Inspired by Atmel Software Framework, and en.wikipedia.org/wiki/Q_(number_format)
 */

// S : sign content, I : integer content, F : fractional content
typedef enum {
  Q32_OUT_OF_RANGE = 0,
  Q30_1, // SIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIF <- -1073741824 < float < 1073741824
  Q29_2, // SIIIIIIIIIIIIIIIIIIIIIIIIIIIIIFF <- -536870912 < float < 536870912
  Q28_3, // SIIIIIIIIIIIIIIIIIIIIIIIIIIIIFFF <- -268435456 < float < 268435456
  Q27_4, // SIIIIIIIIIIIIIIIIIIIIIIIIIIIFFFF <- -134217728 < float < 134217728
  Q26_5, // SIIIIIIIIIIIIIIIIIIIIIIIIIIFFFFF <- -67108864 < float < 67108864
  Q25_6, // SIIIIIIIIIIIIIIIIIIIIIIIIIFFFFFF <- -33554432 < float < 33554432
  Q24_7, // SIIIIIIIIIIIIIIIIIIIIIIIIFFFFFFF <- -16777216 < float < 16777216
  Q23_8, // SIIIIIIIIIIIIIIIIIIIIIIIFFFFFFFF <- -8388608 < float < 8388608
  Q22_9, // SIIIIIIIIIIIIIIIIIIIIIIFFFFFFFFF <- -4194304 < float < 4194304
  Q21_10,// SIIIIIIIIIIIIIIIIIIIIIFFFFFFFFFF <- -2097152 < float < 2097152
  Q20_11,// SIIIIIIIIIIIIIIIIIIIIFFFFFFFFFFF <- -1048576 < float < 1048576
  Q19_12,// SIIIIIIIIIIIIIIIIIIIFFFFFFFFFFFF <- -524288 < float < 524288
  Q18_13,// SIIIIIIIIIIIIIIIIIIFFFFFFFFFFFFF <- -262144 < float < 262144
  Q17_14,// SIIIIIIIIIIIIIIIIIFFFFFFFFFFFFFF <- -131072 < float < 131072
  Q16_15,// SIIIIIIIIIIIIIIIIFFFFFFFFFFFFFFF <- -65536 < float < 65536
  Q15_16,// SIIIIIIIIIIIIIIIFFFFFFFFFFFFFFFF <- -32768 < float < 32768
  Q14_17,// SIIIIIIIIIIIIIIFFFFFFFFFFFFFFFFF <- -16384 < float < 16384
  Q13_18,// SIIIIIIIIIIIIIFFFFFFFFFFFFFFFFFF <- -8192 < float < 8192
  Q12_19,// SIIIIIIIIIIIIFFFFFFFFFFFFFFFFFFF <- -4096 < float < 4096
  Q11_20,// SIIIIIIIIIIIFFFFFFFFFFFFFFFFFFFF <- -2048 < float < 2048
  Q10_21,// SIIIIIIIIIIFFFFFFFFFFFFFFFFFFFFF <= -1024 < float < 1024
  Q9_22, // SIIIIIIIIIFFFFFFFFFFFFFFFFFFFFFF <= -512 < float < 512
  Q8_23, // SIIIIIIIIFFFFFFFFFFFFFFFFFFFFFFF <= -256 < float < 256
  Q7_24, // SIIIIIIIFFFFFFFFFFFFFFFFFFFFFFFF <= -128 < float < 128
  Q6_25, // SIIIIIIFFFFFFFFFFFFFFFFFFFFFFFFF <= -64 < float < 64
  Q5_26, // SIIIIIFFFFFFFFFFFFFFFFFFFFFFFFFF <=  -32 < float < 32
  Q4_27, // SIIIIFFFFFFFFFFFFFFFFFFFFFFFFFFF <= -16 < float < 16
  Q3_28, // SIIIFFFFFFFFFFFFFFFFFFFFFFFFFFFF <= -8 < float < 8
  Q2_29, // SIIFFFFFFFFFFFFFFFFFFFFFFFFFFFFF <= -4 < float < 4
  Q1_30, // SIFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF <= -2 < float < 2
  Q0_31, // SFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF <= -1 < float < 1
  Q32_OUT_OF_RESOLUTION
} fixed32_qformat_t;
typedef int32_t fixed32_t;

#define Q30_1_MIN ((double)INT32_MIN / (1UL<<1))
#define Q30_1_MAX ((double)INT32_MAX / (1UL<<1))
#define Q29_2_MIN ((double)INT32_MIN / (1UL<<2))
#define Q29_2_MAX ((double)INT32_MAX / (1UL<<2))
#define Q28_3_MIN ((double)INT32_MIN / (1UL<<3))
#define Q28_3_MAX ((double)INT32_MAX / (1UL<<3))
#define Q27_4_MIN ((double)INT32_MIN / (1UL<<4))
#define Q27_4_MAX ((double)INT32_MAX / (1UL<<4))
#define Q26_5_MIN ((double)INT32_MIN / (1UL<<5))
#define Q26_5_MAX ((double)INT32_MAX / (1UL<<5))
#define Q25_6_MIN ((double)INT32_MIN / (1UL<<6))
#define Q25_6_MAX ((double)INT32_MAX / (1UL<<6))
#define O24_7_MIN ((double)INT32_MIN / (1UL<<7))
#define Q24_7_MAX ((double)INT32_MAX / (1UL<<7))
#define Q23_8_MIN ((double)INT32_MIN / (1UL<<8))
#define Q23_8_MAX ((double)INT32_MAX / (1UL<<8))
#define Q22_9_MIN ((double)INT32_MIN / (1UL<<9))
#define Q22_9_MAX ((double)INT32_MAX / (1UL<<9))
#define Q21_10_MIN ((double)INT32_MIN / (1UL<<10))
#define Q21_10_MAX ((double)INT32_MAX / (1UL<<10))
#define Q20_11_MIN ((double)INT32_MIN / (1UL<<11))
#define Q20_11_MAX ((double)INT32_MAX / (1UL<<11))
#define Q19_12_MIN ((double)INT32_MIN / (1UL<<12))
#define Q19_12_MAX ((double)INT32_MAX / (1UL<<12))
#define Q18_13_MIN ((double)INT32_MIN / (1UL<<13))
#define Q18_13_MAX ((double)INT32_MAX / (1UL<<13))
#define Q17_14_MIN ((double)INT32_MIN / (1UL<<14))
#define Q17_14_MAX ((double)INT32_MAX / (1UL<<14))
#define Q16_15_MIN ((double)INT32_MIN / (1UL<<15))
#define Q16_15_MAX ((double)INT32_MAX / (1UL<<15))
#define Q15_16_MIN ((double)INT32_MIN / (1UL<<16))
#define Q15_16_MAX ((double)INT32_MAX / (1UL<<16))
#define Q14_17_MIN ((double)INT32_MIN / (1UL<<17))
#define Q14_17_MAX ((double)INT32_MAX / (1UL<<17))
#define Q13_18_MIN ((double)INT32_MIN / (1UL<<18))
#define Q13_18_MAX ((double)INT32_MAX / (1UL<<18))
#define Q12_19_MIN ((double)INT32_MIN / (1UL<<19))
#define Q12_19_MAX ((double)INT32_MAX / (1UL<<19))
#define Q11_20_MIN ((double)INT32_MIN / (1UL<<20))
#define Q11_20_MAX ((double)INT32_MAX / (1UL<<20))
#define Q10_21_MIN ((double)INT32_MIN / (1UL<<21))
#define Q10_21_MAX ((double)INT32_MAX / (1UL<<21))
#define O9_22_MIN ((double)INT32_MIN / (1UL<<22))
#define Q9_22_MAX ((double)INT32_MAX / (1UL<<22))
#define Q8_23_MIN ((double)INT32_MIN / (1UL<<23))
#define Q8_23_MAX ((double)INT32_MAX / (1UL<<23))
#define Q7_24_MIN ((double)INT32_MIN / (1UL<<24))
#define Q7_24_MAX ((double)INT32_MAX / (1UL<<24))
#define Q6_25_MIN ((double)INT32_MIN / (1UL<<25))
#define Q6_25_MAX ((double)INT32_MAX / (1UL<<25))
#define Q5_26_MIN ((double)INT32_MIN / (1UL<<26))
#define Q5_26_MAX ((double)INT32_MAX / (1UL<<26))
#define Q4_27_MIN ((double)INT32_MIN / (1UL<<27))
#define Q4_27_MAX ((double)INT32_MAX / (1UL<<27))
#define Q3_28_MIN ((double)INT32_MIN / (1UL<<28))
#define Q3_28_MAX ((double)INT32_MAX / (1UL<<28))
#define Q2_29_MIN ((double)INT32_MIN / (1UL<<29))
#define Q2_29_MAX ((double)INT32_MAX / (1UL<<29))
#define Q1_30_MIN ((double)INT32_MIN / (1UL<<30))
#define Q1_30_MAX ((double)INT32_MAX / (1UL<<30))
#define Q0_31_MIN ((double)INT32_MIN / (1UL<<31))
#define Q0_31_MAX ((double)INT32_MAX / (1UL<<31))

#ifdef __cplusplus
extern "C" {
#endif

  // Return the Q format with the range larger than given range
  fixed32_qformat_t fixed32_get_qformat_covering_range(double fmin, double fmax);
  // Return the Q format with the unit resolution finer than given epsilon
  fixed32_qformat_t fixed32_get_qformat_covering_resolution(double epsilon);
  // Generate the unit resolutions of Q32 format in float-typed container
  void fixed32_generate_resolutions_in_float(void);
  // Generate the covering ranges of Q32 format in float-typed container
  void fixed32_generate_ranges_in_float(void);
  // Generate the unit resolutions of Q32 format in double-typed container
  void fixed32_generate_resolutions_in_double(void);
  // Generate the covering ranges of Q32 format in double-typed container
  void fixed32_generate_ranges_in_double(void);
  // Conversion between 32bit Q formats
  fixed32_t fixed32_convert(fixed32_t fix32, fixed32_qformat_t q1, fixed32_qformat_t q2);
  // Conversion between 32bit Q format, and standard c-type
  static inline fixed32_t uint8_to_fixed32(uint8_t v, fixed32_qformat_t q) { return (fixed32_t)v << q; }
  static inline fixed32_t int8_to_fixed32(int8_t v, fixed32_qformat_t q) { return (fixed32_t)v << q; }
  static inline fixed32_t uint16_to_fixed32(uint16_t v, fixed32_qformat_t q) { return (fixed32_t)v << q; }
  static inline fixed32_t int16_to_fixed32(int16_t v, fixed32_qformat_t q) { return (fixed32_t)v << q; }
  static inline fixed32_t uint32_to_fixed32(uint32_t v, fixed32_qformat_t q) { return (fixed32_t)v << q; }
  static inline fixed32_t int32_to_fixed32(int32_t v, fixed32_qformat_t q) { return (fixed32_t)v << q; }
  static inline fixed32_t float_to_fixed32(float v, fixed32_qformat_t q) { return (fixed32_t)(v * (1UL << q)); }
  static inline fixed32_t double_to_fixed32(double v, fixed32_qformat_t q) { return (fixed32_t)(v * (1UL << q)); }
  static inline uint8_t fixed32_to_uint8(fixed32_t fix32, fixed32_qformat_t q) { return (uint8_t)(fix32 >> q); }
  static inline int8_t fixed32_to_int8(fixed32_t fix32, fixed32_qformat_t q) { return (int8_t)(fix32 >> q); }
  static inline uint16_t fixed32_to_uint16(fixed32_t fix32, fixed32_qformat_t q) { return (uint16_t)(fix32 >> q); }
  static inline int16_t fixed32_to_int16(fixed32_t fix32, fixed32_qformat_t q) { return (int16_t)(fix32 >> q); }
  static inline uint32_t fixed32_to_uint32(fixed32_t fix32, fixed32_qformat_t q) { return (uint32_t)(fix32 >> q); }
  static inline int32_t fixed32_to_int32(fixed32_t fix32, fixed32_qformat_t q) { return (int32_t)(fix32 >> q); }
  static inline float fixed32_to_float(fixed32_t fix32, fixed32_qformat_t q) { return (float)fix32 / (1UL << q); }
  static inline double fixed32_to_double(fixed32_t fix32, fixed32_qformat_t q) { return (double)fix32 / (1UL << q); }
  // Arithmetic operations of 32bit Q Format
  static inline fixed32_t fixed32_add(fixed32_t a, fixed32_t b) { fixed32_t c; c = a + b; return c; }
  fixed32_t fixed32_add_with_trim(fixed32_t a, fixed32_t b);
  static inline fixed32_t fixed32_subtract(fixed32_t a, fixed32_t b) { fixed32_t c; c = a - b; return c; }
  fixed32_t fixed32_subtract_with_trim(fixed32_t a, fixed32_t b);
  fixed32_t fixed32_multiply(fixed32_t a, fixed32_t b, fixed32_qformat_t q);
  fixed32_t fixed32_divide(fixed32_t a, fixed32_t b, fixed32_qformat_t q);

#ifdef __cplusplus
}
#endif

#endif /* __FIXED32_H__ */

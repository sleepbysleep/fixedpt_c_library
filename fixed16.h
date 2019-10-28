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
#ifndef __FIXED16_H__
#define __FIXED16_H__

#include <inttypes.h>
#include <math.h>

/* 
  Q is a fixed point number format
  where the number of fractional bits
  (and optionally the number of integer bits) is specified.
  For example, a Q15 number has 15 fractional bits;
  a Q1.14 number has 1 integer bit and 14 fractional bits.
  and in applications that require constant resolution.
   - from wikipedia.com
  Inspired by Atmel Software Framework, and
  en.wikipedia.org/wiki/Q_(number_format)
*/
// S : sign content, I : integer content, F : fractional content
typedef enum {
  Q16_OUT_OF_RANGE = 0,
  Q14_1,// SIIIIIIIIIIIIIIF <- -16384 < float < 16384
  Q13_2,// SIIIIIIIIIIIIIFF <-  -8192 < float < 8192
  Q12_3,// SIIIIIIIIIIIIFFF <-  -4096 < float < 4096
  Q11_4,// SIIIIIIIIIIIFFFF <-  -2048 < float < 2048
  Q10_5,// SIIIIIIIIIIFFFFF <-  -1024 < float < 1024
  Q9_6, // SIIIIIIIIIFFFFFF <-   -512 < float < 512
  Q8_7,	// SIIIIIIIIFFFFFFF <-   -256 < float < 256
  Q7_8,	// SIIIIIIIFFFFFFFF <-   -128 < float < 128
  Q6_9,	// SIIIIIIFFFFFFFFF <-    -64 < float < 64
  Q5_10,// SIIIIIFFFFFFFFFF <-    -32 < float < 32
  Q4_11,// SIIIIFFFFFFFFFFF <-    -16 < float < 16
  Q3_12,// SIIIFFFFFFFFFFFF <-     -8 < float < 8
  Q2_13,// SIIFFFFFFFFFFFFF <-     -4 < float < 4
  Q1_14,// SIFFFFFFFFFFFFFF <-     -2 < float < 2
  Q0_15,// SFFFFFFFFFFFFFFF <-     -1 < float < 1
  Q16_OUT_OF_RESOLUTION
} fixed16_qformat_t;

typedef int16_t fixed16_t;

#define Q14_1_MIN ((double)INT16_MIN / (1UL<<1))
#define Q14_1_MAX ((double)INT16_MAX / (1UL<<1))
#define Q13_2_MIN ((double)INT16_MIN / (1UL<<2))
#define Q13_2_MAX ((double)INT16_MAX / (1UL<<2))
#define Q12_3_MIN ((double)INT16_MIN / (1UL<<3))
#define Q12_3_MAX ((double)INT16_MAX / (1UL<<3))
#define Q11_4_MIN ((double)INT16_MIN / (1UL<<4))
#define Q11_4_MAX ((double)INT16_MAX / (1UL<<4))
#define Q10_5_MIN ((double)INT16_MIN / (1UL<<5))
#define Q10_5_MAX ((double)INT16_MAX / (1UL<<5))
#define Q9_6_MIN ((double)INT16_MIN / (1UL<<6))
#define Q9_6_MAX ((double)INT16_MAX / (1UL<<6))
#define O8_7_MIN ((double)INT16_MIN / (1UL<<7))
#define Q8_7_MAX ((double)INT16_MAX / (1UL<<7))
#define Q7_8_MIN ((double)INT16_MIN / (1UL<<8))
#define Q7_8_MAX ((double)INT16_MAX / (1UL<<8))
#define Q6_9_MIN ((double)INT16_MIN / (1UL<<9))
#define Q6_9_MAX ((double)INT16_MAX / (1UL<<9))
#define Q5_10_MIN ((double)INT16_MIN / (1UL<<10))
#define Q5_10_MAX ((double)INT16_MAX / (1UL<<10))
#define Q4_11_MIN ((double)INT16_MIN / (1UL<<11))
#define Q4_11_MAX ((double)INT16_MAX / (1UL<<11))
#define Q3_12_MIN ((double)INT16_MIN / (1UL<<12))
#define Q3_12_MAX ((double)INT16_MAX / (1UL<<12))
#define Q2_13_MIN ((double)INT16_MIN / (1UL<<13))
#define Q2_13_MAX ((double)INT16_MAX / (1UL<<13))
#define Q1_14_MIN ((double)INT16_MIN / (1UL<<14))
#define Q1_14_MAX ((double)INT16_MAX / (1UL<<14))
#define Q0_15_MIN ((double)INT16_MIN / (1UL<<15))
#define Q0_15_MAX ((double)INT16_MAX / (1UL<<15))

#ifdef __cplusplus
extern "C" {
#endif

  // Return the Q format with the range larger than given range
  fixed16_qformat_t fixed16_get_qformat_covering_range(double fmin, double fmax);
  // Return the Q format with the unit resolution finer than given epsilon
  fixed16_qformat_t fixed16_get_qformat_covering_resolution(double epsilon);
  // Generate the unit resolutions of Q16 format in float-typed container
  void fixed16_generate_resolutions_in_float(void);
  // Generate the covering ranges of Q16 format in float-typed container
  void fixed16_generate_ranges_in_float(void);
  // Generate the unit resolutions of Q16 format in double-typed container
  void fixed16_generate_resolutions_in_double(void);
  // Generate the covering ranges of Q16 format in double-typed container
  void fixed16_generate_ranges_in_double(void);
  // Conversion between 16bit Q formats
  fixed16_t fixed16_convert(fixed16_t fix16, fixed16_qformat_t q1, fixed16_qformat_t q2);
  // Conversion between 16bit Q format, and standard c-type
  static inline fixed16_t uint8_to_fixed16(uint8_t v, fixed16_qformat_t q) { return (fixed16_t)v << q; }
  static inline fixed16_t int8_to_fixed16(int8_t v, fixed16_qformat_t q) { return (fixed16_t)v << q; }
  static inline fixed16_t uint16_to_fixed16(uint16_t v, fixed16_qformat_t q) { return (fixed16_t)v << q; }
  static inline fixed16_t int16_to_fixed16(int16_t v, fixed16_qformat_t q) { return (fixed16_t)v << q; }
  static inline fixed16_t uint32_to_fixed16(uint32_t v, fixed16_qformat_t q) { return (fixed16_t)v << q; }
  static inline fixed16_t int32_to_fixed16(int32_t v, fixed16_qformat_t q) { return (fixed16_t)v << q; }
  static inline fixed16_t float_to_fixed16(float v, fixed16_qformat_t q) { return (fixed16_t)(v * (1UL << q)); }
  static inline fixed16_t double_to_fixed16(double v, fixed16_qformat_t q) { return (fixed16_t)(v * (1UL << q)); }
  static inline uint8_t fixed16_to_uint8(fixed16_t fix16, fixed16_qformat_t q) { return (uint8_t)(fix16 >> q); }
  static inline int8_t fixed16_to_int8(fixed16_t fix16, fixed16_qformat_t q) { return (int8_t)(fix16 >> q); }
  static inline uint16_t fixed16_to_uint16(fixed16_t fix16, fixed16_qformat_t q) { return (uint16_t)(fix16 >> q); }
  static inline int16_t fixed16_to_int16(fixed16_t fix16, fixed16_qformat_t q) { return (int16_t)(fix16 >> q); }
  static inline uint32_t fixed16_to_uint32(fixed16_t fix16, fixed16_qformat_t q) { return (uint32_t)(fix16 >> q); }
  static inline int32_t fixed16_to_int32(fixed16_t fix16, fixed16_qformat_t q) { return (int32_t)(fix16 >> q); }
  static inline float fixed16_to_float(fixed16_t fix16, fixed16_qformat_t q) { return (float)fix16 / (1UL << q); }
  static inline double fixed16_to_double(fixed16_t fix16, fixed16_qformat_t q) { return (double)fix16 / (1UL << q); }
  // Arithmetic operations of 16bit Q Format
  static inline fixed16_t fixed16_add(fixed16_t a, fixed16_t b) { fixed16_t c; c = a + b; return c; }
  fixed16_t fixed16_add_with_trim(fixed16_t a, fixed16_t b);
  static inline fixed16_t fixed16_subtract(fixed16_t a, fixed16_t b) { fixed16_t c; c = a - b; return c; }
  fixed16_t fixed16_subtract_with_trim(fixed16_t a, fixed16_t b);
  fixed16_t fixed16_multiply(fixed16_t a, fixed16_t b, fixed16_qformat_t q);
  fixed16_t fixed16_divide(fixed16_t a, fixed16_t b, fixed16_qformat_t q);

#ifdef __cplusplus
}
#endif

#endif /* __FIXED16_H__ */

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
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <stdlib.h>
#include <inttypes.h>

//#define INLINE
#include <fixedpt/fixed16.h>
#include <common.h>

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
int16_t fixed16_convert(int16_t fix16, fixed16_qformat_t q1, fixed16_qformat_t q2)
{
  int dist;

  dist = q2 - q1;
  if (dist > 0) fix16 <<= dist;
  else if (dist < 0) fix16 >>= ABS(dist);

  return fix16;
}

INLINE int16_t uint8_to_fixed16(uint8_t v, fixed16_qformat_t q)
{
  return (int16_t)v << q;
}

INLINE int16_t int8_to_fixed16(int8_t v, fixed16_qformat_t q)
{
  return (int16_t)v << q;
}

INLINE int16_t uint16_to_fixed16(uint16_t v, fixed16_qformat_t q)
{
  return (int16_t)v << q;
}

INLINE int16_t int16_to_fixed16(int16_t v, fixed16_qformat_t q)
{
  return (int16_t)v << q;
}

INLINE int16_t uint32_to_fixed16(uint32_t v, fixed16_qformat_t q)
{
  return (int16_t)v << q;
}

INLINE int16_t int32_to_fixed16(int32_t v, fixed16_qformat_t q)
{
  return (int16_t)v << q;
}

INLINE int16_t float_to_fixed16(float v, fixed16_qformat_t q)
{
  return (int16_t)(v * (1UL << q));
}

INLINE int16_t double_to_fixed16(double v, fixed16_qformat_t q)
{
  return (int16_t)(v * (1UL << q));
}

INLINE uint8_t fixed16_to_uint8(int16_t fix16, fixed16_qformat_t q)
{
  return (uint8_t)(fix16 >> q);
}

INLINE int8_t fixed16_to_int8(int16_t fix16, fixed16_qformat_t q)
{
  return (int8_t)(fix16 >> q);
}

INLINE uint16_t fixed16_to_uint16(int16_t fix16, fixed16_qformat_t q)
{
  return (uint16_t)(fix16 >> q);
}

INLINE int16_t fixed16_to_int16(int16_t fix16, fixed16_qformat_t q)
{
  return (int16_t)(fix16 >> q);
}

INLINE uint32_t fixed16_to_uint32(int16_t fix16, fixed16_qformat_t q)
{
  return (uint32_t)(fix16 >> q);
}

INLINE int32_t fixed16_to_int32(int16_t fix16, fixed16_qformat_t q)
{
  return (int32_t)(fix16 >> q);
}

INLINE float fixed16_to_float(int16_t fix16, fixed16_qformat_t q)
{
  return (float)fix16 / (1UL << q);
}

INLINE double fixed16_to_double(int16_t fix16, fixed16_qformat_t q)
{
  return (double)fix16 / (1UL << q);
}

fixed16_qformat_t fixed16_get_qformat_specifying_range(double fmin, double fmax)
{
  fixed16_qformat_t q;
  int16_t fixmin = INT16_MIN, fixmax = INT16_MAX;

  for (q = Q0_15; q >= Q14_1; q--) {
    if ((fmin >= fixed16_to_double(fixmin, q)) &&
	(fmax <= fixed16_to_double(fixmax, q)))
      return q;
  }

  fprintf(stderr, "This range isn't covered by 'fixed16' at %s, line %d\n", __FILE__, __LINE__);
  //exit(-1);
  return q; // Q16_OUT_OF_RANGE
}

fixed16_qformat_t fixed16_get_qformat_specifying_resolution(double epsilon)
{
  int16_t value;
  fixed16_qformat_t q;

  value = 1;
  for (q = Q14_1; q <= Q0_15; q++) {
    if (epsilon >= fixed16_to_double(value, q))
      return q;
  }

  fprintf(stderr, "This resolution isn't specified by 'fixed16' at %s, line %d\n", __FILE__, __LINE__);
  //exit(-1);
  return q; // Q16_OUT_OF_RANGE
}

void fixed16_generate_float_resolution(void)
{
  int16_t value;
  fixed16_qformat_t q;

  value = 1;
  for (q = Q14_1; q <= Q0_15; q++) {
    printf("Q%d.%d: %d -> %.18e\n", 15-q, q, value, fixed16_to_double(value, q));
  }
}

void fixed16_generate_double_resolution(void)
{
  int16_t value;
  fixed16_qformat_t q;

  value = 1;
  for (q = Q14_1; q <= Q0_15; q++) {
    printf("Q%d.%d: %d -> %.18e\n", 15-q, q, value, fixed16_to_double(value, q));
  }
}

void fixed16_generate_float_mapping(void)
{
  int16_t vmin, vmax;
  fixed16_qformat_t q;

  vmin = INT16_MIN;
  vmax = INT16_MAX;
  for (q = Q14_1; q <= Q0_15; q++) {
    printf("Q%d.%d: %d, %d -> %.18e, %.18e\n", 15-q, q, vmin, vmax, fixed16_to_float(vmin, q), fixed16_to_float(vmax, q));
  }
}

void fixed16_generate_double_mapping(void)
{
  int16_t vmin, vmax;
  fixed16_qformat_t q;

  vmin = INT16_MIN;
  vmax = INT16_MAX;
  for (q = Q14_1; q <= Q0_15; q++) {
    printf("Q%d.%d: %d, %d -> %.18e, %.18e\n", 15-q, q, vmin, vmax, fixed16_to_double(vmin, q), fixed16_to_double(vmax, q));
  }
}

INLINE int16_t fixed16_add(int16_t a, int16_t b)
{
  int16_t c;

  c = a + b;
  return c;
}

int16_t fixed16_add_with_trim(int16_t a, int16_t b)
{
  int16_t c;
  int32_t tmp;

  tmp = (int32_t)a + (int32_t)b;
  if (tmp > INT16_MAX) {
    fprintf(stderr, "The saturation is occurred at %s, line %d.\n", __FILE__, __LINE__);
    tmp = INT16_MAX;
  } else if (tmp < INT16_MIN) {
    fprintf(stderr, "The saturation is occurred at %s, line %d.\n", __FILE__, __LINE__);
    tmp = INT16_MIN;
  }

  c = (int16_t)tmp;
  return c;
}

INLINE int16_t fixed16_subtract(int16_t a, int16_t b)
{
  int16_t c;

  c = a - b;
  return c;
}

int16_t fixed16_subtract_with_trim(int16_t a, int16_t b)
{
  int16_t c;
  int32_t tmp;

  tmp = (int32_t)a - (int32_t)b;
  if (tmp > INT16_MAX) {
    fprintf(stderr, "The saturation is occurred at %s, line %d.\n", __FILE__, __LINE__);
    tmp = INT16_MAX;
  } else if (tmp < INT16_MIN) {
    fprintf(stderr, "The saturation is occurred at %s, line %d.\n", __FILE__, __LINE__);
    tmp = INT16_MIN;
  }

  c = (int16_t)tmp;
  return c;
}

int16_t fixed16_multiply(int16_t a, int16_t b, fixed16_qformat_t q)
{
  int16_t c;
  int32_t tmp;

  tmp = (int32_t)a * (int32_t)b;
  // Rounding
  tmp += (1 << (q-1));
  tmp >>= q;
  if (tmp > INT16_MAX) {
    fprintf(stderr, "The saturation is occurred at %s, line %d.\n", __FILE__, __LINE__);
    tmp = INT16_MAX;
  } else if (tmp < INT16_MIN) { 
    fprintf(stderr, "The saturation is occurred at %s, line %d.\n", __FILE__, __LINE__);
    tmp = INT16_MIN;
  }

  c = (int16_t)tmp;
  return c;
}
	
int16_t fixed16_divide(int16_t a, int16_t b, fixed16_qformat_t q)
{
  int16_t c;
  int32_t tmp;

  // pre-multiply by the base  (Upscale to Q16 so that the result will be in Q8 format)
  tmp = (int32_t)a << q;
  // Rounding: mid values are rounded up (down for negative values).
  if ((tmp >= 0 && b >= 0) || (tmp < 0 && b < 0))
    tmp += b >> 1;
  else
    tmp -= b >> 1;

  c = (int16_t)(tmp/b);

  return c;
}

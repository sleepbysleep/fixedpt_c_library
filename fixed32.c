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
#include <fixedpt/fixed32.h>
#include <common.h>

int32_t fixed32_convert(int32_t fix32, fixed32_qformat_t q1, fixed32_qformat_t q2)
{
  int dist;

  dist = q2 - q1;
  if (dist > 0) fix32 <<= dist;
  else if (dist < 0) fix32 >>= ABS(dist);

  return fix32;
}

INLINE int32_t uint8_to_fixed32(uint8_t v, fixed32_qformat_t q)
{
  return (int32_t)v << q;
}

INLINE int32_t int8_to_fixed32(int8_t v, fixed32_qformat_t q)
{
  return (int32_t)v << q;
}

INLINE int32_t uint16_to_fixed32(uint16_t v, fixed32_qformat_t q)
{
  return (int32_t)v << q;
}

INLINE int32_t int16_to_fixed32(int16_t v, fixed32_qformat_t q)
{
  return (int32_t)v << q;
}

INLINE int32_t uint32_to_fixed32(uint32_t v, fixed32_qformat_t q)
{
  return (int32_t)v << q;
}

INLINE int32_t int32_to_fixed32(int32_t v, fixed32_qformat_t q)
{
  return (int32_t)v << q;
}

INLINE int32_t float_to_fixed32(float v, fixed32_qformat_t q)
{
  return (int32_t)(v * (1UL << q));
}

INLINE int32_t double_to_fixed32(double v, fixed32_qformat_t q)
{
  return (int32_t)(v * (1UL << q));
}

INLINE uint8_t fixed32_to_uint8(int32_t fix32, fixed32_qformat_t q)
{
  return (uint8_t)(fix32 >> q);
}

INLINE int8_t fixed32_to_int8(int32_t fix32, fixed32_qformat_t q)
{
  return (int8_t)(fix32 >> q);
}

INLINE uint16_t fixed32_to_uint16(int32_t fix32, fixed32_qformat_t q)
{
  return (uint16_t)(fix32 >> q);
}

INLINE int16_t fixed32_to_int16(int32_t fix32, fixed32_qformat_t q)
{
  return (int16_t)(fix32 >> q);
}

INLINE uint32_t fixed32_to_uint32(int32_t fix32, fixed32_qformat_t q)
{
  return (uint32_t)(fix32 >> q);
}

INLINE int32_t fixed32_to_int32(int32_t fix32, fixed32_qformat_t q)
{
  return (int32_t)(fix32 >> q);
}

INLINE float fixed32_to_float(int32_t fix32, fixed32_qformat_t q)
{
  return (float)fix32 / (1UL << q);
}

INLINE double fixed32_to_double(int32_t fix32, fixed32_qformat_t q)
{
  return (double)fix32 / (1UL << q);
}

fixed32_qformat_t fixed32_get_qformat_specifying_range(double fmin, double fmax)
{
  fixed32_qformat_t q;
  int32_t fixmin = INT32_MIN, fixmax = INT32_MAX;

  for (q = Q0_31; q >= Q30_1; q--) {
    if ((fmin >= fixed32_to_double(fixmin, q)) &&
	(fmax <= fixed32_to_double(fixmax, q)))
      return q;
  }

  fprintf(stderr, "This range isn't covered by 'fixed32' at %s, line %d.\n", __FILE__, __LINE__);
  //exit(-1);
  return q; // Q32_OUT_OF_RANGE
}

fixed32_qformat_t fixed32_get_qformat_specifying_resolution(double epsilon)
{
  int32_t value;
  fixed32_qformat_t q;

  value = 1;
  for (q = Q30_1; q <= Q0_31; q++) {
    if (epsilon >= fixed32_to_double(value, q))
      return q;
  }

  fprintf(stderr, "This resolution isn't specified by 'fixed32' at %s, line %d.\n", __FILE__, __LINE__);
  //exit(-1);
  return q; // Q32_OUT_OF_RESOLUTION
}

void fixed32_generate_float_resolution(void)
{
  int32_t value;
  fixed32_qformat_t q;

  value = 1;
  for (q = Q30_1; q <= Q0_31; q++) {
    printf("Q%d.%d: %d -> %.18e.\n", 31-q, q, value, fixed32_to_float(value, q));
  }
}

void fixed32_generate_double_resolution(void)
{
  int32_t value;
  fixed32_qformat_t q;

  value = 1;
  for (q = Q30_1; q <= Q0_31; q++) {
    printf("Q%d.%d: %d -> %.18e.\n", 31-q, q, value, fixed32_to_double(value, q));
  }
}

void fixed32_generate_float_mapping(void)
{
  int32_t vmin, vmax;
  fixed32_qformat_t q;

  vmin = INT32_MIN;
  vmax = INT32_MAX;
  for (q = Q30_1; q <= Q0_31; q++) {
    printf("Q%d.%d: %d, %d -> %.18e, %.18e.\n", 31-q, q, vmin, vmax, fixed32_to_float(vmin, q), fixed32_to_float(vmax, q));
  }
}

void fixed32_generate_double_mapping(void)
{
  int32_t vmin, vmax;
  fixed32_qformat_t q;

  vmin = INT32_MIN;
  vmax = INT32_MAX;
  for (q = Q30_1; q <= Q0_31; q++) {
    printf("Q%d.%d: %d, %d => %.18e, %.18e.\n", 31-q, q, vmin, vmax, fixed32_to_double(vmin, q), fixed32_to_double(vmax, q));
  }
}

INLINE int32_t fixed32_add(int32_t a, int32_t b)
{
  int32_t c;
  c = a + b;
  return c;
}

int32_t fixed32_add_with_trim(int32_t a, int32_t b)
{
  int32_t c;
  int64_t tmp;

  tmp = (int64_t)a + (int64_t)b;
  if (tmp > INT32_MAX) {
    fprintf(stderr, "The saturation is occurred at %s, line %d.\n", __FILE__, __LINE__);
    tmp = INT32_MAX;
  } else if (tmp < INT32_MIN) {
    fprintf(stderr, "The saturation is occurred at %s, line %d.\n", __FILE__, __LINE__);
    tmp = INT32_MIN;
  }

  c = (int32_t)tmp;
  return c;
}

INLINE int32_t fixed32_subtract(int32_t a, int32_t b)
{
  int32_t c;

  c = a - b;
  return c;
}

int32_t fixed32_subtract_with_trim(int32_t a, int32_t b)
{
  int32_t c;
  int64_t tmp;

  tmp = (int64_t)a - (int64_t)b;
  if (tmp > INT32_MAX) {
    fprintf(stderr, "The saturation is occurred at %s, line %d.\n", __FILE__, __LINE__);
    tmp = INT32_MAX;
  } else if (tmp < INT32_MIN) {
    fprintf(stderr, "The saturation is occurred at %s, line %d.\n", __FILE__, __LINE__);
    tmp = INT32_MIN;
  }

  c = (int32_t)tmp;
  return c;
}

int32_t fixed32_multiply(int32_t a, int32_t b, fixed32_qformat_t q)
{
  int32_t c;
  int64_t tmp;

  tmp = (int64_t)a * (int64_t)b;

  // Rounding
  tmp += (1 << (q-1));
  tmp >>= q;
  if (tmp > INT32_MAX) {
    fprintf(stderr, "The saturation is occurred at %s, line %d.\n", __FILE__, __LINE__);
    tmp = INT32_MAX;
  } else if (tmp < INT32_MIN) {
    fprintf(stderr, "The saturation is occurred at %s, line %d.\n", __FILE__, __LINE__);
    tmp = INT32_MIN;
  } 

  c = (int32_t)tmp;
  return c;
}

int32_t fixed32_divide(int32_t a, int32_t b, fixed32_qformat_t q)
{
  int32_t c;
  int64_t tmp;

  // pre-multiply by the base (Upscale to Q16 so that will be in Q8 format)
  tmp = (int64_t)a << q;
  // Rounding: mid values are rounded up (down for negative values).
  if ((tmp >= 0 && b >= 0) || (tmp < 0 && b < 0))
    tmp += b>>1;
  else
    tmp -= b>>1;

  c = (int32_t)(tmp / b);
  return c;
}


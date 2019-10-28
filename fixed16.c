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

#include "fixed16.h"

fixed16_t fixed16_convert(fixed16_t fix16, fixed16_qformat_t q1, fixed16_qformat_t q2)
{
  int dist;

  dist = q2 - q1;
  if (dist > 0) fix16 <<= dist;
  else if (dist < 0) fix16 >>= abs(dist);
  /*
  float temp = fixed16_to_float(fix16, q1);
  fixed16_t fix16 = float_to_fixed16(temp, q2);
  */
  return fix16;
}

fixed16_qformat_t fixed16_get_qformat_covering_range(double fmin, double fmax)
{
  fixed16_qformat_t q;
  int16_t fixmin = INT16_MIN, fixmax = INT16_MAX;

  for (q = Q0_15; q >= Q14_1; --q) {
    if ((fmin >= fixed16_to_double(fixmin, q)) &&
	(fmax <= fixed16_to_double(fixmax, q)))
      return q;
  }

  fprintf(stderr, "This range isn't covered by 'fixed16' at %s, line %d\n", __FILE__, __LINE__);
  //exit(-1);
  return q; // Q16_OUT_OF_RANGE
}

fixed16_qformat_t fixed16_get_qformat_covering_resolution(double epsilon)
{
  fixed16_t value;
  fixed16_qformat_t q;

  value = 1;
  for (q = Q14_1; q <= Q0_15; ++q) {
    if (epsilon >= fixed16_to_double(value, q))
      return q;
  }

  fprintf(stderr, "This resolution isn't specified by 'fixed16' at %s, line %d\n", __FILE__, __LINE__);
  //exit(-1);
  return q; // Q16_OUT_OF_RANGE
}

void fixed16_generate_resolutions_in_float(void)
{
  fixed16_qformat_t q;

  printf("Q format of 16bit - Unit resolution in float-typed container\n");
  for (q = Q14_1; q <= Q0_15; ++q) {
    printf("\tQ%d.%d:\t%.18e\n", 15-q, q, fixed16_to_float((fixed16_t)1, q));
  }
}

void fixed16_generate_resolutions_in_double(void)
{
  fixed16_qformat_t q;

  printf("Q format of 16bit - Unit resolution in double-typed container\n");
  for (q = Q14_1; q <= Q0_15; ++q) {
    printf("\tQ%d.%d:\t%.18e\n", 15-q, q, fixed16_to_double((fixed16_t)1, q));
  }
}

void fixed16_generate_ranges_in_float(void)
{
  fixed16_t vmin, vmax;
  fixed16_qformat_t q;

  printf("Q format of 16bit - Covering range in float-typed container\n");
  vmin = INT16_MIN;
  vmax = INT16_MAX;
  for (q = Q14_1; q <= Q0_15; ++q) {
    printf("\tQ%d.%d:\t[%.18e, %.18e]\n", 15-q, q, fixed16_to_float(vmin, q), fixed16_to_float(vmax, q));
  }
}

void fixed16_generate_ranges_in_double(void)
{
  fixed16_t vmin, vmax;
  fixed16_qformat_t q;

  printf("Q format of 16bit - Covering range in double-typed container\n");
  vmin = INT16_MIN;
  vmax = INT16_MAX;
  for (q = Q14_1; q <= Q0_15; q++) {
    printf("\tQ%d.%d:\t[%.18e, %.18e]\n", 15-q, q, fixed16_to_double(vmin, q), fixed16_to_double(vmax, q));
  }
}

fixed16_t fixed16_add_with_trim(fixed16_t a, fixed16_t b)
{
  fixed16_t c;
  int32_t tmp;

  tmp = (int32_t)a + (int32_t)b;
  if (tmp > INT16_MAX) {
    fprintf(stderr, "The saturation is occurred at %s, line %d.\n", __FILE__, __LINE__);
    tmp = INT16_MAX;
  } else if (tmp < INT16_MIN) {
    fprintf(stderr, "The saturation is occurred at %s, line %d.\n", __FILE__, __LINE__);
    tmp = INT16_MIN;
  }

  c = (fixed16_t)tmp;
  return c;
}

fixed16_t fixed16_subtract_with_trim(fixed16_t a, fixed16_t b)
{
  fixed16_t c;
  int32_t tmp;

  tmp = (int32_t)a - (int32_t)b;
  if (tmp > INT16_MAX) {
    fprintf(stderr, "The saturation is occurred at %s, line %d.\n", __FILE__, __LINE__);
    tmp = INT16_MAX;
  } else if (tmp < INT16_MIN) {
    fprintf(stderr, "The saturation is occurred at %s, line %d.\n", __FILE__, __LINE__);
    tmp = INT16_MIN;
  }

  c = (fixed16_t)tmp;
  return c;
}

fixed16_t fixed16_multiply(fixed16_t a, fixed16_t b, fixed16_qformat_t q)
{
  fixed16_t c;
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

  c = (fixed16_t)tmp;
  return c;
}
	
fixed16_t fixed16_divide(fixed16_t a, fixed16_t b, fixed16_qformat_t q)
{
  fixed16_t c;
  int32_t tmp;

  // pre-multiply by the base  (Upscale to Q16 so that the result will be in Q8 format)
  tmp = (int32_t)a << q;
  // Rounding: mid values are rounded up (down for negative values).
  if ((tmp >= 0 && b >= 0) || (tmp < 0 && b < 0))
    tmp += b >> 1;
  else
    tmp -= b >> 1;

  c = (fixed16_t)(tmp/b);

  return c;
}

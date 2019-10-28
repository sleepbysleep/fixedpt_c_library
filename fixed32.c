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

#include "fixed32.h"

fixed32_t fixed32_convert(fixed32_t fix32, fixed32_qformat_t q1, fixed32_qformat_t q2)
{
  int dist;

  dist = q2 - q1;
  if (dist > 0) fix32 <<= dist;
  else if (dist < 0) fix32 >>= abs(dist);

  return fix32;
}

fixed32_qformat_t fixed32_get_qformat_covering_range(double fmin, double fmax)
{
  fixed32_qformat_t q;
  fixed32_t fixmin = INT32_MIN, fixmax = INT32_MAX;

  for (q = Q0_31; q >= Q30_1; --q) {
    if ((fmin >= fixed32_to_double(fixmin, q)) &&
	(fmax <= fixed32_to_double(fixmax, q)))
      return q;
  }

  fprintf(stderr, "This range isn't covered by 'fixed32' at %s, line %d.\n", __FILE__, __LINE__);
  //exit(-1);
  return q; // Q32_OUT_OF_RANGE
}

fixed32_qformat_t fixed32_get_qformat_covering_resolution(double epsilon)
{
  fixed32_t value;
  fixed32_qformat_t q;

  value = 1;
  for (q = Q30_1; q <= Q0_31; ++q) {
    if (epsilon >= fixed32_to_double(value, q))
      return q;
  }

  fprintf(stderr, "This resolution isn't specified by 'fixed32' at %s, line %d.\n", __FILE__, __LINE__);
  //exit(-1);
  return q; // Q32_OUT_OF_RESOLUTION
}

void fixed32_generate_resolutions_in_float(void)
{
  fixed32_qformat_t q;

  printf("Q format of 32bit - Unit resolution in float-typed container\n");
  for (q = Q30_1; q <= Q0_31; ++q) {
    printf("\tQ%d.%d:\t%.18e\n", 31-q, q, fixed32_to_float((fixed32_t)1, q));
  }
}

void fixed32_generate_resolutions_in_double(void)
{
  fixed32_qformat_t q;

  printf("Q format of 32bit - Unit resolution in double-typed container\n");
  for (q = Q30_1; q <= Q0_31; q++) {
    printf("\tQ%d.%d:\t%.18e\n", 31-q, q, fixed32_to_double((fixed32_t)1, q));
  }
}

void fixed32_generate_ranges_in_float(void)
{
  fixed32_t vmin, vmax;
  fixed32_qformat_t q;

  printf("Q format of 32bit - Covering range in float-typed container\n");
  vmin = INT32_MIN;
  vmax = INT32_MAX;
  for (q = Q30_1; q <= Q0_31; ++q) {
    printf("\tQ%d.%d:\t[%.18e, %.18e]\n", 31-q, q, fixed32_to_float(vmin, q), fixed32_to_float(vmax, q));
  }
}

void fixed32_generate_ranges_in_double(void)
{
  fixed32_t vmin, vmax;
  fixed32_qformat_t q;

  printf("Q format of 16bit - Covering range in double-typed container\n");
  vmin = INT32_MIN;
  vmax = INT32_MAX;
  for (q = Q30_1; q <= Q0_31; ++q) {
    printf("\tQ%d.%d:\t[%.18e, %.18e]\n", 31-q, q, fixed32_to_double(vmin, q), fixed32_to_double(vmax, q));
  }
}

fixed32_t fixed32_add_with_trim(fixed32_t a, fixed32_t b)
{
  fixed32_t c;
  int64_t tmp;

  tmp = (int64_t)a + (int64_t)b;
  if (tmp > INT32_MAX) {
    fprintf(stderr, "The saturation is occurred at %s, line %d.\n", __FILE__, __LINE__);
    tmp = INT32_MAX;
  } else if (tmp < INT32_MIN) {
    fprintf(stderr, "The saturation is occurred at %s, line %d.\n", __FILE__, __LINE__);
    tmp = INT32_MIN;
  }

  c = (fixed32_t)tmp;
  return c;
}

fixed32_t fixed32_subtract_with_trim(fixed32_t a, fixed32_t b)
{
  fixed32_t c;
  int64_t tmp;

  tmp = (int64_t)a - (int64_t)b;
  if (tmp > INT32_MAX) {
    fprintf(stderr, "The saturation is occurred at %s, line %d.\n", __FILE__, __LINE__);
    tmp = INT32_MAX;
  } else if (tmp < INT32_MIN) {
    fprintf(stderr, "The saturation is occurred at %s, line %d.\n", __FILE__, __LINE__);
    tmp = INT32_MIN;
  }

  c = (fixed32_t)tmp;
  return c;
}

fixed32_t fixed32_multiply(fixed32_t a, fixed32_t b, fixed32_qformat_t q)
{
  fixed32_t c;
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

  c = (fixed32_t)tmp;
  return c;
}

fixed32_t fixed32_divide(fixed32_t a, fixed32_t b, fixed32_qformat_t q)
{
  fixed32_t c;
  int64_t tmp;

  // pre-multiply by the base (Upscale to Q16 so that will be in Q8 format)
  tmp = (int64_t)a << q;
  // Rounding: mid values are rounded up (down for negative values).
  if ((tmp >= 0 && b >= 0) || (tmp < 0 && b < 0))
    tmp += b>>1;
  else
    tmp -= b>>1;

  c = (fixed32_t)(tmp / b);
  return c;
}


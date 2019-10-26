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
#ifndef __CORDIC_FIXED16_H__
#define __CORDIC_FIXED16_H__

#include <floatpt/realtype.h>
#include <fixedpt/fixed16.h>

#ifdef __cplusplus
extern "C" {
#endif

  real_t CORDIC_fixed16_multiply(real_t a, real_t b, int iteration);
  real_t CORDIC_fixed16_divide(real_t a, real_t b, int iteration);

  // In circular mode
  /* Make sure that the radian is expressed in Q2.13, and
   * the trigonometric is in Q1.14.
   * That means that 'cos_q14' and 'sin_q14' has to be modulated as Q1.14,
   * and 'theta_q13' be as Q2.13.
   */
  void CORDIC_fixed16_compute_cos_and_sin(real_t *cos_t, real_t *sin_t, real_t t, int iteration);
  void CORDIC_fixed16_compute_cos_and_sin_in_Q14(int16_t *cos_q14, int16_t *sin_q14, int16_t t_q13, int iteration);
  real_t CORDIC_fixed16_atan2(real_t y, real_t x, int iteration);
  int16_t CORDIC_fixed16_atan2_in_Q13(int16_t x_q14, int16_t y_q14, int iteration);
  real_t CORDIC_fixed16_enorm2(real_t x, real_t y, int iteration);
  int16_t CORDIC_fixed16_enorm2_in_Q14(int16_t x_q14, int16_t y_q14, int iteration);

  // In hyperbolic mode
  void CORDIC_fixed16_compute_cosh_and_sinh(real_t *cosh_t, real_t *sinh_t, real_t t, int iteration);
  void CORDIC_fixed16_compute_cosh_and_sinh_in_Q14(int16_t *cosh_q14, int16_t *sinh_q14, int16_t t_q14, int iteration);
  real_t CORDIC_fixed16_exp(real_t t, int iteration);
  int16_t CORDIC_fixed16_exp_in_Q14(int16_t t_q14, int iteration);
  real_t CORDIC_fixed16_atanh(real_t x, int iteration);
  int16_t CORDIC_fixed16_atanh_Q14(int16_t x_q14, int iteration);
  real_t CORDIC_fixed16_atanh2(real_t y, real_t x, int iteration);
  int16_t CORDIC_fixed16_atanh2_in_Q14(int16_t y_q14, int16_t x_q14, int iteration);
  real_t CORDIC_fixed16_ln(real_t v, int iteration);
  int16_t CORDIC_fixed16_ln_in_Q14(int16_t v_q14, int iteration);
  real_t CORDIC_fixed16_sqrt(real_t v, int iteration);
  int16_t CORDIC_fixed16_sqrt_in_Q14(int16_t v_q14, int iteration);

#ifdef __cplusplus
}
#endif

#endif /* __CORDIC_FIXED16_H__ */

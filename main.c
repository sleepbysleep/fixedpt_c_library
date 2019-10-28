#include <stdio.h>
#include "fixed16.h"
#include "fixed32.h"

void test_fixed16_in_float(void)
{
  /* Test code for fixed16 */
  fixed16_generate_resolutions_in_float();
  fixed16_generate_ranges_in_float();

  float float_pi = M_PI;
  fixed16_t q2_13_pi = float_to_fixed16(float_pi, Q2_13);
  fixed16_t q4_11_pi = fixed16_convert(q2_13_pi, Q2_13, Q4_11);
  printf("float_to_fixed16:\n %f -> Q2_13(0x%04x) with %f\n", float_pi, q2_13_pi, fixed16_to_float(q2_13_pi, Q2_13));
  printf("fixed16_convert:\n Q2_13(0x%04x) with %f -> Q4_11(0x%04x) with %f\n", q2_13_pi, fixed16_to_float(q2_13_pi, Q2_13), q4_11_pi, fixed16_to_float(q4_11_pi, Q4_11));

  float float_exp = M_E;
  fixed16_t q2_13_exp = float_to_fixed16(float_exp, Q2_13);
  fixed16_t q4_11_exp = fixed16_convert(q2_13_exp, Q2_13, Q4_11);

  fixed16_t sum = fixed16_add(q2_13_pi, q2_13_exp);
  printf("fixed16_add:\n Q2_13(0x%04x) with %f = Q2_13(0x%04x) with %f + Q2_13(0x%04x) with %f\n", sum, fixed16_to_float(sum, Q2_13), q2_13_pi, fixed16_to_float(q2_13_pi, Q2_13), q2_13_exp, fixed16_to_float(q2_13_exp, Q2_13));

  sum = fixed16_add_with_trim(q2_13_pi, q2_13_exp);
  printf("fixed16_add_with_trim:\n Q2_13(0x%04x) with %f = Q2_13(0x%04x) with %f + Q2_13(0x%04x) with %f\n", sum, fixed16_to_float(sum, Q2_13), q2_13_pi, fixed16_to_float(q2_13_pi, Q2_13), q2_13_exp, fixed16_to_float(q2_13_exp, Q2_13));
  
  sum = fixed16_add(q4_11_pi, q4_11_exp);
  printf("fixed16_add:\n Q4_11(0x%04x) with %f = Q4_11(0x%04x) with %f + Q4_11(0x%04x) with %f\n", sum, fixed16_to_float(sum, Q4_11), q4_11_pi, fixed16_to_float(q4_11_pi, Q4_11), q4_11_exp, fixed16_to_float(q4_11_exp, Q4_11));

  sum = fixed16_add_with_trim(q4_11_pi, q4_11_exp);
  printf("fixed16_add_with_trim:\n Q4_11(0x%04x) with %f = Q4_11(0x%04x) with %f + Q4_11(0x%04x) with %f\n", sum, fixed16_to_float(sum, Q4_11), q4_11_pi, fixed16_to_float(q4_11_pi, Q4_11), q4_11_exp, fixed16_to_float(q4_11_exp, Q4_11));

  fixed16_t diff = fixed16_subtract(q2_13_exp, q2_13_pi);
  printf("fixed16_subtract:\n Q2_13(0x%04x) with %f = Q2_13(0x%04x) with %f - Q2_13(0x%04x) with %f\n", diff, fixed16_to_float(diff, Q2_13), q2_13_exp, fixed16_to_float(q2_13_exp, Q2_13), q2_13_pi, fixed16_to_float(q2_13_pi, Q2_13));
  diff = fixed16_subtract_with_trim(q2_13_exp, q2_13_pi);
  printf("fixed16_subtract_with_trim:\n Q2_13(0x%04x) with %f = Q2_13(0x%04x) with %f - Q2_13(0x%04x) with %f\n", diff, fixed16_to_float(diff, Q2_13), q2_13_exp, fixed16_to_float(q2_13_exp, Q2_13), q2_13_pi, fixed16_to_float(q2_13_pi, Q2_13));  

  diff = fixed16_subtract(q4_11_exp, q4_11_pi);
  printf("fixed16_subtract:\n Q4_11(0x%04x) with %f = Q4_11(0x%04x) with %f - Q4_11(0x%04x) with %f\n", diff, fixed16_to_float(diff, Q4_11), q4_11_exp, fixed16_to_float(q4_11_exp, Q4_11), q4_11_pi, fixed16_to_float(q4_11_pi, Q4_11));
  diff = fixed16_subtract_with_trim(q4_11_exp, q4_11_pi);
  printf("fixed16_subtract_with_trim:\n Q4_11(0x%04x) with %f = Q4_11(0x%04x) with %f - Q4_11(0x%04x) with %f\n", diff, fixed16_to_float(diff, Q4_11), q4_11_exp, fixed16_to_float(q4_11_exp, Q4_11), q4_11_pi, fixed16_to_float(q4_11_pi, Q4_11));

  fixed16_t mul = fixed16_multiply(q2_13_pi, q2_13_exp, Q2_13);
  printf("fixed16_multiply:\n Q2_13(0x%04x) with %f = Q2_13(0x%04x) with %f x Q2_13(0x%04x) with %f\n", mul, fixed16_to_float(mul, Q2_13), q2_13_pi, fixed16_to_float(q2_13_pi, Q2_13), q2_13_exp, fixed16_to_float(q2_13_exp, Q2_13));

  mul = fixed16_multiply(q4_11_pi, q4_11_exp, Q4_11);
  printf("fixed16_multiply:\n Q4_11(0x%04x) with %f = Q4_11(0x%04x) with %f x Q4_11(0x%04x) with %f\n", mul, fixed16_to_float(mul, Q4_11), q4_11_pi, fixed16_to_float(q4_11_pi, Q4_11), q4_11_exp, fixed16_to_float(q4_11_exp, Q4_11));

  fixed16_t div = fixed16_divide(q2_13_pi, q2_13_exp, Q2_13);
  printf("fixed16_divide:\n Q2_13(0x%04x) with %f = Q2_13(0x%04x) with %f / Q2_13(0x%04x) with %f\n", div, fixed16_to_float(div, Q2_13), q2_13_pi, fixed16_to_float(q2_13_pi, Q2_13), q2_13_exp, fixed16_to_float(q2_13_exp, Q2_13));

  div = fixed16_divide(q4_11_pi, q4_11_exp, Q4_11);
  printf("fixed16_divide:\n Q4_11(0x%04x) with %f = Q4_11(0x%04x) with %f / Q4_11(0x%04x) with %f\n", div, fixed16_to_float(div, Q4_11), q4_11_pi, fixed16_to_float(q4_11_pi, Q4_11), q4_11_exp, fixed16_to_float(q4_11_exp, Q4_11));
  
}

void test_fixed16_in_double(void)
{
  /* Test code for fixed16 */
  fixed16_generate_resolutions_in_double();
  fixed16_generate_ranges_in_double();

  double double_pi = M_PI;
  fixed16_t q2_13_pi = double_to_fixed16(double_pi, Q2_13);
  fixed16_t q4_11_pi = fixed16_convert(q2_13_pi, Q2_13, Q4_11);
  printf("double_to_fixed16:\n %f -> Q2_13(0x%04x) with %f\n", double_pi, q2_13_pi, fixed16_to_double(q2_13_pi, Q2_13));
  printf("fixed16_convert:\n Q2_13(0x%04x) with %f -> Q4_11(0x%04x) with %f\n", q2_13_pi, fixed16_to_double(q2_13_pi, Q2_13), q4_11_pi, fixed16_to_double(q4_11_pi, Q4_11));

  double double_exp = M_E;
  fixed16_t q2_13_exp = double_to_fixed16(double_exp, Q2_13);
  fixed16_t q4_11_exp = fixed16_convert(q2_13_exp, Q2_13, Q4_11);
  fixed16_t sum = fixed16_add(q2_13_pi, q2_13_exp);
  printf("fixed16_add:\n Q2_13(0x%04x) with %f = Q2_13(0x%04x) with %f + Q2_13(0x%04x) with %f\n", sum, fixed16_to_double(sum, Q2_13), q2_13_pi, fixed16_to_double(q2_13_pi, Q2_13), q2_13_exp, fixed16_to_double(q2_13_exp, Q2_13));

  sum = fixed16_add_with_trim(q2_13_pi, q2_13_exp);
  printf("fixed16_add_with_trim:\n Q2_13(0x%04x) with %f = Q2_13(0x%04x) with %f + Q2_13(0x%04x) with %f\n", sum, fixed16_to_double(sum, Q2_13), q2_13_pi, fixed16_to_double(q2_13_pi, Q2_13), q2_13_exp, fixed16_to_double(q2_13_exp, Q2_13));
  
  sum = fixed16_add(q4_11_pi, q4_11_exp);
  printf("fixed16_add:\n Q4_11(0x%04x) with %f = Q4_11(0x%04x) with %f + Q4_11(0x%04x) with %f\n", sum, fixed16_to_double(sum, Q4_11), q4_11_pi, fixed16_to_double(q4_11_pi, Q4_11), q4_11_exp, fixed16_to_double(q4_11_exp, Q4_11));

  sum = fixed16_add_with_trim(q4_11_pi, q4_11_exp);
  printf("fixed16_add_with_trim:\n Q4_11(0x%04x) with %f = Q4_11(0x%04x) with %f + Q4_11(0x%04x) with %f\n", sum, fixed16_to_double(sum, Q4_11), q4_11_pi, fixed16_to_double(q4_11_pi, Q4_11), q4_11_exp, fixed16_to_double(q4_11_exp, Q4_11));

  fixed16_t diff = fixed16_subtract(q2_13_exp, q2_13_pi);
  printf("fixed16_subtract:\n Q2_13(0x%04x) with %f = Q2_13(0x%04x) with %f - Q2_13(0x%04x) with %f\n", diff, fixed16_to_double(diff, Q2_13), q2_13_exp, fixed16_to_double(q2_13_exp, Q2_13), q2_13_pi, fixed16_to_double(q2_13_pi, Q2_13));
  diff = fixed16_subtract_with_trim(q2_13_exp, q2_13_pi);
  printf("fixed16_subtract_with_trim:\n Q2_13(0x%04x) with %f = Q2_13(0x%04x) with %f - Q2_13(0x%04x) with %f\n", diff, fixed16_to_double(diff, Q2_13), q2_13_exp, fixed16_to_double(q2_13_exp, Q2_13), q2_13_pi, fixed16_to_double(q2_13_pi, Q2_13));  

  diff = fixed16_subtract(q4_11_exp, q4_11_pi);
  printf("fixed16_subtract:\n Q4_11(0x%04x) with %f = Q4_11(0x%04x) with %f - Q4_11(0x%04x) with %f\n", diff, fixed16_to_double(diff, Q4_11), q4_11_exp, fixed16_to_double(q4_11_exp, Q4_11), q4_11_pi, fixed16_to_double(q4_11_pi, Q4_11));
  diff = fixed16_subtract_with_trim(q4_11_exp, q4_11_pi);
  printf("fixed16_subtract_with_trim:\n Q4_11(0x%04x) with %f = Q4_11(0x%04x) with %f - Q4_11(0x%04x) with %f\n", diff, fixed16_to_double(diff, Q4_11), q4_11_exp, fixed16_to_double(q4_11_exp, Q4_11), q4_11_pi, fixed16_to_double(q4_11_pi, Q4_11));

  fixed16_t mul = fixed16_multiply(q2_13_pi, q2_13_exp, Q2_13);
  printf("fixed16_multiply:\n Q2_13(0x%04x) with %f = Q2_13(0x%04x) with %f x Q2_13(0x%04x) with %f\n", mul, fixed16_to_double(mul, Q2_13), q2_13_pi, fixed16_to_double(q2_13_pi, Q2_13), q2_13_exp, fixed16_to_double(q2_13_exp, Q2_13));

  mul = fixed16_multiply(q4_11_pi, q4_11_exp, Q4_11);
  printf("fixed16_multiply:\n Q4_11(0x%04x) with %f = Q4_11(0x%04x) with %f x Q4_11(0x%04x) with %f\n", mul, fixed16_to_double(mul, Q4_11), q4_11_pi, fixed16_to_double(q4_11_pi, Q4_11), q4_11_exp, fixed16_to_double(q4_11_exp, Q4_11));

  fixed16_t div = fixed16_divide(q2_13_pi, q2_13_exp, Q2_13);
  printf("fixed16_divide:\n Q2_13(0x%04x) with %f = Q2_13(0x%04x) with %f / Q2_13(0x%04x) with %f\n", div, fixed16_to_double(div, Q2_13), q2_13_pi, fixed16_to_double(q2_13_pi, Q2_13), q2_13_exp, fixed16_to_double(q2_13_exp, Q2_13));

  div = fixed16_divide(q4_11_pi, q4_11_exp, Q4_11);
  printf("fixed16_divide:\n Q4_11(0x%04x) with %f = Q4_11(0x%04x) with %f / Q4_11(0x%04x) with %f\n", div, fixed16_to_double(div, Q4_11), q4_11_pi, fixed16_to_double(q4_11_pi, Q4_11), q4_11_exp, fixed16_to_double(q4_11_exp, Q4_11));
  
}

void test_fixed32_in_float(void)
{
  /* Test code for fixed32 */
  fixed32_generate_resolutions_in_float();
  fixed32_generate_ranges_in_float();

  float float_pi = M_PI;
  fixed32_t q2_29_pi = float_to_fixed32(float_pi, Q2_29);
  fixed32_t q4_27_pi = fixed32_convert(q2_29_pi, Q2_29, Q4_27);
  printf("float_to_fixed32:\n %f -> Q2_29(0x%04x) with %f\n", float_pi, q2_29_pi, fixed32_to_float(q2_29_pi, Q2_29));
  printf("fixed32_convert:\n Q2_29(0x%04x) with %f -> Q4_27(0x%04x) with %f\n", q2_29_pi, fixed32_to_float(q2_29_pi, Q2_29), q4_27_pi, fixed32_to_float(q4_27_pi, Q4_27));

  float float_exp = M_E;
  fixed32_t q2_29_exp = float_to_fixed32(float_exp, Q2_29);
  fixed32_t q4_27_exp = fixed32_convert(q2_29_exp, Q2_29, Q4_27);
  fixed32_t sum = fixed32_add(q2_29_pi, q2_29_exp);
  printf("fixed32_add:\n Q2_29(0x%04x) with %f = Q2_29(0x%04x) with %f + Q2_29(0x%04x) with %f\n", sum, fixed32_to_float(sum, Q2_29), q2_29_pi, fixed32_to_float(q2_29_pi, Q2_29), q2_29_exp, fixed32_to_float(q2_29_exp, Q2_29));

  sum = fixed32_add_with_trim(q2_29_pi, q2_29_exp);
  printf("fixed32_add_with_trim:\n Q2_29(0x%04x) with %f = Q2_29(0x%04x) with %f + Q2_29(0x%04x) with %f\n", sum, fixed32_to_float(sum, Q2_29), q2_29_pi, fixed32_to_float(q2_29_pi, Q2_29), q2_29_exp, fixed32_to_float(q2_29_exp, Q2_29));
  
  sum = fixed32_add(q4_27_pi, q4_27_exp);
  printf("fixed32_add:\n Q4_27(0x%04x) with %f = Q4_27(0x%04x) with %f + Q4_27(0x%04x) with %f\n", sum, fixed32_to_float(sum, Q4_27), q4_27_pi, fixed32_to_float(q4_27_pi, Q4_27), q4_27_exp, fixed32_to_float(q4_27_exp, Q4_27));

  sum = fixed32_add_with_trim(q4_27_pi, q4_27_exp);
  printf("fixed32_add_with_trim:\n Q4_27(0x%04x) with %f = Q4_27(0x%04x) with %f + Q4_27(0x%04x) with %f\n", sum, fixed32_to_float(sum, Q4_27), q4_27_pi, fixed32_to_float(q4_27_pi, Q4_27), q4_27_exp, fixed32_to_float(q4_27_exp, Q4_27));

  fixed32_t diff = fixed32_subtract(q2_29_exp, q2_29_pi);
  printf("fixed32_subtract:\n Q2_29(0x%04x) with %f = Q2_29(0x%04x) with %f - Q2_29(0x%04x) with %f\n", diff, fixed32_to_float(diff, Q2_29), q2_29_exp, fixed32_to_float(q2_29_exp, Q2_29), q2_29_pi, fixed32_to_float(q2_29_pi, Q2_29));
  diff = fixed32_subtract_with_trim(q2_29_exp, q2_29_pi);
  printf("fixed32_subtract_with_trim:\n Q2_29(0x%04x) with %f = Q2_29(0x%04x) with %f - Q2_29(0x%04x) with %f\n", diff, fixed32_to_float(diff, Q2_29), q2_29_exp, fixed32_to_float(q2_29_exp, Q2_29), q2_29_pi, fixed32_to_float(q2_29_pi, Q2_29));  

  diff = fixed32_subtract(q4_27_exp, q4_27_pi);
  printf("fixed32_subtract:\n Q4_27(0x%04x) with %f = Q4_27(0x%04x) with %f - Q4_27(0x%04x) with %f\n", diff, fixed32_to_float(diff, Q4_27), q4_27_exp, fixed32_to_float(q4_27_exp, Q4_27), q4_27_pi, fixed32_to_float(q4_27_pi, Q4_27));
  diff = fixed32_subtract_with_trim(q4_27_exp, q4_27_pi);
  printf("fixed32_subtract_with_trim:\n Q4_27(0x%04x) with %f = Q4_27(0x%04x) with %f - Q4_27(0x%04x) with %f\n", diff, fixed32_to_float(diff, Q4_27), q4_27_exp, fixed32_to_float(q4_27_exp, Q4_27), q4_27_pi, fixed32_to_float(q4_27_pi, Q4_27));

  fixed32_t mul = fixed32_multiply(q2_29_pi, q2_29_exp, Q2_29);
  printf("fixed32_multiply:\n Q2_29(0x%04x) with %f = Q2_29(0x%04x) with %f x Q2_29(0x%04x) with %f\n", mul, fixed32_to_float(mul, Q2_29), q2_29_pi, fixed32_to_float(q2_29_pi, Q2_29), q2_29_exp, fixed32_to_float(q2_29_exp, Q2_29));

  mul = fixed32_multiply(q4_27_pi, q4_27_exp, Q4_27);
  printf("fixed32_multiply:\n Q4_27(0x%04x) with %f = Q4_27(0x%04x) with %f x Q4_27(0x%04x) with %f\n", mul, fixed32_to_float(mul, Q4_27), q4_27_pi, fixed32_to_float(q4_27_pi, Q4_27), q4_27_exp, fixed32_to_float(q4_27_exp, Q4_27));

  fixed32_t div = fixed32_divide(q2_29_pi, q2_29_exp, Q2_29);
  printf("fixed32_divide:\n Q2_29(0x%04x) with %f = Q2_29(0x%04x) with %f / Q2_29(0x%04x) with %f\n", div, fixed32_to_float(div, Q2_29), q2_29_pi, fixed32_to_float(q2_29_pi, Q2_29), q2_29_exp, fixed32_to_float(q2_29_exp, Q2_29));

  div = fixed32_divide(q4_27_pi, q4_27_exp, Q4_27);
  printf("fixed32_divide:\n Q4_27(0x%04x) with %f = Q4_27(0x%04x) with %f / Q4_27(0x%04x) with %f\n", div, fixed32_to_float(div, Q4_27), q4_27_pi, fixed32_to_float(q4_27_pi, Q4_27), q4_27_exp, fixed32_to_float(q4_27_exp, Q4_27));
  
}

void test_fixed32_in_double(void)
{
  /* Test code for fixed32 */
  fixed32_generate_resolutions_in_double();
  fixed32_generate_ranges_in_double();

  double double_pi = M_PI;
  fixed32_t q2_29_pi = double_to_fixed32(double_pi, Q2_29);
  fixed32_t q4_27_pi = fixed32_convert(q2_29_pi, Q2_29, Q4_27);
  printf("double_to_fixed32:\n %f -> Q2_29(0x%04x) with %f\n", double_pi, q2_29_pi, fixed32_to_double(q2_29_pi, Q2_29));
  printf("fixed32_convert:\n Q2_29(0x%04x) with %f -> Q4_27(0x%04x) with %f\n", q2_29_pi, fixed32_to_double(q2_29_pi, Q2_29), q4_27_pi, fixed32_to_double(q4_27_pi, Q4_27));

  double double_exp = M_E;
  fixed32_t q2_29_exp = double_to_fixed32(double_exp, Q2_29);
  fixed32_t q4_27_exp = fixed32_convert(q2_29_exp, Q2_29, Q4_27);
  fixed32_t sum = fixed32_add(q2_29_pi, q2_29_exp);
  printf("fixed32_add:\n Q2_29(0x%04x) with %f = Q2_29(0x%04x) with %f + Q2_29(0x%04x) with %f\n", sum, fixed32_to_double(sum, Q2_29), q2_29_pi, fixed32_to_double(q2_29_pi, Q2_29), q2_29_exp, fixed32_to_double(q2_29_exp, Q2_29));

  sum = fixed32_add_with_trim(q2_29_pi, q2_29_exp);
  printf("fixed32_add_with_trim:\n Q2_29(0x%04x) with %f = Q2_29(0x%04x) with %f + Q2_29(0x%04x) with %f\n", sum, fixed32_to_double(sum, Q2_29), q2_29_pi, fixed32_to_double(q2_29_pi, Q2_29), q2_29_exp, fixed32_to_double(q2_29_exp, Q2_29));
  
  sum = fixed32_add(q4_27_pi, q4_27_exp);
  printf("fixed32_add:\n Q4_27(0x%04x) with %f = Q4_27(0x%04x) with %f + Q4_27(0x%04x) with %f\n", sum, fixed32_to_double(sum, Q4_27), q4_27_pi, fixed32_to_double(q4_27_pi, Q4_27), q4_27_exp, fixed32_to_double(q4_27_exp, Q4_27));

  sum = fixed32_add_with_trim(q4_27_pi, q4_27_exp);
  printf("fixed32_add_with_trim:\n Q4_27(0x%04x) with %f = Q4_27(0x%04x) with %f + Q4_27(0x%04x) with %f\n", sum, fixed32_to_double(sum, Q4_27), q4_27_pi, fixed32_to_double(q4_27_pi, Q4_27), q4_27_exp, fixed32_to_double(q4_27_exp, Q4_27));

  fixed32_t diff = fixed32_subtract(q2_29_exp, q2_29_pi);
  printf("fixed32_subtract:\n Q2_29(0x%04x) with %f = Q2_29(0x%04x) with %f - Q2_29(0x%04x) with %f\n", diff, fixed32_to_double(diff, Q2_29), q2_29_exp, fixed32_to_double(q2_29_exp, Q2_29), q2_29_pi, fixed32_to_double(q2_29_pi, Q2_29));
  diff = fixed32_subtract_with_trim(q2_29_exp, q2_29_pi);
  printf("fixed32_subtract_with_trim:\n Q2_29(0x%04x) with %f = Q2_29(0x%04x) with %f - Q2_29(0x%04x) with %f\n", diff, fixed32_to_double(diff, Q2_29), q2_29_exp, fixed32_to_double(q2_29_exp, Q2_29), q2_29_pi, fixed32_to_double(q2_29_pi, Q2_29));  

  diff = fixed32_subtract(q4_27_exp, q4_27_pi);
  printf("fixed32_subtract:\n Q4_27(0x%04x) with %f = Q4_27(0x%04x) with %f - Q4_27(0x%04x) with %f\n", diff, fixed32_to_double(diff, Q4_27), q4_27_exp, fixed32_to_double(q4_27_exp, Q4_27), q4_27_pi, fixed32_to_double(q4_27_pi, Q4_27));
  diff = fixed32_subtract_with_trim(q4_27_exp, q4_27_pi);
  printf("fixed32_subtract_with_trim:\n Q4_27(0x%04x) with %f = Q4_27(0x%04x) with %f - Q4_27(0x%04x) with %f\n", diff, fixed32_to_double(diff, Q4_27), q4_27_exp, fixed32_to_double(q4_27_exp, Q4_27), q4_27_pi, fixed32_to_double(q4_27_pi, Q4_27));

  fixed32_t mul = fixed32_multiply(q2_29_pi, q2_29_exp, Q2_29);
  printf("fixed32_multiply:\n Q2_29(0x%04x) with %f = Q2_29(0x%04x) with %f x Q2_29(0x%04x) with %f\n", mul, fixed32_to_double(mul, Q2_29), q2_29_pi, fixed32_to_double(q2_29_pi, Q2_29), q2_29_exp, fixed32_to_double(q2_29_exp, Q2_29));

  mul = fixed32_multiply(q4_27_pi, q4_27_exp, Q4_27);
  printf("fixed32_multiply:\n Q4_27(0x%04x) with %f = Q4_27(0x%04x) with %f x Q4_27(0x%04x) with %f\n", mul, fixed32_to_double(mul, Q4_27), q4_27_pi, fixed32_to_double(q4_27_pi, Q4_27), q4_27_exp, fixed32_to_double(q4_27_exp, Q4_27));

  fixed32_t div = fixed32_divide(q2_29_pi, q2_29_exp, Q2_29);
  printf("fixed32_divide:\n Q2_29(0x%04x) with %f = Q2_29(0x%04x) with %f / Q2_29(0x%04x) with %f\n", div, fixed32_to_double(div, Q2_29), q2_29_pi, fixed32_to_double(q2_29_pi, Q2_29), q2_29_exp, fixed32_to_double(q2_29_exp, Q2_29));

  div = fixed32_divide(q4_27_pi, q4_27_exp, Q4_27);
  printf("fixed32_divide:\n Q4_27(0x%04x) with %f = Q4_27(0x%04x) with %f / Q4_27(0x%04x) with %f\n", div, fixed32_to_double(div, Q4_27), q4_27_pi, fixed32_to_double(q4_27_pi, Q4_27), q4_27_exp, fixed32_to_double(q4_27_exp, Q4_27));
  
}

int main(int argc, char *argv[])
{
  test_fixed16_in_float();
  test_fixed16_in_double();
  test_fixed32_in_float();
  test_fixed32_in_double();
  return 0;
}


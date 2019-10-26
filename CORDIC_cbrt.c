/**
 * Purpose:
 *  	CBRT_CORDIC returns the cube root of a value using the CORDIC method.
 *
 * Licensing:
 *	This code is distributed under the BNU LGPL license.
 *
 * Modified:
 *	19 January 2012. Secondly, 16
 *
 * Parameters:
 *	Input, double X, the number whose cube root is desired.
 *
 *	Input, int N, the number of iterations to take.
 *	This is essentially the number of binary digits of accuracy, and
 *	might go as high as 53.
 *
 *	Output, double CBRT_CORDIC, the approximate cube root of X.
 */
double CORDIC_cbrt(double x, int n)
{
  int i;
  double power_of_2;
  double x_abs;
  double y;

  x_abs = ABS(x);
  if (x_abs == 0) return 0;
  if (x_abs == 1.0) return x;

  power_of_2 = 1.0;

  if (x_abs < 1.0) {
    while (x_abs <= power_of_2 * power_of_2 * power_of_2) {
      power_of_2 = power_of_2 / 2;
    }
    y = power_of_2;
  } else if ( x_abs > 1.0) {
    while (x_abs >= power_of_2 * power_of_2 * power_of_2) {
      power_of_2 = 2.0 * power_of_2;
    }
    y = power_of_2 / 2.0;
  }

  for (i = 0; i < n; i++) {
    power_of_2 = power_of_2 / 2.0;
    if ((y + power_of_2) * (y + power_of_2) * (y + power_of_2) <= x_abs) {
      y = y + power_of_2;
    }
  }

  if (x < 0.0) y = -y;

  return y;
}

// Cube root using CORDIC in the domain of Q19_12
// from http://people.sc.fsu.edu/~jburkardt/c_src/cordic/cordic.c
int32_t CORDIC_cbrt(int32_t x, int iteration)
{
  int i;
  int32_t power_of_2, tmp, cube;
  int32_t x_abs;
  int32_t y;

  x_abs = ABS(x);

  if (x_abs == 0) return 0;
  if (x_abs == 4096 /* int32_to_fixed32(1, Q19_12) */) return x;

  power_of_2 = 4096; // int32_to_fixed32(1, Q19_12);
  if (x_abs < 4096 /* int32_to_fixed32(1, Q19_12) */) {
    for (;;) {
      tmp = fixed32_multiply(power_of_2, power_of_2, Q19_12);
      cube = fixed32_multiply(tmp, power_of_2, Q19_12);
      if (x_abs > cube) break;
      power_of_2 >>= 1;
    }
    y = power_of_2;
    /*
      while (x_abs <= power_of_2 * power_of_2 * power_of_2) {
      power_of_2 >>= 1;
      }
      y = power_of_2;
    */
  } else if (4096 /* int32_to_fixed32(1, Q19_12) */ < x_abs) {
    for (;;) {
      tmp = fixed32_multiply(power_of_2, power_of_2, Q19_12);
      cube = fixed32_multiply(tmp, power_of_2, Q19_12);
      if (x_abs < cube) break;
      power_of_2 <<= 1;
    }
    y = power_of_2 >> 1;
    /*
      while (power_of_2 * power_of_2 * power_of_2 <= x_abs) {
      power_of_2 = 2.0 * power_of_2;
      }
      y = power_of_2 / 2.0;
    */
  }

  for (i = 0; i < iteration; i++) {
    power_of_2 >>= 1;
    tmp = y+power_of_2;
    cube = fixed32_multiply(tmp, tmp, Q19_12);
    cube = fixed32_multiply(cube, tmp, Q19_12);
    if (cube <= x_abs) {
      y += power_of_2;
    }
  }

  if (x < 0) y = -y;

  return y;
}

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

static void CORDIC_fixed16_generate_circular_delta_radians(int max_iteration)
{
  int i;
  real_t value, *delta_angles;

  delta_angles = (real_t *)malloc(max_iteration * sizeof(*delta_angles));

  for (value = 1.0, i = 0; i < max_iteration; i++) {
    delta_angles[i] = atan(value);
    value /= 2.0;
  }

  for (i = 0; i < max_iteration-1; i++) {
    printf("%"PRId16"", real_to_fixed16(delta_angles[i], Q2_13);
	   if (fabs((delta_angles[i]/delta_angles[i+1]) - 2.0) < REAL_EPSILON) {
	     fprintf("\nFurther things are meaningless due to having the value divided by 2 of the previous.\n");
	     break;
	   }
	   printf(",\n");
	   }
      free(delta_angles);
  }

  static void CORDIC_fixed16_generate_circular_K_cumulative_products(int max_iteration)
  {
    int i;
    real_t *k_products, value;

    k_products = (real_t *)malloc(max_iteration * sizeof(*k_products));

    for (value = 1.0, i = 0; i < max_iteration; i++) {
      value *= 1.0 / sqrt(1.0 + pow(2.0, -2.0 * i));
      k_products[i] = value;
    }

    for (i = 0; i < max_iteration-1; i++) {
      printf("%"PRId16"", real_to_fixed16(k_products[i], Q1_14));
      if (fabs(k_products[i] - k_products[i+1]) < REAL_EPSILON) {
	printf("\nFurther things are meaningless due to having the same value with the last.\n");
	break;
      }
      printf(",\n");
    }
    free(k_products);
  }



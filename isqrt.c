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
#include <inttypes.h>

// This is brilliant reference
// Integer square root by Halleck's method, with Legalize's speedup.
long isqrt(long x)
{
  long squaredbit, remainder, root;

  if (x < 1) return 0;

  /* Load the binary constant 0100 0000 ... 0000, 
   * where the number of zero bits to the right of the single one bit is even,
   * and the one bit is as far left as is consistant with that condition.
   */

  squaredbit = (long)((((unsigned long) ~0L) >> 1) &
		      ~(((unsigned long) ~0L) >> 2));
  /* This portable load replaces the loop that used to be here,
   * and was donated by legalize@xmission.com
   */

  // Form bits of the answer.
  remainder = x;
  root = 0;
  while (squaredbit > 0) {
    if (remainder >= (squaredbit | root)) {
      remainder -= (squaredbit | root);
      root >>= 1;
      root |= squaredbit;
    } else {
      root >>= 1;
    }
    squaredbit >>= 2;
  }

  return root;
}

#if 0
int main(int argc, char *argv[])
{
  long i;

  for (i = 100; i > 0; i -= 10) {
    printf("%d = isqrt(%d).\n", isqrt(i), i);
  }

  return 0;
}
#endif


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned power_helper(unsigned base, unsigned result, unsigned n)
{
  if ( 1 == n || n >= UINT_MAX )
    {
      return result;
    }
  result *= base;
  return power_helper(base, result,  n - 1);
}

unsigned power(unsigned x, unsigned y)
{
  unsigned result = x;
  if ( (0 == x && y == 0) || 0 == y )
    {
      return 1;
    }
  if ( 0 == x )
    {
      return x;
    }
  return power_helper(x, result, y);
}

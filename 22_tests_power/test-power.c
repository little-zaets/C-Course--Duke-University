#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

unsigned power(unsigned x, unsigned y);

void testPow(unsigned x ,unsigned y, unsigned expected)
{
  unsigned actual = power(x,y);
  if ( expected != actual )
    {
      printf("Failed: x=%u, y=%u, expected=%u, actual=%u\n", x, y, expected, actual);
      exit(EXIT_FAILURE);
    }
}

int main()
{
  
  testPow(0, 0, 1);
  testPow(0, 1, 0);
  testPow(1, 0, 1);
  testPow(1, 1, 1);
  testPow(-1, 32, 1);
  testPow(-1, 1, -1);
  testPow(2, -1, 0);
  testPow(2, 32, 0);
  testPow(2, 0, 1);
  
  
  return 0;
}

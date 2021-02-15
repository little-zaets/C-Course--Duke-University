#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

size_t maxSeq(int *array, size_t n)
{
  size_t i;
  size_t maxSeq = 1;
  size_t currSeq = 0;
  assert(0 <= n);
  if ( NULL == array )
    {
      return 0;
    }
  if ( 0 == n || 1 == n )
    {
      return n;
    }
  currSeq = 1;
  for(i = 0; (i + 1) < n; ++i)
    {
      if ( array[i] >= array[i + 1] )
	{
	  currSeq = 1;
	}
      if ( array[i] < array[i + 1] )
	{
	  ++currSeq;
	}
      if ( currSeq >=  maxSeq )
	{
	  maxSeq = currSeq;
	}
    }
  return maxSeq;
}
	  

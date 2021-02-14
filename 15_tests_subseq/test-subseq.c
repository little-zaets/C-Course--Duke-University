#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int *array, size_t n);

int main(void)
{
  size_t result;
  int array[] = { 2, 2, 2, 3 };
  int array1[] = { -5, -6, -7, -8, -20 };
  int array2[] = { -1, 5, -33, -32, -8, -1, 9 };
  int array3[] = { 0 };
  int array4[] = { -18, 20, 40, 100, 500, -15, 600, -1 };
  int array5[] = { 0, 1, -1, 1, 0 };
  int array6[] = {};

  if ( maxSeq(NULL, 0) )
    {
      return EXIT_FAILURE;
    }
  if ( maxSeq(array, 0) )
    {
      return EXIT_FAILURE;
    }
  result = maxSeq(array, 4);
  if ( 2 != result )
    {
      return EXIT_FAILURE;
    }
  result = maxSeq(array1, 5);  
  if ( 1 != result )
    {
      return EXIT_FAILURE;
    }
  result = maxSeq(array2, 7);
  if ( 5 != result )
    {
      return EXIT_FAILURE;
    }
  result = maxSeq(array2, 6);
  if ( 4 != result )
    {
      return EXIT_FAILURE;
    }
  result = maxSeq(array3, 1);
  if ( 1 != result )
    {
      return EXIT_FAILURE;
    }
  result = maxSeq(array4, 9);
  if ( 5 != result )
    {
      return EXIT_FAILURE;
    }
  result = maxSeq(array5, 5);
  if ( 2 != result )
    {
      return EXIT_FAILURE;
    }
  result = maxSeq(array6, 0);
  if ( 0 != result)
    {
      return EXIT_FAILURE;
      }
  return EXIT_SUCCESS;
}

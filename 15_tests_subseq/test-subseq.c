#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int *array, size_t n);

int main(void)
{
  int passed = 0;
  size_t result;
  int array[] = { 2, 2, 2, 3 };
  int array1[] = { -5, -6, -7, -8, -20 };
  int array2[] = { -1, 5, -33, -32, -8, -1, 9 };
  int array3[] = { 0 };
  int array4[] = { -18, 20, 40, 100, 500, -15, 600, -1 };
  int array5[] = { 0, 1, -1, 1, 0 };
  int array6[0] = {};

  if ( 0 == maxSeq(NULL, 0) )
    {
      printf("PASSED\n");
      passed++;
    }
  else
    {
      printf("FAILED\n");
      failed++;
      return EXIT_FAILURE;
    }
  if ( 0 ==  maxSeq(array, 0) )
    {
      printf("PASSED\n");
      passed++;
    }
  else
    {
      printf("FAILED\n");
      failed++;
      return EXIT_FAILURE;
    }
  result = maxSeq(array, 4);
  if ( 2 == result )
   {
      printf("PASSED\n");
      passed++;
    }
  else
    {
      printf("FAILED\n");
      failed++;
      return EXIT_FAILURE;
    }
  result = maxSeq(array1, 5);  
  if ( 1 == result )
   {
      printf("PASSED\n");
      passed++;
    }
  else
    {
      printf("FAILED\nresult = %ld\n",result);
      failed++;
      return EXIT_FAILURE;
    }
  result = maxSeq(array2, 7);
  if ( 5 == result )
   {
      printf("PASSED\n");
      passed++;
    }
  else
    {
      printf("FAILED\nresult = %ld\n", result);
      failed++;
      return EXIT_FAILURE;
    }
  result = maxSeq(array2, 6);
  if ( 4 == result )
    {
      printf("PASSED\n");
      passed++;
    }
  else
    {
      printf("FAILED\nresult = %ld\n", result);
      failed++;
      return EXIT_FAILURE;
    }
  result = maxSeq(array3, 1);
  if ( 1 == result )
    {
      printf("PASSED\n");
      passed++;
    }
  else
    {
      printf("FAILED\nresult = %ld\n", result);
      failed++;
      return EXIT_FAILURE;
    }
  result = maxSeq(array4, 8);
  if ( 5 == result )
    {
      printf("PASSED\n");
      passed++;
    }
  else
    {
      printf("FAILED\nresult = %ld\n", result);
      failed++;
      return EXIT_FAILURE;
    }
  result = maxSeq(array5, 5);
  if ( 2 == result )
    {
      printf("PASSED\n");
      passed++;
    }
  else
    {
      printf("FAILED\nresult = %ld\n", result);
      failed++;
      return EXIT_FAILURE;
    }
  result = maxSeq(array6, 0);
  if ( 0 == result)
    {
      printf("PASSED\n");
      passed++;
    }
  else
    {
      printf("FAILED\nresult = %ld\n", result);
      failed++;
      return EXIT_FAILURE;
    }
  printf("Total tests passed: %d out of 10.\n", passed);
  return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


void rotate(char matrix[10][10])
{
  char tempMatrix[10][10];
  size_t i;
  size_t j;
  size_t size = 10;

  for(i = 0; i < size; ++i)
    {
      for(j = 0; j < size; ++j)
	{
	  tempMatrix[j][size - i - 1] = matrix[i][j];
	}
    }
  for(i = 0; i < size; ++i)
    {
      for(j = 0; j < size; ++j)
	{
	  matrix[i][j] = tempMatrix[i][j];
	}
    }
  for(i = 0; i < size; ++i)
    {
      for(j = 0; j < size; ++j)
	{
	  printf("%c", matrix[i][j]);
	}
      printf("\n");
    }
}


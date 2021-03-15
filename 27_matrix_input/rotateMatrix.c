#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void rotateMatrix(char matrix[10][12], size_t n)
{
    char tempMatrix[10][10];
    size_t i;
    size_t j;
    size_t size = n;

    for (i = 0; i < size; ++i)
    {
        for (j = 0; j < size; ++j)
        {
            tempMatrix[j][size - i - 1] = matrix[i][j];
        }
    }
    for (i = 0; i < size; ++i)
    {
        for (j = 0; j < size; ++j)
        {
            matrix[i][j] = tempMatrix[i][j];
        }
    }
}

void checkInput(FILE *input)
{
    char matrix[10][12];
    char *ptr = matrix[0];
    size_t i;
    size_t j;
    char c;

    for (i = 0; i < 10; ++i)
    {
       if( NULL == fgets(matrix[i], 12, input) )
       {
           if ( feof(input) )
           {
                fprintf(stderr, "End Of File reached\n");
                exit(EXIT_FAILURE);
           }
           if ( ferror(input) )
           {
               fprintf(stderr, "Input error occurred");
               exit(EXIT_FAILURE);
           }
       }
       ptr = strchr(matrix[i], '\n');
       if ( NULL == ptr || ptr - matrix[i] != 10 )
       {
           fprintf(stderr, "Invalid number of characters in line\n");
           exit(EXIT_FAILURE);
       }
    }
    rotateMatrix(matrix, 10);
    for (i = 0; i < 10; ++i)
    {
        printf("%s", matrix[i]);
    }
}

int main(int argc, char **argv)
{
    if (2 != argc)
    {
        fprintf(stderr, "Not enough arguments\n");
        return EXIT_FAILURE;
    }
    FILE *f = fopen(argv[1], "r");
    if (NULL == f)
    {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }
    checkInput(f);
    if (0 != fclose(f))
    {
        perror("Failed to close the input file");
        return EXIT_FAILURE;
    }
    return 0;
}
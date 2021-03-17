#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void printMatrix(char matrix[10][12])
{
    size_t i = 0;
    for (i = 0; i < 10; ++i)
    {
        printf("%s", matrix[i]);
    }
}

int findFileSize(const char *filepath)
{
    int c;
    int char_count = 0;
    FILE *input = fopen(filepath, "r");
    if ( NULL == input )
    {
        fprintf(stderr,"File does not exist\n");
        exit(EXIT_FAILURE);
    }
    while ( (c = fgetc(input)) != EOF )
    {   
        ++char_count;
        if ( '\n' == c )
        {
            if ( char_count > 11 )
            {
                fprintf(stderr, "Line too long\n");
                exit(EXIT_FAILURE);
            }
            if ( char_count < 11 )
            {
                fprintf(stderr, "Line too short\n");
                exit(EXIT_FAILURE);
            }
            else
            {
                char_count = 0;
            }
        }
    }
    fseek(input, 0L, SEEK_END);
    int res = ftell(input);
    fseek(input, 0 , SEEK_SET);
    if ( 0 != fclose(input) )
    {
        perror("Failed to close the input file");
        exit(EXIT_FAILURE);
    }
    return res;
}

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

int fillMatrix(const char *filepath, char matrix[10][12])
{
    char *ptr = NULL;
    size_t i = 0;
    int error_code = 0;
    
    long int size = findFileSize(filepath);
    if ( 0 == size )
    {
        fprintf(stderr,"File is blank\n");
        exit(EXIT_FAILURE);
    }
    if ( 110 > size )
    {
        fprintf(stderr, "File too short\n");
        exit(EXIT_FAILURE);
    }
    if ( 110 < size )
    {
        fprintf(stderr, "File too long\n");
        exit(EXIT_FAILURE);
    }
    
    FILE *input = fopen(filepath, "r");
    if ( NULL == input )
    {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < 10; ++i)
    {
        if ( ptr == fgets(matrix[i], 12, input) )
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
    }
    return error_code;
}

int main(int argc, char **argv)
{
    char matrix[10][12];
    int error_code = 0;
    if (2 != argc)
    {
        if ( 2 < argc )
        {
            fprintf(stderr, "Too many arguments\n");
            return EXIT_FAILURE;
        }
        else
        {
            fprintf(stderr, "Not enough arguments\n");
            return EXIT_FAILURE;
        }
    }
    error_code = fillMatrix(argv[1], matrix);
    if ( 0 != error_code )
    {
        return EXIT_FAILURE;
    }
    rotateMatrix(matrix, 10);
    printMatrix(matrix);

    return error_code;
}


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
    FILE *input = fopen(filepath, "r");
    if ( NULL == input )
    {
        perror("Failed to open file");
        error_code = EXIT_FAILURE;
        goto exit;
    }

    for (i = 0; i < 10; ++i)
    {
        if (NULL == fgets(matrix[i], 12, input))
        {
            if (feof(input))
            {
                fprintf(stderr, "End Of File reached\n");
                error_code = EXIT_FAILURE;
                goto exit;
            }
            if (ferror(input))
            {
                fprintf(stderr, "Input error occurred");
                error_code = EXIT_FAILURE;
                goto exit;
            }
        }
        ptr = strchr(matrix[i], '\n');
        if (NULL == ptr || ptr - matrix[i] != 10)
        {
            fprintf(stderr, "Invalid number of characters in line\n");
            error_code = EXIT_FAILURE;
            goto exit;
        }
    }

exit:
    if ( NULL == input )
    {
        return EXIT_FAILURE;
    }
    if ( 0 != fclose(input) )
    {
        perror("Failed to close the input file");
        return EXIT_FAILURE;
    }
    return error_code;
}

int main(int argc, char **argv)
{
    char matrix[10][12];
    int error_code = 0;
    size_t i;
    if (2 != argc)
    {
        fprintf(stderr, "Not enough arguments\n");
        return EXIT_FAILURE;
    }
    error_code = fillMatrix(argv[1], matrix);
    if ( 0 != error_code )
    {
        return error_code;
    }
    rotateMatrix(matrix, 10);
    printMatrix(matrix);

    return error_code;
}
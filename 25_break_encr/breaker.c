#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


size_t mostFrequent(unsigned long arr[26])
{
    size_t i;
    size_t largest_count_index = 0;
    size_t largest_count = 0;
    
    for(i = 0; i < 26; ++i)
    {
        if ( arr[i] > largest_count )
        {
            largest_count = arr[i];
            largest_count_index = i;
        }
        else
        {
            continue;
        }
    }
    return largest_count_index;
}
void decrypt(FILE *input)   
{
    unsigned long arr[26];
    size_t frequent_let_index;
    size_t i = 0;
    int c;
    for(i = 0; i < 26; ++i)
    {
        arr[i] = 0;
    }
    while(( c = fgetc(input)) != EOF)
    {
        if ( isalpha(c) )
        {
            arr[c - 'a']++;
        }
    }
    frequent_let_index = mostFrequent(arr);
    frequent_let_index = (frequent_let_index + 22) % 26;
    if( 0 <= frequent_let_index && frequent_let_index < 26 )
    {
        printf("%ld\n", frequent_let_index);
    }
    else
    {
        fprintf(stderr, "Key is out of valid range");
        exit(EXIT_FAILURE);
    }
}


int main(int argc, char **argv)
{
    if ( 2 != argc )
    {
        fprintf(stderr, "Not enough arguments\n");
        return EXIT_FAILURE;
    }
    FILE *f = fopen(argv[1], "r");  
    if ( NULL == f ) 
    {    
        perror("Could not open file");    
        return EXIT_FAILURE;
    }
    decrypt(f);
    if ( 0 != fclose(f) ) 
    {    
        perror("Failed to close the input file!");    
        return EXIT_FAILURE;  
    }
    return 0;
}
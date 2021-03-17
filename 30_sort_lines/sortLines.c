#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findFileSize(const char *filepath)
{
	FILE *input = fopen(filepath, "r");
	if (NULL == input)
	{
		perror("File does not exist\n");
		exit(EXIT_FAILURE);
	}
	fseek(input, 0L, SEEK_END);
	int res = ftell(input);
	fseek(input, 0, SEEK_SET);
	if (0 != fclose(input))
	{
		perror("Failed to close the input file");
		exit(EXIT_FAILURE);
	}
	return res;
}

void printData(char **data, size_t count)
{
	size_t j;
	for (j = 0; j < count; ++j)
	{
		printf("%s", data[j]);
	}
}

void freeData(char **data, size_t count)
{
	size_t j;
	for (j = 0; j < count; ++j)
	{
		free(data[j]);
	}
	free(data);
}

//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void *vp1, const void *vp2)
{
	const char *const *p1 = vp1;
	const char *const *p2 = vp2;
	return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char **data, size_t count)
{
	qsort(data, count, sizeof(char *), stringOrder);
	printData(data, count);
}

void processFile(const char *filepath)
{
	char *line = NULL;
	size_t n = 0;
	size_t i = 0;
	char **array = NULL;
	long int size = findFileSize(filepath);
	if (0 == size)
	{
		fprintf(stderr, "File is blank\n");
		exit(EXIT_FAILURE);
	}
	FILE *input = fopen(filepath, "r");
	if (NULL == input)
	{
		perror("Failed to open file");
		exit(EXIT_FAILURE);
	}
	while (0 <= getline(&line, &n, input))
	{
		array = realloc(array, (i + 1) * sizeof(*array));
		array[i] = line;
		line = NULL;
		++i;
	}
	free(line);
	sortData(array, i);
	freeData(array, i);
	if ( 0 != fclose(input) )
	{
		perror("Failed to close file");
		exit(EXIT_FAILURE);
	}
}

void processInput(FILE *stream)
{
	char *line = NULL;
	size_t n = 0;
	size_t i = 0;
	char **array = NULL;
	while ( 0 < getline(&line, &n, stream) )
	{
		if (0 == strcmp(line, "quit\n"))
		{
			break;
		}
		array = realloc(array, (i + 1) * sizeof(*array));
		array[i] = line;
		line = NULL;
		++i;
	}
	free(line);
	sortData(array, i);
}

int main(int argc, char **argv)
{
	FILE *f = stdin;
	size_t i = 1;
	if (1 == argc)
	{
		processInput(f);
	}
	else
	{
		for (i = 2; i < argc; ++i)
		{
			processFile(argv[i]);
		}
	}
	return EXIT_SUCCESS;
}

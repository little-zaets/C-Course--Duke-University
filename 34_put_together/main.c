#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t *countFile(const char *filename, kvarray_t *kvPairs) 
{
	char *line = NULL;
	size_t sz = 0;
	FILE *input = fopen(filename, "r");
	if (NULL == input)
	{
		perror("fopen");
		fprintf(stderr, "Trying to open %s\n", filename);
		exit(EXIT_FAILURE);
	}
	counts_t *c = createCounts();
	while ((getline(&line, &sz, input)) != EOF)
	{
		stripWhiteSpace(line);
		char *key = lookupValue(kvPairs, line);
		addCount(c, key);
		free(line);
		line = NULL;
	}
	free(line);
	if (0 != fclose(input))
	{
		perror("fclose");
		fprintf(stderr, "Trying to close %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return c;
}

int main(int argc, char **argv) 
{
	if (2 > argc)
	{
		fprintf(stderr, "Minimum 2 arguments required: input/output files\n");
		return EXIT_FAILURE;
	}
	kvarray_t *kv = readKVs(argv[1]);
	for (size_t i = 2; i < argc; ++i)
	{
		counts_t *c = countFile(argv[i], kv);
		char *outName = computeOutputFileName(argv[i]);
		if (NULL == outName)
		{
			free(outName);
			return EXIT_FAILURE;
		}
		FILE *f = fopen(outName, "w");
		if (NULL == f)
		{
			perror("fopen");
			fprintf(stderr, "Trying to open %s\n", outName);
			return EXIT_FAILURE;
		}
		printCounts(c, f);
		if (0 != fclose(f))
		{
			perror("fclose");
			fprintf(stderr, "Trying to close %s\n", outName);
			return EXIT_FAILURE;
		}
		freeCounts(c);
		free(outName);
	}
	freeKVs(kv);
	return EXIT_SUCCESS;
}

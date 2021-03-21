#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

void stripWhiteSpace(char *str)
{
	char *p = strchr(str, '\n');
	if (p != NULL)
	{
		*p = '\0';
	}
}

kvpair_t *parseKv(char *line, size_t size)
{
	size_t n = 0;
	kvpair_t *kv = malloc(sizeof(*kv));
	if (NULL == kv)
	{
		fprintf(stderr, "Malloc failed for kv");
		return NULL;
	}
	kv->key = NULL;
	char *s = strchr(line, '=');
	kv->key = malloc(sizeof(char) * (s - line) + 1);
	strncpy(kv->key, line, (s - line));
	kv->key[s - line] = '\0';
	kv->value = NULL; 
	if ( '\n' == line[size - 1] )
	{
		--size;
	}
	n = ((line + size) - s + 1);
	kv->value = malloc(sizeof(char) * n);
	strncpy(kv->value, s + 1, n);
	kv->value[n - 1] = '\0';
	return kv;
}

kvarray_t *readKVs(const char *fname)
{
	char *line = NULL;
	size_t sz = 0;
	size_t i = 0;
	size_t size;
	FILE *input = fopen(fname, "r");
	if ( NULL == input )
	{
		perror("File does not exist");
		exit(EXIT_FAILURE);
	}
	kvarray_t *kvPairs = malloc(sizeof(*kvPairs));
	if ( NULL == kvPairs )
	{
		fprintf(stderr, "Malloc failed for kvPairs");
		return NULL;
	}
	kvPairs->pairsArray = NULL;
	while( (size = getline(&line, &sz, input)) != EOF )
	{
		stripWhiteSpace(line);
		kvPairs->pairsArray = realloc(kvPairs->pairsArray, (i + 1) * sizeof(kvPairs->pairsArray));
		if ( NULL == kvPairs->pairsArray )
		{
			fprintf(stderr, "Realloc failed");
			return NULL;
		}
		kvPairs->pairsArray[i] = parseKv(line, size);
		free(line);
		line = NULL;
		++i;
	}
	kvPairs->numPairs = i;
	free(line);
	if (0 != fclose(input))
	{
		perror("Failed to close file");
		exit(EXIT_FAILURE);
	}
	return kvPairs;
}
void freeKv(kvpair_t *pair) 
{
	free(pair->key);
	free(pair->value);
}

void freeKVs(kvarray_t *pairs)
{
	size_t i;
	for(i = 0; i < pairs->numPairs; ++i)
	{
		freeKv(pairs->pairsArray[i]);
	}
	free(pairs->pairsArray);
	free(pairs);
}

void printKVs(kvarray_t *pairs)
{
	size_t i;
	for(i = 0; i < pairs->numPairs; ++i)
	{
		printf("key = '%s' value = '%s'\n", pairs->pairsArray[i]->key, pairs->pairsArray[i]->value);
	}
}

char *lookupValue(kvarray_t *pairs, const char *key)
{
	size_t i;
	for(i = 0; i < pairs->numPairs; ++i)
	{
		if ( 0 == strcmp(key, pairs->pairsArray[i]->key) )
		{
			return pairs->pairsArray[i]->value;
		}
	}
	return NULL; 
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"

one_count_t *createOneCountv2(const char *value, size_t unique_cnt)
{
	one_count_t *name = malloc(sizeof(*name));
	if (NULL == name)
	{
		fprintf(stderr, "Malloc failed for one_count_t");
		return NULL;
	}
	
	name->uniqueValue = strdup(value);
	if(NULL == name->uniqueValue) 
	{
		free(name);
		return NULL;
	}
	name->uniqueCount = unique_cnt;
	return name;
}

counts_t *createCounts(void)
{
	counts_t *matches = malloc(sizeof(*matches));
	if (NULL == matches)
	{
		fprintf(stderr, "Malloc failed for counts_t");
		return NULL;
	}
	matches->matchCounts = NULL;
	matches->numCounts = 0;
	matches->unknownCount = 0;
	return matches;
}

int contains(one_count_t **array, const char *name, size_t n)
{
	size_t i;
	for (i = 0; i < n; ++i)
	{
		if (0 == strcmp(array[i]->uniqueValue, name))
		{
			return i;
		}
	}
	return -1;
}

void addCount(counts_t *c, const char *name)
{
	if (NULL == name)
	{
		c->unknownCount++;
		return;
	}
	int pos = -1;
	if (0 == c->numCounts || (pos = contains(c->matchCounts, name, c->numCounts)) == -1)
	{
		c->matchCounts = realloc(c->matchCounts,
								 (c->numCounts + 1) * sizeof(*c->matchCounts));
		c->matchCounts[c->numCounts] = createOneCountv2(name, 1);
		c->numCounts++;
		return;
	}
	c->matchCounts[pos]->uniqueCount++;
}

void freeUniqueCounts(one_count_t *v)
{
	free(v->uniqueValue);
	free(v);
}

void freeCounts(counts_t *c)
{
	size_t i;
	for (i = 0; i < c->numCounts; ++i)
	{
		freeUniqueCounts(c->matchCounts[i]);
	}
	free(c->matchCounts);
	free(c);
}

void printCounts(counts_t *c, FILE *outFile)
{
	size_t i;
	for(i = 0; i < c->numCounts; ++i) 
	{
		fprintf(outFile, "%s: %lu\n", c->matchCounts[i]->uniqueValue, c->matchCounts[i]->uniqueCount);
	}
	if(0 != c->unknownCount) 
	{
		fprintf(outFile, "<unknown>: %lu\n", c->unknownCount);
	}
}

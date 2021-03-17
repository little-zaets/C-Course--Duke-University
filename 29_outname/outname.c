#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char *computeOutputFileName(const char *inputName) 
{
	char *outputName = malloc((strlen(inputName) + 7) * sizeof(char *));
	if ( NULL == outputName )
	{
		fprintf(stderr, "Malloc failed");
		return NULL;
	}
	if ( NULL != strstr(inputName, ".txt") )
	{
		strcpy(outputName, inputName);
		strcat(outputName, ".counts");
	}
	else
	{
		outputName = realloc(outputName, (strlen(inputName) + 11 * sizeof(char *)));
		if (NULL == outputName)
		{
			fprintf(stderr, "Realloc failed");
			return NULL;
		}
		strcpy(outputName, inputName);
		strcat(outputName, ".txt.counts");
	}
	return outputName;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char *computeOutputFileName(const char *inputName)
{
	char *outputName = malloc((strlen(inputName) + 7) * sizeof(char *));
	if (NULL == outputName)
	{
		fprintf(stderr, "Malloc failed");
		exit(EXIT_FAILURE);
	}
	strcpy(outputName, inputName);
	if (0 != strcmp(inputName, outputName))
	{
		fprintf(stderr, "%s copied to output file name", outputName);
		return NULL;
	}
	strcat(outputName, ".counts");
	return outputName;
}

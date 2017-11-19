#include <stdio.h>
//#include <stdbool.h>
#include <string.h>

#include "analyse_input_stream.h"

void IsMatchInFile(char *phraseSearch, Matchers *matchers, char *filePath){
    	ssize_t numberOfChars = 0;
    	size_t size = 0;
	char *fileLine = NULL;
	int lineNumber = 1;
	FILE *file = fopen(filePath, "r");
	while (getline(&fileLine, &size, file) != -1){
		if (strstr(fileLine,phraseSearch) != NULL)
			printf("%d: %s", lineNumber,fileLine);
		lineNumber++;
	}
	free(fileLine);
	fclose(file);
}

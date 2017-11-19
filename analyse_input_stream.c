#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "analyse_input_stream.h"

void RemoveNewLineChar(char *line);

void ParseLine(char *line, char *separatedWords[], int* stdinWordsCount) {
	int i = 0, isOnlyOneWord = 1;
	separatedWords[i] = line;
	while (*line != '\0') {
		if (*line == ' ') {
			*line = '\0';
			i++;
			separatedWords[i] = line + 1;
			isOnlyOneWord = 0;
		}
		line++;
	}
	if (isOnlyOneWord == 0) {
		*stdinWordsCount = i + 1;
	}
	else {
		*stdinWordsCount = 0;
	}
}

ssize_t analyzeStdin(char** buffer, size_t* size, char *separatedWords[], int *stdinWordsCount) {
	ssize_t numberOfChars = 0;
	numberOfChars = getline(buffer, size, stdin);
	RemoveNewLineChar(*buffer);
	ParseLine(*buffer, separatedWords, stdinWordsCount);
	return numberOfChars;
}

bool IsStdin(int argc) {
	return (argc < 2);
}

void RemoveNewLineChar(char *line){
	int lineLen = strlen(line);
	if (line[lineLen - 1] == '\n'){
		line[lineLen - 1] = '\0';
}
}

void SetNecessaryMatchers(char *words[], Matchers *matchers, int numOfWords){
     int i = 0;
    //for (i = 0; i<numOfWords; i++) // TEST
    	//printf("word %d: %s\n", i, words[i]);
//printf("numOfWords in Set is: %d", numOfWords);
     for (i = 0; i < numOfWords; i++){
	if (strcmp(words[i], "-A") == 0){
	   matchers->is_A = true;
	   matchers->A_value = atoi(words[i+1]);
	} 
	else if (strcmp(words[i], "-b") == 0)
	   matchers->is_b = true;
	else if (strcmp(words[i], "-c") == 0)
	   matchers->is_c = true;
	else if (strcmp(words[i], "-i") == 0)
	   matchers->is_i = true;
	else if (strcmp(words[i], "-n") == 0)
	   matchers->is_n = true;
	else if (strcmp(words[i], "-v") == 0)
	   matchers->is_v = true;
	else if (strcmp(words[i], "-x") == 0)
	   matchers->is_x = true;
	else if (strcmp(words[i], "-E") == 0)
	   matchers->is_E = true;
     }
    	//printf("\nis_A: %d, A_value: %d, is_b: %d, is_c: %d, is_i: %d, is_n: %d, is_v: %d, is_x: %d, is_E: %d\n", matchers->is_A, matchers->A_value, matchers->is_b, matchers->is_c, matchers->is_i, matchers->is_n, matchers->is_v, matchers->is_x, matchers->is_E); // PRINT MATCHERS STRUCT
}

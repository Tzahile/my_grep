#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "analyse_input_stream.h"
#include "file.h"

int findInstancesInFile(char* path, char* instance);

int main(int argc, char* argv[]) {
    ssize_t numberOfChars = 0;
    size_t size = 0;
    FILE* file = NULL;
    char* buffer = NULL;// getline variables
    char* path=NULL;
    char *StdinWords[MAX_STDIN_ARGUMENTS];
    char* wantedInstance = NULL;
    int stdinWordsCount = 0, i = 0;
    Matchers matchers = {false, 0, false, false, false, false, false, false, false};
    if (!IsStdin(argc)){// get ARGV
        path = argv[argc-1];
        wantedInstance =argv[argc-2];
        file = fopen(path, "r");
        assert(file != NULL);
        numberOfChars = getline(&buffer, &size, file);
    }
    else{// get STDIN
        numberOfChars = analyzeStdin(&buffer, &size, StdinWords, &stdinWordsCount);
	file = fopen(StdinWords[stdinWordsCount-1], "r");
	SetNecessaryMatchers(StdinWords, &matchers, stdinWordsCount);
	IsMatchInFile(StdinWords[0], &matchers, StdinWords[stdinWordsCount-1]);
    }


    //findInstancesInFile(path, wantedInstance);
    //for (i = 0; i<stdinWordsCount; i++) // TEST
    	//printf("word %d: %s\n", i, StdinWords[i]);
    	//printf("is_A: %d, A_value: %d, is_b: %d, is_c: %d, is_i: %d, is_n: %d, is_v: %d, is_x: %d, is_E: %d\n", matchers.is_A, matchers.A_value, matchers.is_b, matchers.is_c, matchers.is_i, matchers.is_n, matchers.is_v, matchers.is_x, matchers.is_E); // PRINT MATCHERS STRUCT
    free(buffer);
    return 0;
}


int findInstancesInFile(char* path, char* instance){
    FILE*  targetText = fopen(path, "r");
    char* lineBuffer = NULL;
    size_t lineSize = 0;
    if (targetText  == NULL) return -1;
    ssize_t numberOfChars = 0;
    while(numberOfChars!=-1){
        numberOfChars=getline(&lineBuffer, &lineSize, targetText);
        if(strstr(lineBuffer, instance)!=NULL)
            printf("%s\n", lineBuffer);
    }
    return 0;
}

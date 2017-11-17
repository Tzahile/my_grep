#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STDIN_ARGUMENTS 12

//typedef struct LineData {
//    char* line;
//    int lineNum;
//} lineData;

void ParseLine(char *line, char *separatedWords[], int *stdinWordsCount);
bool IsStdin(int argc);
ssize_t analyzeStdin(FILE* f, char** buffer, size_t* size, char *separatedWords[], int* stdinWordsCount);
int findInstancesInFile(char* path, char* instance);

int main(int argc, char* argv[]) {
    ssize_t numberOfChars = 0;
    size_t size = 0;
    FILE* f = NULL;
    char* buffer = NULL;// getline variables
    char* path=NULL;
    char *StdinWords[MAX_STDIN_ARGUMENTS];
    char* wantedInstance = NULL;
    int stdinWordsCount = 0, i = 0;
    if (!IsStdin(argc)){// get ARGV
        path = argv[argc-1];
        wantedInstance =argv[argc-2];
        f = fopen(path, "r");
        assert(f != NULL);
        numberOfChars = getline(&buffer, &size, f);
    }
    else{// get STDIN
        numberOfChars = analyzeStdin(stdin, &buffer, &size, StdinWords, &stdinWordsCount);
        path = StdinWords[stdinWordsCount-1];
        wantedInstance =StdinWords[stdinWordsCount-2];
    }
    findInstancesInFile(path, wantedInstance);
    free(buffer);
    return 0;
}
ssize_t analyzeStdin(FILE* f, char** buffer, size_t* size, char *separatedWords[], int* stdinWordsCount){
    ssize_t numberOfChars = 0;
    numberOfChars = getline(buffer, size, stdin);
    ParseLine(*buffer, separatedWords, stdinWordsCount);
    return numberOfChars;
}
bool IsStdin(int argc){
    return (argc < 2);
}
void ParseLine(char *line, char *separatedWords[], int* stdinWordsCount){
    int i = 0, isOnlyOneWord = 1;
    separatedWords[i] = line;
    while (*line != '\0'){
        if (*line == ' '){
            *line = '\0';
            i++;
            separatedWords[i] = line+1;
            isOnlyOneWord = 0;
        }
        line++;
    }
    if (isOnlyOneWord == 0){
        *stdinWordsCount = i+1;
    } else {
        *stdinWordsCount = 0;
    }
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
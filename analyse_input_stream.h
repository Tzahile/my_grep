#ifndef INPUT_STREAM_H
#define INPUT_STREAM_H

#include <stdbool.h>
#define MAX_STDIN_ARGUMENTS 12

typedef struct _Matchers{
    	bool is_A;
	int  A_value;
	bool is_b;
	bool is_c;
	bool is_i;
	bool is_n;
	bool is_v;
	bool is_x;
	bool is_E;
} Matchers;

ssize_t analyzeStdin(char** buffer, size_t* size, char *separatedWords[], int* stdinWordsCount);
bool IsStdin(int argc);
void SetNecessaryMatchers(char *words[], Matchers *matchers, int numOfWords);

#endif

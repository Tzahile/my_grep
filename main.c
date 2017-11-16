#include <stdio.h>
#include <stdlib.h>

ssize_t get_line(char **lineptr, size_t* n, FILE* f, int argc, char* argv[]);

int main(int argc, char* argv[]) {
    ssize_t a = 0;
    char* buffer = NULL;
    size_t  size=0;
    FILE* f = NULL;

    while(a != -1){
        a = get_line(&buffer, &size, f, argc, argv);
    }
    free(buffer);
    return 0;
}

ssize_t get_line(char **lineptr, size_t* n, FILE* f, int isStdin, int argc, char* argv[]){
    ssize_t mine;
    isStdin = 0;
    if(argc < 2){
       f = stdin;
//     parseLine()
    }
    else{
        f = fopen(argv[argc-1], "r");
        isStdin = 1;
    }
    mine = getline(lineptr, n, f);
    if(flag==1) fclose(f);
    return mine;
}
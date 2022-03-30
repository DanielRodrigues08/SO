#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[]){
    FILE* filePointer = fopen(argv[2], "r");
    if(filePointer == NULL){
        printf("Invalid file! \n");
        return 1;
    }

    char* line = NULL;
    size_t len = 0;
    int numLine = 1;
    int size = strlen(argv[1]);


    while ((getline(&line, &len, filePointer)) != -1) {
        char* start = line;
        char* end = line + len;
        char* offset = line;
        while(offset < end){
            offset = strstr(offset, argv[1]);
            if(offset == NULL) break;
            if(offset + size >= end) break;
            printf("[%d:%ld]\n",numLine, offset-start+1);
            offset += size;
        }
        numLine++;
    }

    return 0;
}
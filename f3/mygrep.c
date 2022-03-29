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

    int * line = NULL;
    size_t len = 0;
    int numLine = 1;
    int size = strlen(argv[1]);


    while ((getline(&line, &len, filePointer)) != -1) {
        FILE* start = filePointer;
        FILE* offset = filePointer;
        while(offset < start + len){
            offset = strstr(offset, argv[1]);
            if(offset == NULL) break;
            if(offset + size >= start + len) break;
            offset += size;
            printf("[%d:%ld]\n",numLine, offset-start);
        }
        numLine++;
    }

    free(line);
    return 0;
}
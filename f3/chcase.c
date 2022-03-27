#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc,char* argv[]){
    if(argc > 3) return 1;
    char mode = 'r';
    FILE* filePtr;
    if(argc == 2) filePtr = fopen(argv[1], &mode);
    if(argc == 3) filePtr = fopen(argv[2], &mode);
    if(filePtr == NULL){
        printf("Invalid File!\n");
        return 1;
    }

    fseek(filePtr, 0, SEEK_END);
    long int size = ftell(filePtr);
    fseek(filePtr, 0, SEEK_SET);
    char* p1 = malloc(size);
    fread(p1, 1, size, filePtr);

    fclose(filePtr);

    if(argc == 2){
        printf("%s", p1);
        return 0;
    }

    char modeL[] = "-l";
    char modeU[] = "-u";
    
    if(strcmp(argv[1], modeL) == 0){
        char* pointer = p1;
        while(*pointer != '\0'){
            *pointer = tolower(*pointer);
            pointer++;
        }
    }else if(strcmp(argv[1], modeU) == 0){
        char* pointer = p1;
        while(*pointer != '\0'){
            *pointer = toupper(*pointer);
            pointer++;
        }
    }
    else{
        printf("Invalid option! \n");
        return 1;
    }
    printf("%s", p1);
    return 0;
}
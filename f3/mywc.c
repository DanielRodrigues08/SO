#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[]){
    FILE* filePtr;

    if(argc == 2){
        filePtr = fopen(argv[1], "r");
    }else if(argc == 3){
        filePtr = fopen(argv[2], "r");
    }else{
        printf("Invalid Arguments!\n");
        return 1;
    }

    if(filePtr == NULL){ 
            printf("Invalid file!\n");
            return 1;
    }

    if(argc == 2 || strcmp(argv[1], "-c") == 0){
        fseek(filePtr, 0, SEEK_END);
        long int size = ftell(filePtr);
        printf("Size: %ld \n", size);
        
    }
    else if(strcmp(argv[1], "-l") == 0){
        int counter = 0;
        char ch;
        while((ch = getc(filePtr)) != EOF){
            if(ch == '\n') counter++;
        }
        printf("Lines: %d \n", counter);
    }
    else if(strcmp(argv[1], "-w") == 0){
        int counter = 0;
        char ch;
        while((ch = getc(filePtr)) != EOF){
            if(ch == ' ') counter++;
        }
        printf("Words: %d\n", counter+1);
    }
    else{
        printf("Invalid flag!\n");
        return 1;
    }
        
    fclose(filePtr);
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("Invalid arguments!");
        return 1;
    }
    FILE* filePtr = fopen(argv[1], "r");
    if(filePtr == NULL){ 
            printf("Invalid file!\n");
            return 1;
        }
        
    fseek(filePtr, 0, SEEK_END);
    long int size = ftell(filePtr);
        
    fseek(filePtr, 0, SEEK_SET);
    char* p1 = malloc(size);
    fread(p1, 1, size, filePtr);
    
    fclose(filePtr);

    filePtr = fopen(argv[2], "w+");

    fwrite(p1, 1, size, filePtr);
    fclose(filePtr);
    
    return 0;
}
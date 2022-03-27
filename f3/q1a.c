#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_STR_SIZE 64

int main(int argc, char* argv[]) {
    char* p1 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
    
    if(argc != 2)
        return EXIT_FAILURE;
    
    if(strlen(argv[1]) > MAX_STR_SIZE){
        printf("Exceed the string size!\n");
        return EXIT_FAILURE;
    }


    strcpy(p1, argv[1]);

    char* pointer = p1;
    while(*pointer != '\0'){
        *pointer = toupper(*pointer);
        pointer++;
    }
    
    printf("%s\n", p1);

    return EXIT_SUCCESS;
}
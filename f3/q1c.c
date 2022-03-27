#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_STR_SIZE 64

int main(int argc, char* argv[]) {
    printf("1");
    char* p1 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
    char* p2 = (char*)malloc(MAX_STR_SIZE * sizeof(char));

    if(argc != 3)
        return EXIT_FAILURE;
    
    if(strlen(argv[1]) > MAX_STR_SIZE || strlen(argv[2]) > MAX_STR_SIZE){
        printf("Exceed the string size!\n");
        return EXIT_FAILURE;
    }

    strcpy(p1, argv[1]);
    strcpy(p2, argv[2]);
    char* p3 = p2 + strlen(p2);
    int size = strlen(p1);

    int counter = 0;
    while(p2 < p3){
        p2 = strstr(p2, p1);
        if (p2 == NULL) break;
        if(p2 + size >= p3) break;
        p2 += size;
        counter++;
    }

    printf("Nº de vezes: %d\n", counter);
    return EXIT_SUCCESS;
}
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[]){
    if(argc != 1){
        printf("usage: ./mypwd\n");
        return 0;
    }
    size_t size = 255;
    char buf[255];
    getcwd(buf, size);
    printf("%s\n", buf);
    return 0;
}
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    if (argc < 2) {
        fprintf(stderr, "usage: %s file\n", argv[0]);
        return EXIT_FAILURE;
    }

    for(int i = 1; i < argc; i++){
        int fd;
        if(fd = open(argv[i], O_CREAT, 0644) == -1){
            fprintf(stderr, "mytouch: Can’t create %s\n", argv[1]);
            continue;
        }
        if(utimes(argv[i],NULL)==-1){
            fprintf(stderr, "mytouch: Time error %s\n", argv[1]);
            continue;
        }
        close(fd);
    }

    return EXIT_SUCCESS;
}
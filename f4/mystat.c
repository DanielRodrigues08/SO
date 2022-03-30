#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    struct stat info;
    if (argc < 2) {
        fprintf(stderr, "usage: %s file\n", argv[0]);
        return EXIT_FAILURE;
    }
    int counterByte = 0, counterDisk = 0;
    for(int i = 1; i < argc;i++){
        if (lstat(argv[i], &info) == -1) {
            fprintf(stderr, "fsize: Can’t stat %s\n", argv[1]);
            continue;
        }
        counterByte += (int)info.st_size;
        counterDisk += (int)info.st_blocks;
        printf("%s size: %d bytes, disk_blocks: %d, owner: %d, last modification: %ld\n",argv[1], (int)info.st_size, (int)info.st_blocks, info.st_uid, info.st_mtime);
    }
    printf("Total size: %d bytes, disk_blocks: %d \n",counterByte, counterDisk);
    
    return EXIT_SUCCESS;
}
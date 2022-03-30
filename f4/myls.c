#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char** argv){
    if(argc != 1){
        fprintf(stderr, "usage: %s\n",argv[0]);
        return EXIT_FAILURE;
    }

    DIR* q;
    struct dirent* p;
    struct stat info;
    q = opendir(".");
    p = readdir(q);
    while(p != NULL){
        if (lstat(p->d_name, &info) == -1) {
            fprintf(stderr, "ls: Can’t stat %s\n", p->d_name);
            continue;
        }
        printf( (S_ISDIR(info.st_mode)) ? "d" : "-");printf( (info.st_mode & S_IRUSR) ? "r" : "-");printf( (info.st_mode & S_IWUSR) ? "w" : "-");printf( (info.st_mode & S_IXUSR) ? "x" : "-");printf( (info.st_mode & S_IRGRP) ? "r" : "-");printf( (info.st_mode & S_IWGRP) ? "w" : "-");printf( (info.st_mode & S_IXGRP) ? "x" : "-");printf( (info.st_mode & S_IROTH) ? "r" : "-");printf( (info.st_mode & S_IWOTH) ? "w" : "-");printf( (info.st_mode & S_IXOTH) ? "x" : "-");
        printf("%d %d %ld %ld %s\n", info.st_uid, info.st_gid, info.st_size,info.st_mtime, p->d_name);
        p = readdir(q);
    }
    closedir(q);
    return EXIT_SUCCESS;
}
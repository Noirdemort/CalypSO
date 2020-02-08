// flock and fcntl -- exclusive locks
// /proc/locks

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char* argv[]){
    struct flock flk = {F_WRLCK, SEEK_SET, 0, 0, 0};
    int fd;
    
    flk.l_pid = getpid();
    
    if (argc>1){
        flk.l_type = F_RDLCK;
    }
    
    if ((fd=open("file_locks.c", O_RDWR)) == -1){
        perror("Error in opening file");
        exit(1);
    }
    
    puts("Hit Enter to lock the file");
    getchar();
    
    puts("Checking if we can lock file...");
    
    if (fcntl(fd, F_SETLKW, &flk) == -1) {
        perror("fcntl error");
        exit(1);
    }
    
    puts("Hit Enter to unlock the file");
    getchar();
    
    flk.l_type = F_UNLCK;
   
    if (fcntl(fd, F_SETLK, &flk) == -1) {
        perror("fcntl error");
        exit(1);
    }
    
    puts("File Unlocked");
    close(fd);
    
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){
    pid_t cpid;
    
    if (fork() == 0) {
        exit(0);
    }
    
    cpid = wait(NULL);
    printf("Parent's process id: %d \n Child's process id: %d\n", getpid(), cpid);
    
}

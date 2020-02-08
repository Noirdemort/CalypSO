#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>

#define KEY 0x1111

union semun {
    int value;
    struct semid_ds *buf;
    unsigned short *array;
};

struct sembuf a = {0, -1, SEM_UNDO};
struct sembuf b = {0, +1, SEM_UNDO};


int main(){
    int id = semget(key, 1, 0666 | IPC_CREAT);
    
    if (id<0){
        perror("semget error");
        exit(1);
    }
    
    union semun su;
    su.value = 1;
    
    if (semctl(id, 0, setval, su) < 0){
        perror("semctl error");
        exit(1);
    }
    
    int pid;
    pid = fork();
    srand(pid);
    
    if (pid < 0){
        perror("fork error");
        exit(1);
    }
    
    
    char *se = "abc";
    int l = strlen(se);
        
    for(int i=0; i<l; i++){
        if (semop(id, &a, 1) < 0){
            perror("semop error with a");
            exit(1);
        }
        
        putchar(se[i]);
        fflush(stdout);
        sleep(1);
        
        putchar(se[i]);
        fflush(stdout);
        
        if (semop(id, &b, 1) < 0){
            perror("semop error with a");
            exit(1);
        }
        
        sleep(1);
    }
    
        
}

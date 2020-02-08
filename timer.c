#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>

#define INTERVAL 500 // no of miliseconds

void doStuff(int);


int main(){
    
    struct itimerval it_val;
    
    if (signal(SIGALRM, (void (*) (int)) doStuff) == SIG_ERR){
        perror("Unable to catch alarm");
        exit(1);
    }
    
    it_val.it_value.tv_sec = INTERVAL/1000;
    it_val.it_value.tv_usec = INTERVAL*1000 % 1000000;
    
    it_val.it_interval = it_val.it_value;
    
    if(setitimer(ITIMER_REAL, &it_val, NULL) == -1){
        perror("setitimer error");
        exit(1);
    }
    
    for(;;)
        pause();
    
}


void doStuff(int sigCode){
    puts("Timer went off.");
}

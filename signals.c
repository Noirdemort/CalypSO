#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signalHandler(int);

int main(){
    singal(SIGINT, signalHandler);
    
    for(;;){
        printf("Sleeping...\n");
        sleep(3);
    }
}

void signalHandler(int a){
    printf("Caught signal %d...\n", a);
    exit(1);
}

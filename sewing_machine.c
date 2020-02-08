#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


void *threadCore(void *vargp){
    sleep(2);
    puts("Hell Threading");
    return NULL;
}

int main(){
    pthread_t thread_id;
    
    puts("Earlier no threading used");
    
    pthread_create(&thread_id, NULL, threadCore, NULL);
    
    pthread_join(thread_id, NULL);
    
    puts("After threading... Done.");
    
    exit(0);
}

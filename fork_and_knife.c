#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    fork();
    puts("LibertyWorld!!");
    
    // exit(0); // performs some cleaning before terminating the programs
    
    // _exit(0); // simply exits
    
    puts("Forest !!");
}

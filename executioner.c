#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    char *args[] = {"./extd", NULL};
    
    execvp(args[0], args);
    
    puts("This is executioner.");
}

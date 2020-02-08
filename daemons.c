#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>

static void struct_daemon(){
    pid_t pid;
    pid = fork();
    
    if (pid<0)
        exit(EXIT_FAILURE);
    
    if (pid>0)
        exit(EXIT_SUCCESS);
    
    if(setsid() < 0)
        exit(EXIT_FAILURE);
    
    signal(SIGCHLD, SIG_IGN);
    signal(SIGHUP, SIG_IGN);
    
    pid = fork();
    
    if (pid<0)
        exit(EXIT_FAILURE);
    
    if (pid>0)
        exit(EXIT_SUCCESS);

    umask(0);
    chdir("/");
    
    for(int i=sys_conf(_SC_OPEN_MAX); i>=0; i--){
        close(i);
    }
    
    openlog("daemon: ", LOG_PID, LOG_DAEMON);
    
}

int main(){
    struct_daemon();
    
    for(;;){
        syslog(LOG_NOTICE, "Daemon started");
        sleep(20);
        break;
    }
    
    syslog(LOG_NOTICE, "Daemon terminated");
    closelog();
    
    return EXIT_SUCCESS;
}

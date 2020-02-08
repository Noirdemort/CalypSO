#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <unistd.h>

#define EVENT_SIZE (sizeof(struct inotify_event))
#define BUFF_SIZE (1024 * (EVENT_SIZE + 16))

int main(){
    int length, i=0;
    int fd, wd;
    
    fd = inotify_init();
    
    if (fd<0){
        perror("inotify_init");
    }
    
    wd = inotify_add_watch(fd, "/home/Desktop", IN_MODIFY | IN_DELETE | IN_CREATE);
    length = read(fd, buffer, BUFF_SIZE);
    
    if (length < 0)
        perror("read");
    
    while (i<length) {
        struct inotify_event *event = (struct inotify_event *) &buffer[i];
        
        if(event->mask &IN_CREATE)
            printf("File %s was created.\n", event->name);
        
        if(event->mask &IN_DELETE)
            printf("File %s was deleted.\n", event->name);
        
        if(event->mask &IN_MODIFY)
        printf("File %s was modified.\n", event->name);
        
        i += EVENT_SIZE + event->len;
    }
    
    (void) inotify_rm_watch(fd, wd);
    (void) close();
    
}

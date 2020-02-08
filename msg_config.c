#include <stdio.h>
#include <sys/msg.h>
#include <sys/ipc.h>

struct msg_buffer {
    long msg_type;
    char msg_txt[500];
} message;


int main() {
    key_t key;
    int msg_id;
    
    key = ftok("progfile", 65);
    
    msg_id = msgget(key, 0666 | IPC_CREAT);
    
    message.msg_type = 1;
    
    puts("Enter data to send: ");
    fgets(message.msg_txt, 500, stdin);
    
    msgsnd(msg_id, &message, sizeof(message), 0);
    printf("We have sent: %s\n", message.msg_txt);
}


// recieving a msg

#include <stdio.h>
#include <sys/msg.h>
#include <sys/ipc.h>

struct msg_buffer {
    long msg_type;
    char msg_txt[500];
} message;


int main() {
    key_t key;
    int msg_id;
    
    key = ftok("progfile", 65);
    
    msg_id = msgget(key, 0666 | IPC_CREAT);
    
    
    msgrecv(msg_id, &message, sizeof(message), 1, 0);
    printf("We have sent: %s\n", message.msg_txt);
    
    msgctl(msg_id, IPC_RMID, 0);
}


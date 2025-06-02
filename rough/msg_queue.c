#include <stdio.h>
#include <string.h>
//#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_SIZE 128

void read_msg_queue()
{
    char buf[MAX_SIZE] = {0};
    int id = msgget(2345, 0666);
    msgrcv(id, &buf, MAX_SIZE, 0, IPC_NOWAIT);
 //   msgctl(id, IPC_RMID, NULL);
    printf("Data : %s\n", buf);
}
void write_msg_queue()
{
    char buf[MAX_SIZE] = "Hey dood i'm raja!";
    int id = msgget(2345, 0666| IPC_CREAT);
    msgsnd(id, buf, MAX_SIZE, IPC_NOWAIT);
 //   msgctl(id, IPC_RMID, NULL);
}

int main(int argc, char *argv[])
{
    if(strncmp(argv[1], "-w", 2) == 0)
        write_msg_queue();
    if(strncmp(argv[1], "-r", 2) == 0)
        read_msg_queue();
}

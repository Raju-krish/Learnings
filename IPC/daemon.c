#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void create_daemon()
{
    pid_t pid = fork();
    if(pid > 0) exit(0); // Parent exiting

    while(1) {
        printf("Daemon is running\n");
        sleep(1);
    }
}
int main(int argc, char *argv[])
{
    create_daemon();
}

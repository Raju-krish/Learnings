#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if(fork() == 0) {
        # getsid - Session ID 
        printf("Hey I'm the child: %d | %d\n", getpid(), getsid(getpid()));
    } else {
        printf("Hey I'm the parent: %d | %d\n", getpid(), getsid(getpid()));
    }
}

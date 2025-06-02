#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd[2] = {0};
    pipe(fd);

    if(fork() == 0) {
        sleep(1);
        char buf[100] = {0};
        close(fd[1]);
        read(fd[0], buf, sizeof(buf));
        printf("From sender : %s\n", buf);
        sleep(10);
        close(fd[0]);
    }
    else {
        char buf[100] = "Hey I'm the server !!";
        close(fd[0]);
        write(fd[1], buf, sizeof(buf));
        printf("I've written the data\n");
        close(fd[1]);
    }
}

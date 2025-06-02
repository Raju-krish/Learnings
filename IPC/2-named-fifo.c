#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define FIFO_FILE "/tmp/fifo"

/* Client */
void client()
{
    int fd = open(FIFO_FILE, O_RDWR);
    char buf[100] = {0};

    read(fd, buf, sizeof(buf));
    printf("From server : %s\n", buf);
    write(fd, "I'm done bye", 100);
}


/* Server */
void server()
{
    int fd = open(FIFO_FILE, O_RDWR);
    char buf[100] = "Hey this is raja's server !";

    write(fd, buf, sizeof(buf));
    memset(buf, 0, sizeof(buf));
    read(fd, buf, sizeof(buf));
    printf("FRom client : %s\n", buf);
}

int main(int argc, char *argv[])
{
    mkfifo(FIFO_FILE, 0666); // You can do it in shell either with mkfifo command -> creates a file with pipe
    if(strncmp(argv[1], "-c", 3) == 0) client();
    if(strncmp(argv[1], "-s", 3) == 0) server();
}

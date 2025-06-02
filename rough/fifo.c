#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>


void read_fifo()
{
    char buf[10] = {0};
    mkfifo("/tmp/fifo-file", 0666);

    int fd = open("/tmp/fifo-file", O_RDONLY);

    read(fd, &buf, 10);
    printf("Read from fifo: %s\n", buf);
    close(fd);

}

void write_fifo()
{
    mkfifo("/tmp/fifo-file", 0666);

    int fd = open("/tmp/fifo-file", O_WRONLY);

    write(fd, "naa raja..", 10);
    close(fd);

}

int main(int argc, char *argv[])
{
    if(strncmp(argv[1], "-w", 2) == 0)
        write_fifo();
    if(strncmp(argv[1], "-r", 2) == 0)
        read_fifo();

}

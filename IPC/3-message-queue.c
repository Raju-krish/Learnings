#include <fcntl.h>
#include <stdio.h>
#include <mqueue.h>
#include <string.h>
#include <errno.h>

void client()
{
    mqd_t fd = mq_open("/msg_queue", O_RDONLY);
    char buf[124] = {0};

    if(mq_receive(fd, buf, sizeof(buf), 0) == -1)
        perror("mq_recive : ");
    printf("From server : %s\n", buf);
    mq_close(fd);
    mq_unlink("/msg_queue");
}

void server()
{
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 124;  // must match or exceed the message size you're sending
    // attr.mq_curmsgs = 0;

    mqd_t fd = mq_open("/msg_queue", O_WRONLY|O_CREAT, 0666, &attr);
    char buf[124] = "Hey this is server da !";
    mq_send(fd, buf, 124, 0);
    mq_close(fd);
}

int main(int argc, char *argv[])
{
    if(strncmp(argv[1], "-c", 3) == 0) client();
    if(strncmp(argv[1], "-s", 3) == 0) server();
}

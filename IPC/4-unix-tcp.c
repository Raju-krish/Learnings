#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>

#define SOCK_FILE "/tmp/sock_file"

void client()
{
    int sock_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    
    struct sockaddr_un addr;
    strncpy(addr.sun_path, SOCK_FILE, sizeof(addr.sun_path));
    addr.sun_family = AF_UNIX;

    connect(sock_fd, (struct sockaddr *)&addr, sizeof(addr));

    char buf[124] = "Hey i'm client";
    send(sock_fd,buf, sizeof(buf), 0);
    memset(buf, 0, sizeof(buf));
    recv(sock_fd, buf, sizeof(buf), 0);
    printf("From server: %s\n", buf);
}

void server()
{
    int sock_fd = socket(AF_UNIX, SOCK_STREAM, 0);

    struct sockaddr_un addr;
    strncpy(addr.sun_path, SOCK_FILE, sizeof(addr.sun_path));
    addr.sun_family = AF_UNIX;

    bind(sock_fd, (struct sockaddr *)&addr, sizeof(addr));

    listen(sock_fd, 3);
    while(1) {
        char buf[124] = {0};
        int new_sock_fd = accept(sock_fd, NULL, NULL);
        recv(new_sock_fd, buf, sizeof(buf), 0);
        printf("recv : %s\n", buf);
        send(new_sock_fd, "Hi, okay bye", 124, 0);
    }
}

int main(int argc, char *argv[])
{
    if(strncmp(argv[1], "-c", 3) == 0) client();
    if(strncmp(argv[1], "-s", 3) == 0) server();
}

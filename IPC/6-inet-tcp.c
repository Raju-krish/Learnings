#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

void server(int port)
{
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    bind(sock_fd, (struct sockaddr*)&addr, sizeof(addr));
    listen(sock_fd, 5);
    while(1) {
        char buf[124] = {0};
        int new_sock_fd = accept(sock_fd, NULL, NULL);
        recv(new_sock_fd, buf, sizeof(buf), 0);
        printf("From client : %s\n", buf);
        memset(buf, 0, sizeof(buf));
        send(new_sock_fd, "Okay bye bye", sizeof(buf), 0);
        close(new_sock_fd);
    }
    close(sock_fd);
}

void client(char *ip_addr, int port)
{
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_addr);
    addr.sin_port = htons(port);

    char buf[124] = {0};
    connect(sock_fd, (struct sockaddr*)&addr, sizeof(addr));
    send(sock_fd, "Hey I'm client !", sizeof(buf), 0);
    recv(sock_fd, buf, sizeof(buf), 0);
    printf("From server : %s\n", buf);
    close(sock_fd);
}

int main(int argc, char *argv[])
{
    if(strncmp(argv[1], "-s", 3) == 0) server(atoi(argv[2])); 
    if(strncmp(argv[1], "-c", 3) == 0) client(argv[2], atoi(argv[3])); 
}

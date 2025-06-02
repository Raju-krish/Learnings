#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

void server(int port)
{
    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    bind(sock_fd, (struct sockaddr*) &addr, sizeof(addr));

    while(1) {
        struct sockaddr_in client_addr;
        char buf[124] = {0};
        socklen_t len = sizeof(client_addr);
        recvfrom(sock_fd, buf, sizeof(buf), 0, (struct sockaddr*)&client_addr, &len);
        printf("From client: %s\n", buf);
        memset(buf, 0, sizeof(buf));
        sendto(sock_fd, "Okay myname is billa bye!\n", sizeof(buf), 0, (struct sockaddr*)&client_addr, len);
    }
    close(sock_fd);
}

void client(char *ip_addr, int port)
{
    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip_addr);

    char buf[124] = {0};
    sendto(sock_fd, "Hey this is client\n", sizeof(buf), 0, (struct sockaddr*)&addr, sizeof(addr));
    recvfrom(sock_fd, buf, sizeof(buf), 0, (struct sockaddr*)&addr, (socklen_t*)sizeof(addr));
    printf("FRom server: %s\n", buf);
    close(sock_fd);
}

int main(int argc, char *argv[])
{
    if(strncmp(argv[1], "-c", 3) == 0) client(argv[2], atoi(argv[3]));
    if(strncmp(argv[1], "-s", 3) == 0) server(atoi(argv[2]));

}

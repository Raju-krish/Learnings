#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCK_FILE "/tmp/unix-stream"
#define MAX_SIZE 128

void init_client()
{
    int sock_fd = socket(AF_LOCAL, SOCK_STREAM, IPPROTO_IP);
    char buf[MAX_SIZE] = {0};
    struct sockaddr_un cli_addr;
    cli_addr.sun_family = AF_LOCAL;
    strncpy(cli_addr.sun_path, SOCK_FILE, sizeof(cli_addr.sun_path));

    connect(sock_fd, (struct sockaddr*)&cli_addr, sizeof(cli_addr));
    recv(sock_fd, &buf, MAX_SIZE, 0);
    printf("Data from server: %s\n", buf);
    strncpy(buf, "Hi dood, I'm client, tata", MAX_SIZE);
    send(sock_fd, buf, MAX_SIZE, 0);
    close(sock_fd);
}

void init_server()
{
    int sock_fd = socket(AF_LOCAL, SOCK_STREAM, IPPROTO_IP);

    struct sockaddr_un serv_addr;
    serv_addr.sun_family = AF_LOCAL;
    strncpy(serv_addr.sun_path,SOCK_FILE, sizeof(serv_addr.sun_path));

    bind(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    listen(sock_fd, 5);
    while (1)
    {
        char buf[MAX_SIZE] = "Hey!! client, I'm the server";
        int cli_fd = accept(sock_fd, NULL, NULL);
        send(cli_fd, buf, MAX_SIZE, 0);
        recv(cli_fd, &buf, MAX_SIZE, 0);
        printf("Data from client: %s\n", buf);
        close(cli_fd);
    }
}

int main(int argc, char *argv[])
{
    if(strncmp(argv[1], "-s", 2)== 0)
        init_server();
    if(strncmp(argv[1], "-c", 2) == 0)
        init_client();
}

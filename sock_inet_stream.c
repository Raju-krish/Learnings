#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define  MAX_SIZE 128
void init_client(char *addr)
{
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    char buf[MAX_SIZE] = {0};
    struct sockaddr_in client_addr;
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(6229);
    client_addr.sin_addr.s_addr = inet_addr(addr);

    connect(sock_fd, (struct sockaddr*)&client_addr, sizeof(client_addr));
    recv(sock_fd, &buf, MAX_SIZE, 0);
    printf("Data from server: %s\n", buf);
    strncpy(buf, "Hi dood, i'm client tata bye!!", MAX_SIZE);
    send(sock_fd, buf, MAX_SIZE, 0);
    close(sock_fd);
}

void init_server()
{
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(6229);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    bind(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    listen(sock_fd, 5);
    while(1)
    {
        char buf[MAX_SIZE] = "Hey!! client, I'm the server";
        int new_cli = accept(sock_fd, NULL,NULL);
        send(new_cli, buf, MAX_SIZE, 0);
        recv(new_cli, &buf, MAX_SIZE, 0);

        printf("Data from client: %s\n", buf);
        close(new_cli);
    }
    close(sock_fd);

}

int main(int argc, char **argv)
{
    if(strncmp(argv[1], "-c", 2) == 0)
        init_client(argv[2]);
    if(strncmp(argv[1], "-s", 2) == 0)
        init_server();
}

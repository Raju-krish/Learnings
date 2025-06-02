#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define  MAX_SIZE 128
void init_client(char *addr)
{
    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    char buf[MAX_SIZE] = {0};
    struct sockaddr_in client_addr;
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(6229);
    client_addr.sin_addr.s_addr = inet_addr(addr);

    strncpy(buf, "Hi dood, i'm client tata bye!!", MAX_SIZE);
    sendto(sock_fd, buf, MAX_SIZE, 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
    close(sock_fd);
}

void init_server()
{
    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in serv_addr, client_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(6229);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    bind(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    while(1)
    {
        char buf[MAX_SIZE] = {0};
        recvfrom(sock_fd, &buf, MAX_SIZE, 0, (struct sockaddr*)&client_addr, (socklen_t*)sizeof(client_addr));

        printf("Data from client: %s\n", buf);
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

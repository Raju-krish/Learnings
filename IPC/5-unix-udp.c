#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <errno.h>

#define SERVER_SOCK_FILE "/tmp/server_sock_file"
#define CLIENT_SOCK_FILE "/tmp/cli_sock_file"
void client()
{
    int sock_fd = socket(AF_UNIX, SOCK_DGRAM, 0);
    struct sockaddr_un addr, server_addr;

    strncpy(addr.sun_path, CLIENT_SOCK_FILE, sizeof(addr.sun_path));
    addr.sun_family = AF_UNIX;
    
    strncpy(server_addr.sun_path, SERVER_SOCK_FILE, sizeof(server_addr.sun_path));
    server_addr.sun_family = AF_UNIX;

    if(bind(sock_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Bind failed: ");
    }

    char buf[124] = "Hey I'm client";
    if(sendto(sock_fd, buf, sizeof(buf), 0, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
        perror("Send_to failed: ");
    memset(buf, 0, sizeof(buf));
    if(recvfrom(sock_fd, buf, sizeof(buf), 0, NULL, NULL) < 0)
        perror("REcvfrom failed: ");
    printf("From server: %s\n", buf);
    close(sock_fd);
    unlink(CLIENT_SOCK_FILE);
}

void server()
{
    int sock_fd =  socket(AF_UNIX, SOCK_DGRAM, 0);
    struct sockaddr_un addr, client_addr;

    strncpy(addr.sun_path, SERVER_SOCK_FILE, sizeof(addr.sun_path));
    addr.sun_family = AF_UNIX;
    
    if(bind(sock_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        perror("Bind failed: ");

    while(1) {
        char buf[124] = {0};
        socklen_t len = sizeof(addr);
        if(recvfrom(sock_fd, buf, sizeof(buf), 0, (struct sockaddr*)&client_addr, &len) < 0)
            perror("Recv_from failed: ");
        printf("Message from client: %s\n", buf);
        strncpy(buf, "Hey I'm server, tata bye", 124);
        if(sendto(sock_fd, buf, sizeof(buf), 0, (struct sockaddr*)&client_addr, len) < 0)
            perror("Send_to failed: ");
    }

    close(sock_fd);
    unlink(SERVER_SOCK_FILE);
}

int main(int argc, char *argv[])
{
    if(strncmp(argv[1], "-c", 3) == 0) client();
    if(strncmp(argv[1], "-s", 3) == 0) server();
}

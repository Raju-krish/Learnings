#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>


int server_func()
{
    int sock_fd = socket(AF_UNIX, SOCK_STREAM, 0);

    struct sockaddr_un  server_addr;
    server_addr.sun_family = AF_UNIX;
    strncpy(server_addr.sun_path,"/tmp/test", sizeof(server_addr.sun_path));

    bind(sock_fd, (struct sockaddr *)&server_addr, (socklen_t)sizeof(struct sockaddr_un));
    listen(sock_fd, 2);
    char buf[1024] = {0};
        int new_sock ;
    while(1) {
    while((new_sock = accept(sock_fd, NULL, NULL)) > 0) {
        read(new_sock, &buf, sizeof(buf));
        printf("Recevive from client - %s\n", buf);
        write(new_sock, "tata byebye", 100);
        close(new_sock);
    }
    }
    return 0;
}

int client_func()
{
    int sock_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    struct sockaddr_un client_addr;
    client_addr.sun_family = AF_UNIX;
    strncpy(client_addr.sun_path, "/tmp/test", sizeof(client_addr.sun_path));
    connect(sock_fd, (struct sockaddr*)&client_addr, (socklen_t)sizeof(struct sockaddr_un));
    write(sock_fd, "Hey server i;m client", 100);
    char buf[1024] = {0};
    read(sock_fd, &buf, sizeof(buf));
    printf("From server: %s\n", buf);
    return 0;
}

int main(int argc, char *argv[])
{
    if(argc < 2) return 0;
    if(strncmp(argv[1], "-s", 2) == 0) server_func();
    if(strncmp(argv[1], "-c", 2) == 0) client_func();
}

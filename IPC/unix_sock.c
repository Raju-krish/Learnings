#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int create_server() 
{
    int sock_fd = socket(AF_LOCAL, SOCK_STREAM, 0);
    struct sockaddr_un addr;
    if(sock_fd < 0) {
        printf("Socket creation failed\n");
        return -1;
    }
    addr.sun_family = AF_LOCAL;
    strcpy(addr.sun_path, "/tmp/sock_path");

    if(bind(sock_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        printf("Binding failed\n");
        return -1;
    }
    
    listen(sock_fd, 4);
    int new_fd = accept(sock_fd, NULL, NULL);
    if(new_fd < 0) {
        printf("Accept failed\n");
        return -1;
    }

    char buf[1024] = {0};
    int num = read(new_fd, buf, sizeof(buf));
    buf[num] = '\0';
    printf("Message from client : %s\n", buf);
    close(new_fd);
    close(sock_fd);
    return 0;
}

int create_client()
{

    int sock_fd = socket(AF_LOCAL, SOCK_STREAM, 0);
    struct sockaddr_un addr;
    if(sock_fd < 0) {
        printf("Failure in creating socket\n");
        return -1;
    }
    
    addr.sun_family = AF_LOCAL;
    strncpy(addr.sun_path, "/tmp/sock_path", sizeof(addr.sun_path));

    if(connect(sock_fd, (struct sockaddr *) &addr, sizeof(struct sockaddr_un)) < 0) {
        printf("Connection failed\n");
        return -1;
    }

    char *buf = "Hi I'm rajagopal";
    write(sock_fd, buf, strlen(buf));
    close(sock_fd);

    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Need argument as whtehr its a cleint or server\n");
        return -1;
    }

    if(strstr(argv[1], "-c") != NULL) {
        create_client();
    }
    if(strstr(argv[1], "-s") != NULL) {
        create_server();
    }
}

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DST_PORT 2223

int main()
{
    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd < 0) { perror("socket"); return 1; }

    struct sockaddr_in addr = {0};
    addr.sin_family      = AF_INET;
    addr.sin_port        = htons(DST_PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return 1;
    }

    printf("Listening on UDP port %d ...\n\n", DST_PORT);

    char buf[1600] = {0};
    struct sockaddr_in sender = {0};
    socklen_t sender_len = sizeof(sender);

    int n = recvfrom(fd, buf, sizeof(buf), 0,
                     (struct sockaddr *)&sender, &sender_len);

    printf("=== What app received ===\n");
    printf("Bytes returned by recvfrom() : %d\n", n);
    printf("Data                         : %s\n", buf);
    printf("Data (hex): %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n", 
                        buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7], buf[8], buf[9], buf[10], buf[11],
                        buf[12], buf[13], buf[14]);
    printf("\n");
    printf("ETH(14) + IP(20) + UDP(8) = 42 bytes were stripped by kernel\n");
    printf("Only payload reached userspace — decapsulation proven.\n");

    close(fd);
    return 0;
}


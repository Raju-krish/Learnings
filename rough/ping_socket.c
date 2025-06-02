#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1
unsigned short calculate_checksum(void *buffer, int length) {
    unsigned short *ptr = buffer;
    unsigned int sum = 0;

    // Sum all 16-bit words
    while (length > 1) {
        sum += *ptr++;
        length -= 2;
    }

    // If there's a leftover byte, pad and add
    if (length == 1) {
        sum += *(unsigned char *)ptr;
    }

    // Add carry bits
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);

    // One's complement (flip bits)
    return (unsigned short)(~sum);
}

int main(int argc, char *argv[])
{
    int sockfd = 0;
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if(sockfd < 0)
    {
        printf("Socket creation failed");
        return FAILURE;
    }

    struct sockaddr_in target_addr;
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(argv[1]);


    struct icmphdr icmp_req;
    memset(&icmp_req, 0, sizeof(icmp_req));

    icmp_req.type = ICMP_ECHO;
    icmp_req.code = 0;
    //icmp_req.checksum = calculate_checksum(&icmp_req, sizeof(icmp_req));

    if (sendto(sockfd, &icmp_req, sizeof(icmp_req), 0, (struct sockaddr*)&target_addr, sizeof(target_addr)) < 0)
    {
        printf("Sento failed\n");
        return FAILURE;
    }

     printf("Ping request sent to %s\n", argv[1]);


    char buffer[1024] = {0};
    struct sockaddr_in recv_addr;
    socklen_t socklen = sizeof(recv_addr);
    recvfrom(sockfd, &buffer, sizeof(buffer), 0, (struct sockaddr*)&recv_addr, &socklen);

    struct icmphdr *icmp_resp = (struct icmphdr *)(buffer + 20);


    if (icmp_resp->type == ICMP_ECHOREPLY) {
        printf("Received ICMP Echo Reply from %s\n", argv[1]);
    }
    else {
        printf("Received ICMP with packet type =%d\n", icmp_resp->type);
    }
}

/******************************************************************************
  * @file      :  
  * @brief     :  
  * @Author    : M Rajagopalaswamy (m.rajagopalaswamy@vvdntech.in)
  * @Copyright : (c) 2021 , VVDN Technologies Pvt. Ltd.
  *              Permission is hereby granted to everyone in VVDN Technologies
  *              to use the Software without restriction, including without
  *              limitation the rights to use, copy, modify, merge, publish,
  *              distribute, distribute with modifications.
  ****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>

#define DEST_IP "127.0.0.1"  // Loopback address
#define BUFFER_SIZE 4096

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    if (len == 1)
        sum += *(unsigned char *)buf;

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

int main() {
    int sockfd;
    struct sockaddr_in dest_addr;
    char buffer[BUFFER_SIZE];

    // Create a raw socket
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the destination address
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = inet_addr(DEST_IP); // Loopback address

    // Create an ICMP header
    struct icmphdr *icmp_header = (struct icmphdr *)buffer;
    icmp_header->type = ICMP_ECHO;
    icmp_header->code = 0;
    icmp_header->checksum = 0; // Checksum will be calculated
    icmp_header->un.echo.id = htons(1);
    icmp_header->un.echo.sequence = htons(1);

    // Calculate the checksum
    icmp_header->checksum = checksum(buffer, sizeof(struct icmphdr));

    // Send the packet
    ssize_t sent_size = sendto(sockfd, buffer, sizeof(struct icmphdr), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
    if (sent_size < 0) {
        perror("Packet sending failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("ICMP Echo Request sent to %s\n", DEST_IP);

    close(sockfd);
    return 0;
}


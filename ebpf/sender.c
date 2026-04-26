#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netpacket/packet.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define IPHSIZE   20
#define ETHSIZE   14
#define UDPHSIZE  8
#define PAYLOADSIZE 15   /* "Rajagoapalasamy" */

typedef unsigned char BYTE;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t  u8;

/* ── checksum helpers ── */
static unsigned short in_cksum(u16 *ptr, int nbytes)
{
    register long sum = 0;
    u16 oddbyte;
    register u16 answer;

    while (nbytes > 1) { sum += *ptr++; nbytes -= 2; }
    if (nbytes == 1) {
        oddbyte = 0;
        *((unsigned char *)&oddbyte) = *(unsigned char *)ptr;
        sum += oddbyte;
    }
    sum     = (sum >> 16) + (sum & 0xffff);
    sum    += (sum >> 16);
    answer  = ~sum;
    return answer;
}

unsigned short udp_checksum(u32 src, u32 dst, u8 proto, u16 len, u8 *hstart)
{
    struct pseudo {
        u32 src;
        u32 dst;
        u8  zero;
        u8  proto;
        u16 length;
    } *hdr = (struct pseudo *)(hstart - sizeof(struct pseudo));

    hdr->src    = src;
    hdr->dst    = dst;
    hdr->zero   = 0;
    hdr->proto  = proto;
    hdr->length = htons(len);
    return in_cksum((u16 *)hdr, len + sizeof(struct pseudo));
}

/* ── socket ── */
int create_socket(char *device)
{
    struct ifreq ifr;
    int sock_fd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sock_fd < 0) { perror("socket"); return -1; }

    printf("Interface : %s\n", device);
    strncpy(ifr.ifr_name, device, sizeof(ifr.ifr_name));
    if (ioctl(sock_fd, SIOCGIFINDEX, &ifr) < 0) { perror("ioctl"); return -1; }

    struct sockaddr_ll addr = {0};
    addr.sll_family   = AF_PACKET;
    addr.sll_ifindex  = ifr.ifr_ifindex;
    addr.sll_protocol = htons(ETH_P_ALL);
    if (bind(sock_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return -1;
    }
    return sock_fd;
}

int main(int argc, char *argv[])
{
    if (argc < 2) { fprintf(stderr, "Usage: %s <interface>\n", argv[0]); return 1; }

    /* ── buffer ── */
    char buf[1600] = {0};
    char payload[]  = "Rajagopalaswamy";   /* 15 bytes */

    /* ── L2 : Ethernet header ──
     *  src mac : aa:bb:cc:dd:ee:ff   (sender NIC  — change to your sender MAC)
     *  dst mac : ff:ee:dd:cc:bb:aa   (receiver NIC — change to your receiver MAC)
     *  type    : 0x0800 (IPv4)
     */
    BYTE l2_hdr[ETHSIZE] = {
 // Add sender and receiver mac like below
 //       0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff,   /* dst mac */
 //      0xff, 0xee, 0xdd, 0xcc, 0xbb, 0xaa,   /* src mac */
        0x08, 0x00                              /* EtherType IPv4 */
    };

    /* ── L3 : IP header ── */
    struct iphdr ip = {0};
    ip.version  = 4;
    ip.ihl      = IPHSIZE >> 2;              /* 5 (20 bytes) */
    ip.tos      = 0;
    ip.id       = htons(1675);
    ip.frag_off = 0;
    ip.ttl      = 64;                        /* FIX: was htons(5) — ttl is 1 byte */
    ip.protocol = IPPROTO_UDP;
    ip.saddr    = inet_addr("REPLACE_SENDER_IP");
    ip.daddr    = inet_addr("REPLACE_RECEIVER_IP");
    ip.tot_len  = htons(IPHSIZE + UDPHSIZE + PAYLOADSIZE);
    ip.check    = (unsigned short)in_cksum((unsigned short *)&ip, IPHSIZE); /* FIX: was missing */

    /* ── L4 : UDP header ── */
    struct udphdr udp = {0};
    udp.uh_sport = htons(1112);
    udp.uh_dport = htons(2223);
    udp.uh_ulen  = htons(UDPHSIZE + PAYLOADSIZE);

    /* UDP checksum — place payload at buf+120 for pseudo-header room */
    BYTE *udp_start = (BYTE *)(buf + 120);
    memcpy(udp_start,            &udp,    UDPHSIZE);
    memcpy(udp_start + UDPHSIZE, payload, PAYLOADSIZE);
    udp.uh_sum = udp_checksum(ip.saddr, ip.daddr, ip.protocol,
                               UDPHSIZE + PAYLOADSIZE, udp_start);

    /* ── assemble frame ── */
    memcpy(buf,                            l2_hdr,  ETHSIZE);
    memcpy(buf + ETHSIZE,                  &ip,     IPHSIZE);
    memcpy(buf + ETHSIZE + IPHSIZE,        &udp,    UDPHSIZE);
    memcpy(buf + ETHSIZE + IPHSIZE + UDPHSIZE, payload, PAYLOADSIZE);

    int total = ETHSIZE + IPHSIZE + UDPHSIZE + PAYLOADSIZE;

    /* ── send ── */
    int sock_fd = create_socket(argv[1]);
    if (sock_fd < 0) return 1;

    int sent = write(sock_fd, buf, total);
    printf("Sent %d bytes\n", sent);
    printf("  ETH  header : %d bytes\n", ETHSIZE);
    printf("  IP   header : %d bytes\n", IPHSIZE);
    printf("  UDP  header : %d bytes\n", UDPHSIZE);
    printf("  Payload     : %d bytes  (\"%s\")\n", PAYLOADSIZE, payload);
    printf("  Total       : %d bytes on wire\n", total);

    close(sock_fd);
    return 0;
}


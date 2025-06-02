#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netpacket/packet.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <getopt.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <malloc.h>
#include <net/ethernet.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>


#define IPHSIZE 20
#define ETHSIZE	14
#define UDPHSIZE 8

typedef unsigned char BYTE;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;


int create_socket(char *device)
{
    struct ifreq ifr;
    int sock_fd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if(sock_fd < 0)
    {
        perror("Socket creation failed");
        return -1;
    }

    printf("User given Device : %s\n", device);
    strncpy(ifr.ifr_name, device, sizeof(ifr.ifr_name));
    if(ioctl(sock_fd, SIOCGIFINDEX, &ifr) < 0)
    {
        perror("ioctl Failed");
        return -1;
    }

    struct sockaddr_ll addr;

    addr.sll_family = AF_PACKET;
    addr.sll_ifindex = ifr.ifr_ifindex;
    addr.sll_protocol = htons(ETH_P_ALL);

    if(bind(sock_fd,(struct sockaddr*)&addr, (socklen_t)sizeof(addr)) < 0 )
    {
        perror("socket bidn failed");
        return -1;
    }

    return sock_fd;
}
static unsigned short in_cksum(u16 *ptr, int nbytes)
{
  register long sum=0;
  u16 oddbyte;
  register u16 answer;

  while(nbytes>1) { sum += *ptr++; nbytes -= 2; }
  if(nbytes == 1) { oddbyte = 0; *((unsigned char *) &oddbyte) = *(unsigned char *)ptr; sum += oddbyte; }
  sum  = (sum >> 16)+(sum & 0xffff); sum+=(sum >> 16); answer = ~sum;
  return(answer);
}
unsigned short magic_tcpudp_cksum(u32 src, u32 dst, u8 proto, u16 len, u8 *hstart)
{
	struct pseudo { u32 src; u32 dst; u8 zero; u8 proto; u16 length;
	} *hdr = (struct pseudo *) (hstart - sizeof(struct pseudo));
	
	hdr->src = src;
	hdr->dst = dst;
	hdr->zero = 0;
	hdr->proto = proto;
	hdr->length = htons(len);
	return in_cksum((u16 *) hdr, len + sizeof(struct pseudo));
}

int main(int argc, char *argv[])
{
    // BYTE custom_buf[25] = {0x23, 0x33, 0x44, 0x55, 0x00, 0x19, 0x00, 0x00, 'R', 'A', 'J', 'A', 'g', 'o', 'p', 'a', 'l', 'a', 's', 'w',
    //                        'a', 'm', 'y' };
    char buf[1600] = {0};
    char custom_buf[17] = "Rajagoapalasamy";

    // Here ETHERNET header is formed (dest mac, src mac, type)
    BYTE l2_hdr[14] = { 0x34, 0x73, 0x5a, 0xd3, 0x5f, 0xc4, 0xc0, 0x18, 0x50, 0x1b, 0x2b, 0xab, 0x08, 0x00};

    // Here IP header is formed
    struct iphdr ip;
    ip.version    = 4;
    ip.ihl = IPHSIZE >> 2;
    ip.tos = 0;
    ip.id = htons(1675);
    ip.frag_off = 0;
    ip.ttl = htons(5);
    ip.protocol = IPPROTO_UDP;
    ip.saddr = inet_addr("10.42.0.1");
    ip.daddr = inet_addr("10.42.0.22");
    ip.tot_len = htons(IPHSIZE + UDPHSIZE + 25);

    // Here udp checksum calculated (google and get it)
    // BYTE *buf_chksum = (BYTE *)(buf+120);
    // memcpy(buf_chksum, custom_buf, 25);
    // unsigned short new_udp_checksum = magic_tcpudp_cksum(ip.saddr, ip.daddr, ip.protocol, (u16)(UDPHSIZE+25), (u8*) buf_chksum );
    //
    // ip.check = (unsigned short)in_cksum((unsigned short *)&ip, IPHSIZE);

    // Here UDP header is formed
    struct udphdr udp;
    udp.uh_sport = htons(1112);
    udp.uh_dport = htons(2223);
    udp.uh_ulen = htons(UDPHSIZE + 25);
    // udp.uh_sum = new_udp_checksum;

    memcpy(buf, l2_hdr, ETHSIZE);
    memcpy(buf+ETHSIZE, &ip, IPHSIZE);
    memcpy(buf+ETHSIZE+IPHSIZE, &udp, UDPHSIZE);
    memcpy(buf+ETHSIZE+IPHSIZE + UDPHSIZE, custom_buf, 25);

    int sock_fd = create_socket(argv[1]);
    if(!(sock_fd) ) { printf("no sock_fd found\n"); }
 
	write(sock_fd, buf, ETHSIZE+IPHSIZE+UDPHSIZE+25);

}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct packet {
    char length;
    char data[];
};

int main() {
    char msg[20];

    struct packet *p = malloc(sizeof(struct packet));
    scanf("%s", msg);
    size_t len = strlen(msg) + 1;
    p->length = len;
    printf("Packet length: %ld, data: %s\n", sizeof(struct packet), p->data);
    memcpy(p->data, msg, len);

    printf("Packet length: %ld, data: %s\n", sizeof(struct packet), p->data);
    free(p);
    return 0;
}

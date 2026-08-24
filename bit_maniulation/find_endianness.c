#include <stdio.h>

int main()
{
    unsigned int x = 0x12345678;
    unsigned char *p = (unsigned char *)&x;

    if (*p == 0x78)
        printf("Little Endian\n");
    else if (*p == 0x12)
        printf("Big Endian\n");

    return 0;
}

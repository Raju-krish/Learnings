#include <stdio.h>

union check{
    int data;
    char byte[4];
    char num;
};

int main(int argc, char *argv[])
{
    union check c;
    c.data = 0x12345678;
    
    // printf("%x %x %x %x\n", c.byte[0], c.byte[1], c.byte[2], c.byte[3]);
    // printf("%x\n", c.data);

    if(c.byte[0] == 0x78)
        printf("Little Endian\n");
    else if(c.byte[0] == 0x12)
        printf("Big Endian\n");
    else
        printf("Unknown endianness\n");

}

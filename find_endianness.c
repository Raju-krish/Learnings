#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 0x12345678;
    char *b = &a;
    if(*b == 0x78)
        printf("Litle endian machin\n");
    if(*b == 0x12)
        printf("Big endian machin\n");
}

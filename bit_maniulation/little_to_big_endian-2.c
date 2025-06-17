#include <stdio.h>


int convert_endiannes(int val) 
{
    return (val >> 24 & 0x000000FF) |
           (val >> 8  & 0x0000FF00) |
           (val << 8  & 0x00FF0000) |
           (val << 24 & 0xFF000000);
}

int main(int argc, char *argv[])
{
    int little_endian = 0x12345678;
    int big_endian = convert_endiannes(little_endian);

    printf("Littel = %x\nBig = %x\n", little_endian, big_endian);
}

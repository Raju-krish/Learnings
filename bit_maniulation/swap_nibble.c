#include <stdio.h>


int main(int argc, char *argv[])
{
    int a = 0x3e3e3e3e;                 // 00111110 00111110 
    int right_nibble_mask = 0x0f0f0f0f; // 00001111
    int right_nible = a & right_nibble_mask; // 00001110
    a &= 0xf0f0f0f0; // 00110000 00110000
    a >>= 4;
    right_nible <<= 4;
    a |= right_nible;
    printf("after swap = %x\n", a);

}


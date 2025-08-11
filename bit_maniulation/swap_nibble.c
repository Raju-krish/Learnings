
#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 0x3e3e3e3e; 
    int right_nibble_mask = 0x0f0f0f0f; // 00001111
    int left_nibble_mask = 0xf0f0f0f0;  // 11110000
    
    int right_nible = a & right_nibble_mask;
    int left_nibble = a & left_nibble_mask;
    
    right_nible <<= 4;
    left_nibble >>= 4;
    a = left_nibble | right_nible;
   
    printf("after swap = %x\n", a);
}

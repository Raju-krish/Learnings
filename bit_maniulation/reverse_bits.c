#include <stdio.h>

int reverse_bits(int n)
{
    int reversed = 0;
    for (int i = 0; i < 32; i++) {
        reversed <<= 1;
        reversed |= (n & 1);
        n >>= 1;
    }
    return reversed;
}

int main(int argc, char *argv[])
{
    int a = 0b00101111;
    int b = reverse_bits(a);
    printf("%u", b);
}

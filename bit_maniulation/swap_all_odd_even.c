#include <stdio.h>

int main(int argc, char *argv[])
{
    int even_bit_mask = 0xAAAAAAAA; // ==> 10101010 10101010 10101010 10101010 ==> all even bit position alone set
    int odd_bit_mask = 0x55555555;  // ==> 01010101 01010101 01010101 01010101 ==> all odd bit position alone set

    int even = 0;
    int odd = 0;
    printf("Enter number to shift the even bit position : ");
    scanf("%d", &even);
    printf("Enter number to shift the odd bit position : ");
    scanf("%d", &odd);

    int final = (even & even_bit_mask) >> 1;
    printf("After swapping all even position bits : %d\n", final);
    final = (odd & odd_bit_mask) << 1;
    printf("After swapping all odd position bits : %d\n", final);


}

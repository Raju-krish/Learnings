#include <stdio.h>

void set_bits_range(int* num, int start, int end)
{
    int mask = (1 << (start-end + 1));
    mask = (mask - 1) << end;
    *num |= mask;
}

void print_bits(int num) 
{
    for(int i = 31; i >= 0; i--)
    {
        if((i+1) % 8 == 0)
            printf(" ");
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int start = 0;
    int end = 0;
    int num = 0;
    printf("Enter the range to set the bits \n");
    printf("Starts at bit : ");
    scanf("%d", &start);
    printf("Ends at bit : ");
    scanf("%d", &end);
    set_bits_range(&num, start, end);
    print_bits(num);
}

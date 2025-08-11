#include <stdio.h>

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

int main()
{
    int n = 127;
    int count = 0;
    printf("Enter the num of rotation: ");
    scanf("%d", &count);
    
    int mask = (1<<count);
    mask = mask-1;
    
    int val = n & mask;
    n = n >> count;
    val = val << (32-count);
    
    n = n | val;
    print_bits(n);

    return 0;
}

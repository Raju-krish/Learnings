#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 0;
    int b = 0;

    printf("Enter numbers to be flipped : ");
    scanf("%d %d", &a, &b);

    int n = a ^ b; // Which gives the different bits alone
    int count = 0;

    while(n) {
        n = n &(n-1);
        count++;
    }

    printf("Total number of bits to flipped = %d\n", count);
}

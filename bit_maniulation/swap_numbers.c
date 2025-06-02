#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 0;
    int b = 0;

    printf("Enter two numbers to swap : ");
    scanf("%d %d", &a, &b);

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    printf(" a = %d, b = %d\n", a, b);
}

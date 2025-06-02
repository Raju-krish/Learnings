#include <stdio.h>


int main(int argc, char *argv[])
{
    volatile int a = 10;
    printf("%d %d %d\n", a++, ++a, a);
}

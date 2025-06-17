#include <stdio.h>

int next_power(int val)
{
    int power = 1;
    while(power < val) 
        power = power * 2;
    return power;
}

int main(int argc, char *argv[])
{
    int val = 0;
    scanf("%d", &val);
    printf("%d is the next power of two\n", next_power(val));
}

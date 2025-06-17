#include <stdio.h>


int calculate_power(int base, int exponent)
{
    int negative = 0;
    float output = 1;
    
    if(exponent < 0) {
        negative = 1;
        exponent = -exponent;
    }
    for(int i = 0; i < exponent; i++) {
        output *= base;
    }
    if(negative == 1)
        output = 1 / output;

    printf("Final value = %f\n", output);
    return output;
}

int main(int argc, char *argv[])
{
    int base = 0;
    int exponent = 0;

    printf("Enter base : ");
    scanf("%d", &base);
    printf("Enter exponent : ");
    scanf("%d", &exponent);

    calculate_power(base, exponent);
}

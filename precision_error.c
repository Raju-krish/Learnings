#include <stdio.h>

int main(int argc, char *argv[])
{
    float a = 0.0;
    for(a = -1.0; a < 1.0; a += 0.2)
        printf("val of a = %f\n", a);
}

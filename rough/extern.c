#include <stdio.h>

extern int my_var;

void print_my_var()
{
    my_var++;
    printf("%s-%d\n", __func__, my_var);
}

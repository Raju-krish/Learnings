#include <stdio.h>
#include <stdlib.h>

int add(int a, int b)
{
    return a+b;
}
int sub(int a, int b)
{
    return a-b;
}
int main(int argc, char *argv[])
{
    int a = atoi(argv[1]);
    int (*func_ptr)(int a, int b);
    if(a == 1)
        func_ptr = &add;
    if(a == 2)
        func_ptr = &sub;

    printf("%d\n",func_ptr(2,3));
}

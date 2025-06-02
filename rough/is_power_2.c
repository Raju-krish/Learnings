#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int val = atoi(argv[1]);
    if((val & (val-1)) == 0)
        printf("Yes its power of two\n");
    else
        printf("NO !! It's not a power of two\n");
}

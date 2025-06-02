
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
    int val = atoi(argv[1]);

    if((val & 1) == 0) 
        printf("Yes even\n");
    else
        printf("It's odd\n");
}

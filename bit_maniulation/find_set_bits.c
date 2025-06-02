#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 0;
    int count = 0;
    printf("enter the number : ");
    scanf("%d", &a);

    while(a) {
        a = a &(a-1);
        count++;
    }
    printf("There are %d set bits\n", count);
}

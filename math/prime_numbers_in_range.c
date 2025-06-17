#include <stdio.h>


int is_prime(int val)
{
    if(val == 1) return 1;
    if(val == 2) return 1;
    if(val%2 == 0) return 0;

    for(int i = 3; i*i < val; i = i+2) {
        if(val % i == 0) return 0;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    int range_start = 0;
    int range_end = 0;

    printf("Enter range start : ");
    scanf("%d", &range_start);
    printf("Enter range Ends : ");
    scanf("%d", &range_end);

    for(int i = range_start; i < range_end; i++) {
        int val = is_prime(i);
        if(val == 1)
            printf(" %d", i);
    }
    printf("\n");
}

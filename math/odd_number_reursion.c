#include <stdio.h>


void print_odd_numbers(int start, int end)
{
    if(start%2 == 0) 
        start += 1;
    for(int i = start; i <= end; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int range_start = 0;
    int range_end = 0;
    printf("Enter start range : ");
    scanf("%d", &range_start);
    printf("Enter end range : ");
    scanf("%d", &range_end);

    print_odd_numbers(range_start, range_end);
}

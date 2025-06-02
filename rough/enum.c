
#include <stdio.h>


typedef enum
{
    sunday = 0,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday
}weekdays;


void print_day_num(int day)
{
    printf("Its %d in a week\n", day);
}

int main()
{
    weekdays monday_1 = 19;
    print_day_num(monday_1);
}

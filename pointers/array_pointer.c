#include <stdio.h>

void pointer()
{
    int arr[3] = {10, 20, 30};
    int *ptr;
    ptr = arr+1;
    printf("%d\n", *ptr);
    *ptr = 40;
    printf("%d\n", *ptr);
}

void pointer_to_array()
{
    int arr[3] = {10, 20, 30};
    int (*ptr)[3] = &arr;

    printf("%d %d %d\n", (*ptr)[0], (*ptr)[1], (*ptr)[2]);

}
int main(int argc, char *argv[])
{
    pointer();
    pointer_to_array();
}

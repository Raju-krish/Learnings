#include <stdio.h>

void func(int *arr)
{
    arr[1] = 10;
}

int main(int argc, char *argv[])
{
    int arr[4] = {2, 3, 4, 5};
    func(arr);
    for(int i = 0; i < 4; i++)
        printf("%d ", arr[i]);
}

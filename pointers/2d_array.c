#include <stdio.h>
#include <stdlib.h>
void func(int (*arr)[3] )
{
    for(int i = 0 ; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
        }
    }
}
void static_array()
{
    int arr[2][3] = {{1,2,3}, {4,5,6}};
    int  (*ptr)[3] = arr;
    func(ptr);
}

void func_dynamic(int **arr)
{
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
        }
    }
}

void dynamic_array()
{
    int **arr;
    arr = malloc(sizeof(int*) *2);
    for(int  i = 0; i < 2; i++) {
        arr[i] = malloc(sizeof(int) * 3);
        for(int j = 0; j < 3; j++) {
            arr[i][j] = i+j;
        }
    }
    func_dynamic(arr);
}
int main(int argc, char *argv[])
{
    static_array();
    dynamic_array();
}

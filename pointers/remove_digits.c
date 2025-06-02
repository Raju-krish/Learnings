#include <stdio.h>
#include <stdlib.h>

int *remove_digits(int  *arr, int digit, int *new_len)
{
    int  *temp = NULL;
    int *res_arr = NULL;
    int res_len = 0;
    for(int i = 0; i < 9; i++) {
        if(arr[i] != digit) {
            res_len++;
            temp = realloc(res_arr, res_len*sizeof(int));
            if(temp == NULL) {
                printf("Realloc failed \n");
                return NULL;
            }
            res_arr = temp;
            res_arr[res_len-1] = arr[i];
        }
    }
    *new_len = res_len;
    return res_arr;
}

int main(int argc, char *argv[])
{
    int arr[9] = {1,3,2,4,5,1,7,8,1};
    int digit = 0;
    int new_len = 0;
    printf("Enter digit to remove\n");
    scanf("%d", &digit);
    int *new_arr = remove_digits(arr, digit, &new_len);
    if(new_arr == NULL) {
        printf("New array is null\n");
    }
    for(int i= 0; i < new_len; i++) {
        printf("%d ", new_arr[i]);
    }
}

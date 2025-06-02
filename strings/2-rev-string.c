#include <stdio.h>
#include <string.h>

void reverse_string(char *arr)
{
    int i = 0, j = strlen(arr)-1;
    for(int  i = 0; i < j; i++,j--) {
        arr[i] = arr[i] ^ arr[j];
        arr[j] = arr[i] ^ arr[j];
        arr[i] = arr[i] ^ arr[j];
    }
}
int main(int argc, char *argv[])
{
    char arr[124];
    printf("Enter a srting to reverse\n");
    scanf("%s", arr);
    reverse_string(arr);
    printf("After reversed : %s\n", arr);

}

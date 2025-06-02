#include <stdio.h>
#include <string.h>
#include <sys/types.h>

__uint8_t check_palindrome(char *arr)
{
    int  i = 0, j = strlen(arr)-1;
    for(int i = 0;  i < j; i++, j--) {
        if(arr[i] != arr[j]) 
            return 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    char buf[124] = {0};
    printf("Enter the string : ");
    scanf("%s", buf);
    printf("%s palindrome\n", (check_palindrome(buf) == 0) ? "Yes It is a" : "No it is not a");
}

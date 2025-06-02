#include <stdio.h>


void my_strcpy(char *dest, char *src)
{
    if(src == NULL || dest == NULL) return;

    while(*src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }
}

int main(int argc, char *argv[])
{
    char arr[] = "Rajagopala swamy";
    char new_arr[24] = {0};

    my_strcpy(new_arr, arr);
    printf("new_arr: %s\n", new_arr);
}

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

===============================================
    #include <stdio.h>

void my_strcpy(char dest[], char src[])
{
    int i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';   // Copy the null character
}

int main()
{
    char src[] = "Hello";
    char dest[20];

    my_strcpy(dest, src);

    printf("Source      : %s\n", src);
    printf("Destination : %s\n", dest);

    return 0;
}

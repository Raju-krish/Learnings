#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    char *ptr = malloc(sizeof(char) * 20);
    strncpy(ptr, "Raja_gopal", 15);
    ptr = realloc(ptr, 30);
    printf("data = %s\n", ptr);
    free(ptr);
    printf("data = %s\n", ptr);
}

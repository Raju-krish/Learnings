#include <stdio.h>
#include <string.h>

int my_strlen(char *name)
{
    if(name == NULL)
        return 0;
    int len = 0;
    name[0] = 'G';
    while(name[len] != '\0' ) 
        len++;

    return len;
}

int main(int argc, char *argv[])
{
    char name[124] = {0};
    printf("Enter string to check : ");
    fgets(name, sizeof(name), stdin );
    printf("my_strlen = %d | strlen = %ld\n", my_strlen(name), strlen(name));
    printf("name : %s\n", name);
}

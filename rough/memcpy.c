#include <stdio.h>
#include <string.h>

int main()
{
    char name[20] = "Rajagopalaswamy";
    char a[20] = {0};
    char b[20] = {0};
    name[5] = '\0';
    strncpy(a, name, 20);
    memcpy(b, name, 20);
    printf("a = %s, b = %s\n",a ,b);
    printf("a-%ld,b=%ld\n", sizeof(a), sizeof(b));
}

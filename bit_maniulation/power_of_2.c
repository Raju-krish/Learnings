#include <stdio.h>

int main(int argc, char *argv[])
{
    int num = 0;
    printf("Enter the number to check : ");
    scanf("%d", &num);
    printf("%s\n", (num & (num-1)) == 0 ? "Yes" : "No");
}

#include <stdio.h>


int main(int argc, char *argv[])
{
    int a = 0;
    int b = 0;

    printf("Enter a and b : ");
    scanf("%d %d", &a, &b);
    if((a^b) < 0) {
        printf("Yess it has opposite sign\n");
    } 
    else {
        printf("Both has same sign");
    }
}

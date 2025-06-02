#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 0;
    int k = 0;
    printf("Enter number : ");
    scanf("%d", &a);
    printf("Enter kth bit to Turn OFF : ");
    scanf("%d", &k);

    /* Turn OFF the Kth k */ 
    // Logic is to use (num) & (~(1 << (k-1)))
    // if num = 12, k = 3
    // num          = 1100 
    // 1 << (k-1)   = 0100 ==> (~)  = 1011
    // which makes &= 1000
    //
    printf("Turn off kth  bit= %d\n", a & (~(1<<(k-1))));

    /* Turn ON Kth k */ 
    printf("Enter kth bit to Turn ON : ");
    scanf("%d", &k);
    printf("Turn on kth bit = %d\n", a | (1 << (k-1)));
    
    /* Check if Kth bit is set */ 
    printf("Enter kth bit to check : ");
    scanf("%d", &k);
    printf("status of kth bit = %s\n", ((a & (1 << (k-1))) > 0) ? "Set" : "Not set");
    
    /* Check if Kth bit is set */ 
    printf("Enter kth bit to Toggle : ");
    scanf("%d", &k);
    printf("After toggle kth bit = %d\n", a ^ (1 << (k-1)));
}

#include <stdio.h>

int main(int argc, char *argv[])
{
    int num = 12345678;
    int new_num = 0;
    int carry = 0;

    while(num) {
        new_num = new_num * 10;
        carry = num % 10;
        num = num / 10;
        new_num = new_num + carry;
    }
    printf("Reversed number : %d\n", new_num);
}

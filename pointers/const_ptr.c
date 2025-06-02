#include <stdio.h>


void constant_pointer()
{
    int a = 10;
    int *const ptr = &a;

    // ptr = &a;  // It throws error, can't assign int data int const*
    printf("ptr=%d\n", *ptr);
    *ptr = 20;
    printf("ptr=%d\n", *ptr);
}

void pointer_to_constant()
{
    int a = 10;
    int const *ptr; // (or) const int *ptr;
   
    ptr = &a;
    // *ptr = 20; // Throwws error read only pointer
    printf("ptr = %d\n", *ptr);

    int *ptr1;
    ptr1 = &a;
    *ptr1 = 20; // It will work because a is not a constant, just the ptr is points to constant data
    printf("ptr1 = %d\n", *ptr1);
}

void constant_pointer_to_pointer()
{
    int a = 10;
    const int *const ptr = &a;
    // *ptr = 20; // Throws error
    // ptr = &a; // Throws error
    printf("%s - ptr = %d\n", __func__, *ptr);
}

int main(int argc, char *argv[])
{
    constant_pointer();
    pointer_to_constant();
    constant_pointer_to_pointer();
}

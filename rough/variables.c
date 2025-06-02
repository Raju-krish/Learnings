
#include <stdio.h>

static int a = 0;
int my_var = 5;
void func()
{
    a++;
    printf("%s-%d\n", __func__,a);
}
void func_test()
{
    a++;
    printf("%s-%d\n", __func__ ,a);
}
int main()
{
    func();
    func_test();
    printf("before - %d\n", my_var);
    print_my_var();
    printf("After - %d\n", my_var);
}

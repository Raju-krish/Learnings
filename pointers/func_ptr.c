#include <stdio.h>

void f1() { printf("f1\n"); }
void f2() { printf("f2\n"); }

int main() {
    void (*funcs[2])() = {f1, f2};
    (*funcs[1])();
    return 0;
}

=====================================
    
#include <stdio.h>

void execute_op(int x, int y, int (*operation)(int, int)) {
    printf("Operation Result: %d\n", operation(x, y));
}

int multiply(int a, int b) { return a * b; }

int main() {
    // Passing the multiply function as an argument
    execute_op(4, 5, multiply);
    return 0;
}

====================================
    #include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int main()
{
    int (*fp)(int, int);   // Function pointer

    fp = add;              // Store function address

    printf("%d\n", fp(10, 20));

    return 0;
}

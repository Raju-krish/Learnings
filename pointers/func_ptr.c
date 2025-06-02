#include <stdio.h>

void f1() { printf("f1\n"); }
void f2() { printf("f2\n"); }

int main() {
    void (*funcs[2])() = {f1, f2};
    (*funcs[1])();
    return 0;
}

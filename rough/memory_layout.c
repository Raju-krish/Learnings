
#include <stdio.h>

int b = 10;
static int c;

int main()
{
    int a = 20;
	int sum = b + a;
	printf("sum-%d, c-%d\n", sum, c);
}

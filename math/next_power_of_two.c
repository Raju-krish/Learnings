#include <stdio.h>

int next_power(int val)
{
    int power = 1;
    while(power < val) 
        power = power * 2;
    return power;
}

int main(int argc, char *argv[])
{
    int val = 0;
    scanf("%d", &val);
    printf("%d is the next power of two from the given Value\n", next_power(val));
}

==========================================================================
power = 1
val = 10

| Iteration | `power` | `power < 10`? | After `power *= 2` |
| --------: | ------: | :-----------: | -----------------: |
|         1 |       1 |      Yes      |                  2 |
|         2 |       2 |      Yes      |                  4 |
|         3 |       4 |      Yes      |                  8 |
|         4 |       8 |      Yes      |                 16 |
|         5 |      16 |       No      |               Stop |

Time complexity = O(log n)
Space complexity = O(1)

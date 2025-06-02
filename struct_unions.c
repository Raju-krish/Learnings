#include <stdio.h>
#include <sys/types.h>

union class
{
    u_int16_t two_byte;
    struct
    {
        u_int8_t second_byte;
        u_int8_t first_byte;
    }parts;
};



int main()
{
    union class c;
    c.two_byte = 1001;
    printf("c.first = %d, c.second = %d\n", c.parts.first_byte, c.parts.second_byte);
}

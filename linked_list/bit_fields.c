#include <stdio.h>

struct subject_status {
    unsigned int maths:1;
    unsigned int tamil:1;
    unsigned int science:1;
    unsigned int english:1;
    unsigned int social:1;
};

int main(int argc, char *argv[])
{
    struct subject_status s;
    s.maths = 1;
    s.tamil = 1;
    s.science = 0;
    s.english = 1;
    s.social = 0;
    printf("%d\n", s.maths);
    printf("%u\n", s.tamil);
    printf("%u\n", s.science);
    printf("%u\n", s.english);
    printf("%u\n", s.social);
    printf("%ld\n", sizeof(s));
    return 0;
}

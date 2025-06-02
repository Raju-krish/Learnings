#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handler_func()
{
    printf("Hey you pressed ctrl+c\n");
}
int main(int argc, char *argv[])
{
    signal(SIGINT, handler_func);
    while(1) {
        sleep(1);
        printf("I'm still running\n");
    }
}

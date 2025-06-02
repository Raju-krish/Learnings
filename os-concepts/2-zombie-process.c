#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char *argv[])
{
    while(1) {
        if(fork() == 0) {
            printf("Hi I'm chuld and I'm done..\n");
            sleep(10);
            return 0;
        } else {
            // wait(NULL); // This prevents the child becoming zombie, it check the status of child and update to os
            printf("Hi This is parent\n");
            sleep(5);
        }
    }
}

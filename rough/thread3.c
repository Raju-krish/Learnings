#include "thread.h"
#include <stdio.h>
#include <unistd.h>
void* connect_thread(void* arg)
{
    int i = 0;
    while(1)
    {
        printf("Hello im %d\n", i++);
        sleep(1);
    }
}

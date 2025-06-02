#include <stdio.h>
#include <pthread.h>
#include "thread.h"
#include <unistd.h>

pthread_t thread = 0;

void create_thread()
{
    if(pthread_create(&thread, NULL, connect_thread, NULL) != 0)
    {
        printf("Failed to create thread\n");
    }

}

int main(int argc, char *argv[])
{

    create_thread();
    printf("pthread created %p\n", (void*)thread);
    
    sleep(5);
    pthread_cancel(thread);
    printf("Thread is cancelled %p\n", (void*)thread);
    if(pthread_detach(thread) == 0)
        printf("Thread is detached %p\n", (void*)thread);
    printf("Thread is detached %p\n", (void*)thread);
    
    create_thread();
    printf("pthread created %p\n", (void*)thread);
    
    sleep(5);
    pthread_cancel(thread);
    sleep(10);
}

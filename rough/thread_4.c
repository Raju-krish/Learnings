#include <stdio.h>
#include <threads.h>
#include <pthread.h>
#include <unistd.h>
void *check_background(void *arg)
{
    printf("Hey I'm thread func\n");
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t th_id;
    pthread_create( &th_id, NULL, check_background, NULL);
    pthread_detach(th_id);

    printf("Hey i'm main func\n");
    sleep(1);
    printf("Hey i'm main func at end\n");
}

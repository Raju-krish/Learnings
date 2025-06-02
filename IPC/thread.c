#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t mutex;

void *print_func(void *arg)
{
    pthread_mutex_lock(&mutex);
    printf("This is thread %d\n", *(int*)arg);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t th[4];
    pthread_mutex_init(&mutex, 0);
    for(int  i =0 ; i < 4; i++) {
        int *data = malloc(sizeof(int));
        *data = i;
        pthread_create(&th[i], NULL, print_func, data);
    }
    for(int  i =0 ; i < 4; i++) {
        pthread_join(th[i], 0);
    }
    pthread_mutex_destroy(&mutex);
}

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

volatile int a;
pthread_mutex_t mutex;
sem_t sem;

void* func_odd() {
    for(int i = 0; i < 50000; i++) {
        // pthread_mutex_lock(&mutex);
        // sem_wait(&sem);
        a = a + i;
        // sem_post(&sem);
        // pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void* func_even() {
    for(int i = 50000; i < 100000; i++) {
        // pthread_mutex_lock(&mutex);
        // sem_wait(&sem);
        a = a + i;
        // sem_post(&sem);
        // pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t th[2];
    // pthread_mutex_init(&mutex, 0);
    // sem_init(&sem, 0, 1);
 
    pthread_create(&th[0], NULL, func_even, NULL);
    pthread_create(&th[1], NULL, func_odd, NULL);

    pthread_join(th[0], NULL);
    pthread_join(th[1], NULL);
    
    printf("Number = %d\n", a);
    a  =0;

    for(int i = 0; i < 100000; i++) {
        a = a + i;
    }
    printf("Number = %d\n", a);
    // pthread_mutex_destroy(&mutex);
    // sem_destroy(&sem);
}

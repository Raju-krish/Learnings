#include <pthread.h>
#include <stdio.h>
#include <threads.h>
#include <semaphore.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex;
sem_t sem;
void* routine1(void *arg)
{
    pthread_mutex_lock(&mutex);
    printf("Before sleep Hey i'm Routine1 \n");
    sleep(1);
    printf("After sleep Hey i'm Routine1 \n");
    pthread_mutex_unlock(&mutex);
    free(arg);
    return NULL;
}
void* routine2(void *arg)
{
    sem_wait(&sem);
    printf("Before sleep Hey i'm Routine2 \n");
    sleep(1);
    printf("After sleep Hey i'm Routine2 \n");
    sem_post(&sem);
    free(arg);
    return NULL;
}
int main()
{
    pthread_t threads[5];

    pthread_mutex_init(&mutex, NULL);
    sem_init(&sem, 0, 4);

    for(long i = 0;  i<5; i++)
    {
       // pthread_create(&threads[i], NULL, &routine1, NULL);
         pthread_create(&threads[i], NULL, &routine2, NULL);
    }
    
    for(int i = 0;  i<5; i++)
    {
        pthread_join(threads[i],NULL);
    }
     pthread_mutex_destroy(&mutex);
    return 0;
}

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;

void *worker(void *arg)
{
    int id = *(int *)arg;

    printf("Thread %d waiting for semaphore\n", id);

    sem_wait(&sem);

    printf("Thread %d entered critical section\n", id);

    sleep(2);

    printf("Thread %d leaving critical section\n", id);

    sem_post(&sem);

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    int id1 = 1;
    int id2 = 2;

    // Initial value = 1
    sem_init(&sem, 0, 1);

    pthread_create(&t1, NULL, worker, &id1);
    pthread_create(&t2, NULL, worker, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&sem);

    return 0;
}

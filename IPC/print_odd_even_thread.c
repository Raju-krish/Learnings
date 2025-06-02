#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
void *print_odd(void *arg)
{
    int num = *(int*)arg;
    for(int i = 1; i< num; i=i+2 ) {
    pthread_mutex_lock(&mutex);
        printf("%d ", i);
    pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *print_even(void *arg)
{
    int num = *(int*)arg;
    for(int i = 0; i< num; i=i+2 ) {
    pthread_mutex_lock(&mutex);
        printf("%d ", i);
    pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t th_odd;
    pthread_t th_even;
    pthread_mutex_init(&mutex, NULL);
    int num = 0;
    printf("enter upto which num to print : ");
    scanf("%d", &num);
    pthread_create(&th_odd, NULL, print_odd, (void*)&num);
    pthread_create(&th_even, NULL, print_even, (void*)&num);
    pthread_join(th_odd, NULL);
    pthread_join(th_even, NULL);
    pthread_mutex_destroy(&mutex);
}

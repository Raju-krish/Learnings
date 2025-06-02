/******************************************************************************
  * @file      :  
  * @brief     :  
  * @Author    : M Rajagopalaswamy (m.rajagopalaswamy@vvdntech.in)
  * @Copyright : (c) 2021 , VVDN Technologies Pvt. Ltd.
  *              Permission is hereby granted to everyone in VVDN Technologies
  *              to use the Software without restriction, including without
  *              limitation the rights to use, copy, modify, merge, publish,
  *              distribute, distribute with modifications.
  ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;

void* routine(void *arg) {
    pthread_mutex_lock(&mutex);
    // Correctly cast arg back to int
    printf("Hey, I'm thread %d\n", *(volatile int*)arg);
    pthread_mutex_unlock(&mutex);
    free(arg);  // Free the allocated memory
    return NULL;
}

int main() {
    pthread_t threads[5];

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < 5; i++) {
        int *arg = malloc(sizeof(int));  // Allocate memory for the argument
        if (arg == NULL) {
            perror("Failed to allocate memory");
            exit(1);
        }
        *arg = i;  // Store the thread number
        if (pthread_create(&threads[i], NULL, &routine, arg) != 0) {
            perror("Failed to create thread");
            free(arg);  // Free memory if thread creation fails
            exit(1);
        }
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}


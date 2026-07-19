#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/stat.h>
#include <semaphore.h>

typedef struct
{
    int counter;
} SharedData;

int main()
{
    int fd = shm_open("/my_shm", O_RDWR, 0666);

    SharedData *data = mmap(NULL,
                            sizeof(SharedData),
                            PROT_READ | PROT_WRITE,
                            MAP_SHARED,
                            fd,
                            0);

    sem_t *sem = sem_open("/my_sem", 0);

    while (1)
    {
        sem_wait(sem);

        printf("Consumer reads : %d\n", data->counter);

        sem_post(sem);

        sleep(1);
    }
}

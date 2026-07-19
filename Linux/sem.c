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
    int fd = shm_open("/my_shm", O_CREAT | O_RDWR, 0666);

    ftruncate(fd, sizeof(SharedData));

    SharedData *data = mmap(NULL,
                            sizeof(SharedData),
                            PROT_READ | PROT_WRITE,
                            MAP_SHARED,
                            fd,
                            0);

    sem_t *sem = sem_open("/my_sem", O_CREAT, 0666, 1);

    data->counter = 0;

    while (1)
    {
        sem_wait(sem);

        data->counter++;

        printf("Producer : %d\n", data->counter);

        sem_post(sem);

        sleep(1);
    }
}

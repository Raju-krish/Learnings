#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = 0;
int rear = -1;

void enqueue(int value)
{
    if (rear == SIZE - 1)
    {
        printf("Queue Full\n");
        return;
    }

    queue[++rear] = value;
}

int dequeue()
{
    if (front > rear)
    {
        printf("Queue Empty\n");
        return -1;
    }

    return queue[front++];
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Removed: %d\n", dequeue());
    printf("Removed: %d\n", dequeue());

    return 0;
}

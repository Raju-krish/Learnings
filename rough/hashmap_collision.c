#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int key;
    int value;
    struct Node *next;
};

struct Node *hashmap[SIZE];

/* Hash function */
int hash(int key)
{
    return key % SIZE;
}

/* Insert key/value */
void insert(int key, int value)
{
    int index = hash(key);

    struct Node *new_node = malloc(sizeof(struct Node));

    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    new_node->key = key;
    new_node->value = value;

    /* Add to beginning of linked list */
    new_node->next = hashmap[index];
    hashmap[index] = new_node;
}

/* Search for a key */
int get(int key, int *value)
{
    int index = hash(key);

    struct Node *temp = hashmap[index];

    while (temp != NULL) {
        if (temp->key == key) {
            *value = temp->value;
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

/* Display hashmap */
void display()
{
    int i;

    for (i = 0; i < SIZE; i++) {
        struct Node *temp = hashmap[i];

        printf("Bucket %d: ", i);

        while (temp != NULL) {
            printf("[%d -> %d] ", temp->key, temp->value);
            temp = temp->next;
        }

        printf("\n");
    }
}

/* Free hashmap */
void free_hashmap()
{
    int i;

    for (i = 0; i < SIZE; i++) {
        struct Node *temp = hashmap[i];

        while (temp != NULL) {
            struct Node *next = temp->next;
            free(temp);
            temp = next;
        }

        hashmap[i] = NULL;
    }
}

int main()
{
    int value;

    insert(10, 100);
    insert(20, 200);
    insert(30, 300);
    insert(15, 150);
    insert(25, 250);

    display();

    printf("\n");

    if (get(20, &value))
        printf("Key 20 -> Value %d\n", value);
    else
        printf("Key 20 not found\n");

    if (get(25, &value))
        printf("Key 25 -> Value %d\n", value);
    else
        printf("Key 25 not found\n");

    if (get(50, &value))
        printf("Key 50 -> Value %d\n", value);
    else
        printf("Key 50 not found\n");

    free_hashmap();

    return 0;
}

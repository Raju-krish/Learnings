#include <stdio.h>

#define SIZE 10

struct Entry {
    int key;
    int value;
    int used;
};

struct Entry hashmap[SIZE];

/* Simple hash function */
int hash(int key)
{
    return key % SIZE;
}

/* Insert key/value */
void insert(int key, int value)
{
    int index = hash(key);

    hashmap[index].key = key;
    hashmap[index].value = value;
    hashmap[index].used = 1;
}

/* Search for a key */
int get(int key, int *value)
{
    int index = hash(key);

    if (hashmap[index].used &&
        hashmap[index].key == key) {

        *value = hashmap[index].value;
        return 1;
    }

    return 0;
}

int main()
{
    int value;

    insert(10, 100);
    insert(20, 200);
    insert(30, 300);

    if (get(20, &value))
        printf("Key 20 -> Value %d\n", value);
    else
        printf("Key 20 not found\n");

    if (get(50, &value))
        printf("Key 50 -> Value %d\n", value);
    else
        printf("Key 50 not found\n");

    return 0;
}

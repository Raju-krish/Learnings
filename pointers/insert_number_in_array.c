#include <stdio.h>

int main()
{
    int arr[100] = {10, 20, 30, 40, 50};
    int size = 5;
    int pos, value;

    printf("Enter position (0 to %d): ", size);
    scanf("%d", &pos);

    printf("Enter value to insert: ");
    scanf("%d", &value);

    // Shift elements to the right
    for (int i = size; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    // Insert the new value
    arr[pos] = value;
    size++;

    printf("Array after insertion:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}

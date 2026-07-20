#include <stdio.h>

int main()
{
    int arr[100] = {10, 20, 30, 40, 50};
    int size = 5;
    int pos;

    printf("Enter the position to delete (0 to %d): ", size - 1);
    scanf("%d", &pos);

    // Check for valid position
    if (pos < 0 || pos >= size)
    {
        printf("Invalid position!\n");
        return 0;
    }

    // Shift elements to the left
    for (int i = pos; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    size--;

    printf("Array after deletion:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}

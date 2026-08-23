#include <stdio.h>
#include <stdlib.h>

/* It's teh recursive approach */

Method 1
--------

void merge(int arr[], int low, int mid, int high)
{
    int temp[100];
    int i = low;
    int j = mid + 1;
    int k = 0;

    // Compare elements from both halves
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // Copy remaining elements from left half
    while (i <= mid)
        temp[k++] = arr[i++];

    // Copy remaining elements from right half
    while (j <= high)
        temp[k++] = arr[j++];

    // Copy back to original array
    for (i = low, k = 0; i <= high; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    // Divide
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    // Merge
    merge(arr, low, mid, high);
}

int main()
{
    int arr[] = {5, 8, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

==============================================================================================
Method 2:
----------
void merge(int **arr, int low, int mid, int high)
{
    int *temp = malloc(sizeof(int)*(high-low)+1);
    int left = low;
    int right = mid+1;
    int idx = 0;
    
    /* Merge two hypothetical arrays into a new array */
    while(left <= mid && right <= high) {
        if((*arr)[left] <= (*arr)[right]) {
            temp[idx] = (*arr)[left];
            left++;
        }
        else {
            temp[idx] = (*arr)[right];
            right++;
        }
        idx++;
    }
    /* If left array exhausted copy all the values of right array */
    if(left >= mid) {
        while(right <= high) {
            temp[idx] = (*arr)[right];
            right++;
            idx++;
        }
    }
    /* If right array exhausted copy all the values of left array */
    if(right >= high) {
        while(left <= mid) {
            temp[idx] = (*arr)[left];
            left++;
            idx++;
        }
    }

    /* Now temp arr has sorted data
     * Copy the temp arr to original array */

    for(int i = low; i <= high; i++) {
        (*arr)[i] = temp[i-low];
    }
    free(temp);
}

void merge_sort(int **arr, int low, int high)
{
    if(low >= high) return;

    int mid = (low+high)/2;
    
    /* Sort the left half */
    merge_sort(arr, low, mid);

    /* Sort the right half */
    merge_sort(arr, mid+1, high);

    /* Merge the complete left and right half */
    merge(arr, low, mid, high);
}

void print_sorted_list(int **arr, int size) {
    printf("Sorted list : ");
    for(int i =0 ; i < size; i++) {
        printf("%d ", (*arr)[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int size = 0;
    int *arr = NULL;

    printf("Enetr the size of array : ");
    scanf("%d", &size);

    arr = malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    merge_sort(&arr, 0, size-1);
    print_sorted_list(&arr, size);
    free(arr);
}

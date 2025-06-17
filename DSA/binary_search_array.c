#include <stdio.h>
#include <stdlib.h>

/* Recusrsive binary_search */
int recursive_binary_search(int *arr, int target, int low, int high)
{
    int mid = (low+high)/2;

    if(arr[mid] == target) return mid;
    if(arr[mid] > target)
        return recursive_binary_search(arr, target, low, mid-1);
    else if(arr[mid] < target)
        return recursive_binary_search(arr, target, mid+1, high);
    else 
        return -1;
}

/* Iterative binary_search */
int iterative_binary_search(int *arr, int target, int low, int high)
{
    int mid = 0;
    int ans = 0;
    while(arr[ans] != target) {
    
        if(low > high) break;

        mid = (low+high)/2;
        
        /* If mid matches return it */
        if(arr[mid] == target) {
            ans = mid;
            break;
        }
        /* If mid is less than taret value, ignore left half */
        else if(arr[mid] < target) {
            low = mid + 1;
        }
        /* If mid is greater than taret value, ignore right half */
        else if(arr[mid] > target) {
            high = mid - 1;
        }
    }
    return ans;
}

int main(int argc, char *argv[])
{
    int size = 0;
    int target = 0;
    int  *arr = NULL;

    printf("Enter the size of array :");
    scanf("%d", &size);
    arr = malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to search : ");
    scanf("%d", &target);
    
    printf("[Iterative] The number %d is at index arr[%d]\n", target, iterative_binary_search(arr, target, 0, size-1));
    printf("[Recusrsive] The number %d is at index arr[%d]\n", target, recursive_binary_search(arr, target, 0, size-1));
    free(arr);
}

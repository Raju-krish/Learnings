#include <stdio.h>

/* This find the square root of a given number using binary search */

int binary_search(int low, int high, int target)
{
    if(low > high) return high;
    int mid = (low+high)/2;

    if((mid *mid) == target) 
        return mid;
    else if ((mid*mid) < target)
        return binary_search(mid+1, high, target);
    else if ((mid*mid) > target)
        return binary_search(low, mid-1, target);

    return -1;
}

int main(int argc, char *argv[])
{
    int num;
    printf("Enter the number to find its square root : ");
    scanf("%d", &num);

    int ret = binary_search(0, num/2, num);
    printf("Answer  is : %d\n", ret);
}

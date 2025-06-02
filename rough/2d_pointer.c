#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **arr = malloc(4*sizeof(char*));
    
    arr[0] = malloc(10*sizeof(char));
    strcpy(arr[0],"Raja");
    arr[1] = malloc(10*sizeof(char));
    strcpy(arr[1],"gopala");
    arr[2] = malloc(10*sizeof(char));
    strcpy(arr[2],"swamy");
    arr[3] = malloc(10*sizeof(char));
    strcpy(arr[3],"and co");
    printf("%s %s %s %s", arr[0], arr[1], arr[2], arr[3]);
 
    free(arr[0]);
    free(arr[2]);
    free(arr[1]);
    free(arr[3]);
    free(arr);
}

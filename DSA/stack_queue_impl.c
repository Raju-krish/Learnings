#include <stdio.h>
#include <stdlib.h>

#define STACK 1
#define QUEUE 2

typedef void (*func_ptr)();
int stack_size  = 0;
int *stack = NULL;
int type = 0;

void push()
{
    stack_size++;
    int *realloc_ptr = realloc(stack, sizeof(int)*stack_size);
    
    if(realloc_ptr == NULL)
        exit(-1);

    stack = realloc_ptr;
    printf("Enter the number to push\n");
    scanf("%d", &stack[stack_size-1]);
}

void pop()
{
    if(type == QUEUE) {
        int *temp = malloc(sizeof(int)*stack_size-1);
        for(int  i = 0 ; i <stack_size-1; i++) {
            temp[i] = stack[i+1];
        }
        stack_size--;
        free(stack);
        stack = temp;
    }
    else if (type == STACK) {
        stack_size--;
        int *realloc_ptr = realloc(stack, sizeof(int)*stack_size);
        if(realloc_ptr == NULL)
            exit(-1);
        stack = realloc_ptr;
    }
}

void print()
{
    for(int  i = 0; i < stack_size; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void free_exit()
{
    free(stack);
    exit(0);
}

int main(int argc, char *argv[])
{
    int choice;
    func_ptr func[4] = {push, pop, print, free_exit};
    
    printf("Decide the datastructre : \n 1)stack or 2)queue\n");
    scanf("%d", &type);

    while(1) {
        printf("Enter the choice :  1) Push 2)Pop 3)Print 4)Exit\n");
        scanf("%d", &choice);
        func[choice-1]();
    }
}

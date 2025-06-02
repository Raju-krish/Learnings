#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
    int val;
    struct List *prev;
    struct List *next;

}List_t;

List_t* create_node(int data)
{
    List_t *temp = malloc(sizeof(List_t));
    if(temp)
    {
        temp->val = data;
        temp->next = NULL;
        temp->prev = NULL;
    }
    return temp;
}

void add_node(int data, List_t **head)
{
    List_t *temp = create_node(data);

    if(!temp)
        return;

    if(*head == NULL)
        *head = temp;
    else
    {
        List_t *ptr = *head;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
    }
}

void print_node(List_t *head)
{
    List_t *ptr = head;
    u_int8_t i = 0;
    while(ptr != NULL)
    {
        i++;
        printf("==Node %d==\n", i);
        printf("-----------------------\n");
        printf("|  %d   |  %d  |  %d   |\n",  \
               (ptr->prev != NULL) ? ptr->prev->val : 0,
               ptr->val,
               (ptr->next != NULL) ? ptr->next->val : 0 );
        printf("-----------------------\n");
        // if(ptr->prev != NULL)
        //     printf("prev_val = %d\n", ptr->prev->val);
        // if(ptr->next != NULL)
        //     printf("next_val = %d\n", ptr->next->val);
        // printf("cur = %d\n", ptr->val);
        ptr = ptr->next;
    }
}

int main()
{
    int size = 0;
    List_t *head = NULL;
    int i = 0;

    printf("Enter no of nodes to create\n");
    scanf("%d", &size);

    while(i != size)
    {
        add_node(i, &head);
        i++;
    }

    print_node(head);
    add_node(10, &head);
    print_node(head);

}

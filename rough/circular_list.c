#include <stdio.h>
#include <stdlib.h>

typedef struct List 
{
    int val;
    struct List *next;
} List;

List*  create_node(int data)
{
    List *temp = malloc(sizeof(List));
    temp->val = data;
    temp->next = NULL;
    return temp;
}

void add_node(List **head, int data)
{
    List *temp = create_node(data);
    if( *head == NULL)
        *head = temp;
    else{
        List *ptr = *head;
        temp->next = *head;
        while(ptr->next != NULL && ptr->next != *head)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

void print_node(List **head)
{
    List *temp = *head;
    u_int8_t i = 0;
    printf("=======Printing nodes=======\n");
    while(temp->next != *head)
    {
        i++;
        printf("node - %d\n", i);
        printf("val = %d\n", temp->val);
        temp = temp->next;
    }
    i++;
    printf("node - %d\n", i);
    printf("val = %d\n", temp->val);
}

void del_node (List **head, int data)
{
    List *temp = *head;
    List *prev = NULL;
    do
    {
        if(temp->val == data)
        {
            if(temp == *head || prev == NULL)
            {
                printf("Ohh no culprit is head\n");
                List *ptr = *head;
                while(ptr->next != *head)
                    ptr = ptr->next;
                ptr->next = temp->next;
                *head = temp->next;
            }
            if(prev != NULL)
            {
                prev->next = temp->next;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }while(temp->next != *head);
}
int main(int argc, char *argv[])
{
    List *head = NULL;

    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    print_node(&head);
    del_node(&head, 1);
    print_node(&head);
}

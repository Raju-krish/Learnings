#include <endian.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct  List
{
    int val;
    struct List *next;
} List;


List* create_node(int data)
{
    List *node = (List*)malloc(sizeof(List));
    printf("%s - %d\n", __func__, data);
    if(node != NULL)
    {
        node->val = data;
        node->next = NULL;
    }
    return node;
}

void print_nodes(List *head)
{
    List *temp = head;
    int idx = 0;
    {
        while(temp != NULL)
        {
            printf("\n Node-%d\n", idx);
            printf("val = %d\n", temp->val);
            printf("---------------\n");
            idx++;
            temp = temp->next;
        }
    }
}

void del_node(int data, List **head)
{
    List *temp = *head;
    List *prev = NULL;

    while(temp != NULL)
    {
        if(temp->val == data)
        {
            printf("Found the node\n");
            if(temp == *head)
            {
                printf("Ohh, head needs to be deleted, changing head\n");
                *head = temp->next;
            }else
            {
                prev->next = temp->next;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return;
}

void add_node(int data, List **head)
{
    List *temp = create_node(data);
    if (temp)
    {
        if(*head == NULL)
            *head = temp;
        else
        {
            List *ptr = *head;
            while(ptr->next != NULL)
            {
                ptr=ptr->next;
            }
            ptr->next = temp;
        }
    }
}

void free_nodes(List *head)
{
    List *temp = head;
    List *cur = head;
    while(temp != NULL)
    {
        cur = temp;
        temp = cur->next;
        free(cur);
    }
}
int main()
{

    List *head = NULL;
    int size = 0;
    int a = 0;
    printf("Enter the size of entry\n");
    scanf("%d", &size);

    if(size == 0)
    {
        printf("Size is not valid\n");
        return 0;
    }
 
    int i = size;
    while(i != 0)
    {
        a += 1;
        add_node(a, &head);
        i--;
    }

    print_nodes(head);

    del_node(1, &head);

    // add_node(8, &head);
    print_nodes(head);
    print_nodes(head);

    free_nodes(head);
}

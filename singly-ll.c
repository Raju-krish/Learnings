#include <stdio.h>
#include <stdlib.h>

typedef struct student_details {
    int id;
    char name[20];
    struct student_details *next;
} student_details_t;


void create_ll(int size, student_details_t **head)
{
    student_details_t *ptr = NULL, *curr = NULL;
    int  i = 0;
    while(i != size)
    {
        ptr = (student_details_t *)malloc(sizeof(student_details_t));
        printf("Enter %d)student id : ", i);
        scanf("%d", &ptr->id);
        printf("Enter %d)student name : ", i);
        scanf("%s", ptr->name);
        ptr->next = NULL;
        if (*head != NULL) {
            curr->next = ptr;
        } 
        else {
            *head = ptr;
        }
        curr = ptr;
        i++;
    };

}

void print_ll(student_details_t **head)
{
    student_details_t *ptr = NULL;
    ptr = *head;
    int i = 1;

    while(ptr != NULL)
    {
        printf("student %d:\n", i);
        printf("\t\t id\t: %d\n", ptr->id);
        printf("\t\t name\t: %s\n", ptr->name);
        ptr = ptr->next;
    }
}

void print_specific_node_ll(student_details_t *ptr)
{
    if(ptr != NULL)
    {
        printf("stdident id\t= %d\n", ptr->id);
        printf("stdident name\t= %s\n", ptr->name);
    }
}
void search_ll(student_details_t **head)
{
    student_details_t *ptr = *head;
    int id_to_find = -1, found = 0;

    printf("Enter the student id : ");
    scanf("%d", &id_to_find);
    if(id_to_find < 0)
    {
        printf("Its not a valid student id : %d\n", id_to_find);
        return;
    }

    while(ptr != NULL)
    {
        if(ptr->id == id_to_find)
        {
            print_specific_node_ll(ptr);
            found = 1;
            break;
        }
        ptr = ptr->next;
    }
    if(found == 0) {
        printf("Unable to find the id(%d) in database\n", id_to_find);
    }
}


void insert_in_order(student_details_t **head, student_details_t *entry)
{
    student_details_t  *ptr = *head, *prev = NULL;

    while(ptr != NULL) {
        if(ptr->id > entry->id) {
            if(prev == NULL) {
                entry->next = ptr;
                *head = entry;
            }
            else {
                prev->next = entry;
                prev->next->next = ptr;
            }
            printf("Student id : %d is inserted\n", entry->id);
            break;
        }
        prev = ptr;
        ptr = ptr->next;
    }
}
void insert_ll(student_details_t **head)
{
    student_details_t *ptr = *head;
    int num_entry = 0;
    int i = 0;

    student_details_t *entry = NULL;
    printf("Enter no.of student entries want to add : ");
    scanf("%d", &num_entry);
    if(num_entry == 0)
    {
        printf("Number of entries to insertdis zero, hence exit\n");
        return;
    }
    while(i != num_entry)
    {
        entry = malloc(sizeof(student_details_t));

        printf("Enter student id\t: ");
        scanf("%d", &entry->id);
        printf("Enter student name\t: ");
        scanf("%s", entry->name);
        insert_in_order(head, entry);
        i++;
    }
}

void delete_entry_ll(student_details_t **head, int id)
{
    student_details_t *ptr = *head, *prev = NULL;

    while(ptr != NULL) {
        if(ptr->id == id) {
            if(prev == NULL) {
                *head = ptr->next;
                free(ptr);
            }
            else {
                prev->next = ptr->next;
                free(ptr);
            }
            printf("Student id %d is deleted\n", id);
            break;
        }
        prev = ptr;
        ptr = ptr->next;
    }
}
void delete_ll(student_details_t **head)
{
    int num_entry = 0;
    int i = 0, id = -1;
    printf("Enter no.of student entries to delete : ");
    scanf("%d", &num_entry);
    if(num_entry == 0)
    {
        printf("Number of entries to insertdis zero, hence exit\n");
        return;
    }

    while(i != num_entry)
    {
        printf("Enter student id to delete : ");
        scanf("%d", &id);
        delete_entry_ll(head, id);
        i++;
    }

}

int main(int argc, char**argv)
{
    int size = 0, i =0, option = 0;
    student_details_t  *stud = NULL, *head = NULL, *ptr = NULL, *curr;
    while(1) {
        printf("Enter the options:\n");
        printf("\t1) Create Database\n");
        printf("\t2) Insert a student detail\n");
        printf("\t3) Delete a student detail\n");
        printf("\t4) Search a student detail\n");
        printf("\t5) Print all student details in database\n");
        scanf ("%d", &option);
        switch(option) {
            case 1:
                printf("Enter the size of list : ");
                scanf("%d", &size);
                create_ll(size, &head);
                break;
            case 2:
                insert_ll(&head);
                break;
            case 3:
                delete_ll(&head);
                break;
            case 4:
                search_ll(&head);
                break;
            case 5:
                print_ll(&head);
                break;
        }
    }

}

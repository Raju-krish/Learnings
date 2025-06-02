#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct movie_details{
    char movie_name[24];
    char time[8];
    int price;
    struct movie_details *next;
};

void create_database(struct movie_details **head)
{
    struct movie_details *temp = NULL, *prev = NULL;
    int input = 0;

    printf("Enter no of entries to create\n");
    if (scanf("%d", &input) != 1) {
        int ch;
        printf("Invalid input. Please enter an integer.\n");
        while ((ch = getchar()) != '\n' && ch != EOF);
    }
    if(input == 0) return;

    while(input--) {
        temp = (struct movie_details*) malloc(sizeof(struct movie_details));
        printf("Enter movie name: ");
        scanf("%s", temp->movie_name);
        printf("Enter show time: ");
        scanf("%s", temp->time);
        printf("Enter ticket price: ");
        scanf("%d", &temp->price);
        printf("\n");
        temp->next = NULL;
        if(*head == NULL) {
            *head = temp;
        } else {
            prev->next = temp;
        }
        prev = temp;
        temp = temp->next;
    }
}

void read_database(struct movie_details **head) 
{
    struct movie_details *temp = NULL;
    u_int8_t idx = 1;
    temp = *head;

    while(temp != NULL) {
        printf("%d)movie name\t: %s\n",idx,  temp->movie_name);
        printf("%d)show time\t: %s\n", idx, temp->time);
        printf("%d)Ticket price\t: %d\n", idx, temp->price);
        printf("\n");
        idx++;
        temp = temp->next;
    }
}

void update_database(struct movie_details **head) 
{
    char movie_to_update[24] = {0};
    struct movie_details *temp = NULL;
    printf("Enter movie name to Update\n");
    scanf("%s", movie_to_update);

    temp = *head;
    while(temp != NULL) {
        if(strncmp(temp->movie_name, movie_to_update, sizeof(temp->movie_name)) != 0) {
            temp = temp->next;
            continue;
        }
        printf("New show time\n");
        scanf("%s", temp->time);
        printf("New ticket price\n");
        scanf("%d", &temp->price);
        break;
    }

}
void delete_database(struct movie_details **head) 
{
    char movie_to_delete[24] = {0};
    struct movie_details *temp = NULL, *prev = NULL;
    printf("Enter movie name to Delete\n");
    scanf("%s", movie_to_delete);

    temp = *head;
    while(temp != NULL) {
        if(strncmp(temp->movie_name, movie_to_delete, sizeof(temp->movie_name)) != 0) {
            prev = temp;
            temp = temp->next;
            continue;
        }
        if(temp == *head) {
            *head = (*head)->next;
        }
        else {
            prev->next = temp->next;
        }
        free(temp);
        break;
    }
}

void clean_exit(struct movie_details **head)
{
    struct movie_details *temp = *head, *next = NULL;
    while(temp != NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    exit(0);
}

int main(int argc, char *argv[])
{
    struct movie_details *head = NULL;
    int operation = 0;
    void (*func_ptr[5])(struct movie_details **head) = {create_database, read_database, update_database, delete_database, clean_exit};

    while(1) {
        printf("Operation to perform\n");
        printf("1. Create database\n");
        printf("2. Read database\n");
        printf("3. Update database\n");
        printf("4. Delete database\n");
        printf("5. Exit \n");
        scanf("%d", &operation);
        func_ptr[operation-1](&head);
    }
}

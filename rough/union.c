#include <stdio.h>

typedef union user_data
{
    char name[20];
    int id;
    char area[30];
    int pincode;
} user_data_t;

void show_user_data(user_data_t user, int type)
{
    if(type == 0)
        printf("My name is %s\n", user.name);
    if(type == 1)
        printf("My id is %d\n", user.id);
    if(type == 2)
        printf("My area is %s\n", user.area);
    if(type == 3)
        printf("My pincode is %d\n", user.pincode);
}

int main(int argc, char *argv[])
{
    user_data_t user;
    printf("Enter you name : ");
    scanf("%s", user.name);
    show_user_data(user, 0);
    
    printf("Enter you id : ");
    scanf("%d", &user.id);
    show_user_data(user, 1);
    
    printf("Enter you are : ");
    scanf("%s", user.area);
    show_user_data(user, 2);
    
    printf("Enter you pincode : ");
    scanf("%d", &user.pincode);
    show_user_data(user, 3);
    printf("size of user = %ld\n", sizeof(user));
}

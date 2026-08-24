#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* ---------------------------------------------------
   1. Create a new node
   --------------------------------------------------- */
Node *createNode(int data)
{
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

/* ---------------------------------------------------
   2. Add node at the FRONT
   --------------------------------------------------- */
void addFront(Node **head, int data)
{
    Node *newNode = createNode(data);

    newNode->next = *head;
    *head = newNode;
}

/* ---------------------------------------------------
   3. Add node at the END
   --------------------------------------------------- */
void addEnd(Node **head, int data)
{
    Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *current = *head;

    while (current->next != NULL)
        current = current->next;

    current->next = newNode;
}

/* ---------------------------------------------------
   4. Print the list
   --------------------------------------------------- */
void printList(Node *head)
{
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

/* ---------------------------------------------------
   5. Find Middle
      Pattern: Fast & Slow Pointer

      slow moves 1 step
      fast moves 2 steps

      When fast reaches the end,
      slow is at the middle.
   --------------------------------------------------- */
Node *findMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

/* ---------------------------------------------------
   6. Detect Loop
      Pattern: Fast & Slow Pointer

      If slow and fast meet, there is a loop.
   --------------------------------------------------- */
int detectLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return 1;
    }

    return 0;
}

/* ---------------------------------------------------
   7. Nth Node From End
      Pattern: Two Pointers

      Move fast N steps ahead.
      Then move slow and fast together.

      When fast reaches NULL,
      slow is at Nth node from end.
   --------------------------------------------------- */
Node *nthFromEnd(Node *head, int n)
{
    Node *slow = head;
    Node *fast = head;

    /* Move fast N steps */
    for (int i = 0; i < n; i++) {

        if (fast == NULL)
            return NULL;    // n > list length

        fast = fast->next;
    }

    /* Move both together */
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

/* ---------------------------------------------------
   8. Reverse List
      Pattern: Three Pointers

      prev
      current
      next
   --------------------------------------------------- */
void reverseList(Node **head)
{
    Node *prev = NULL;
    Node *current = *head;
    Node *next = NULL;

    while (current != NULL) {

        /* Save next node */
        next = current->next;

        /* Reverse the link */
        current->next = prev;

        /* Move prev */
        prev = current;

        /* Move current */
        current = next;
    }

    *head = prev;
}

/* ---------------------------------------------------
   9. Merge Two Sorted Lists
      Pattern: Dummy + Tail

      Example:

      List1: 1 -> 4 -> 7
      List2: 2 -> 3 -> 8

      Result:
      1 -> 2 -> 3 -> 4 -> 7 -> 8
   --------------------------------------------------- */
Node *mergeSortedLists(Node *head1, Node *head2)
{
    Node dummy;
    Node *tail = &dummy;

    dummy.next = NULL;

    while (head1 != NULL && head2 != NULL) {

        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        }
        else {
            tail->next = head2;
            head2 = head2->next;
        }

        tail = tail->next;
    }

    /* Attach remaining nodes */
    if (head1 != NULL)
        tail->next = head1;
    else
        tail->next = head2;

    return dummy.next;
}

/* ---------------------------------------------------
   10. Remove Duplicates from Sorted List
       Pattern: Single Traversal

       Example:
       1 -> 1 -> 2 -> 2 -> 3

       Result:
       1 -> 2 -> 3
   --------------------------------------------------- */
void removeDuplicates(Node *head)
{
    Node *current = head;

    while (current != NULL && current->next != NULL) {

        if (current->data == current->next->data) {

            Node *duplicate = current->next;

            current->next = duplicate->next;

            free(duplicate);
        }
        else {
            current = current->next;
        }
    }
}

/* ---------------------------------------------------
   11. Free entire list
   --------------------------------------------------- */
void freeList(Node *head)
{
    Node *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/* ---------------------------------------------------
   MAIN
   --------------------------------------------------- */
int main(void)
{
    Node *head = NULL;

    /* Create list using addFront */
    addFront(&head, 30);
    addFront(&head, 20);
    addFront(&head, 10);

    printf("List: ");
    printList(head);


    /* Add at end */
    addEnd(&head, 40);

    printf("After addEnd: ");
    printList(head);


    /* Find middle */
    Node *middle = findMiddle(head);

    if (middle != NULL)
        printf("Middle: %d\n", middle->data);


    /* Nth node from end */
    int n = 2;

    Node *nth = nthFromEnd(head, n);

    if (nth != NULL)
        printf("%dnd node from end: %d\n", n, nth->data);


    /* Detect loop */
    if (detectLoop(head))
        printf("Loop detected\n");
    else
        printf("No loop\n");


    /* Reverse */
    reverseList(&head);

    printf("Reversed: ");
    printList(head);


    /* Remove duplicates */
    Node *dupList = NULL;

    addEnd(&dupList, 1);
    addEnd(&dupList, 1);
    addEnd(&dupList, 2);
    addEnd(&dupList, 2);
    addEnd(&dupList, 3);

    printf("Before removing duplicates: ");
    printList(dupList);

    removeDuplicates(dupList);

    printf("After removing duplicates: ");
    printList(dupList);


    /* Merge sorted lists */
    Node *list1 = NULL;
    Node *list2 = NULL;

    addEnd(&list1, 1);
    addEnd(&list1, 4);
    addEnd(&list1, 7);

    addEnd(&list2, 2);
    addEnd(&list2, 3);
    addEnd(&list2, 8);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    Node *merged = mergeSortedLists(list1, list2);

    printf("Merged: ");
    printList(merged);


    /* Free memory */
    freeList(head);
    freeList(dupList);
    freeList(merged);

    return 0;
}

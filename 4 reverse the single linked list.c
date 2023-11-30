#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};
struct node *head, *head1, *head2, *ptr, *ptr1, *ptr2, *prev, *save, *current;
;
void create(struct node *);
void display(struct node *);
void reverse(struct node *);
int count = 0;
int main()
{
    printf("This program made by Deepak Yadav\n");
    head = 0;
    head = (struct node *)malloc(sizeof(struct node)); // node memory allocation
    int ch;
    printf("Create a  linked list\n");
    create(head);
    system("cls");
    printf("This program made by Deepak Yadav\n");
    printf("\nYOUR LINKED LIST IS \n");
    display(head);
    reverse(head);
    printf("\nYOUR LINKED LIST AFTER REVERSE \n");
    display(head);
    printf("\nNumber of Node in Linked List is  %d", count);
    printf("\n");
    int a;
    scanf("%d",&a);
}

// create the linked list
void create(struct node *head1)
{
    struct node *head2;
    int c;
    int x;
    printf("enter the value \n");
    scanf("%d", &x);
    head1->info = x;
    printf("you want to create more then press 1 \n");
    scanf("%d", &c);
    if (c == 1)
    {
        head2 = (struct node *)malloc(sizeof(struct node));
        head1->next = head2;
        create(head2);
    }
    else
    {
        head1->next = NULL;
    }
}

// display the linked list
void display(struct node *head1)
{
    struct node *head2;
    for (head2 = head1; head2 != NULL; head2 = head2->next)
    {
        printf("%d", head2->info);
        printf("\t");
    }
}

// reverse the single linked list
void reverse(struct node *head1)
{
    current = head1;
    prev = NULL;
    while (current != NULL)
    {
        save = current->next;
        current->next = prev;
        prev = current;
        current = save;
        count++;
    }
    head = prev;
}
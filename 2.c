#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
    struct node *prev;
};
struct node *head, *head1, *head2, *head3, *ptr, *ptr1, *ptr2;
int q, w;
void create(struct node *);
void display(struct node *);
void ins_beg_sll(struct node *);
void ins_end_sll(struct node *);
void ins_spf_sll(struct node *);
void del_beg_sll(struct node *);
void del_end_sll(struct node *);
void del_spf_sll(struct node *);
void create_cll();
void display_cll();
void ins_beg_cll(struct node *);
void ins_end_cll(struct node *);
void ins_spf_cll(struct node *);
void del_beg_cll(struct node *);
void del_end_cll(struct node *);
void del_spf_cll(struct node *);
int sll();
int cll();
int main()
{

    head = 0;
    head = (struct node *)malloc(sizeof(struct node)); // node memory allocation
    int ch, sh;

    int a = 1, b = 1;
    while (a == 1)
    {
        a = 0;
        system("cls");
        printf("This program made by Deepak Yadav\n");
        printf("\n*****MAIN MENU****\n ");
        printf("\nChoice type of linked list \n");
        printf("1. Single linked list \n");
        printf("2. Circular linked list \n");
        printf("3. Exit \n");
        scanf("%d", &sh);
        switch (sh)
        {
        case 1:
            a = sll();
            break;
        case 2:
            a = cll();
            break;
        case 3:
            break;
        default:
            printf("\nWrong input please choice only 1-3 \n");
            break;
        }
    }
}
// choice function for singular ll
int sll()
{
    int ch;
    printf("\nCreate the single linked list \n");
    create(head);
    display(head);
    int a = 1;
    while (a == 1)
    {
        system("cls");
        printf("This program made by Deepak Yadav\n");
        printf("\nYOUR SINGLE LINKED LIST IS \n");
        display(head);
        printf("\n\nChoice option 1-8 \n");
        printf("1. Inserting at the beginning in  single linked list \n");
        printf("2. Insertion at the end in single linked list \n");
        printf("3. Insertion at the specified loction in single linked list\n");
        printf("4. Deletion at the beginning in single linked list\n");
        printf("5. Deletion at the end in single linked list\n");
        printf("6. Deletion at the specified loction in single linked list\n");
        printf("7. Change type of linked list (Back to Main Menu)\n");
        printf("8. EXIT\n");
        scanf("%d", &ch);

        switch (ch)
        {

        case 1:
            ins_beg_sll(head);
            display(head);
            break;
        case 2:
            ins_end_sll(head);
            display(head);
            break;
        case 3:
            ins_spf_sll(head);
            display(head);
            break;
        case 4:
            del_beg_sll(head);
            display(head);
            break;
        case 5:
            del_end_sll(head);
            display(head);
            break;
        case 6:
            del_spf_sll(head);
            display(head);
            break;
        case 7:
            return 1;
        case 8:
            return 0;
        default:
            printf("\nWrong input please choice only 1-8 \n");
            break;
        }
        printf("\nPress 1 to coutinue \n ");
        scanf("%d", &a);
    }
}

// choice function for circular ll
int cll()
{
    int ch;
    create_cll();
    display_cll();
    int a = 1;
    while (a == 1)
    {
        system("cls");
        printf("This program made by Deepak Yadav\n");
        printf("\nYOUR CIRCULAR LINKED LIST IS \n");
        display_cll();
        printf("\n\nChoice option 1-8 \n");
        printf("1. Inserting at the beginning in  circular linked list \n");
        printf("2. Insertion at the end in circular linked list \n");
        printf("3. Insertion at the specified loction in circular linked list\n");
        printf("4. Deletion at the beginning in circular linked list\n");
        printf("5. Deletion at the end in circular linked list\n");
        printf("6. Deletion at the specified loction in circular linked list\n");
        printf("7. Change type of linked list (Back to Main Menu)\n");
        printf("8. EXIT\n");
        scanf("%d", &ch);

        switch (ch)
        {

        case 1:
            ins_beg_cll(head);
            display_cll();
            break;
        case 2:
            ins_end_cll(head);
            display_cll();
            break;
        case 3:
            ins_spf_cll(head);
            display_cll();
            break;
        case 4:
            del_beg_cll(head);
            display_cll();
            break;
        case 5:
            del_end_cll(head);
            display_cll();
            break;
        case 6:
            del_spf_cll(head);
            display_cll();
            break;
        case 7:
            return 1;
        case 8:
            return 0;
        default:
            printf("\nWrong input please choice only 1-8 \n");
            break;
        }
        printf("\nPress 1 to coutinue \n ");
        scanf("%d", &a);
    }
}
// create the single linked list
void create(struct node *head1)
{
    int c;
    int x;
    printf("Enter the value \n");
    scanf("%d", &x);
    head1->info = x;
    printf("You want to create more then press 1 \n");
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

// create circular linked list
void create_cll()
{
    int c = 1;
    struct node *new, *temp;
    head = 0;
    printf("\nCreate the circular linked list \n");
    while (c == 1)
    {

        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value \n");
        scanf("%d", &new->info);
        new->next = 0;
        if (head == 0)
        {
            head = temp = new;
        }
        else
        {
            temp->next = new;
            temp = new;
        }
        temp->next = head;
        printf("You want to create more then press 1 \n");
        scanf("%d", &c);
    }
}
// display the single linked list
void display(struct node *head1)
{
    if (head1 == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        for (head2 = head1; head2 != NULL; head2 = head2->next)
        {
            printf("%d", head2->info);
            printf(" -> ");
        }
    }
}

// display circular linked list
void display_cll()
{
    struct node *temp;
    if (head == 0)
    {
        printf("List is empty \n");
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            printf("%d", temp->info);
            printf(" -> ");
            temp = temp->next;
        }
        printf("%d", temp->info);
        printf("( %d", temp->next);
        printf(")");
    }
}
// Inserting at the beginning in single linked list
void ins_beg_sll(struct node *head1)
{

    printf("\nInserting at the beginning in single linked list \n");
    printf("\nEnter  new element who insert at beginning \n");
    scanf("%d", &q);
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->info = q;
    ptr->next = head;
    head = ptr;
}

// Inserting at the beginning in circular linked list
void ins_beg_cll(struct node *head1)
{
    struct node *new, *temp;
    if (head1 == 0)
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value \n");
        scanf("%d", &new->info);
        new->next = 0;
        if (head == 0)
        {
            head = temp = new;
        }
        else
        {
            temp->next = new;
            temp = new;
        }
        temp->next = head;
    }
    else
    {
        printf("\nInserting at the beginning in circular linked list \n");
        printf("\nEnter  new element who insert at beginning \n");
        scanf("%d", &q);
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->info = q;
        head1 = head;
        while (head1->next != head)
        {
            head1 = head1->next;
        }
        ptr->next = head;
        head1->next = ptr;
        head = ptr;
    }
}

// Insertion at the end in single linked list
void ins_end_sll(struct node *head1)
{

    printf("\nInsertion at the end in single linked list\n");
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter  new element who insert at end \n");
    scanf("%d", &q);
    ptr->info = q;
    if (head1 == 0)
    {
        head = ptr;
        head->next = NULL;
    }
    else
    {
        ptr1 = head;
        while (ptr1->next != NULL)
        {
            ptr1 = ptr1->next;
        }
        ptr->next = NULL;
        ptr1->next = ptr;
    }
}

// Insertion at the end in circular linked list
void ins_end_cll(struct node *head1)
{
    struct node *new, *temp;
    if (head1 == 0)
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value \n");
        scanf("%d", &new->info);
        new->next = 0;
        if (head == 0)
        {
            head = temp = new;
        }
        else
        {
            temp->next = new;
            temp = new;
        }
        temp->next = head;
    }
    else
    {
        printf("\nInserting at the end in circular linked list \n");
        printf("\nEnter  new element who insert at end \n");
        scanf("%d", &q);
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->info = q;
        if (head == 0)
        {
            head = ptr;
            head->next = head;
        }
        else
        {
            head1 = head;
            while (head1->next != head)
            {
                head1 = head1->next;
            }
            ptr->next = head;
            head1->next = ptr;
        }
    }
}
// Insertion at the specified loction in single linked list
void ins_spf_sll(struct node *head1)
{
    head2 = head1;
    int f = 0, g = 1;
    printf("\nInsertion at the specified loction in single  linked list \n");
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter element as specified location after new element  insert  \n");
    scanf("%d", &w);
    while (head2 != NULL)
    {
        if (head2->info != w)
        {
            f = 1;
        }
        else
        {
            printf("\nEnter new element who insert after specified location \n");
            scanf("%d", &q);
            ptr->info = q;
            ptr1 = head;
            while (ptr1->info != w)
            {
                ptr1 = ptr1->next;
            }
            ptr2 = ptr1->next;
            ptr->next = ptr2;
            ptr1->next = ptr;
            g = 0;
            break;
        }
        head2 = head2->next;
    }
    if (f == 1 && g == 1)
    {
        printf("%d", w);
        printf(" is not in list \n ");
    }
}

// Insertion at the specified loction in circular linked list
void ins_spf_cll(struct node *head1)
{
    head2 = head1;
    int f = 0, g = 1;
    printf("\nInsertion at the specified loction in single  linked list \n");
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter element as specified location after new element  insert  \n");
    scanf("%d", &w);
    if (head == NULL)
    {
        f = 1;
    }
    else
    {
        if (head2->info == w)
        {
            printf("\nEnter new element who insert after specified location \n");
            scanf("%d", &q);
            ptr->info = q;
            ptr1 = head;

            ptr2 = ptr1->next;
            ptr->next = ptr2;
            ptr1->next = ptr;
        }
        else
        {
            head2 = head2->next;
            while (head2 != head1)
            {
                if (head2->info != w)
                {
                    f = 1;
                }
                else
                {
                    printf("\nEnter new element who insert after specified location \n");
                    scanf("%d", &q);
                    ptr->info = q;
                    ptr1 = head;
                    while (ptr1->info != w)
                    {
                        ptr1 = ptr1->next;
                    }
                    ptr2 = ptr1->next;
                    ptr->next = ptr2;
                    ptr1->next = ptr;
                    g = 0;
                    break;
                }
                head2 = head2->next;
            }
        }
    }
    if (f == 1 && g == 1)
    {
        printf("%d", w);
        printf(" is not in list \n ");
    }
}
// Delection at the beginning in single linked list
void del_beg_sll(struct node *head1)
{
    printf("\nDeletion at the beginning in single linked list \n");
    if (head1 == NULL)
    {
        printf("No element in the list to delere\n");
    }
    else
    {
        head2 = head;
        head1 = head->next;
        free(head2);
        head = head1;
    }
}

// Delection at the beginning in circular linked list
void del_beg_cll(struct node *head1)
{
    printf("\nDeletion at the beginning in circular linked list \n");
    if (head1 == NULL)
    {
        printf("No element in the list to delere\n");
    }
    else
    {
        if (head->next == head)
        {
            free(head);
            head = 0;
        }
        else
        {
            head1 = head;
            head2 = head->next;
            head3 = head->next;
            while (head2->next != head)
            {
                head1 = head1->next;
                head2 = head2->next;
            }
            head2->next = head3;

            free(head);
            head = head3;
        }
    }
}
// Delection at the end in single linked list
void del_end_sll(struct node *head1)
{

    printf("\nDeletion at the end in  linked list\n");
    if (head1 == NULL)
    {
        printf("No element in the list to delere\n");
    }
    else
    {
        if (head1->next == NULL)
        {
            free(head1);
            head = 0;
        }
        else
        {
            head1 = head;
            head2 = head->next;
            while (head2->next != NULL)
            {
                head1 = head1->next;
                head2 = head2->next;
            }
            head1->next = NULL;
            free(head2);
        }
    }
}

// Delection at the end in circular linked list
void del_end_cll(struct node *head1)
{
    int g = 1;
    printf("\nDeletion at the end in circular linked list \n");
    if (head == NULL)
    {
        printf("No element in the list to delere\n");
    }
    else
    {
        if (head->next == head)
        {
            free(head);
            head = 0;
        }
        else
        {
            head1 = head;
            head2 = head->next;
            while (head2->next != head)
            {
                head1 = head1->next;
                head2 = head2->next;
            }
            head1->next = head;
            free(head2);
        }
    }
}
// Delection at the specified loction in single linked list
void del_spf_sll(struct node *head1)
{
    if (head1 == NULL)
    {
        printf("No element in the list to delere\n");
    }
    else
    {
        head3 = head1;
        int f = 0, g = 1;
        printf("\nDeletion at the specified loction in single linked list\n");
        printf("\nEnter element ,you want to delete  \n");
        scanf("%d", &w);
        while (head3 != NULL)
        {
            if (head3->info != w)
            {
                f = 1;
            }
            else
            {
                if (head1->info == w)
                {
                    del_beg_sll(head);
                    g = 0;
                }
                else
                {
                    head1 = head;
                    head2 = head->next;
                    while (head2->info != w)
                    {
                        head1 = head1->next;
                        head2 = head2->next;
                    }
                    head1->next = head2->next;
                    free(head2);
                    g = 0;
                }
                break;
            }
            head3 = head3->next;
        }
        if (f == 1 && g == 1)
        {
            printf("%d", w);
            printf(" is not in list \n ");
        }
    }
}

// Delection at the specified loction in circular linked list
void del_spf_cll(struct node *head1)
{
    if (head1 == NULL)
    {
        printf("No element in the list to delere\n");
    }
    else
    {
        head3 = head1;
        int f = 0, g = 1;
        printf("\nDeletion at the specified loction in circular linked list\n");
        printf("\nEnter element ,you want to delete  \n");
        scanf("%d", &w);
        if (head3->info == w)
        {
            // printf("d");
            del_beg_cll(head3);
            g = 0;
            f = 1;
            // printf("A");
        }
        else
        {
            head3 = head3->next;
            while (head3 != head1)
            {
                if (head3->info != w)
                {
                    f = 1;
                }
                else
                {
                    head1 = head;
                    head2 = head->next;
                    while (head2->info != w)
                    {
                        head1 = head1->next;
                        head2 = head2->next;
                    }
                    head1->next = head2->next;
                    free(head2);
                    g = 0;
                    break;
                }
                head3 = head3->next;
            }
        }
        if (f == 1 && g == 1)
        {
            printf("%d", w);
            printf(" is not in list \n ");
        }
    }
}

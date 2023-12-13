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
void create_dll();
void display_dll();
void ins_beg_dll(struct node *);
void ins_end_dll(struct node *);
void ins_spf_dll(struct node *);
void del_beg_dll(struct node *);
void del_end_dll(struct node *);
void del_spf_dll(struct node *);

void create_dcll();
void display_dcll();
void ins_beg_dcll(struct node *);
void ins_end_dcll(struct node *);
void ins_spf_dcll(struct node *);
void del_beg_dcll(struct node *);
void del_end_dcll(struct node *);
void del_spf_dcll(struct node *);

int dll();
int dcll();
// main function
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
        printf("1. Double linked list  \n");
        printf("2. Double Circular linked list  \n");
        printf("3. Exit \n");
        scanf("%d", &sh);
        switch (sh)
        {
        case 1:
            a = dll();
            break;
        case 2:
            a = dcll();
            break;
        case 3:
            break;
        default:
            printf("\nWrong input please choice only 1-3 \n");
            break;
        }printf("\nPress 1 to coutinue \n ");
        scanf("%d", &a);
    }
}

int dll()
{int ch;
    create_dll();
    display_dll();
    int b = 1, a = 1;
    printf("%d", a);
    while (b == 1)
    {
        system("cls");
        printf("This program made by Deepak Yadav\n");
        printf("\nYOUR DOUBLE LINKED LIST IS \n");
        display_dll();
        printf("\n\nChoice option 1-7 \n");
        printf("1. Inserting at the beginning in double linked list \n");
        printf("2. Insertion at the end in double linked list \n");
        printf("3. Insertion at the specified loction in double linked list\n");
        printf("4. Deletion at the beginning in double linked list\n");
        printf("5. Deletion at the end in double linked list\n");
        printf("6. Deletion at the specified loction in double linked list\n");
        printf("7. Change type of linked list\n");
        printf("8. EXIT\n");
        scanf("%d", &ch);

        switch (ch)
        {

        case 1:
            ins_beg_dll(head);
            display_dll();
            break;
        case 2:
            ins_end_dll(head);
            display_dll();
            break;
        case 3:
            ins_spf_dll(head);
            display_dll();
            break;
        case 4:
            del_beg_dll(head);
            display_dll();
            break;
        case 5:
            del_end_dll(head);
            display_dll();
            break;
        case 6:
            del_spf_dll(head);
            display_dll();
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
        scanf("%d", &b);
    }
}
int dcll()
{
    int ch;
    create_dcll();
    display_dcll(head);
    int a = 1;
    while (a == 1)
    {
        system("cls");
        printf("This program made by Deepak Yadav\n");
        printf("\nYOUR DOUBLE CIRCULAR LINKED LIST IS \n");
        display_dcll(head);
        printf("\n\nChoice option 1-7 \n");
        printf("1. Inserting at the beginning in double circular linked list \n");
        printf("2. Insertion at the end in double circular linked list \n");
        printf("3. Insertion at the specified loction in double circular linked list\n");
        printf("4. Deletion at the beginning in double circular linked list\n");
        printf("5. Deletion at the end in double circular linked list\n");
        printf("6. Deletion at the specified loction in double circular linked list\n");
        printf("7. Change type of linked list\n");
        printf("8. EXIT\n");
        scanf("%d", &ch);

        switch (ch)
        {

        case 1:
            ins_beg_dcll(head);
            display_dcll();
            break;
        case 2:
            ins_end_dcll(head);
            display_dcll();
            break;
        case 3:
            ins_spf_dcll(head);
            display_dcll();
            break;
        case 4:
            del_beg_dcll(head);
            display_dcll();
            break;
        case 5:
            del_end_dcll(head);
            display_dcll();
            break;
        case 6:
            del_spf_dcll(head);
            display_dcll();
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
// create double linked list
void create_dll()
{
    int c = 1;
    struct node *new, *temp;
    head = 0;
    printf("\nCreate the double linked list \n");
    while (c == 1)
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value \n");
        scanf("%d", &new->info);

        if (head == 0)
        {
            head = temp = new;
        }
        else
        {
            temp->next = new;
            new->prev = temp;
            temp = new;
        }
        temp->next = head;
        printf("You want to create more then press 1 \n");
        scanf("%d", &c);
    }
    head->prev = NULL;
    new->next = NULL;
}

// create double circular linked list
void create_dcll()
{
    int c = 1;
    struct node *new, *temp;
    head = 0;
    printf("\nCreate the double circular linked list \n");
    while (c == 1)
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value \n");
        scanf("%d", &new->info);

        if (head == 0)
        {
            head = temp = new;
        }
        else
        {
            temp->next = new;
            new->prev = temp;
            temp = new;
        }
        temp->next = head;
        printf("You want to create more then press 1 \n");
        scanf("%d", &c);
    }
    head->prev = temp;
}
// display double  linked list
void display_dll()
{

    if (head == NULL)
    {
        printf("List is empty \n");
    }
    else
    {

        ptr = head;
        while (ptr->next != NULL)
        {
            printf("%d", ptr->info);
            printf(" -> ");
            ptr = ptr->next;
        }
        printf(" %d", ptr->info);
    }
}

// display double circular linked list
void display_dcll()
{

    if (head == NULL)
    {
        printf("List is empty \n");
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            
            printf("%d", ptr->info);
            printf(" -> ");
            ptr = ptr->next;
        }
        printf(" %d", ptr->info);
    }
}
// Inserting at the beginning in double linked list
void ins_beg_dll(struct node *head1)
{
    struct node *new, *temp;
    if (head1 == 0)
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value \n");
        scanf("%d", &new->info);

        if (head == 0)
        {
            head = temp = new;
        }
        else
        {
            temp->next = new;
            new->prev = temp;
            temp = new;
        }
        temp->next = head;
        head->prev = NULL;
        new->next = NULL;
    }
    else
    {
        printf("\nInserting at the beginning in double linked list \n");
        printf("\nEnter  new element who insert at beginning \n");
        scanf("%d", &q);
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->info = q;
        head1 = head->prev;
        ptr->next = head;
        ptr->prev = NULL;
        head->prev = ptr;
        head = ptr;
    }
}

// Inserting at the beginning in double circular linked list
void ins_beg_dcll(struct node *head1)
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
        head->next = head;
        head->prev = head;
    }
    else
    {
        printf("\nInserting at the beginning in double circular linked list \n");
        printf("\nEnter  new element who insert at beginning \n");
        scanf("%d", &q);
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->info = q;
        head1 = head->prev;
        ptr->next = head;
        ptr->prev = head1;
        head1->next = ptr;
        head->prev = ptr;
        head = ptr;
    }
}
// Insertion at the end in double  linked list
void ins_end_dll(struct node *head1)
{

    struct node *new, *temp;
    if (head1 == 0)
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value \n");
        scanf("%d", &new->info);

        if (head == 0)
        {
            head = temp = new;
        }
        else
        {
            temp->next = new;
            new->prev = temp;
            temp = new;
        }
        temp->next = head;
        head->prev = NULL;
        new->next = NULL;
    }
    else
    {
        printf("\nInserting at the end in double linked list \n");
        printf("\nEnter  new element who insert at end \n");
        scanf("%d", &q);
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->info = q;
        head1 = head;
        while (head1->next != NULL)
        {
            head1 = head1->next;
        }
        ptr->next = NULL;
        ptr->prev = head1;
        head1->next = ptr;
    }
}

// Insertion at the end in double circular linked list
void ins_end_dcll(struct node *head1)
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
        head->next = head;
        head->prev = head;
    }
    else
    {
        printf("\nInserting at the end in double circular linked list \n");
        printf("\nEnter  new element who insert at end \n");
        scanf("%d", &q);
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->info = q;
        head1 = head->prev;
        ptr->next = head;
        ptr->prev = head1;
        head1->next = ptr;
        head->prev = ptr;
    }
}
// Insertion at the specified loction in double linked list
void ins_spf_dll(struct node *head1)
{
    head2 = head1;
    int f = 0, g = 1;
    printf("\nInsertion at the specified loction in double linked list \n");
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
            if (head->next == NULL)
            {
                ins_end_dll(head);
                g = 0;
            }
            else
            {
                printf("\nEnter new element who insert after specified location \n");
                scanf("%d", &q);
                ptr->info = q;
                ptr1 = head;
                ptr2 = ptr1->next;
                ptr->next = ptr2;
                ptr1->next = ptr;
                ptr->prev = ptr1;
                ptr2->prev = ptr;
            }
        }
        else
        {
            head2 = head2->next;
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
                    ptr1 = head2;
                    if (ptr1->next == NULL)
                    {
                        ptr->next = NULL;
                        ptr->prev = ptr1;
                        ptr1->next=ptr;
                    }
                    else
                    {
                        ptr2 = ptr1->next;
                        ptr->next = ptr2;
                        ptr1->next = ptr;
                        ptr->prev = ptr1;
                        ptr2->prev = ptr;
                    }
                    g = 0;
                    break;
                }
                head2 = head2->next;
            }
        }
        if (f == 1 && g == 1)
        {
            printf("%d", w);
            printf(" is not in list \n ");
        }
    }
}

// Insertion at the specified loction in double circular linked list
void ins_spf_dcll(struct node *head1)
{
    head2 = head1;
    int f = 0, g = 1;
    printf("\nInsertion at the specified loction in double circular  linked list \n");
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
            ptr->prev = ptr1;
            ptr2->prev = ptr;
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
                    ptr->prev = ptr1;
                    ptr2->prev = ptr;
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
// Delection at the beginning in double  linked list
void del_beg_dll(struct node *head1)
{
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("\nDeletion at the beginning in double linked list \n");
    if (head1 == NULL)
    {
        printf("No element in the list to delere\n");
    }
    else
    {
        if (head->next == NULL)
        {
            free(head);
            head = 0;
        }
        else
        {
            head1 = head;
            head = head->next;
            head->prev = NULL;
            free(head1);
        }
    }
}

// Delection at the beginning in double circular linked list
void del_beg_dcll(struct node *head1)
{
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("\nDeletion at the beginning in double circular linked list \n");
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
            head = head->next;
            ptr = head1->prev;
            head->prev = ptr;
            ptr->next = head;
            free(head1);
        }
    }
}
// Delection at the end in double linked list
void del_end_dll(struct node *head1)
{
    int g = 1;
    printf("\nDeletion at the end in double linked list \n");
    if (head1 == NULL)
    {
        printf("No element in the list to delere\n");
    }
    else
    {
        if (head->next == NULL)
        {
            free(head);
            head = 0;
        }
        else
        {
            head1 = NULL;
            head2 = head->next;
            while (head2->next != NULL)
            {
                head2 = head2->next;
            }
            head1 = head2->prev;
            head1->next = NULL;
            free(head2);
        }
    }
}

// Delection at the end in double circular linked list
void del_end_dcll(struct node *head1)
{
    int g = 1;
    printf("\nDeletion at the end in double circular linked list \n");
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
            head1 = head1->prev;
            head2 = head1->prev;
            head2->next = head;
            head->prev = head2;
            free(head1);
        }
    }
}
// Delection at the specified loction in double linked list
void del_spf_dll(struct node *head1)
{
    if (head1 == NULL)
    {
        printf("No element in the list to delere\n");
    }
    else
    {
        head3 = head1;
        int f = 0, g = 1;
        printf("\nDeletion at the specified loction in double linked list\n");
        printf("\nEnter element ,you want to delete  \n");
        scanf("%d", &w);
        if (head3->info == w)
        {
            del_beg_dll(head3);
            g = 0;
            f = 1;
        }
        else
        {
            head3 = head3->next;
            while (head3 != NULL)
            {
                if (head3->info != w)
                {
                    f = 1;
                }
                else
                {
                    head2 = head->next;
                    while (head2->info != w)
                    {
                        // head1 = head1->next;
                        head2 = head2->next;
                    }
                    head1 = head2->prev;
                    if (head2->next == NULL)
                    {
                        head1->next = head2->next;
                    }
                    else
                    {
                        head1 = head2->prev;
                        head3 = head2->next;
                        head1->next = head2->next;
                        head3->prev = head1;
                    }

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

// Delection at the specified loction in double circular linked list
void del_spf_dcll(struct node *head1)
{
    if (head1 == NULL)
    {
        printf("No element in the list to delere\n");
    }
    else
    {
        head3 = head1;
        int f = 0, g = 1;
        printf("\nDeletion at the specified loction in double circular linked list\n");
        printf("\nEnter element ,you want to delete  \n");
        scanf("%d", &w);
        if (head3->info == w)
        {
            // printf("d");
            del_beg_dcll(head3);
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

                    head1 = 0;
                    head2 = head->next;
                    while (head2->info != w)
                    {
                        // head1 = head1->next;
                        head2 = head2->next;
                    }

                    head1 = head2->prev;
                    head3 = head2->next;
                    head1->next = head2->next;
                    head3->prev = head1;

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
#include <stdio.h>
#include <conio.h>

//WE USE CONIO.H HEADER FILE FOR GETCH FUNTION, GETCH FUNCTION IS USED FOR HOLD A SCREEN 
//AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11-12TH OCTOBER 2023
#define size 5

int queue[size];
int front = -1, rear = -1;
//WHERE FRONT AND REAR IS USE FOR ARRAY AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11-12TH OCTOBER 2023
struct node
{
    int info;
    struct node *next;
};
struct node *top = 0, *temp, *ptr, *frontl = 0, *rearl = 0;
//WHERE FRONTL AND REARL IS USE FOR LINKED LIST AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11-12TH OCTOBER 2023
//ENQUEUE FUNCTION OF CIRCULAR QUEUE USING ARRAY AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11-12TH OCTOBER 2023
void enqueue()
{
    int data;
    printf("Enter a data for Enqueue \n");
    scanf("%d", &data);

    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = data;
        printf("%d is Enqueue form Queue successfully \n", data);
    }
    else
    {
        if (((rear + 1) % size) == front)
        {
            printf("Overflow\n");
        }
        else
        {
            rear = ((rear + 1) % size);
            queue[rear] = data;
            printf("%d is Enqueue form Queue successfully \n", data);
        }
    }
}

//DEQUEUE FUNCTION OF CIRCULAR QUEUE USING ARRAY AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11-12TH OCTOBER 2023
int dequeue()
{
    int item;
    if (front == -1 && rear == -1)
    {
        printf("Queue Underflow \n");
    }
    else
    {
        if (front == rear)
        {
            item = queue[front];
            front = rear = -1;
            printf("%d is Dequeue form Queue successfully \n", item);
        }
        else
        {
            item = queue[front];
            front = ((front + 1) % size);
            printf("%d is Dequeue form Queue successfully \n", item);
        }
    }
}

//DISPLAY FUNCTION OF CIRCULAR QUEUE USING ARRAY AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11-12TH OCTOBER 2023
void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\tQueue is empty.\n");
    }
    else
    {

        printf("\tQueue elements : ");
        while (i != rear)
        {
            printf("%d  ", queue[i]);
            i = ((i + 1) % size);
        }
        printf("%d  ", queue[rear]);
        printf("\n");
    }
}

//ENQUEUE FUNCTION OF CIRCULAR QUEUE USING LINKED LIST AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11-12TH OCTOBER 2023
void enqueuel()
{
    int data;
    printf(" Enter the element ");
    scanf("%d", &data);
    ptr = (struct node *)malloc(sizeof(struct node)); // node memory allocation
    ptr->info = data;
    ptr->next = 0;
    if (rearl == 0)
    {
        frontl = rearl = ptr;
        rearl->next = ptr;
        printf("%d is Enqueue form Queue successfully \n", data);
    }
    else
    {
        rearl->next = ptr;
        rearl = ptr;
        rearl->next = frontl;
        printf("%d is Enqueue form Queue successfully \n", data);
    }
}

//DEQUEUE FUNCTION OF CIRCULAR QUEUE USING LINKED LIST AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11-12TH OCTOBER 2023
int dequeuel()
{
    int item;
    temp = frontl;
    temp = frontl;
    if (frontl == 0 && rearl == 0)
    {
        printf("Queue is Underflow\n");
    }
    else
    {
        item = frontl->info;
        if (frontl == rearl)
        {
            frontl = rearl = 0;
            printf("%d is Dequeue form Queue successfully \n", item);
            free(temp);
        }
        else
        {
            frontl = frontl->next;
            rearl->next = frontl;
            printf("%d is Dequeue form Queue successfully \n", item);
            free(temp);
        }
    }
}

//DISPLAY FUNCTION OF CIRCULAR QUEUE USING LINKED LIST AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11-12TH OCTOBER 2023
void displayl()
{
    temp = frontl;
    if (frontl == 0 && rearl == 0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue is : ");
        while (temp->next != frontl)
        {
            printf("%d  ", temp->info);
            temp = temp->next;
        }
        printf("%d  \n", temp->info);
    }
}
//MAIN FUNCTION OF CIRCULAR QUEUE USING ARRAY AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11-12TH OCTOBER 2023
int que()
{
    int ch, b, a = 1;

    while (a == 1)
    {
        system("cls");
        printf("\tThis Queue program made by DEEPAK YADAV\n\n");
        display();
        printf("\n******************************************************************\n");
        printf("\n\t OPERATIONS PERFORMED ON CIRCULAR QUEUE USING ARRAY                        \n");
        printf("\t1. Enqueue a element in Circular Queue                            \n");
        printf("\t2. Dequeue a element form Circular Queue                          \n");
        printf("\t3. Display Queue                                                  \n");
        printf("\t4. Back to Main Menu                                      \n");
        printf("\t5. Exits                                                          \n");
        printf("\n******************************************************************\n");
        printf("\n\tEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 1;
            break;
        case 5:
            return 0;
        default:
            printf("Wrong choose 1-4\n");
        }
        getch();
    }

    return 0;
}
//MAIN FUNCTION OF CIRCULAR QUEUE USING LINKED LIST AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11-12TH OCTOBER 2023
int quell()
{
    int ch, b, a = 1;

    while (a == 1)
    {
        system("cls");
        printf("\tThis Queue program made by DEEPAK YADAV\n\n");
        displayl();
        printf("\n******************************************************************\n");
        printf("\n\t OPERATIONS PERFORMED ON CIRCULAR QUEUE USING LINKED LIST       \n");
        printf("\t1. Enqueue a element in Circular Queue                            \n");
        printf("\t2. Dequeue a element form Circular Queue                          \n");
        printf("\t3. Display Queue                                                  \n");
        printf("\t4. Back to Main Menu                                         \n");
        printf("\t5. Exits                                                          \n");
        printf("\n******************************************************************\n");
        printf("\n\tEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enqueuel();
            break;
        case 2:
            dequeuel();
            break;
        case 3:
            displayl();
            break;
        case 4:
            return 1;
            break;
        case 5:
            return 0;
        default:
            printf("Wrong choose 1-4\n");
        }
        getch();
    }

    return 0;
}

//MAIN FUNCTION OF THIS PROGRAM AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11-12TH OCTOBER 2023
int main()
{
    int ch, a = 1;

    while (a == 1)
    {
        system("cls");
        printf("\tThis Queue program made by DEEPAK YADAV\n\n");
        printf("\n******************************************************************\n");
        printf("\n\t SELECT CIRCULAR QUEUE                                          \n");
        printf("\t1. Circular Queue using array                                     \n");
        printf("\t2. Circular Queue using a linked list                             \n");
        printf("\t3. Exits                                                          \n");
        printf("\n******************************************************************\n");
        printf("\n\tEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            a = que();
            break;
        case 2:
            a = quell();
            break;
        case 3:
            return 0;
        default:
            printf("Wrong choose 1-3\n");
        }
    }
    return 0;
}

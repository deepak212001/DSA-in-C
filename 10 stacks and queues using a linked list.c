#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


//WE USE CONIO.H HEADER FILE FOR GETCH FUNTION, GETCH FUNCTION IS USED FOR HOLD A SCREEN 
//AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11-12TH OCTOBER 2023
struct node
{
    int info;
    struct node *next;
};
struct node *top = 0, *temp, *ptr, *front = 0, *rear = 0;

//PUSH FUNCTION OF STACK USING LINKED LIST, USE FOR INTERSTION A ELEMENT FROM THE STACK AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11-12TH OCTOBER 2023
int push()
{
    int item;
    printf(" Enter a element to push in stack ");
    scanf("%d", &item);
    ptr = (struct node *)malloc(sizeof(struct node)); // node memory allocation
    ptr->info = item;
    ptr->next = top;
    top = ptr;
    printf("%d is push form stack successfully \n", item);
}

//POP FUNCTION OF STACK USING LINKED LIST, USE FOR DELETION A ELEMENT FROM THE STACK AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11-12TH OCTOBER 2023
int pop()
{
    temp = top;
    if (top == 0)
    {
        printf("Underflow");
    }
    else
    {
        printf("%d is pop from stack\n", top->info);
        top = top->next;
        free(temp);
    }
}

//DISPLAY FUNCTION OF STACK USING LINKED LIST ,USE TO DISPLAY ALL ELEMENT OF STACK AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11-12TH OCTOBER 2023
int display()
{
    temp = top;
    if (top == 0)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements: ");
        while (temp != 0)
        {
            printf("%d \t", temp->info);
            temp = temp->next;
        }
        printf("\n");
    }
}
//PEEP FUNCTION OF STACK USING LINKED LIST USE FOR PRINT TOPMOST ELEMENT OF STACK AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11-12TH OCTOBER 2023
int peep()
{
    if (top == 0)
    {
        printf("Underflow");
    }
    else
    {
        printf("%d is topmost element from stack\n", top->info);
    }
}

//ENQUEUE FUNCTION OF QUEUE USING LINKED LIST, USE FOR INTERSETION A ELEMENT FROM THE QUEUE AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11-12TH OCTOBER 2023
int enqueue()
{
    int data;
    printf("Enter a data for Enqueue in Queue \n");
    scanf("%d", &data);
    ptr = (struct node *)malloc(sizeof(struct node)); // node memory allocation
    ptr->info = data;
    ptr->next = 0;
    if (front == 0 && rear == 0)
    {
        front = rear = ptr;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
    }
    printf("%d is Enqueue form Queue successfully \n", data);
}

//DEQUEUE FUNCTION OF QUEUE USING LINKED LIST, USE FOR DELETION A ELEMENT FROM THE QUEUE AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11-12TH OCTOBER 2023
int dequeue()
{
    temp = front;
    if (front == 0 && rear == 0)
    {
        printf("Queue is underflow  \n");
    }
    else
    {
        printf("%d is Dequeue form Queue successfully \n", front->info);
        front = front->next;
        free(temp);
        if (front == 0)
        {
            rear = 0;
        }
    }
}

//DISPLAY FUNCTION OF QUEUE USING LINKED LIST, USE FOR DISPLAY ALL ELEMENT OF THE QUEUE AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11-12TH OCTOBER 2023
int displayqueue()
{
    if (front == 0)
    {
        printf("Queue is empty \n");
    }
    else
    {
        temp = front;
        printf("Queue elements : ");
        while (temp != 0)
        {
            printf("%d \t", temp->info);
            temp = temp->next;
        }
        printf("\n");
    }
}

//MAIN FUNCTION OF QUEUE USING LINKED LIST, AND SELECT OPTION FOR QUEUE AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11-12TH OCTOBER 2023
int que()
{
    int ch, a = 1;

    while (a == 1)
    {
        system("cls");
        printf("\tThis Queue program made by DEEPAK YADAV\n\n");
        displayqueue();
        printf("\n******************************************************************\n");
        printf("\n\t OPERATIONS PERFORMED ON QUEUE USING LINKED LIST                                  \n");
        printf("\t1. Enqueue a element in Queue                                     \n");
        printf("\t2. Dequeue a element form Queue                                   \n");
        printf("\t3. Display Queue                                                  \n");
        printf("\t4. Back to Main Menu                                                          \n");
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
            displayqueue();
            break;
        case 4:
            return 1;
        case 5:
            return 0;
        default:
            printf("Wrong choose 1-5\n");
        }
        getch();
    }

    return 0;
}

//MAIN FUNCTION OF STACK USING LINKED LIST, AND SELECT OPTION FOR STACK AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11-12TH OCTOBER 2023
int sta()
{
    int ch, a = 1;
    while (a == 1)
    {
        system("cls");
        printf("\tThis Stack  program made by DEEPAK YADAV\n\n");
        display();
        printf("\n******************************************************************\n");
        printf("\n\t OPERATIONS PERFORMED ON STACK USING LINKED LIST                                  \n");
        printf("\t1. Push a element in Stack                                        \n");
        printf("\t2. Pop a element form Satck                                       \n");
        printf("\t3. Display Stack                                                  \n");
        printf("\t4. Topmost element in Stack                                       \n");
        printf("\t5. Back to Main Menu                                                          \n");
        printf("\t6. Exits                                                          \n");
        printf("\n******************************************************************\n");
        printf("\n\tEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            peep();
            break;
        case 5:
            return 1;
        case 6:
            return 0;
        default:
            printf("Wrong choose 1-6\n");
        }
        getch();
    }
    return 0;
}

//MAIN FUNCTION OF THIS PROGRAM, SELECT STACK OR QUEUE AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11-12TH OCTOBER 2023
int main()
{
    int ch, a = 1;
    while (a == 1)
    {
        system("cls");
        printf("\tThis program made by DEEPAK YADAV \n\n");
        printf("\n******************************************************************\n");
        printf("\n\t SELECT A OPTION                                                \n");
        printf("\t1. Stack Using Linked List                                                          \n");
        printf("\t2. Queue Using Linked List                                                          \n");
        printf("\t3. Exits                                                          \n");
        printf("\n******************************************************************\n");
        printf("\n\tEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            a = sta();
            break;
        case 2:
            a = que();
        case 3:
            return 0;
        default:
            printf("Wrong choose 1-3\n");
        }
    }
    return 0;
}

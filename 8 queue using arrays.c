//THIS IS PROGRAM NO 8 AND IN THIS PROGRAM IMPLEMENT OPERTIONS ON A QUEUE USING ARRAY

#include <stdio.h>
#include <conio.h>

//WE USE CONIO.H HEADER FILE FOR GETCH FUNTION, GETCH FUNCTION IS USED FOR HOLD A SCREEN 
//AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11TH OCTOBER 2023
#define size 5

int queue[size];
int front = -1, rear = -1;

//ENQUEUE FUNCTION OF QUEUE USING ARRAY AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11TH OCTOBER 2023
void enqueue()
{
    int data;
    printf("Enter a data for Enqueue \n");
    scanf("%d", &data);
    if (rear == size - 1)
    {
        printf("%d is  not Enqueue form Queue because Queue is Overflow \n", data);
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear++;
            queue[rear] = data;
            printf("%d is Enqueue form Queue successfully \n", data);
        }
        else
        {
            rear++;
            queue[rear] = data;
            printf("%d is Enqueue form Queue successfully \n", data);
        }
    }
}

//DEQUEUE FUNCTION OF QUEUE USING ARRAY AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11TH OCTOBER 2023
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
            front++;
            printf("%d is Dequeue form Queue successfully \n", item);
        }
    }
}

//DISPLAY FUNCTION OF QUEUE USING ARRAY AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11TH OCTOBER 2023
void display()
{
    if (front == -1 && rear == -1)
    {
        printf("\tQueue is empty.\n");
    }
    else
    {

        printf("\tQueue elements: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d  ", queue[i]);
        }
        printf("\n");
    }
}

//MAIN FUNCTION OF THIS PROGRAM AND THIS PROGRAM MADE BY DEEPAK YADAV ON 11TH OCTOBER 2023
int main()
{
    int ch, a = 1;

    while (a == 1)
    {
        system("cls");
        printf("\tThis Queue program made by DEEPAK YADAV\n\n");
        display();
        printf("\n******************************************************************\n");
        printf("\n\t OPERATIONS PERFORMED ON QUEUE                             \n");
        printf("\t1. Enqueue a element in Queue                                \n");
        printf("\t2. Dequeue a element form Queue                              \n");
        printf("\t3. Display Queue                                             \n");
        printf("\t4. Exits                                                     \n");
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

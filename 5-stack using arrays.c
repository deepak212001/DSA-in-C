#include <stdio.h>
#include <stdbool.h>

#define size 5

int stack[size];
int top = -1;

bool isEmpty()
{
    return top == -1;
}

void push()
{
    int d;
    if (top == size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter a data for push \n");
        scanf("%d", &d);
        top++;
        stack[top] = d;
    }
}

int pop()
{
    int i;
    if (top == -1)
    {
        printf("Stack Underflow \n");
    }
    else
    {
        i = stack[top];
        top--;
        printf("%d is pop form stack \n", i);
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d  ", stack[i]);
        }
        printf("\n");
    }
}
int peep()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Top most element in Stack is %d\n ", stack[top]);
        printf("\n");
    }
}

int main()
{
    int ch, a = 1;

    while (a == 1)
    {
        system("cls");
        printf("This stack program made by DEEPAK YADAV\n\n");
        display();
        printf("\nStack Menu:\n");
        printf("1. Push a element in stack\n");
        printf("2. Pop a element form stack\n");
        printf("3. Display stack\n");
        printf("4. Topmost element\n");
        printf("5. Exits\n");
        printf("Enter your choice: ");
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
            return 0;
        default:
            printf("Wrong choose 1-4\n");
        }
        printf("\nPress 1 for continue otherwise key any key");
        scanf("%d", &a);
    }

    return 0;
}

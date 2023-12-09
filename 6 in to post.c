#include <stdbool.h>
#include <stdio.h>

#define MAXSIZE 10

typedef struct
{
    char items[MAXSIZE];
    int TOS;
} Stack;

void initializeStack(Stack *ST)
{
    ST->TOS = -1;
}

void push(Stack *ST, char value)
{
    if (ST->TOS == MAXSIZE - 1)
    {
        printf("Stack Overflow! Cannot push more elements.\n");
    }
    else
    {
        ST->items[++(ST->TOS)] = value;
    }
}

char pop(Stack *ST)
{
    if (ST->TOS == -1)
    {
        printf("Stack Underflow. Cannot pop.\n");
        return '\0';
    }
    else
    {
        return ST->items[(ST->TOS)--];
    }
}

char peek(Stack *ST)
{
    if (ST->TOS == -1)
    {
        return '\0';
    }
    else
    {
        return ST->items[ST->TOS];
    }
}

int operator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int isAlphanumeric(char ch)
{
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
}

int precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '^')
    {
        return 3;
    }
    return 0;
}

int isValidInfix(char *exp)
{
    int check = 0;
    int countb = 0, counto = 0, count = 0, counts = 0;

    while (exp[check] != '\0')
    {
        if (exp[check] == '(')
        {
            countb++;
        }
        else if (exp[check] == ')')
        {
            countb--;
        }
        if ((exp[check] >= 'a' && exp[check] <= 'z') || (exp[check] >= 'A' && exp[check] <= 'Z') || (exp[check] >= '0' && exp[check] <= '9'))
        {
            counto++;
        }
        else
        {
            if (exp[check] == '+' || exp[check] == '-' || exp[check] == '*' || exp[check] == '/' || exp[check] == '^')
            {
                counts++;
            }
            else if (exp[check] != ')' && exp[check] != '(')
            {
                count++;
            }
        }
        check++;
    }
    if (countb == 0 && (counts == counto - 1) && count == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void infixToPostfix(char *infix)
{
    Stack ST;
    initializeStack(&ST);

    int infixLength = 0;
    while (infix[infixLength] != '\0')
    {
        infixLength++;
    }

    char postfix[MAXSIZE];
    int pIndex = 0;
    int i = 0;
    while (i < infixLength)
    {
        char ch = infix[i];

        if (isAlphanumeric(ch))
        {
            postfix[pIndex++] = ch;
        }
        else if (operator(ch))
        {
            while (precedence(ch) <= precedence(peek(&ST)))
            {
                postfix[pIndex++] = pop(&ST);
            }
            push(&ST, ch);
        }
        else if (ch == '(')
        {
            push(&ST, ch);
        }
        else if (ch == ')')
        {
            while (peek(&ST) != '(')
            {
                postfix[pIndex++] = pop(&ST);
            }
            pop(&ST);
        }
        i++;
    }

    while (peek(&ST) != '\0')
    {
        postfix[pIndex++] = pop(&ST);
    }

    postfix[pIndex] = '\0';
    printf("Postfix expression: %s\n", postfix);
}

int main()
{
    int a = 1;
    while (a == 1)
    {
        system("cls");
        char infix[MAXSIZE];
        printf("Enter an infix expression: ");
        scanf("%s", infix);

        if (isValidInfix(infix))
        {
            printf("The infix expression is valid.\n");
            infixToPostfix(infix);
        }
        else
        {
            printf("The infix expression is not valid.\n");
        }
        printf("Press 1 for continue ");
        scanf("%d", &a);
    }

    return 0;
}
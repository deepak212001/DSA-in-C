#include <stdio.h>
int a[50];
int size, q = 0;

int display(int size)
{
    if (size == 0)
    {
        printf("Array not contain elements\n");
    }
    else
    {
        printf("The elements of array\n");
        for (int i = 0; i < size; i++)
        {
            printf("%d", a[i]);
            printf("\t");
        }
    }
    printf("\n");
}
int inw_beg(int size)
{
    if (size > 50)
    {
        printf("Over Flow Condition");
    }
    else
    {
        for (int i = size - 1; i >= 0; i--)
        {
            a[i + 1] = a[i];
        }
        printf("Enter a number who insert at beg\n");
        scanf("%d", &a[0]);
    }
}
int ins_end(int size)
{
    if (size > 50)
    {
        printf("Over Flow Condition");
    }
    else
    {
        int i = size;
        printf("Enter a number who insert at end\n");
        scanf("%d", &a[i]);
    }
}

int ins_spf(int size)
{
    display(size);
    int n, p;
    if (size == 0)
    {
        inw_beg(size);
    }
    else
    {
        if (size > 50)
        {
            printf("Over Flow Condition\n");
        }
        else
        {
            printf("Enter postion \n");
            scanf("%d", &p);
            if (p < +size)
            {
                printf("Enter number you want to insert\n");
                scanf("%d", &n);
                for (int i = size - 1; i >= p - 1; i--)
                {
                    a[i + 1] = a[i];
                }
                a[p - 1] = n;
            }
            else
            {
                printf("Invalid position\n");
                q = 1;
            }
        }
    }
}
int ins_spf_ele(int size)
{
    display(size);
    int n, p = 100, e;
    if (size == 0)
    {
        inw_beg(size);
    }
    else
    {
        if (size > 50)
        {
            printf("Over Flow Condition\n");
        }
        else
        {
            printf("Enter element as specified location before new element  insert \n");
            scanf("%d", &e);
            for (int j = 0; j < size; j++)
            {
                if (a[j] == e)
                {
                    p = j + 1;
                    break;
                }
            }
            if (p == 100)
            {
                printf("\n %d is not in array \n", e);
                q = 1;
            }
            else
            {
                printf("Enter number you want to insert\n");
                scanf("%d", &n);
                for (int i = size - 1; i >= p - 1; i--)
                {
                    a[i + 1] = a[i];
                }
                a[p - 1] = n;
                size++;
            }
        }
    }
}
int dlt_beg(int size)
{
    if (size == 0)
    {
        printf("Array not contain elements\n");
    }
    else
    {
        int i = 0;
        for (i = 0; i < size; i++)
            a[i] = a[i + 1];
    }
}
int dlt_end(int size)
{
    if (size == 0)
    {
        printf("Array not contain elements\n");
    }
    else
    {
        a[size - 1] = NULL;
    }
}
int dlt_spf(int size)
{
    int d, i;
    if (size == 0)
    {
        printf("Array not contain elements\n");
    }
    else
    {
        printf("From which position you want to delete ");
        scanf("%d", &d);
        if (d <= 0 || d > size)
        {
            printf("\nInvalid position\n");
            q = 1;
        }
        else
        {
            for (i = d - 1; i < size - 1; i++)
            {
                a[i] = a[i + 1];
            }
            a[i] = NULL;
        }
    }
}
int dlt_spf_ele(int size)
{
    display(size);
    int d, i, p = 100;
    if (size == 0)
    {
        printf("Array not contain elements\n");
    }
    else
    {
        printf("Enter element who want to delete\n ");
        scanf("%d", &d);
        for (int j = 0; j < size; j++)
        {
            if (a[j] == d)
            {
                p = j + 1;
                break;
            }
        }
        if (p == 100)
        {
            printf("\n %d is not in array \n", d);
            q = 1;
        }
        else
        {
            for (i = p - 1; i < size - 1; i++)
            {
                a[i] = a[i + 1];
            }
            a[i] = NULL;
        }
    }
}
int lin_sch(int size)
{
    int n, g = 1;
    printf("Enter number for search ");
    scanf("%d", &n);
    for (int i = 0; i < size; i++)
    {
        if (a[i] == n)
        {
            printf("The element %d was found at position %d \n", n, i + 1);
            g = 0;
        }
    }
    if (g == 1)
    {
        printf("The element %d was not found in this array \n", n);
    }
}
int main()
{
    printf("This Array program made by DEEPAK YADAV\n\n");
    printf("Emter size of array ");
    scanf("%d", &size);
    printf("Emter elements of array\n");
    for (int i = 0; i < size; i++)
    {
        printf(" a[%d] : ", i);
        scanf("%d", &a[i]);
        printf("\n");
    }
    display(size);
    printf("\n");
    int a = 1, ch;
    while (a == 1)
    {
        system("cls");
        printf("This Array program made by DEEPAK YADAV\n\n");
        display(size);
        printf("1. Insert at beg \n");
        printf("2. Insert at end \n");
        printf("3. Insert at pos \n");
        printf("4. Insert after element \n");
        printf("5. Delete at beg \n");
        printf("6. Delete at end \n");
        printf("7. Delete at spf \n");
        printf("8. deletion element \n");
        printf("9. linear search \n");
        printf("10. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            inw_beg(size);
            size++;
            display(size);
            break;
        case 2:
            ins_end(size);
            size++;
            display(size);
            break;
        case 3:
            ins_spf(size);
            if (q == 0)
            {
                size++;
            }
            q = 0;
            display(size);
            break;
        case 4:
            ins_spf_ele(size);
            if (q == 0)
            {
                size++;
            }
            q = 0;
            display(size);
            break;
        case 5:
            dlt_beg(size);
            size--;
            display(size);
            break;
        case 6:
            dlt_end(size);
            size--;
            display(size);
            break;
        case 7:
            dlt_spf(size);
            if (q == 0)
            {
                size--;
            }
            q = 0;
            display(size);
            break;
        case 8:
            dlt_spf_ele(size);
            if (q == 0)
            {
                size--;
            }
            q = 0;
            display(size);
            break;
        case 9:
            lin_sch(size);
            break;
        case 10:
            break;
        default:
            printf("Wrong choose 1-8");
            break;
        }
        printf("\nPress 1 for continue otherwise key any key ");
        scanf("%d", &a);
    }
}

#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    int temp[high - low + 1];

    int index = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp[index] = arr[left];
            left++;
        }
        else
        {
            temp[index] = arr[right];
            right++;
        }
        index++;
    }

    while (left <= mid)
    {
        temp[index] = arr[left];
        left++;
        index++;
    }

    while (right <= high)
    {
        temp[index] = arr[right];
        right++;
        index++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1);    

    for (int j = low; j <= high - 1; j++)
    {
        
        if (arr[j] <= pivot)
        {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

void insort(int a[], int size)
{
     for (int i = 0; i < size; i++)
    {
        int temp;

        for (int j = i; j >= 0; j--)
        {
            while (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int size, ch, a = 1;
    while (a == 1)
    {
        system("cls");
        printf("Enter the size of array : ");
        scanf("%d", &size);

        int arr[size];
        printf("Enter %d elements:\n", size);
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &arr[i]);
        }
        system("cls");

        printf("Before Sorting Array:\n");
        printArray(arr, size);
        printf("\n*****MAIN MENU******");
        printf("\n 1. Sort by Insertion");
        printf("\n 2. Sort by Merge");
        printf("\n 3. Sort by Quick \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insort(arr,size);
            break;
        case 2:
            mergeSort(arr, 0, size - 1);
            break;
        case 3:
            quickSort(arr, 0, size - 1);
            break;

        default:
            break;
        }
        

        printf("After Sorting Array:\n");
        printArray(arr, size);
        printf("\n");
         printf("\nPress 1 to coutinue \n ");
        scanf("%d", &a);
    }

    return 0;
}

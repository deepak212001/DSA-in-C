#include <stdio.h>
#include <conio.h>
int main()
{
    int row, col;
    int count = 0;
    printf("Enter the no. of row and no. of column \n");
    scanf("%d %d", &row, &col);
    int a[row][col];
    printf("Enter elment in MAATRIX \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("a[%d][%d]", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("The elements of matrix\n");
    for (int j = 0; j < row; j++)
    {
        for (int i = 0; i < col; i++)
        {
            printf("%d", a[j][i]);
            printf("\t");
            if (a[j][i] != 0)
            {
                count++;
            }
        }
        printf("\n");
    }
    if (count <= (row * col) / 4)
    {
        printf("\n");
        int r = count + 1;
        int k = 1;
        int b[r][3];
        b[0][0] = row;
        b[0][1] = col;
        b[0][2] = count;

        for (int j = 0; j < row; j++)
        {
            for (int i = 0; i < col; i++)
            {
                if (a[j][i] != 0)
                {

                    b[k][0] = j;
                    b[k][1] = i;
                    b[k][2] = a[j][i];
                    k++;
                }
            }
            printf("\n");
        }
        printf("The elements of triplet matrix\n");
        for (int j = 0; j < r; j++)
        {
            for (int i = 0; i < 3; i++)
            {
                printf("%d", b[j][i]);
                printf("\t");
            }
            printf("\n");
        }
    }
    else
    {
        printf("The triplet matrix is not create because the non zero element is more than one-fourth ");
    }

    getch();
}
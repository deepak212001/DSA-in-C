#include <stdio.h>
#include <conio.h>

#define max 5

void bfs(int adj[][max], int visited[], int start)
{
    int queue[max], rear = -1, front = -1, i, k;
    for (k = 0; k < max; k++)
    {
        visited[k] = 0;
    }
    queue[++rear] = start;
    ++front;
    visited[start] = 1;

    while (rear >= front)
    {
        start = queue[front++];
        printf("%c-", start + 65);
        for (i = 0; i < max; i++)
        {
            if (adj[start][i] && visited[i] == 0)
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}
void dfs(int adj[][max], int visited[], int start)
{
    int stack[max];
    int top=-1,i,k;
    for(k=0;k<max;k++)
    {
        visited[k]=0;
    }
    stack[++top] = start;
    visited[start] = 1;

    while (top !=-1)
    {
        start = stack[top--];
        printf("%c-", start + 65);
        for (i = 0; i < max; i++)
        {
            if (adj[start][i] && visited[i] == 0)
            {
                stack[++top] = i;
                visited[i] = 1;
                break;
            }
        }
    }
}

int main()
{
    int visited[max] = {0};
    int adj[max][max], i, j;
    int ch, size;
    do
    {
        printf("\n Enter the adjacency matrix : ");
            for (int i = 0; i < max; i++)
            {
                for (int j = 0; j < max; j++)
                {
                    scanf("%d", &adj[i][j]);
                }
            }
            printf("\nBFS Traversal : ");
            bfs(adj, visited, 0);
            printf("\n");
            printf("\nDFS Traversal : ");
            dfs(adj, visited, 0);
        
    } while (1);
}
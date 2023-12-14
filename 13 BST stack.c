#include <stdio.h>
#include <stdlib.h>

// Structure for a node in BST
struct node
{
    int info;
    struct node *left, *right;
};

// Function to create a new node
// Function to create a new BST node
struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct node *insert(struct node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->info)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->info)
    {
        root->right = insert(root->right, value);
    }

    return root;
}
// Function to perform inorder traversal using stack
void inorder(struct node *root)
{
    if (root == NULL)
        return;

    struct node *current = root;
    struct node *stack[100]; //  maximum 100 nodes in the stack
    int top = -1;

    while (current != NULL || top != -1)
    {
        while (current != NULL)
        {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->info);
        current = current->right;
    }
}

// Function to perform preorder traversal using stack
void preorder(struct node *root)
{
    if (root == NULL)
        return;

    struct node *stack[100]; // Assuming maximum 100 nodes in the stack
    int top = -1;
    stack[++top] = root;

    while (top != -1)
    {
        struct node *current = stack[top--];
        printf("%d ", current->info);

        if (current->right != NULL)
            stack[++top] = current->right;
        if (current->left != NULL)
            stack[++top] = current->left;
    }
}

// Function to perform postorder traversal using stack
void postorder(struct node *root)
{
    if (root == NULL)
        return;

    struct node *stack1[100]; // Assuming maximum 100 nodes in the stack
    struct node *stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;

    while (top1 != -1)
    {
        struct node *current = stack1[top1--];
        stack2[++top2] = current;

        if (current->left != NULL)
            stack1[++top1] = current->left;
        if (current->right != NULL)
            stack1[++top1] = current->right;
    }

    while (top2 != -1)
    {
        struct node *temp = stack2[top2--];
        printf("%d ", temp->info);
    }
}

int main()
{
    struct node *root;
    root = NULL;
    printf("\n");
    int element;
    int ch, a = 1, b = 1;
    while (a == 1)
    {

        printf("1. Insertion \n");
        printf("2. Inorder Traversing tree    \n");
        printf("3. Postorder Traversing tree  \n");
        printf("4. PreorderTraversing tree    \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            while (b == 1)
            {
                printf("enter a element ");
                scanf("%d", &element);
                root = insert(root, element);
                printf("Press 1 for continue ");
                scanf("%d", &b);
            }
            break;
        case 2:
            printf("Traversing tree using Inorder \n");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Traversing tree using Postorder \n");
            postorder(root);
            printf("\n");
            break;
        case 4:
            printf("Traversing tree using preorder \n");
            preorder(root);
            printf("\n");
            break;

        default:
            printf("Wrong input !   Enter 1-4 only \n");
            break;
        }
        printf("You want to continue then press 1 \n");
        scanf("%d", &a);
    }
    return 0;
}

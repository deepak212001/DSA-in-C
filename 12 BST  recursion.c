#include <stdio.h>
#include <stdlib.h>

// Structure of a BST node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new BST node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to perform inorder traversal
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to perform preorder traversal
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to perform postorder traversal
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Function to search for a node in the BST
struct Node *search(struct Node *root, int value)
{
    if (root == NULL || root->data == value)
    {
        return root;
    }

    if (value < root->data)
    {
        return search(root->left, value);
    }
    else
    {
        return search(root->right, value);
    }
}

// Function to find the minimum value node in a BST
struct Node *minValueNode(struct Node *node)
{
    struct Node *current = node;

    while (current && current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

// Function to delete a node from the BST
struct Node *deleteNode(struct Node *root, int value)
{
    if (root == NULL)
    {
        return root;
    }

    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Main function to demonstrate the BST operations
int main()
{
    struct Node *root = NULL;
    printf("\n");
    int element;
    int ch, a = 1, b = 1;
    while (a == 1)
    {

        printf("1. Insertion \n");
        printf("2. Search element from tree \n");
        printf("3. Delete node from tree   \n");
        printf("4. Traversing tree  using Inorder \n");
        printf("5. Traversing tree  using Postorder \n");
        printf("6. Traversing tree  using preorder \n");
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
            printf("Enter element who want to search in tree \n");
            scanf("%d", &element);
            struct node *searchResult = search(root, element);
            if (searchResult != NULL)
            {
                printf("%d found in the tree.\n", element);
            }
            else
            {
                printf("%d not found in the tree.\n", element);
            }
            break;
        case 3:
            printf("Enter element who want to delete from tree \n");
            scanf("%d", &element);
            deleteNode(root, element);
            break;
        case 4:
            printf("Traversing tree using Inorder \n");
            inorder(root);
            printf("\n");
            break;
        case 5:
            printf("Traversing tree using Postorder \n");
            postorder(root);
            printf("\n");
            break;
        case 6:
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

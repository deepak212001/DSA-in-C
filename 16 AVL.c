#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *left;
    struct Node *right;
    int height;
};

int getHeight(struct Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

struct Node *createNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->info = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int max(int a, int b)
{
    if(a > b)
        return a;
    else       
        return b;
}

int getBalanceFactor(struct Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return x;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return y;
}

struct Node *insert(struct Node *node, int key)
{
    if (node == NULL)
        return createNode(key);

    if (key < node->info)
        node->left = insert(node->left, key);
    else if (key > node->info)
        node->right = insert(node->right, key);

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    int bf = getBalanceFactor(node);

    // Left Left rotation Case
    if (bf > 1 && key < node->left->info)
    {
        return rightRotate(node);
    }
    // Right Right rotation Case
    if (bf < -1 && key > node->right->info)
    {
        return leftRotate(node);
    }
    // Left Right rotation Case
    if (bf > 1 && key > node->left->info)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Left rotation Case
    if (bf < -1 && key < node->right->info)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->info);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;

    int val, a = 1;
    while (a == 1)
    {
        printf("\nenter a number in avl ");
        scanf("%d", &val);
        root = insert(root, val);
        printf("\n you want to continue then press 1 otherwise press 0 ");
        scanf("%d", &a);
    }
    printf("\n Preorder ");
    preOrder(root);
    return 0;
}

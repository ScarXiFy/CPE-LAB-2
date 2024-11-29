#include <stdio.h>
#include <stdlib.h>
#include "main.h"

// Function to perform breadth-first traversal
void breadthFirstTraversal(struct Node *root)
{
    if (root == NULL)
        return;

    struct Node *queue[100]; // Assuming a maximum of 100 nodes for simplicity
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        struct Node *current = queue[front++];
        printf("%d ", current->data);
        if (current->left != NULL)
            queue[rear++] = current->left;
        if (current->right != NULL)
            queue[rear++] = current->right;
    }
}

// Function to traverse the binary tree in Inorder
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to traverse the binary tree in Preorder
void preorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to traverse the binary tree in Postorder
void postorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

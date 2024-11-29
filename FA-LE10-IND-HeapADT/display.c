#include <stdio.h>
#include <stdlib.h>
#include "main.h"

// Function to print the text-based representation of the binary search tree
void printTree(struct Node *root, int space)
{
    if (root == NULL)
    {
        return;
    }
    space += 5;
    printTree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", root->data);
    printTree(root->left, space);
}

void treeMode(struct Node *root)
{
    if (!root)
        return;

    int maxDepth = treeDepth(root, 1);

    for (int i = 0; i < maxDepth; i++)
        printf("\n");
    MOVE_UP(maxDepth);
    treeDisplay(root, 1);
    MOVE_DOWN(maxDepth);
    printf("\n");
}

int treeDepth(struct Node *root, int depth)
{
    if (!root)
        return depth - 1;

    int dLeft = treeDepth(root->left, depth + 1);
    int dRight = treeDepth(root->right, depth + 1);

    return (dLeft > dRight) ? dLeft : dRight;
}

void treeDisplay(struct Node *root, int depth)
{
    if (!root)
        return;

    treeDisplay(root->left, depth + 1);
    MOVE_DOWN(depth);
    printf("[%3d]%d", root->data, depth);
    MOVE_UP(depth);
    treeDisplay(root->right, depth + 1);
}

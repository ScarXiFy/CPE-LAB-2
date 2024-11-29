#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void heapify(struct Node* root) {
    struct Node* smallest = root;
    struct Node* left = root->left;
    struct Node* right = root->right;

    if (left && left->data < smallest->data)
        smallest = left;

    if (right && right->data < smallest->data)
        smallest = right;

    if (smallest != root) {
        printTree(root, 0);
        swap(&root->data, &smallest->data);
        printTree(root, 0);
        heapify(smallest);
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int extractMin(struct Node** root) {
    if (*root == NULL) {
        printf("Heap is empty\n");
        return -1;
    }

    int minValue = (*root)->data;

    // Find the rightmost node in the last level
    struct Node* lastNode;
    while ((*root)->right) {
        lastNode = *root;
        *root = (*root)->right;
    }

    if ((*root)->left) {
        (*root)->data = (*root)->left->data;
        free((*root)->left);
        (*root)->left = NULL;
    } else {
        if (lastNode) {
            lastNode->right = NULL;
        }
        free(*root);
        *root = NULL;
    }

    if (*root) {
        heapify(*root);
    }

    return minValue;
}

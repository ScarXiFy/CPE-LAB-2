#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "main.h"

void displayTree(Node* root, int level) {
    if (root == NULL) {
        return;
    }

    displayTree(root->right, level + 1);
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    printf("%d\n", root->data);
    displayTree(root->left, level + 1);
}

void breadthFirst(Node* root) {
    if (root == NULL) {
        return;
    }

    // Create a queue for BFS
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node* current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
    printf("\n");
}

void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}
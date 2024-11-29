#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"

void printSpaces(int count) {
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
}

void printTreeRecursive(struct Node* root, int level, int isLeft) {
    if (root == NULL)
        return;

    int width = 4;
    int indent = 5;
    int spacing = 3;

    printTreeRecursive(root->right, level + 1, 0);

    if (level != 0) {
        printSpaces(indent);
        for (int i = 0; i < level - 1; i++) {
            printSpaces(spacing);
        }
        if (isLeft) {
            printf("|--");
        } else {
            printf("||--");
        }
        printf("%d\n", root->key);
    } else {
        printf("%d\n", root->key);
    }

    printTreeRecursive(root->left, level + 1, 1);
}

void printTree(struct Node* root) {
    printTreeRecursive(root, 0, 0);
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

#include <stdio.h>
#include <math.h>
#include "main.h"

void printSpaces(int count) {
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
}

void printTreeRecursive(Node* node, int level, int isLeft) {
    if (node == NULL)
        return;

    int width = 4;
    int indent = 5;
    int spacing = 3;

    printTreeRecursive(node->right, level + 1, 0);

    if (level != 0) {
        printSpaces(indent);
        for (int i = 0; i < level - 1; i++) {
            printSpaces(spacing);
        }
        if (isLeft) {
            printf("/--");
        } else {
            printf("\\--");
        }
        printf("%d\n", node->data);
    } else {
        printf("%d\n", node->data);
    }

    printTreeRecursive(node->left, level + 1, 1);
}

void printTree(Node* root) {
    printTreeRecursive(root, 0, 0);
}

void printHeapTree(Node* heap[], int size) {
    int levels = (int)ceil(log2(size + 1));

    for (int i = 0, j = 1; i < levels; i++, j *= 2) {
        int nodesInLevel = (i == levels - 1) ? (size + 1 - (1 << i)) : (1 << i);

        int spacing = (1 << (levels - i + 1)) - 1;

        for (int k = 0; k < nodesInLevel; k++) {
            int index = (1 << i) - 1 + k;

            int positionInLevel = k * 2 + 1;

            for (int s = 0; s < spacing * positionInLevel; s++) {
                printf(" ");
            }

            printf("%d", heap[index]->data);
        }

        printf("\n");
    }
}





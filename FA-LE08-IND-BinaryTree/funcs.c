// funcs.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

void enqueue(QueueNode** front, QueueNode** rear, Node* data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (*rear == NULL) {
        *front = newNode;
    } else {
        (*rear)->next = newNode;
    }
    *rear = newNode;
}

Node* dequeue(QueueNode** front, QueueNode** rear) {
    if (*front == NULL) {
        fprintf(stderr, "Queue is empty\n");
        exit(1);
    }

    Node* data = (*front)->data;
    QueueNode* temp = *front;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
    return data;
}

bool isEmpty(QueueNode* front) {
    return front == NULL;
}

void printTree(Node* root, int space) {
    if (root == NULL) {
        return;
    }
    space += 5;
    printTree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    printTree(root->left, space);
}

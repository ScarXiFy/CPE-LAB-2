// traverse.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void breadthFirstTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    QueueNode* queueFront = NULL;
    QueueNode* queueRear = NULL;
    enqueue(&queueFront, &queueRear, root);

    while (!isEmpty(queueFront)) {
        Node* current = dequeue(&queueFront, &queueRear);
        printf("%d ", current->data);

        if (current->left != NULL) {
            enqueue(&queueFront, &queueRear, current->left);
        }
        if (current->right != NULL) {
            enqueue(&queueFront, &queueRear, current->right);
        }
    }
}

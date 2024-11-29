#include <stdio.h>
#include <stdlib.h>
#include "main.h"

// Function to delete a node from the binary search tree
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        printf("Node not found\n");
        return NULL;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = root->right;
        while (temp && temp->left) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

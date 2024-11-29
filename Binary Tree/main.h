#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

// Structure for a binary tree node

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function prototypes

Node* createNode(int value);
Node* insertNode(Node* root, int value);
Node* findMin(Node* root);
Node* deleteNode(Node* root, int value);
void breadthFirst(Node* root);
void inOrder(Node* root);
void preOrder(Node* root);
void postOrder(Node* root);

#endif // MAIN_H_INCLUDED

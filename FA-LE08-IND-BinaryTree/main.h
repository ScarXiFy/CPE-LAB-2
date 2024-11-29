// main.h
#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct QueueNode {
    Node* data;
    struct QueueNode* next;
} QueueNode;

Node* createNode(int data);
Node* insertNode(Node* root, int data);
Node* findMin(Node* root);
Node* deleteNode(Node* root, int data);
void preorderTraversal(Node* root);
void inorderTraversal(Node* root);
void postorderTraversal(Node* root);
void breadthFirstTraversal(Node* root);
void enqueue(QueueNode** front, QueueNode** rear, Node* data);
Node* dequeue(QueueNode** front, QueueNode** rear);
bool isEmpty(QueueNode* front);

#endif // MAIN_H_INCLUDED

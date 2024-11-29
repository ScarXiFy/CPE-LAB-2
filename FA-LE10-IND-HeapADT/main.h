#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

// Structure for nodes in the Min Heap Tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

// Function Prototype for addnode.c
void addNode(Node* heap[], int* size, int value);

// Function Prototype for deletenode.c
void deleteNode(Node* heap[], int* size);

// Function Prototypes for funcs.c
Node* createNode(int data);
void printNodes(Node* heap[], int size);
Node* minValueNode(Node* node);
void swap(int* a, int* b);
void heapifyUp(Node* heap[], int index);
void heapifyDown(Node* heap[], int size, int index);

// Function Prototypes for printtree.c
void printSpaces(int count);
void printHeapTreeRecursive(Node* heap[], int index, int level);
void printTree(Node* root);
void printHeapTree(Node* heap[], int size);

#endif // MAIN_H_INCLUDED

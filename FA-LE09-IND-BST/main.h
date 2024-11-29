#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

// Node Structure for Binary Search Tree
struct Node {
    int key;
    struct Node *left, *right;
};

// Function Prototypes for addnode.c
struct Node* newNode(int item);
struct Node* insert(struct Node* node, int key);

// Function Prototypes for deletenode.c
struct Node* deleteNode(struct Node* root, int key);

// Function Prototypes for traverse.c
void breadthFirst(struct Node* root);
void preorder(struct Node* root);
void inorder(struct Node* root);
void postorder(struct Node* root);

// Function Prototypes for funcs.c
void printSpaces(int count);
void printTreeRecursive(struct Node* root, int level, int isLeft);
void printTree(struct Node* root);
struct Node* minValueNode(struct Node* node);


#endif // MAIN_H_INCLUDED

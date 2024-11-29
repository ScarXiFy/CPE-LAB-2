#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#define MOVE_UP(x) printf("\e[%dA", x)
#define MOVE_DOWN(x) printf("\e[%dB", x)
#define MOVE_LEFT(x) printf("\e[%dD", x)

// header file for addnode.c

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
} Node;

struct Node *createNode(int value);
void addNode(struct Node** root, int value);

// header file for deletenode.c

struct Node* deleteNode(struct Node* root, int value);

// header file for display.c

void treeMode(struct Node *root);
int treeDepth(struct Node *root, int depth);
void treeDisplay(struct Node *root, int depth);
void printTree(struct Node *root, int space);

// header file for heapify.c

void heapify(struct Node* root);
void swap(int* a, int* b);
int extractMin(struct Node** root);

// header file for traverse.c

void breadthFirstTraversal(struct Node *root);
void inorderTraversal(struct Node *root);
void preorderTraversal(struct Node *root);
void postorderTraversal(struct Node *root);


#endif // MAIN_H_INCLUDED

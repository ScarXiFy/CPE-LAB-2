#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#define MOVE_UP(x) printf("\e[%dA", x)
#define MOVE_DOWN(x) printf("\e[%dB", x)
#define MOVE_LEFT(x) printf("\e[%dD", x)

// add.c

typedef struct node {
        int data;
        struct node* left;
        struct node* right;
    } NODE;

    typedef struct list{
        NODE* node;
        struct list* next;
    } LIST;

    void addMenu(NODE** root);
    LIST* addNode(NODE** root, int data);

// balance.c

    void balanceTree(NODE** root, LIST* checkNodes);

    NODE* rotateLeft(NODE* A, NODE* B);
    NODE* rotateRight(NODE* A, NODE* B);
    NODE** parentOf(NODE** root, NODE* child);

    void push(LIST** head, NODE* toAdd);
    NODE* pop(LIST** head);

// delete.c

void deleteMenu(NODE** root);
LIST* deleteNode(NODE** root, int data);

// search.c

void searchMenu(NODE* root);
NODE* searchNode(NODE* root, int x);

// traverse.c

void enqueue(LIST** root, NODE* toAdd);
NODE* dequeue(LIST** root);
void traverseMenu(NODE* root);
void breadthFirst(NODE* root);
void inFix(NODE* root);
void preFix(NODE* root);
void postFix(NODE* root);
void treeDisplay(NODE* root, int match);
void showLeaves(NODE* root, int depth, int match);
int treeDepth(NODE* root, int depth);

#endif // MAIN_H_INCLUDED

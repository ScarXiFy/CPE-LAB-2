#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

typedef struct node {

    char userInput[256];
    int x;
    int y;
    int z;
    struct node* left;
    struct node* right;
    struct node* next;
    struct node* prev;
} Node;

void createNode(Node*, char userInput);
void expressionTree(char userInput[]);
int evaluateExpression(int x, int y, int z, char userInput);

#endif // MAIN_H_INCLUDED

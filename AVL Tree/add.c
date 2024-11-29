#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include "main.h"

void addMenu(NODE** root){

    int newValue;

    // submenu
    printf("=== ADD NEW NODE ===\n");
    printf("Insert value to add: ");
    scanf(" %d", &newValue);
    printf("\n");

    // initial adding of value to tree
    LIST* checkBalance = addNode(root, newValue);
    printf("Before balancing: ");
    treeDisplay(*root, newValue);
    printf("\n");

    // balancing of tree
    balanceTree(root, checkBalance);
    printf("After balancing: ");
    treeDisplay(*root, newValue);
    printf("\n");

    // presents result
    printf("Success!\n");
    printf("Node added\n");
    printf("Press any key to continue\n");
    getche();
}

LIST* addNode(NODE** root, int data){
    LIST* traversed = NULL;

    // when tree is empty
    if (!*root){
        *root = calloc(1, sizeof(NODE));
        (*root)->data = data;

    // otherwise
    } else {
        NODE* newNode = calloc(1, sizeof(NODE));
        newNode->data = data;

        // find position in tree to insert node in
            // initial move; from root to branch
            NODE* currentNode = *root;
            NODE** nextNode = (data < currentNode->data) ? &(currentNode->left) : &(currentNode->right);
            push(&traversed, currentNode); // history of nodes visited

            // next succeeding moves; from branch to branch
            while(*nextNode){
                currentNode = *nextNode;
                nextNode = (data < currentNode->data) ? &(currentNode->left) : &(currentNode->right);
                push(&traversed, currentNode);
            }

        // insert node in position
        *nextNode = newNode;
    }

    return traversed;
}

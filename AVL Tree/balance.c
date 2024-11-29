#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include "main.h"

void balanceTree(NODE** root, LIST* checkNodes){
    // when and while there are nodes that needs their balance factors checked
    if (checkNodes){
        while(checkNodes){
            NODE* checkBalance = pop(&checkNodes);
            NODE** currentNode = parentOf(root, checkBalance);
            // balance factor is defined as R-L; ie right-heavy trees have positive BF and left-heavy trees have negative BF
            int currentBF = treeDepth(checkBalance->right, 1) - treeDepth(checkBalance->left, 1);

            NODE* childOf;
            int nextBF;

            // when tree is right-heavy
            if (currentBF == 2){

                childOf = checkBalance->right;
                nextBF = treeDepth(childOf->right, 1) - treeDepth(childOf->left, 1);
                
                // when subtree is left-heavy, perform a R rotation on subtree
                if (nextBF == -1) checkBalance->right = rotateRight(childOf, childOf->left);
                // perform a L rotation on tree
                *currentNode = rotateLeft(checkBalance, checkBalance->right);

                // check https://en.wikipedia.org/wiki/AVL_tree#Delete for why 2 sets of rotations is needed at most to balance an AVL tree
                break;
            
            // similar to above; when tree is left-heavy
            } else if (currentBF == -2){
                childOf = checkBalance->left;
                nextBF = treeDepth(childOf->right, 1) - treeDepth(childOf->left, 1);
                
                // when subtree is right-heavy, perform a L rotation on subtree
                if (nextBF == 1) checkBalance->left = rotateLeft(childOf, childOf->right);
                // perform a R rotation on tree
                *currentNode = rotateRight(checkBalance, checkBalance->left);

                break;
            }
        }
    }
}

NODE* rotateLeft(NODE* A, NODE* B){
    A->right = B->left;
    B->left = A;
    return B;
}

NODE* rotateRight(NODE* A, NODE* B){
    A->left = B->right;
    B->right = A;
    return B;
}

NODE** parentOf(NODE** root, NODE* child){

    NODE** result;

    if(child->data == (*root)->data)
        result = root;
    else if(child->data < (*root)->data)
        result = parentOf(&((*root)->left), child);
    else
        result = parentOf(&((*root)->right), child);

    return result;
}

void push(LIST** head, NODE* toAdd){
    LIST* newHead = calloc(1, sizeof(LIST));
    newHead->node = toAdd;

    if (*head) newHead->next = *head;

    *head = newHead;
}

NODE* pop(LIST** head){
    NODE* result = (*head)->node;
    *head = (*head)->next;
    return result;
}
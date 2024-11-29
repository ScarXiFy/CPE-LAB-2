#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include "main.h"

void deleteMenu(NODE** root){

    int delValue, isDeleted;

    // submenu
    printf("=== DELETE A NODE ===\n");
    printf("value to delete: ");
    scanf(" %d", &delValue);
    printf("\n");

    // determines first if value is in tree
    NODE* isPresent = searchNode(*root, delValue);
    printf("Tree display: ");
    treeDisplay(*root, delValue);
    printf("\n");

    // if value is not in tree
    if (!isPresent){
        printf("FAILED!\n");
        printf("Data not found in tree\n");
        printf("\n");

    // otherwise
    } else {
        printf("Success!\n");
        printf("Node removed\n");
        printf("\n");

        // initial removal of node to tree
        LIST* checkBalance = deleteNode(root, delValue);
        printf("Before balancing: ");
        treeDisplay(*root, -999);
        printf("\n");

        // balancing of tree
        balanceTree(root, checkBalance);
        printf("After balancing: ");
        treeDisplay(*root, -999);
        printf("\n");
    }

    printf("Press any key to continue\n");
    getche();
}

LIST* deleteNode(NODE** root, int data){

    LIST* traversed = NULL;
    NODE* toDelete = *root;

    // traversal to the node to be deleted ('toDelete')
    while(toDelete->data != data){
        push(&traversed, toDelete);
        toDelete = (toDelete->data > data) ? toDelete->left : toDelete->right;
    }

    // pointer that points to 'toDelete'
    NODE** parentNode = parentOf(root, toDelete);

    // value that replaces 'toDelete' ('toReplace')
    NODE* toReplace = toDelete->right;

    // when nodes right of 'toDelete' exist
    if(toReplace){
        // determines leftmost node
        while(toReplace->left)
            toReplace = toReplace->left;

        // parent of replacement node
        NODE** upperCon = parentOf(root, toReplace);

        // right subtree of replacement node
        NODE* lowerCon = toReplace->right;

        // deletion of 'data'
        (*parentNode)->data = toReplace->data;

        // reconnecting right subtree to parent
        *upperCon = lowerCon;

    // when there are no nodes to the right of 'toDelete'
    } else
        // replace 'toDelete'
        *parentNode = toDelete->left;

    // when replaced node exists; ie not NULL
    if(*parentNode){
        push(&traversed, *parentNode);

        // when replaced node has right children
        if((*parentNode)->right)
            push(&traversed, (*parentNode)->right);
    }

    return traversed;
}

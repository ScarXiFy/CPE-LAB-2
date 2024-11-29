#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "main.h"

trienode *createNode() {
    trienode *newNode = (trienode *) malloc(sizeof *newNode);
    for(int i = 0; i < NUM_CHAR; i++)
        newNode->children[i] = NULL;
    newNode->isEndOfWord = false;
    return newNode;
}

bool trieInsert(trienode **root, char *str) {
    if(*root == NULL)
        *root = createNode();

    trienode *temp = *root;
    int length = strlen(str);
    for(int i = 0; i < length; i++) {
        int index = str[i] - 'a';

        if(temp->children[index] == NULL)
            temp->children[index] = createNode();

        temp = temp->children[index];
    }

    if(temp->isEndOfWord)
        return false;
    else {
        temp->isEndOfWord = true;
        return true;
    }
}

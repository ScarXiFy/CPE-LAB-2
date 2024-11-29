#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "main.h"

bool trieDelete(trienode **root, char *str) {
    if(*root == NULL)
        return false;

    trienode *temp = *root;
    int length = strlen(str);
    for(int i = 0; i < length; i++) {
        int index = str[i] - 'a';

        if(temp->children[index] == NULL)
            return false;

        temp = temp->children[index];
    }

    if(!temp->isEndOfWord)
        return false;

    temp->isEndOfWord = false;

    for(int i = 0; i < NUM_CHAR; i++) {
        if(temp->children[i] != NULL)
            return true;
    }

    free(temp);

    return true;
}

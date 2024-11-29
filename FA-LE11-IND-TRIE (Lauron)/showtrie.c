#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "main.h"

void showTries(trienode *root) {
    if (root == NULL) {
        printf("\n Trie is currently empty. \n");
        return;
    }

    printTrie(root);

}


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "main.h"

void printTrieRec(trienode *node, unsigned char *prefix, int length) {
    if(node->isEndOfWord)
        printf("\n$ --- %s*\n", prefix);

    for(int i = 0; i < NUM_CHAR; i++) {
        if(node->children[i] != NULL) {
            unsigned char newPrefix[length + 2];
            memcpy(newPrefix, prefix, length);
            newPrefix[length] = i + 'a';
            newPrefix[length + 1] = '\0';

            printf("%s\n", newPrefix);

            printTrieRec(node->children[i], newPrefix, length + 1);
        }
    }
}

void printTrie(trienode *root) {
    if(root == NULL)
        return;

    printTrieRec(root, "", 0);
}

void printMenu() {
    printf("\n=== TRIE MAIN MENU ===\n");
    printf("\n [1] Add new word\n");
    printf("\n [2] Delete word\n");
    printf("\n [3] Show Trie\n");
    printf("\n [4] Exit\n");
}

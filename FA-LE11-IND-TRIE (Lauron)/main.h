#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#define NUM_CHAR 26

typedef struct trienode {

    struct trienode *children[NUM_CHAR];
    bool isEndOfWord;

} trienode;

trienode *createNode();
bool trieInsert(trienode **root, char *str);
bool trieDelete(trienode **root, char *str);
void printTrieRec(trienode *node, unsigned char *prefix, int length);
void printTrie(trienode *root);
void printMenu();
void showTries(trienode *root);

#endif // MAIN_H_INCLUDED

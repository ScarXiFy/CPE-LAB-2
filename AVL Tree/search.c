#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "main.h"

void searchMenu(NODE* root){

    char* input = calloc(25, sizeof(char));
    int searchFor;
    NODE* match = root;

    // submenu
    printf("=== SEARCH A NODE ===\n");
    printf("[S] Smallest node\n");
    printf("[L] Largest node\n");
    printf("Or enter a specific number\n");
    scanf(" %25[^\n]s", input);
    printf("\n");

    // when user-defined number
    if (isdigit(*input)) {
        // converts number from string to integer
        searchFor = atoi(input);

        // determines if value is in tree
        match = searchNode(root, searchFor);

        // if value is in tree
        if (!match)
            printf("Value %d is not found in tree!\n", searchFor);

        // otherwise
        else
            printf("Value %d is in tree!\n", searchFor);

    // when smallest or largest value
    } else {
        char userChoice = tolower(*input);

        // determine smallest value
        if (userChoice == 's')
            while((match->left))
                match = match->left;

        // determines largest value
        else
            while((match->right))
                match = match->right;

        // prints determined values
        searchFor = match->data;
        printf("%s value is %d\n", (userChoice == 's') ? "Smallest" : "Largest", searchFor);
    }

    // prints tree
    printf("Value in tree:");
    treeDisplay(root, searchFor);
    printf("\n");

    printf("Press any key to continue\n");
    getche();
}

NODE* searchNode(NODE* root, int x){
    NODE* result;

    // when node is NULL
    if (!root)
        result = NULL;

    // when node is found
    else if (root->data == x)
        result = root;

    // otherwise, recursive call
    else
        result = searchNode((root->data > x) ? root->left : root->right, x);

    return result;
}

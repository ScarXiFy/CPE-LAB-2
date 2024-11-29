#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"

int main() {
    struct Node* root = NULL;
    int choice, key;

    do {
        printf("\n=== MAIN MENU ===\n");
        printf("[1] Add new node\n");
        printf("[2] Delete a node\n");
        printf("[3] Traverse tree\n");
        printf("[4] Exit\n");
        printf("Choice? ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n=== ADD NEW NODE ===\n");
                printf("Insert value to add: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("SUCCESS: node added\n");
                printTree(root);
                break;
            case 2:
                printf("\n=== DELETE NEW NODE ===\n");
                printf("Insert value to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("SUCCESS: node removed\n");
                printTree(root);
                break;
            case 3:
                printf("\n=== TRAVERSE TREE ===\n");
                printf("Breadth-first: ");
                breadthFirst(root);
                printf("\n");
                printf("Depth-first Inorder Traversal: ");
                inorder(root);
                printf("\n");
                printf("Depth-first Preorder Traversal: ");
                preorder(root);
                printf("\n");
                printf("Depth-first Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

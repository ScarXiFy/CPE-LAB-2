#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "main.h"

int main() {
    Node* root = NULL;
    int choice, value;

    while (1) {
        // system("cls");
        printf("\n=== MAIN MENU ===\n");
        printf("[1] Add new node\n");
        printf("[2] Delete a node\n");
        printf("[3] Traverse binary tree\n");
        printf("[4] Exit\n");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                printf("Insert value to add: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                printf("Tree display: \n");
                displayTree(root, 0);
                printf("\n");
                break;
            case 2:
                printf("Insert value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Tree display: \n");
                displayTree(root, 0);
                printf("\n");
                break;
            case 3:
                printf("Breadth-first: ");
                breadthFirst(root);
                printf("Depth-first Inorder Traversal: ");
                inOrder(root);
                printf("\n");
                printf("Depth-first Preorder Traversal: ");
                preOrder(root);
                printf("\n");
                printf("Depth-first Postorder Traversal: ");
                postOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting Program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    Node* root = NULL;
    int choice, value;

    do {
        printf("\n=== MAIN MENU ===\n");
        printf("[1] Add new node\n");
        printf("[2] Delete a node\n");
        printf("[3] Traverse binary tree\n");
        printf("[4] Exit\n");
        printf("Choice? ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n=== ADD NEW NODE ===\n");
                printf("Insert value to add: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                printf("Tree representation after adding node:\n");
                printTree(root, 0);
                break;
            case 2:
                printf("\n=== DELETE NODE ===\n");
                printf("Insert value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Tree representation after deleting node:\n");
                printTree(root, 0);
                break;
            case 3:
                printf("\n=== TRAVERSE TREE ===\n");
                printf("[1] Breadth-first traversal\n");
                printf("[2] Depth-first Inorder Traversal\n");
                printf("[3] Depth-first Preorder Traversal\n");
                printf("[4] Depth-first Postorder Traversal\n");
                printf("Choice? ");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        printf("Breadth-first traversal: ");
                        breadthFirstTraversal(root);
                        printf("\n");
                        break;
                    case 2:
                        printf("Depth-first Inorder Traversal: ");
                        inorderTraversal(root);
                        printf("\n");
                        break;
                    case 3:
                        printf("Depth-first Preorder Traversal: ");
                        preorderTraversal(root);
                        printf("\n");
                        break;
                    case 4:
                        printf("Depth-first Postorder Traversal: ");
                        postorderTraversal(root);
                        printf("\n");
                        break;
                    default:
                        printf("Invalid choice\n");
                        break;
                }
                break;
            case 4:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice\n");
        }
    } while (choice != 4);

    return 0;
}

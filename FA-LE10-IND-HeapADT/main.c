#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main() {
    Node* heap[100];
    int size = 0, choice, value;
    char again;

    while (1)
    {
        system("cls");
        printf("\n=== MIN HEAP MAIN MENU ===\n");
        printf("[1] Add new node\n");
        printf("[2] Delete a node\n");
        printf("[3] Show heap tree\n");
        printf("[4] Exit\n");
        printf("Choice? ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                do {
                    system("cls");
                    printf("\n=== ADD NEW NODE ===\n");
                    printf("Enter value to add: ");
                    scanf("%d", &value);
                    addNode(heap, &size, value);
                    printf("\n\nAgain [Y/N]? ");
                    scanf(" %c", &again);
                } while (again != 'N' && again != 'n');
                break;
            case 2:
                do {
                    system("cls");
                    printf("\n=== DELETE NEW NODE ===\n");
                    deleteNode(heap, &size);
                    printf("\n\nAgain [Y/N]? ");
                    scanf(" %c", &again);
                } while (again != 'N' && again != 'n');
                break;
            case 3:
                system("cls");
                printf("\n=== HEAP TREE ===\n");
                printHeapTree(heap, size);
                printf("\n");
                printf("Press any key to return to MAIN MENU...");
                _getch(); // Wait for user input
                break;
            case 4:
                printf("\nExiting Program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

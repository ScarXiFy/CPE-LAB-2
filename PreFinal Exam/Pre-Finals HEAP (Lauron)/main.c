#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "main.h"

int main() {
    int choice;
    char again;

    system("title Lauron's Heap Tree");
    system("color F0");

    while(1) {
        system("cls");
        printf("\n=== MAIN MENU ===\n");
        printf("1. Add new node\n");
        printf("2. Delete a node\n");
        printf("3. Show all nodes\n");
        printf("4. Exit\n");
        printf("\nChoice? ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                do {
                system("cls");
                printf("\n === ADD NEW NODE === \n");
                addNode();
                fflush(stdin);
                printf("\nAgain [Y/N]? ");
                scanf(" %c", &again);
                } while (again != 'N' && again != 'n');
                break;
            case 2:
                do {
                system("cls");
                printf("\n === DELETE NEW NODE === \n");
                deleteNode();
                fflush(stdin);
                printf("\nAgain [Y/N]? ");
                scanf(" %c", &again);
                } while (again != 'N' && again != 'n');
                break;
            case 3:
                do {
                system("cls");
                printf("\n === SHOW ALL NODES === \n");
                showNodes();
                fflush(stdin);
                printf("\nAgain [Y/N]? ");
                scanf(" %c", &again);
                } while (again != 'N' && again != 'n');
                break;
            case 4:
                printf("\nExiting Program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

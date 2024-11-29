#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "main.h"

int main() {
    int choice;
    trienode *root = NULL;
    char str[100];
    char again;

    do {
        system("cls");
        printMenu();
        printf("\nChoice? ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                do {
                    system("cls");
                    printf("\n === ADD NEW WORD === \n");
                    printf("\nInsert word to add: ");
                    scanf("%s", str);
                    trieInsert(&root, str);
                    printf("\nTrie after adding '%s': \n", str);
                    printf("\n");
                    printTrie(root);
                    fflush(stdin);
                    printf("\nAgain [Y/N]? ");
                    scanf(" %c", &again);
                } while(again == 'Y' || again == 'y');
                break;
            case 2:
                do {
                    system("cls");
                    printf("\n === DELETE WORD === \n");
                    printf("\nInsert word to delete: ");
                    scanf("%s", str);
                    if(trieDelete(&root, str))
                        printf("'%s' deleted successfully.\n", str);
                    else
                        printf("ERROR: '%s' not found.\n", str);
                    printf("\nTrie after deleting '%s': \n", str);
                    printTrie(root);
                    fflush(stdin);
                    printf("\nAgain [Y/N]? ");
                    scanf(" %c", &again);
                } while(again == 'Y' || again == 'y');
                break;
            case 3:
                do {
                    system("cls");
                    printf("\n === TRIE ===\n");
                    showTries(root);
                    fflush(stdin);
                    printf("\nAgain [Y/N]? ");
                    scanf(" %c", &again);
                } while (again == 'Y' || again == 'y');
                break;
            case 4:
                printf("\n\n Exiting Program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}

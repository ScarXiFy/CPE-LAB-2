#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "phonebookSLL.h"

void deleteRecord(struct Node** head)
{
    char inputChoice;
    clearScreen();
    displayDeleteMenu();
    inputChoice = toupper(getch());

    struct Node* current = *head;
    struct Node* prev = NULL;

    if (inputChoice == 'L')
    {
        clearScreen();
        char inputLastName[100];
        printf("\n\tInput Last Name: ");
        scanf("%s", inputLastName);

        struct Node* current = *head;
        struct Node* prev = NULL;

        while (current != NULL) {
            if (strcmp(current->data.lastName, inputLastName) == 0) {
                if (prev == NULL) {
                    *head = current->next;
                } else {
                    prev->next = current->next;
                }

                free(current);
                printf("\n\t%s successfully deleted!\n", inputLastName);
                Sleep(1000);
                return;
            }

            prev = current;
            current = current->next;
        }

        printf("\n\tError: Last Name not found!\n");
    }

    else if (inputChoice == 'M')
    {
        clearScreen();
        char inputMobileNo[100];
        printf("\n\tInput Mobile No.: ");
        scanf("%s", inputMobileNo);

        struct Node* current = *head;
        struct Node* prev = NULL;

        while (current != NULL) {
            if (strcmp(current->data.mobileNo, inputMobileNo) == 0) {
                if (prev == NULL) {
                    *head = current->next;
                } else {
                    prev->next = current->next;
                }

                free(current);
                printf("\n\t%s successfully deleted!\n", inputMobileNo);
                Sleep(1000);
                return;
            }

            prev = current;
            current = current->next;
        }

        printf("\n\tError: Mobile No. not found!\n");
        Sleep(1000);
    } else {
        printf("\n\tInvalid choice!\n");
        Sleep(1000);
    }
}

void displayDeleteMenu()
{
    printf("\n\tDELETE MENU\n");
    printf("\n\t[L] Search by Last Name\n");
    printf("\n\t[M] Search by Mobile No.\n");
    printf("\n\tInput Choice: ");
}

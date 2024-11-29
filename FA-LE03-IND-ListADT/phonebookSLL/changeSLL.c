#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "phonebookSLL.h"


void changeRecord(struct Node* head)
{
    char changeChoice;
    char inputLastName[100];
    char inputMobileNo[100];
    struct Node* current = head;
    int found = 0;

    clearScreen();
    displayChangeMenu();
    changeChoice = toupper(getch());

    switch (changeChoice) {
        case 'L':
        {
            clearScreen();
            printf("\n\tInput Last Name: ");
            scanf("%s", inputLastName);

            while (current != NULL) {
                if (strcmp(current->data.lastName, inputLastName) == 0) {
                    found = 1;
                    break;
                }
                current = current->next;
            }
            break;
        }

        case 'M':
        {
            clearScreen();
            printf("\n\tInput Mobile No.: ");
            scanf("%s", inputMobileNo);

            while (current != NULL) {
                if (strcmp(current->data.mobileNo, inputMobileNo) == 0) {
                    found = 1;
                    break;
                }
                current = current->next;
            }
            break;
        }

        default:
            printf("\n\tInvalid choice! Please choose again.\n");
            Sleep(1000);
            return;
    }

    if (!found) {
        printf("\n\tError: Last Name/Mobile No. not found!\n");
        Sleep(1000);
        return;
    }
        clearScreen();
        printf("\n\tCHANGE WHAT?\n");
        printf("\n\t[L] last name\n");
        printf("\n\t[M] middle name\n");
        printf("\n\t[F] first name\n");
        printf("\n\t[N] mobile no.\n");
        printf("\n\t[E] email address\n");
        printf("\n\tChoice? ");
        changeChoice = toupper(getch());

    switch (changeChoice) {
        case 'L':
        case 'l':
            printf("\n\n\n\tReplace last name: ");
            scanf(" %[^\n]", current->data.lastName);
            break;

        case 'M':
        case 'm':
            printf("\n\n\n\tReplace middle name: ");
            scanf(" %[^\n]", current->data.middleName);
            break;

        case 'F':
        case 'f':
            printf("\n\n\n\tReplace first name: ");
            scanf(" %[^\n]", current->data.firstName);
            break;

        case 'N':
        case 'n':
            printf("\n\n\n\tReplace mobile no.: ");
            scanf(" %[^\n]", current->data.mobileNo);
            break;

        case 'E':
        case 'e':
            printf("\n\n\n\tReplace email address: ");
            scanf(" %[^\n]", current->data.emailAddress);
            break;

        default:
            printf("\n\nInvalid choice! Please choose again.\n");
            Sleep(1000);
            return;
    }

    printf("\n\n\tRecord successfully changed!\n");
    Sleep(1000);
}

void displayChangeMenu()
{
    clearScreen();
    printf("\n\tCHANGE MENU\n");
    printf("\n\t[L] Search by Last Name\n");
    printf("\n\t[M] Search by Mobile Number\n");
    printf("\n\tChoice? ");
}

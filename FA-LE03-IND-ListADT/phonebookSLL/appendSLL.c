#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "phonebookSLL.h"

struct Node* head = NULL;

struct Node* appendRecord(struct Node** head) {
    char appendChoice, userInput = 'Y';

    do {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        }

        newNode->next = NULL;  // Initialize next pointer to NULL

        clearScreen();
        printf("\n\tInput First Name: ");
        scanf(" %[^\n]", newNode->data.firstName);
        printf("\n\tInput Middle Name: ");
        scanf(" %[^\n]", newNode->data.middleName);
        printf("\n\tInput Last Name: ");
        scanf(" %[^\n]", newNode->data.lastName);
        printf("\n\tInput Mobile No.: ");
        scanf(" %[^\n]", newNode->data.mobileNo);
        printf("\n\tInput Email Address: ");
        scanf(" %[^\n]", newNode->data.emailAddress);

        printf("\n\n\tSave record [Y/N]? ");
        appendChoice = toupper(getch());

        if (appendChoice == 'Y') {
            FILE* fp = fopen("phonebook.txt", "a");
            if (fp == NULL) {
                printf("Error opening file for writing!\n");
                exit(EXIT_FAILURE);
            }

            fprintf(fp, "%s\t%s\t%s\t%s\t%s\n", newNode->data.firstName, newNode->data.middleName,
                    newNode->data.lastName, newNode->data.mobileNo, newNode->data.emailAddress);

            fclose(fp);

            newNode->next = *head;
            *head = newNode;

            printf("\n\n\tRecord Saved Successfully!");
            Sleep(1000);
            printf("\n\n\n\tAgain [Y/N]?");
            fflush(stdin);
            userInput = toupper(getch());
        } else {
            free(newNode);
            userInput = 'N';
        }

    } while (userInput == 'Y');

    return *head;
}

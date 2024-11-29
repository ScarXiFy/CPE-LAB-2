#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "phonebookSLL.h"

int main()
{
    struct Node* head = NULL;
    char userInput;

    while(1)
    {
        displayMainMenu();
        fflush(stdin);
        userInput = toupper(getch());

        if (userInput == 'E')
        {
            clearScreen();
            printf("\n\n\tThank you for using Enrico's Phonebook! Bye!\n\n");
            Sleep(1000);
            exit(0);
        }

        switch (userInput)
        {
        case 'A':
            appendRecord(&head);
            break;

        case 'B':
            browseRecord(head);
            break;

        case 'C':
            changeRecord(head);
            break;

        case 'D':
            deleteRecord(&head);
            break;

        default:
            printf("\n\n\t\tInvalid choice! Please choose again...");
            Sleep(1000);
            break;
        }


    }

    freeLinkedList(head);


    return 0;
}

void displayMainMenu()
{
    clearScreen();
    printf("\n\tPHONEBOOK MAIN MENU:\n");
    printf("\n\t[A] ppend\n");
    printf("\t[B] browse\n");
    printf("\t[C] hange\n");
    printf("\t[D] elete\n");
    printf("\t[E] xit\n");
    printf("\n\nChoice? ");
}

void freeLinkedList(struct Node* head)
{
    struct Node* current = head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void clearScreen()
{
    system("cls");
}

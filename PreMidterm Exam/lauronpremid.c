#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "lauronpremid.h"

int main()
{
    struct Node* head = NULL;
    char payDate[100];
    char Payee[100];
    char payID[100];
    char payAmount[100];
    char userInput;
    char key;

    while(1)
    {
        mainmenu:
        displayMainMenu();
        fflush(stdin);
        userInput = toupper(getch());

        if (userInput == 'X')
        {
            system("cls");
            printf("Exiting program.\n");
            exit(0);
        }

        switch (userInput)
        {

        case '+':
            addPaymentRecord(&head, payDate, Payee, payID, payAmount);
            break;

        case '-':
            deletePaymentRecord(&head);
            break;

        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }

    freeLinkedList(head);


    return 0;
}


void displayMainMenu()
{
    system("cls");
    printf("=== PAYMENT RECORD MAIN MENU ===\n");
    printf("\n [+] add new payment record\n");
    printf("\n [-] delete payment record\n");
    printf("\n [X] exit program\n");
    printf("\n\n Choice? ");
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

struct Node* addPaymentRecord(struct Node** head, char payDate[], char Payee[], char payID[], char payAmount[])
{
    char key;
    char addChoice, userInput = 'Y';
    do {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        }

        newNode->next = NULL;  // Initialize next pointer to NULL

        system("cls");
        printf("\n\tInput ID #: ");
        scanf(" %[^\n]", newNode->data.payID);
        printf("\n\tInput payee's full name: ");
        scanf(" %[^\n]", newNode->data.Payee);
        printf("\n\tInput pay date: ");
        scanf(" %[^\n]", newNode->data.payDate);
        printf("\n\tInput pay amount: ");
        scanf(" %[^\n]", newNode->data.payAmount);

        printf("\n\n\tSave record [Y/N]? ");
        addChoice = toupper(getch());

        if (addChoice == 'Y') {
            FILE* fp = fopen("paymentrecords.txt", "a");
            if (fp == NULL) {
                printf("Error opening file for writing!\n");
                exit(EXIT_FAILURE);
            }

            fprintf(fp, "%s\t%s\t%s\t%s\t%s\n", newNode->data.payID, newNode->data.Payee,
                    newNode->data.payDate, newNode->data.payAmount);

            fclose(fp);

            newNode->next = *head;
            *head = newNode;

            printf("\n\n\tRecord Saved Successfully!");
            Sleep(1000);
            printf("\n\n\n\tAgain [Y/N]?");
            fflush(stdin);
            userInput = toupper(getch());
            displayPaymentMenu(head);
            printf("\n\npress any other key to go back to main menu.... ");
            fflush(stdin);
            getch();
            return;


        } else {
            free(newNode);
            userInput = 'N';
        }

    } while (userInput == 'Y');

    return *head;
}

void deletePaymentRecord(struct Node** head)
{
    displayDeleteMenu();
    char inputChoice;

    struct Node* current = *head;
    struct Node* prev = NULL;

    if (inputChoice == 'M')
    {
        system("cls");
        char payID[100];
        printf("\n\tInput ID #: ");
        scanf("%s", payID);

        struct Node* current = *head;
        struct Node* prev = NULL;

        while (current != NULL) {
            if (strcmp(current->data.payID, payID) == 0) {
                if (prev == NULL) {
                    *head = current->next;
                } else {
                    prev->next = current->next;
                }

                free(current);
                printf("\n\t%s successfully deleted!\n", payID);
                printf("\n\npress any other key to go back to main menu.... ");
                fflush(stdin);
                getch();
                return;
            }

            prev = current;
            current = current->next;
        }

        printf("\n\tError: Mobile No. not found!\n");
        printf("\n\npress any other key to go back to main menu.... ");
                fflush(stdin);
                getch();
   } else {
        printf("\n\tInvalid choice!\n");
        printf("\n\npress any other key to go back to main menu.... ");
                fflush(stdin);
                getch();
    }
}

void displayDeleteMenu()
{
    system("cls");
    printf("=== DELETE PAYMENT RECORD ===");
    printf("\n\nRecord #\t\tPay Date\t\tPay Amt\t\tPay ID\t\tPayee\n");
    printf("===========================================================================================\n");
    printf("WARNING - the record above will be deleted!\n");
    printf("Proceed [y/n]?");

}

void displayPaymentMenu(struct Node* head)
{
    struct Node* currentB = head;
    system("cls");

    printf("\n\nRecord #\t\tPay Date\t\tPay Amt\t\tPay ID\t\tPayee\n");
    printf("===========================================================================================\n");
    while(currentB != NULL)
            {
                for (int i = 0; currentB != NULL; i++)
                {
                    printf("%d %-15s %-15s %-15s %-15s\n",
                       i, currentB->data.payDate,
                       currentB->data.payAmount, currentB->data.payID,
                       currentB->data.Payee);
                currentB = currentB->next;
                }
            }
}

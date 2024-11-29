#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "phonebookSLL.h"

void browseRecord(struct Node* head)
{
    char userInput = 'A';

    do
    {
        displayBrowseMenu();
        fflush(stdin);
        userInput = toupper(getch());

        int found = 0;

        switch (userInput)
        {
        case 'B':
            printf("\n\n\n\tBROWSE ALL\n\n");
            printf("Last Name\tFirst Name\tMiddle Name\tMobile No.\tEmail Address\n");
            printf("==========================================================================================================\n");

            struct Node* currentB = head;
            while (currentB != NULL)
            {
                printf("%-15s %-15s %-15s %-15s %-15s\n",
                       currentB->data.lastName, currentB->data.firstName,
                       currentB->data.middleName, currentB->data.mobileNo,
                       currentB->data.emailAddress);
                currentB = currentB->next;
            }
            break;

        case 'L':;
            char inputLastName[100];
            clearScreen();
            printf("\n\tBROWSE BY LAST NAME MENU\n");
            printf("\n\tInput Last Name: ");
            scanf("%s", inputLastName);

            struct Node* currentL = head;
            printf("\nLast Name\tFirst Name\tMiddle Name\tMobile No.\tEmail Address\n");
            printf("==========================================================================================================\n");

            while (currentL != NULL)
            {
                if (strcmp(currentL->data.lastName, inputLastName) == 0)
                {
                    found = 1;
                    printf("%-15s %-15s %-15s %-15s %-15s\n",
                           currentL->data.lastName, currentL->data.firstName,
                           currentL->data.middleName, currentL->data.mobileNo,
                           currentL->data.emailAddress);
                }
                currentL = currentL->next;
            }

            if (!found)
            {
                printf("\n\tError: Last Name not found!\n");
            }
            break;

        case 'N':;
            char inputMobileNo[100];
            clearScreen();
            printf("\n\tBROWSE BY MOBILE NO. MENU\n");
            printf("\n\tInput Mobile No.: ");
            scanf("%s", inputMobileNo);

            struct Node* currentN = head;
            printf("\nLast Name\tFirst Name\tMiddle Name\tMobile No.\tEmail Address\n");
            printf("==========================================================================================================\n");

            while (currentN != NULL)
            {
                if (strcmp(currentN->data.mobileNo, inputMobileNo) == 0)
                {
                    found = 1;
                    printf("%-15s %-15s %-15s %-15s %-15s\n",
                           currentN->data.lastName, currentN->data.firstName,
                           currentN->data.middleName, currentN->data.mobileNo,
                           currentN->data.emailAddress);
                }
                currentN = currentN->next;
            }

            if (!found)
            {
                printf("Error: Mobile No. not found!\n");
            }
            break;

        default:
            printf("Invalid choice! Please choose again.\n");
            Sleep(1000);
            return;
        }

        printf("\n\n\tAgain [Y/N]?");
        fflush(stdin);
        userInput = toupper(getch());

    } while (userInput != 'N');
    return;
}

void displayBrowseMenu()
{
    clearScreen();
    printf("   BROWSE MENU\n");
    printf("[B] Browse All\n");
    printf("[L] Browse by Last Name\n");
    printf("[N] Browse by Contact Number\n");
    printf("\n\n\tChoice? ");
}

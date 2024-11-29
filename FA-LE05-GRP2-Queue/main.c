#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "queueDLL.h"
int main()
{
    Queue queue;
    initialize(&queue);
    char againChoice;
    int choice;

    char firstName[100];
    char middleName[100];
    char lastName[100];
    char mobileNumber[100];
    char emailAddress[100];

    while (1)
    {
        system("cls");
        printf("\nQUEUE ADT - DLL MENU:\n");
        printf("[1] Enqueue\n");
        printf("[2] Dequeue\n");
        printf("[3] Show\n");
        printf("[4] Exit\n");
        printf("\nChoice? ");

        scanf(" %d", &choice);

        switch(choice)
        {
            case 1:
                do {
                    enqueue(&queue, firstName, middleName, lastName, mobileNumber, emailAddress);
                    fflush(stdin);
                    printf("\nAgain [Y/N]? ");
                    scanf(" %c", &againChoice);
                } while (againChoice != 'N' && againChoice != 'n');
                break;

            case 2:
            do {
                dequeue(&queue);
                fflush(stdin);
                printf("\nAgain [Y/N]? ");
                scanf(" %c", &againChoice);
            } while (againChoice != 'N' && againChoice != 'n');

                break;

            case 3:
                show(&queue);
                printf("\nPress any key to return to MAIN MENU... ");
                getche();
                fflush(stdin);
                break;

            case 4:
                printf("Exiting Program.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

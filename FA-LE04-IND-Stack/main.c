#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "stackSLL.h"

int main()
{
    LinkedList list;
    list.top = NULL;
    int menuChoice;
    char againChoice;

    do {
    system("cls");
    printf("STACK ADT - SLL MENU:\n");
    printf("\t[1] Push\n");
    printf("\t[2] Pop\n");
    printf("\t[3] Show\n");
    printf("\t[4] Exit\n");
    printf("\nChoice? ");
    scanf("%d", &menuChoice);

    switch(menuChoice)
    {
    case 1:
        do
        {
        push(&list);
        fflush(stdin);
        printf("\nAgain [Y/N]? ");
        scanf("%c", &againChoice);
        } while (againChoice != 'N' && againChoice != 'n');
        break;

    case 2:
            do
            {
                pop(&list);
                fflush(stdin);
                printf("\nAgain [Y/N]? ");
                scanf("%c", &againChoice);
            } while (againChoice != 'N' && againChoice != 'n');
            break;

    case 3:

                show(&list);
                printf("\nPress any key to return to main menu... ");
                getche();
                fflush(stdin);


            break;

    case 4:
            printf("Exiting Stack.\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }
        fflush(stdin);
    } while (menuChoice != '4');

    freeStack();

    return 0;
}

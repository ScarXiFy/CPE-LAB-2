#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "stackSLL.h"

struct Node* head = NULL;

void push(LinkedList* list) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    system("cls");
    printf("\nInput First Name: ");
    fflush(stdin);
    gets(newNode->record.firstName);
    printf("Input Middle Name: ");
    gets(newNode->record.middleName);
    printf("Input Last Name: ");
    gets(newNode->record.lastName);
    printf("Input Mobile No.: ");
    gets(newNode->record.mobileNumber);
    printf("Input Email Address: ");
    gets(newNode->record.emailAddress);

    newNode->next = list->top;
    list->top = newNode;
}

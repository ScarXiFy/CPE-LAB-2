#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "stackSLL.h"

void pop(LinkedList* list) {
    if (list->top == NULL) {
        printf("\nStack is empty.\n");
        return;
    }
    Node* temp = list->top;
    list->top = list->top->next;
    printf("\tRecord popped:\n");
    printf("\nFirst Name: %s\n", temp->record.firstName);
    printf("\nMiddle Name: %s\n", temp->record.middleName);
    printf("\nLast Name: %s\n", temp->record.lastName);
    printf("\nMobile No.: %s\n", temp->record.mobileNumber);
    printf("\nEmail Address: %s\n", temp->record.emailAddress);
    free(temp);
}

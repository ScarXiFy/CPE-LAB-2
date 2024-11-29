#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "stackSLL.h"

void show(LinkedList* list) {
    if (list->top == NULL) {
        printf("\nStack is empty.\n");
        return;
    }
    printf("%-19s %-19s %-19s %-14s %-19s\n", "First Name", "Middle Name", "Last Name", "Mobile No.", "Email Address");
    printf("========================================================================================\n");
    Node* current = list->top;
    while (current != NULL) {
        printf("%-19s %-19s %-19s %-14s %-19s\n", current->record.lastName, current->record.firstName, current->record.middleName, current->record.mobileNumber, current->record.emailAddress);
        current = current->next;
    }
    printf("========================================================================================\n");
}

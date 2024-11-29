#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "stackSLL.h"

void freeStack(struct Node* head)
{
    struct Node* current = head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
